/*
 * Copyright (c) Christian Berger and Bernhard Rumpe, Rheinisch-Westfaelische Technische Hochschule Aachen, Germany.
 *
 * The Hesperia Framework.
 */

#ifndef HESPERIA_CORE_WRAPPER_UDPRECEIVER_H_
#define HESPERIA_CORE_WRAPPER_UDPRECEIVER_H_

#include "core/wrapper/Mutex.h"
#include "core/wrapper/PacketObserver.h"
#include "core/wrapper/PacketListener.h"
#include "core/wrapper/StringObserver.h"
#include "core/wrapper/StringPipeline.h"

namespace core {
    namespace wrapper {

        using namespace std;

        /**
         * This class is the abstract superclass for receiving UDP packets
         * using UDP.
         *
         * It can be used for a stringlistener receiving asynchronously
         * decoupled strings or for a packetlistener receiving synchronously
         * packets.
         *
         * @code
         * class MyStringListener : public StringListener {
         *      public:
         *          virtual void nextString(const string &s) {
         *              clog << "Received: " << s << endl;
         *          }
         * };
         * ...
         *
         * MyStringListener msl;
         * const string address = "0.0.0.0";
         * const uint32_t port = 12345;
         * UDPReceiver *r = NULL;
         *
         * try {
         *     r = UDPFactory::getInstance().createUDPReceiver(address, port);
         * }
         * catch(string &s) {
         *    clog << "Failed: " << s << endl;
         * }
         *
         * if (r != NULL) {
         *     r->setStringListener(&msl);
         *     r->start();
         * }
         *
         * ...
         * // Do some different things.
         * ...
         *
         * if (r != NULL) {
         *     r->stop();
         *     delete r;
         * }
         *
         * @endcode
         */
        class UDPReceiver : public PacketObserver, public StringObserver {
            private:
                /**
                 * "Forbidden" copy constructor. Goal: The compiler should warn
                 * already at compile time for unwanted bugs caused by any misuse
                 * of the copy constructor.
                 */
                UDPReceiver(const UDPReceiver &);

                /**
                 * "Forbidden" assignment operator. Goal: The compiler should warn
                 * already at compile time for unwanted bugs caused by any misuse
                 * of the assignment operator.
                 */
                UDPReceiver& operator=(const UDPReceiver &);

            protected:
                /**
                 * Protected constructor for enforcing subclasses for this class.
                 */
                UDPReceiver();

            public:
                virtual ~UDPReceiver();

                /**
                 * This method starts the asynchronous
                 * UDP receiving.
                 */
                virtual void start() = 0;

                /**
                 * This method stops the asynchronous
                 * UDP receiving. A stopped receiving cannot be restarted!
                 */
                virtual void stop() = 0;

                virtual void setStringListener(StringListener *sl);

                virtual void setPacketListener(PacketListener *pl);

            protected:
                /**
                 * This method is called from deriving classes to
                 * pass newly arrived packets.
                 */
                void nextPacket(const Packet &p);

            private:
                StringPipeline m_stringPipeline;

                Mutex *m_packetListenerMutex;
                PacketListener *m_packetListener;
        };

    }
} // core::wrapper

#endif /*HESPERIA_CORE_WRAPPER_UDPRECEIVER_H_*/
