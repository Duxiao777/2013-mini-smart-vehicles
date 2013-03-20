/*
 * Copyright (c) Christian Berger and Bernhard Rumpe, Rheinisch-Westfaelische Technische Hochschule Aachen, Germany.
 *
 * The Hesperia Framework.
 */

#ifndef PLAYERTESTSUITE_H_
#define PLAYERTESTSUITE_H_

#include "cxxtest/TestSuite.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

#include "core/SharedPointer.h"
#include "core/base/FIFOQueue.h"
#include "core/base/Service.h"
#include "core/base/Thread.h"
#include "core/data/Container.h"
#include "core/data/TimeStamp.h"
#include "core/io/ContainerConference.h"
#include "core/io/ContainerConferenceFactory.h"
#include "core/io/ContainerListener.h"
#include "core/io/StreamFactory.h"
#include "core/io/URL.h"

#include "hesperia/data/player/PlayerCommand.h"
#include "hesperia/dmcp/ModuleConfigurationProvider.h"
#include "hesperia/dmcp/discoverer/Server.h"
#include "hesperia/dmcp/connection/Server.h"
#include "hesperia/dmcp/connection/ConnectionHandler.h"
#include "hesperia/dmcp/connection/ModuleConnection.h"

#include "../include/Player.h"

using namespace std;
using namespace player;
using namespace core::base;
using namespace core::data;
using namespace hesperia::data;
using namespace hesperia::data::dmcp;
using namespace hesperia::dmcp;
using namespace core::io;

class PlayerTestService : public Service {
    public:
        PlayerTestService(const int32_t &argc, char **argv) :
                myPlayer(argc, argv) {}

        virtual void beforeStop() {
            // Stop player.
            myPlayer.setModuleState(ModuleState::NOT_RUNNING);
        }

        virtual void run() {
            serviceReady();
            myPlayer.runModule();
        }

    private:
        Player myPlayer;
};

class PlayerTestContainerListener : public ContainerListener {
    public:
        PlayerTestContainerListener() :
                fifo(NULL) {
            fifo = new FIFOQueue();
        }

        FIFOQueue& getQueue() {
            return *fifo;
        }

        virtual void nextContainer(Container &c) {
            if ( (c.getDataType() != Container::UNDEFINEDDATA) &&
                    (c.getDataType() != Container::PLAYER_COMMAND) ) {
                fifo->enter(c);
            }
        }

    private:
        PlayerTestContainerListener(const PlayerTestContainerListener& );
        PlayerTestContainerListener& operator=(const PlayerTestContainerListener& );
        FIFOQueue *fifo;
};

