/*
 * Mini-Smart-Vehicles.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#ifndef PROXY_H_
#define PROXY_H_

#include <map>

#include "core/base/ConferenceClientModule.h"
#include "core/wrapper/StringListener.h"

#include "PointSensor.h"
#include "SensorBoardData.h"

namespace msv {

    using namespace std;

    /**
     * This class is a skeleton to translate OpenDaVINCI Containers to UDP_Server commands.
     */
    class Proxy : public core::base::ConferenceClientModule, public core::wrapper::StringListener {
        public:
            // Packets that only expect ack
            enum CAR_NORES_PACKET_ID {
                CAR_PACKET_SET_POWER_SERVO = 0,
                CAR_PACKET_WRITE_POS
            };

            // Packets that expect response
            enum CAR_RES_PACKET_ID {
                CAR_PACKET_READ_VALUES = 0,
                CAR_PACKET_READ_POS,
                CAR_PACKET_READ_SENS_ULTRA,
                CAR_PACKET_READ_SENS_IR,
                CAR_PACKET_PING,
                CAR_PACKET_ACK2 = 254
            };

            enum CAR_SPECIAL_CMD {
                CAR_PACKET_RES = 1,
                CAR_PACKET_NORES = 2,
                CAR_PACKET_ACK = 254
            };

        private:
            /**
             * "Forbidden" copy constructor. Goal: The compiler should warn
             * already at compile time for unwanted bugs caused by any misuse
             * of the copy constructor.
             *
             * @param obj Reference to an object of this class.
             */
            Proxy(const Proxy &/*obj*/);

            /**
             * "Forbidden" assignment operator. Goal: The compiler should warn
             * already at compile time for unwanted bugs caused by any misuse
             * of the assignment operator.
             *
             * @param obj Reference to an object of this class.
             * @return Reference to this instance.
             */
            Proxy& operator=(const Proxy &/*obj*/);

        public:
            /**
             * Constructor.
             *
             * @param argc Number of command line arguments.
             * @param argv Command line arguments.
             */
            Proxy(const int32_t &argc, char **argv);

            virtual ~Proxy();

            core::base::ModuleState::MODULE_EXITCODE body();

            virtual void nextString(const string &s);

        private:
            virtual void setUp();

            virtual void tearDown();

            /**
             * This method creates the payload part of the packet to be sent to UDP_Server.
             *
             * @param speed Speed information.
             * @param dir Steering information.
             * @return payload part of the packet to be sent to UDP_Server.
             */
            string createPayloadForSettingAccelerationAndSteering(const uint16_t &speed, const uint8_t &direction) const;

            string createPayloadForQueryOnboardData() const;

            string createPayloadForQueryUltraSonicData() const;

            string createPayloadForQueryInfraRedData() const;

            string createPayloadForQueryPositionData() const;

            /**
             * This method creates the outer frame (CRC16 checksum).
             *
             * @param s Payload to be sent to the server.
             * @return packet to be sent to UDP_Server.
             */
            string createPacket(const string &s) const;

            unsigned short crc16(const unsigned char *buf, unsigned int len) const;

        private:
            map<uint16_t, PointSensor*> m_mapOfPointSensors;
            SensorBoardData m_sensorBoardData;
            bool m_debug;
    };

} // msv

#endif /*PROXY_H_*/