class PlayerTest : public CxxTest::TestSuite,
            public connection::ConnectionHandler,
            public ModuleConfigurationProvider {
    public:
        PlayerTest() :
            m_configuration(),
            m_connection() {}

        KeyValueConfiguration m_configuration;
        core::SharedPointer<connection::ModuleConnection> m_connection;

        virtual KeyValueConfiguration getConfiguration(const ModuleDescriptor& /*md*/) {
            return m_configuration;
        }

        virtual void onNewModule(connection::ModuleConnection* mc) {
            m_connection = core::SharedPointer<connection::ModuleConnection>(mc);
        }

        void testPlayerCommand() {
            hesperia::data::player::PlayerCommand pc;
            stringstream s;
            s << pc;

            hesperia::data::player::PlayerCommand pc2;
            s >> pc2;

            hesperia::data::player::PlayerCommand pc3;
            pc3 = pc;

            hesperia::data::player::PlayerCommand pc4(pc);

            TS_ASSERT(pc.toString() == "Pause.");
            TS_ASSERT(pc.toString() == pc2.toString());
            TS_ASSERT(pc.toString() == pc3.toString());
            TS_ASSERT(pc.toString() == pc4.toString());

            pc.setCommand(hesperia::data::player::PlayerCommand::PLAY);
            s << pc;
            s >> pc2;
            pc3 = pc;

            hesperia::data::player::PlayerCommand pc5(pc);

            TS_ASSERT(pc.toString() == "Play.");
            TS_ASSERT(pc.toString() == pc2.toString());
            TS_ASSERT(pc.toString() == pc3.toString());
            TS_ASSERT(pc.toString() == pc5.toString());

            pc.setCommand(hesperia::data::player::PlayerCommand::REWIND);
            TS_ASSERT(pc.toString() == "Rewind.");

            pc.setCommand(hesperia::data::player::PlayerCommand::STEP_FORWARD);
            TS_ASSERT(pc.toString() == "Step forward.");
        }

        void testRealtimeReplayNoRewind() {
            // Prepare record file.
            fstream fout("PlayerTest.rec", ios::out | ios::binary | ios::trunc);

            // Write data.
            TimeStamp ts1(0, 1);
            Container c1(Container::TIMESTAMP, ts1);
            c1.setReceivedTimeStamp(ts1);
            fout << c1;

            TimeStamp ts2(1, 2);
            Container c2(Container::TIMESTAMP, ts2);
            c2.setReceivedTimeStamp(ts2);
            fout << c2;

            TimeStamp ts3(2, 3);
            Container c3(Container::TIMESTAMP, ts3);
            c3.setReceivedTimeStamp(ts3);
            fout << c3;

            TimeStamp ts4(3, 4);
            Container c4(Container::TIMESTAMP, ts4);
            c4.setReceivedTimeStamp(ts4);
            fout << c4;

            TimeStamp ts5(4, 5);
            Container c5(Container::TIMESTAMP, ts5);
            c5.setReceivedTimeStamp(ts5);
            fout << c5;

            fout.flush();
            fout.close();

            // Setup ContainerConference.
            PlayerTestContainerListener ptcl;
            ContainerConference *conference = ContainerConferenceFactory::getInstance().getContainerConference("225.0.0.100");
            conference->setContainerListener(&ptcl);

            // Setup DMCP.
            stringstream sstr;
            sstr << "player.input = file://PlayerTest.rec" << endl
            << "player.autoRewind = 0" << endl
            << "player.remoteControl = 0" << endl
            << "player.timeScale = 1.0" << endl
            << "player.sizeOfCache = 3" << endl;

            m_configuration = KeyValueConfiguration();
            sstr >> m_configuration;

            ServerInformation serverInformation("127.0.0.1", 19000);
            discoverer::Server dmcpDiscovererServer(serverInformation,
                                                    "225.0.0.100",
                                                    BROADCAST_PORT_SERVER,
                                                    BROADCAST_PORT_CLIENT);
            dmcpDiscovererServer.startResponding();

            connection::Server dmcpConnectionServer(serverInformation, *this);
            dmcpConnectionServer.setConnectionHandler(this);

            // Setup player.
            string argv0("player");
            string argv1("--cid=100");
            int32_t argc = 2;
            char **argv;
            argv = new char*[2];
            argv[0] = const_cast<char*>(argv0.c_str());
            argv[1] = const_cast<char*>(argv1.c_str());

            PlayerTestService pts(argc, argv);

            pts.start();

            uint32_t numberOfElements = 0;
            while (numberOfElements != 5) {
                numberOfElements = ptcl.getQueue().getSize();
                Thread::usleep(10*1000*1000);
            }

            pts.stop();

            // Check replayed data:
            Container c;
            TimeStamp ts;

            c = ptcl.getQueue().leave();
            ts = c.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts1.toMicroseconds());
            cerr << "testRealtimeReplayNoRewind - 1: " << ts.toMicroseconds() << " == " << ts1.toMicroseconds() << ": " << (ts.toMicroseconds() == ts1.toMicroseconds()) << endl;

            c = ptcl.getQueue().leave();
            ts = c.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts2.toMicroseconds());
            cerr << "testRealtimeReplayNoRewind - 2: " << ts.toMicroseconds() << " == " << ts2.toMicroseconds() << ": " << (ts.toMicroseconds() == ts2.toMicroseconds()) << endl;

            c = ptcl.getQueue().leave();
            ts = c.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts3.toMicroseconds());
            cerr << "testRealtimeReplayNoRewind - 3: " << ts.toMicroseconds() << " == " << ts3.toMicroseconds() << ": " << (ts.toMicroseconds() == ts3.toMicroseconds()) << endl;

            c = ptcl.getQueue().leave();
            ts = c.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts4.toMicroseconds());
            cerr << "testRealtimeReplayNoRewind - 4: " << ts.toMicroseconds() << " == " << ts4.toMicroseconds() << ": " << (ts.toMicroseconds() == ts4.toMicroseconds()) << endl;

            c = ptcl.getQueue().leave();
            ts = c.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts5.toMicroseconds());
            cerr << "testRealtimeReplayNoRewind - 5: " << ts.toMicroseconds() << " == " << ts5.toMicroseconds() << ": " << (ts.toMicroseconds() == ts5.toMicroseconds()) << endl;

            delete &(StreamFactory::getInstance());

            unlink("PlayerTest.rec");

            HESPERIA_CORE_DELETE_POINTER(conference);
            ContainerConferenceFactory &ccf = ContainerConferenceFactory::getInstance();
            ContainerConferenceFactory *ccf2 = &ccf;
            HESPERIA_CORE_DELETE_POINTER(ccf2);
        }

        void testDoubleRealtimeReplayNoRewind() {
            // Prepare record file.
            fstream fout("PlayerTest.rec", ios::out | ios::binary | ios::trunc);

            // Write data.
            TimeStamp ts1(0, 0);
            Container c1(Container::TIMESTAMP, ts1);
            c1.setReceivedTimeStamp(ts1);
            fout << c1;

            TimeStamp ts2(1, 0);
            Container c2(Container::TIMESTAMP, ts2);
            c2.setReceivedTimeStamp(ts2);
            fout << c2;

            TimeStamp ts3(2, 0);
            Container c3(Container::TIMESTAMP, ts3);
            c3.setReceivedTimeStamp(ts3);
            fout << c3;

            TimeStamp ts4(3, 0);
            Container c4(Container::TIMESTAMP, ts4);
            c4.setReceivedTimeStamp(ts4);
            fout << c4;

            TimeStamp ts5(4, 0);
            Container c5(Container::TIMESTAMP, ts5);
            c5.setReceivedTimeStamp(ts5);
            fout << c5;

            fout.flush();
            fout.close();

            // Setup ContainerConference.
            PlayerTestContainerListener ptcl;
            ContainerConference *conference = ContainerConferenceFactory::getInstance().getContainerConference("225.0.0.100");
            conference->setContainerListener(&ptcl);

            // Setup DMCP.
            stringstream sstr;
            sstr << "player.input = file://PlayerTest.rec" << endl
            << "player.autoRewind = 0" << endl
            << "player.remoteControl = 0" << endl
            << "player.timeScale = 0.5" << endl
            << "player.sizeOfCache = 3" << endl;

            m_configuration = KeyValueConfiguration();
            sstr >> m_configuration;

            ServerInformation serverInformation("127.0.0.1", 19000);
            discoverer::Server dmcpDiscovererServer(serverInformation,
                                                    "225.0.0.100",
                                                    BROADCAST_PORT_SERVER,
                                                    BROADCAST_PORT_CLIENT);
            dmcpDiscovererServer.startResponding();

            connection::Server dmcpConnectionServer(serverInformation, *this);
            dmcpConnectionServer.setConnectionHandler(this);

            // Setup player.
            string argv0("player");
            string argv1("--cid=100");
            int32_t argc = 2;
            char **argv;
            argv = new char*[2];
            argv[0] = const_cast<char*>(argv0.c_str());
            argv[1] = const_cast<char*>(argv1.c_str());

            PlayerTestService pts(argc, argv);

            pts.start();

            uint32_t numberOfElements = 0;
            while (numberOfElements != 5) {
                numberOfElements = ptcl.getQueue().getSize();
                Thread::usleep(10*1000*1000);
            }

            pts.stop();

            // Check replayed data:
            TimeStamp ts;

            c1 = ptcl.getQueue().leave();
            ts = c1.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts1.toMicroseconds());
            cerr << "testDoubleRealtimeReplayNoRewind - 1: " << ts.toMicroseconds() << " == " << ts1.toMicroseconds() << ": " << (ts.toMicroseconds() == ts1.toMicroseconds()) << endl;

            c2 = ptcl.getQueue().leave();
            ts = c2.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts2.toMicroseconds());
            cerr << "testDoubleRealtimeReplayNoRewind - 2: " << ts.toMicroseconds() << " == " << ts2.toMicroseconds() << ": " << (ts.toMicroseconds() == ts2.toMicroseconds()) << endl;

            c3 = ptcl.getQueue().leave();
            ts = c3.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts3.toMicroseconds());
            cerr << "testDoubleRealtimeReplayNoRewind - 3: " << ts.toMicroseconds() << " == " << ts3.toMicroseconds() << ": " << (ts.toMicroseconds() == ts3.toMicroseconds()) << endl;

            c4 = ptcl.getQueue().leave();
            ts = c4.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts4.toMicroseconds());
            cerr << "testDoubleRealtimeReplayNoRewind - 4: " << ts.toMicroseconds() << " == " << ts4.toMicroseconds() << ": " << (ts.toMicroseconds() == ts4.toMicroseconds()) << endl;

            c5 = ptcl.getQueue().leave();
            ts = c5.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts5.toMicroseconds());
            cerr << "testDoubleRealtimeReplayNoRewind - 5: " << ts.toMicroseconds() << " == " << ts5.toMicroseconds() << ": " << (ts.toMicroseconds() == ts5.toMicroseconds()) << endl;

            TimeStamp delta;
            delta = c2.getSentTimeStamp() - c1.getSentTimeStamp();
            TS_ASSERT_DELTA(delta.toMicroseconds() / 1000000.0, 0.5, 1e-1);

            delta = c3.getSentTimeStamp() - c2.getSentTimeStamp();
            TS_ASSERT_DELTA(delta.toMicroseconds() / 1000000.0, 0.5, 1e-1);

            delta = c4.getSentTimeStamp() - c3.getSentTimeStamp();
            TS_ASSERT_DELTA(delta.toMicroseconds() / 1000000.0, 0.5, 1e-1);

            delta = c5.getSentTimeStamp() - c4.getSentTimeStamp();
            TS_ASSERT_DELTA(delta.toMicroseconds() / 1000000.0, 0.5, 1e-1);

            delete &(StreamFactory::getInstance());

            unlink("PlayerTest.rec");

            HESPERIA_CORE_DELETE_POINTER(conference);
            ContainerConferenceFactory &ccf = ContainerConferenceFactory::getInstance();
            ContainerConferenceFactory *ccf2 = &ccf;
            HESPERIA_CORE_DELETE_POINTER(ccf2);
        }

        void testHalfRealtimeReplayNoRewind() {
            // Prepare record file.
            fstream fout("PlayerTest.rec", ios::out | ios::binary | ios::trunc);

            // Write data.
            TimeStamp ts1(0, 0);
            Container c1(Container::TIMESTAMP, ts1);
            c1.setReceivedTimeStamp(ts1);
            fout << c1;

            TimeStamp ts2(1, 0);
            Container c2(Container::TIMESTAMP, ts2);
            c2.setReceivedTimeStamp(ts2);
            fout << c2;

            TimeStamp ts3(2, 0);
            Container c3(Container::TIMESTAMP, ts3);
            c3.setReceivedTimeStamp(ts3);
            fout << c3;

            TimeStamp ts4(3, 0);
            Container c4(Container::TIMESTAMP, ts4);
            c4.setReceivedTimeStamp(ts4);
            fout << c4;

            TimeStamp ts5(4, 0);
            Container c5(Container::TIMESTAMP, ts5);
            c5.setReceivedTimeStamp(ts5);
            fout << c5;

            fout.flush();
            fout.close();

            // Setup ContainerConference.
            PlayerTestContainerListener ptcl;
            ContainerConference *conference = ContainerConferenceFactory::getInstance().getContainerConference("225.0.0.100");
            conference->setContainerListener(&ptcl);

            // Setup DMCP.
            stringstream sstr;
            sstr << "player.input = file://PlayerTest.rec" << endl
            << "player.autoRewind = 0" << endl
            << "player.remoteControl = 0" << endl
            << "player.timeScale = 2.0" << endl
            << "player.sizeOfCache = 3" << endl;

            m_configuration = KeyValueConfiguration();
            sstr >> m_configuration;

            ServerInformation serverInformation("127.0.0.1", 19000);
            discoverer::Server dmcpDiscovererServer(serverInformation,
                                                    "225.0.0.100",
                                                    BROADCAST_PORT_SERVER,
                                                    BROADCAST_PORT_CLIENT);
            dmcpDiscovererServer.startResponding();

            connection::Server dmcpConnectionServer(serverInformation, *this);
            dmcpConnectionServer.setConnectionHandler(this);

            // Setup player.
            string argv0("player");
            string argv1("--cid=100");
            int32_t argc = 2;
            char **argv;
            argv = new char*[2];
            argv[0] = const_cast<char*>(argv0.c_str());
            argv[1] = const_cast<char*>(argv1.c_str());
            PlayerTestService pts(argc, argv);

            pts.start();

            uint32_t numberOfElements = 0;
            while (numberOfElements != 5) {
                numberOfElements = ptcl.getQueue().getSize();
                Thread::usleep(10*1000*1000);
            }

            pts.stop();

            // Check replayed data:
            TimeStamp ts;

            c1 = ptcl.getQueue().leave();
            ts = c1.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts1.toMicroseconds());
            cerr << "testHalfRealtimeReplayNoRewind - 1: " << ts.toMicroseconds() << " == " << ts1.toMicroseconds() << ": " << (ts.toMicroseconds() == ts1.toMicroseconds()) << endl;

            c2 = ptcl.getQueue().leave();
            ts = c2.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts2.toMicroseconds());
            cerr << "testHalfRealtimeReplayNoRewind - 2: " << ts.toMicroseconds() << " == " << ts2.toMicroseconds() << ": " << (ts.toMicroseconds() == ts2.toMicroseconds()) << endl;

            c3 = ptcl.getQueue().leave();
            ts = c3.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts3.toMicroseconds());
            cerr << "testHalfRealtimeReplayNoRewind - 3: " << ts.toMicroseconds() << " == " << ts3.toMicroseconds() << ": " << (ts.toMicroseconds() == ts3.toMicroseconds()) << endl;

            c4 = ptcl.getQueue().leave();
            ts = c4.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts4.toMicroseconds());
            cerr << "testHalfRealtimeReplayNoRewind - 4: " << ts.toMicroseconds() << " == " << ts4.toMicroseconds() << ": " << (ts.toMicroseconds() == ts4.toMicroseconds()) << endl;

            c5 = ptcl.getQueue().leave();
            ts = c5.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts5.toMicroseconds());
            cerr << "testHalfRealtimeReplayNoRewind - 5: " << ts.toMicroseconds() << " == " << ts5.toMicroseconds() << ": " << (ts.toMicroseconds() == ts5.toMicroseconds()) << endl;

            TimeStamp delta;
            delta = c2.getSentTimeStamp() - c1.getSentTimeStamp();
            TS_ASSERT_DELTA(delta.toMicroseconds() / 1000000.0, 2.0, 1e-1);

            delta = c3.getSentTimeStamp() - c2.getSentTimeStamp();
            TS_ASSERT_DELTA(delta.toMicroseconds() / 1000000.0, 2.0, 1e-1);

            delta = c4.getSentTimeStamp() - c3.getSentTimeStamp();
            TS_ASSERT_DELTA(delta.toMicroseconds() / 1000000.0, 2.0, 1e-1);

            delta = c5.getSentTimeStamp() - c4.getSentTimeStamp();
            TS_ASSERT_DELTA(delta.toMicroseconds() / 1000000.0, 2.0, 1e-1);

            delete &(StreamFactory::getInstance());

            unlink("PlayerTest.rec");

            HESPERIA_CORE_DELETE_POINTER(conference);
            ContainerConferenceFactory &ccf = ContainerConferenceFactory::getInstance();
            ContainerConferenceFactory *ccf2 = &ccf;
            HESPERIA_CORE_DELETE_POINTER(ccf2);
        }

        void testRealtimeReplayAutoRewind() {
            // Prepare record file.
            fstream fout("PlayerTest.rec", ios::out | ios::binary | ios::trunc);

            // Write data.
            TimeStamp ts1(0, 1);
            Container c1(Container::TIMESTAMP, ts1);
            c1.setReceivedTimeStamp(ts1);
            fout << c1;

            TimeStamp ts2(1, 2);
            Container c2(Container::TIMESTAMP, ts2);
            c2.setReceivedTimeStamp(ts2);
            fout << c2;

            TimeStamp ts3(2, 3);
            Container c3(Container::TIMESTAMP, ts3);
            c3.setReceivedTimeStamp(ts3);
            fout << c3;

            TimeStamp ts4(3, 4);
            Container c4(Container::TIMESTAMP, ts4);
            c4.setReceivedTimeStamp(ts4);
            fout << c4;

            TimeStamp ts5(4, 5);
            Container c5(Container::TIMESTAMP, ts5);
            c5.setReceivedTimeStamp(ts5);
            fout << c5;

            fout.flush();
            fout.close();

            // Setup ContainerConference.
            PlayerTestContainerListener ptcl;
            ContainerConference *conference = ContainerConferenceFactory::getInstance().getContainerConference("225.0.0.100");
            conference->setContainerListener(&ptcl);

            // Setup DMCP.
            stringstream sstr;
            sstr << "player.input = file://PlayerTest.rec" << endl
            << "player.autoRewind = 1" << endl
            << "player.remoteControl = 0" << endl
            << "player.timeScale = 1.0" << endl
            << "player.sizeOfCache = 3" << endl;

            m_configuration = KeyValueConfiguration();
            sstr >> m_configuration;

            ServerInformation serverInformation("127.0.0.1", 19000);
            discoverer::Server dmcpDiscovererServer(serverInformation,
                                                    "225.0.0.100",
                                                    BROADCAST_PORT_SERVER,
                                                    BROADCAST_PORT_CLIENT);
            dmcpDiscovererServer.startResponding();

            connection::Server dmcpConnectionServer(serverInformation, *this);
            dmcpConnectionServer.setConnectionHandler(this);

            // Setup player.
            string argv0("player");
            string argv1("--cid=100");
            int32_t argc = 2;
            char **argv;
            argv = new char*[2];
            argv[0] = const_cast<char*>(argv0.c_str());
            argv[1] = const_cast<char*>(argv1.c_str());
            PlayerTestService pts(argc, argv);
            pts.start();

            uint32_t numberOfElements = 0;
            while (!(numberOfElements > 10)) {
                numberOfElements = ptcl.getQueue().getSize();
                Thread::usleep(10*1000*1000);
            }

            pts.stop();

            // Check replayed data:
            Container c;
            TimeStamp ts;

            c = ptcl.getQueue().leave();
            ts = c.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts1.toMicroseconds());
            cerr << "testRealtimeReplayAutoRewind - 1: " << ts.toMicroseconds() << " == " << ts1.toMicroseconds() << ": " << (ts.toMicroseconds() == ts1.toMicroseconds()) << endl;

            c = ptcl.getQueue().leave();
            ts = c.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts2.toMicroseconds());
            cerr << "testRealtimeReplayAutoRewind - 2: " << ts.toMicroseconds() << " == " << ts2.toMicroseconds() << ": " << (ts.toMicroseconds() == ts2.toMicroseconds()) << endl;

            c = ptcl.getQueue().leave();
            ts = c.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts3.toMicroseconds());
            cerr << "testRealtimeReplayAutoRewind - 3: " << ts.toMicroseconds() << " == " << ts3.toMicroseconds() << ": " << (ts.toMicroseconds() == ts3.toMicroseconds()) << endl;

            c = ptcl.getQueue().leave();
            ts = c.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts4.toMicroseconds());
            cerr << "testRealtimeReplayAutoRewind - 4: " << ts.toMicroseconds() << " == " << ts4.toMicroseconds() << ": " << (ts.toMicroseconds() == ts4.toMicroseconds()) << endl;

            c = ptcl.getQueue().leave();
            ts = c.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts5.toMicroseconds());
            cerr << "testRealtimeReplayAutoRewind - 5: " << ts.toMicroseconds() << " == " << ts5.toMicroseconds() << ": " << (ts.toMicroseconds() == ts5.toMicroseconds()) << endl;

            c = ptcl.getQueue().leave();
            ts = c.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts1.toMicroseconds());
            cerr << "testRealtimeReplayAutoRewind - 1: " << ts.toMicroseconds() << " == " << ts1.toMicroseconds() << ": " << (ts.toMicroseconds() == ts1.toMicroseconds()) << endl;

            c = ptcl.getQueue().leave();
            ts = c.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts2.toMicroseconds());
            cerr << "testRealtimeReplayAutoRewind - 2: " << ts.toMicroseconds() << " == " << ts2.toMicroseconds() << ": " << (ts.toMicroseconds() == ts2.toMicroseconds()) << endl;

            c = ptcl.getQueue().leave();
            ts = c.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts3.toMicroseconds());
            cerr << "testRealtimeReplayAutoRewind - 3: " << ts.toMicroseconds() << " == " << ts3.toMicroseconds() << ": " << (ts.toMicroseconds() == ts3.toMicroseconds()) << endl;

            c = ptcl.getQueue().leave();
            ts = c.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts4.toMicroseconds());
            cerr << "testRealtimeReplayAutoRewind - 4: " << ts.toMicroseconds() << " == " << ts4.toMicroseconds() << ": " << (ts.toMicroseconds() == ts4.toMicroseconds()) << endl;

            c = ptcl.getQueue().leave();
            ts = c.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts5.toMicroseconds());
            cerr << "testRealtimeReplayAutoRewind - 5: " << ts.toMicroseconds() << " == " << ts5.toMicroseconds() << ": " << (ts.toMicroseconds() == ts5.toMicroseconds()) << endl;

            delete &(StreamFactory::getInstance());

            unlink("PlayerTest.rec");

            HESPERIA_CORE_DELETE_POINTER(conference);
            ContainerConferenceFactory &ccf = ContainerConferenceFactory::getInstance();
            ContainerConferenceFactory *ccf2 = &ccf;
            HESPERIA_CORE_DELETE_POINTER(ccf2);
        }

        void testRealtimeReplayNoRewindRemoteControl() {
            // Prepare record file.
            fstream fout("PlayerTest.rec", ios::out | ios::binary | ios::trunc);

            // Write data.
            TimeStamp ts1(0, 1);
            Container c1(Container::TIMESTAMP, ts1);
            c1.setReceivedTimeStamp(ts1);
            fout << c1;

            TimeStamp ts2(1, 2);
            Container c2(Container::TIMESTAMP, ts2);
            c2.setReceivedTimeStamp(ts2);
            fout << c2;

            TimeStamp ts3(2, 3);
            Container c3(Container::TIMESTAMP, ts3);
            c3.setReceivedTimeStamp(ts3);
            fout << c3;

            TimeStamp ts4(3, 4);
            Container c4(Container::TIMESTAMP, ts4);
            c4.setReceivedTimeStamp(ts4);
            fout << c4;

            TimeStamp ts5(4, 5);
            Container c5(Container::TIMESTAMP, ts5);
            c5.setReceivedTimeStamp(ts5);
            fout << c5;

            fout.flush();
            fout.close();

            // Setup ContainerConference.
            PlayerTestContainerListener ptcl;
            ContainerConference *conference = ContainerConferenceFactory::getInstance().getContainerConference("225.0.0.100");
            conference->setContainerListener(&ptcl);

            // Setup DMCP.
            stringstream sstr;
            sstr << "player.input = file://PlayerTest.rec" << endl
            << "player.autoRewind = 0" << endl
            << "player.remoteControl = 1" << endl
            << "player.timeScale = 1.0" << endl
            << "player.sizeOfCache = 3" << endl;

            m_configuration = KeyValueConfiguration();
            sstr >> m_configuration;

            ServerInformation serverInformation("127.0.0.1", 19000);
            discoverer::Server dmcpDiscovererServer(serverInformation,
                                                    "225.0.0.100",
                                                    BROADCAST_PORT_SERVER,
                                                    BROADCAST_PORT_CLIENT);
            dmcpDiscovererServer.startResponding();

            connection::Server dmcpConnectionServer(serverInformation, *this);
            dmcpConnectionServer.setConnectionHandler(this);

            // Setup player.
            string argv0("player");
            string argv1("--cid=100");
            int32_t argc = 2;
            char **argv;
            argv = new char*[2];
            argv[0] = const_cast<char*>(argv0.c_str());
            argv[1] = const_cast<char*>(argv1.c_str());
            PlayerTestService pts(argc, argv);

            pts.start();

            // Wait int16_tly.
            Thread::usleep(10*1000*1000);

            ////////////////////////////////////////////////////////////////////
            // Start player.
            ////////////////////////////////////////////////////////////////////

            // Start playing.
            hesperia::data::player::PlayerCommand playerCommand;
            playerCommand.setCommand(hesperia::data::player::PlayerCommand::PLAY);
            Container cPC1(Container::PLAYER_COMMAND, playerCommand);
            conference->send(cPC1);

            uint32_t numberOfElements = 0;
            while (!(numberOfElements > 0)) {
                numberOfElements = ptcl.getQueue().getSize();
                Thread::usleep(50);
            }

            // Pause playing.
            playerCommand.setCommand(hesperia::data::player::PlayerCommand::PAUSE);
            Container cPC2(Container::PLAYER_COMMAND, playerCommand);
            conference->send(cPC2);

            ////////////////////////////////////////////////////////////////////
            // Pause player (first token of recorded file has to be replayed).
            ////////////////////////////////////////////////////////////////////

            TS_ASSERT(ptcl.getQueue().getSize() == 1);

            // Check replayed data:
            Container c;
            TimeStamp ts;

            c = ptcl.getQueue().leave();
            ts = c.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts1.toMicroseconds());

            ////////////////////////////////////////////////////////////////////
            // Rewind player.
            ////////////////////////////////////////////////////////////////////

            // Rewind.
            playerCommand.setCommand(hesperia::data::player::PlayerCommand::REWIND);
            Container cPC3(Container::PLAYER_COMMAND, playerCommand);
            conference->send(cPC3);

            Thread::usleep(1000);

            ////////////////////////////////////////////////////////////////////
            // Start player.
            ////////////////////////////////////////////////////////////////////

            // Start playing.
            // Clear queue.
            ptcl.getQueue().clear();
            playerCommand.setCommand(hesperia::data::player::PlayerCommand::PLAY);
            Container cPC4(Container::PLAYER_COMMAND, playerCommand);
            conference->send(cPC4);

            numberOfElements = 0;
            while (!(numberOfElements > 0)) {
                numberOfElements = ptcl.getQueue().getSize();
                Thread::usleep(50);
            }

            ////////////////////////////////////////////////////////////////////
            // Pause player (first token of recorded file has to be replayed again).
            ////////////////////////////////////////////////////////////////////

            // Pause playing.
            playerCommand.setCommand(hesperia::data::player::PlayerCommand::PAUSE);
            Container cPC5(Container::PLAYER_COMMAND, playerCommand);
            conference->send(cPC5);

            TS_ASSERT(ptcl.getQueue().getSize() == 1);

            // Check replayed data:
            c = ptcl.getQueue().leave();
            ts = c.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts1.toMicroseconds());

            Thread::usleep(1000);

            ////////////////////////////////////////////////////////////////////
            // Start player.
            ////////////////////////////////////////////////////////////////////

            // Start playing.
            // Clear queue.
            ptcl.getQueue().clear();
            playerCommand.setCommand(hesperia::data::player::PlayerCommand::PLAY);
            Container cPC6(Container::PLAYER_COMMAND, playerCommand);
            conference->send(cPC6);

            numberOfElements = 0;
            while (!(numberOfElements > 0)) {
                numberOfElements = ptcl.getQueue().getSize();
                Thread::usleep(50);
            }

            ////////////////////////////////////////////////////////////////////
            // Pause player (second token of recorded file has to be replayed).
            ////////////////////////////////////////////////////////////////////

            // Pause playing.
            playerCommand.setCommand(hesperia::data::player::PlayerCommand::PAUSE);
            Container cPC7(Container::PLAYER_COMMAND, playerCommand);
            conference->send(cPC7);

            TS_ASSERT(ptcl.getQueue().getSize() == 1);

            // Check replayed data:
            c = ptcl.getQueue().leave();
            ts = c.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts2.toMicroseconds());

            Thread::usleep(1000);

            ////////////////////////////////////////////////////////////////////
            // Stepwise playing.
            ////////////////////////////////////////////////////////////////////

            // Clear queue.
            ptcl.getQueue().clear();
            playerCommand.setCommand(hesperia::data::player::PlayerCommand::STEP_FORWARD);
            Container cPC8(Container::PLAYER_COMMAND, playerCommand);
            conference->send(cPC8);

            numberOfElements = 0;
            while (!(numberOfElements > 0)) {
                numberOfElements = ptcl.getQueue().getSize();
                Thread::usleep(50);
            }

            TS_ASSERT(ptcl.getQueue().getSize() == 1);

            // Check replayed data:
            c = ptcl.getQueue().leave();
            ts = c.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts3.toMicroseconds());

            // Clear queue.
            ptcl.getQueue().clear();
            playerCommand.setCommand(hesperia::data::player::PlayerCommand::STEP_FORWARD);
            Container cPC9(Container::PLAYER_COMMAND, playerCommand);
            conference->send(cPC9);

            numberOfElements = 0;
            while (!(numberOfElements > 0)) {
                numberOfElements = ptcl.getQueue().getSize();
                Thread::usleep(50);
            }

            TS_ASSERT(ptcl.getQueue().getSize() == 1);

            // Check replayed data:
            c = ptcl.getQueue().leave();
            ts = c.getData<TimeStamp>();
            TS_ASSERT(ts.toMicroseconds() == ts4.toMicroseconds());

            pts.stop();

            delete &(StreamFactory::getInstance());

            unlink("PlayerTest.rec");

            HESPERIA_CORE_DELETE_POINTER(conference);
            ContainerConferenceFactory &ccf = ContainerConferenceFactory::getInstance();
            ContainerConferenceFactory *ccf2 = &ccf;
            HESPERIA_CORE_DELETE_POINTER(ccf2);
        }
};

#endif /*PLAYERTESTSUITE_H_*/
