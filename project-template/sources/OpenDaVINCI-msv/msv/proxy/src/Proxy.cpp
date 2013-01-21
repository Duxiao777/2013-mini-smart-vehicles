/*
 * Mini-Smart-Vehicles.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#include <cstring>
#include <cmath>

#include <string>

#include "core/macros.h"
#include "core/base/FIFOQueue.h"
#include "core/data/Container.h"
#include "core/base/KeyValueConfiguration.h"
#include "core/data/TimeStamp.h"
#include "core/data/control/ForceControl.h"
#include "core/data/environment/VehicleData.h"
#include "core/io/ContainerConference.h"
#include "core/wrapper/UDPFactory.h"
#include "core/wrapper/UDPSender.h"
#include "core/wrapper/UDPReceiver.h"
#include "core/io/StreamFactory.h"
#include "core/io/URL.h"
#include "core/exceptions/Exceptions.h"

#include "SensorBoardData.h"
#include "Proxy.h"

namespace msv {

    using namespace std;
    using namespace core::base;
    using namespace core::data;
    using namespace core::data::control;
    using namespace core::data::environment;
    using namespace core::exceptions;
    using namespace core::io;

    // Table of CRC constants - implements x^16+x^12+x^5+1
    const unsigned short crc16_tab[] = { 0x0000, 0x1021, 0x2042, 0x3063, 0x4084,
            0x50a5, 0x60c6, 0x70e7, 0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad,
            0xe1ce, 0xf1ef, 0x1231, 0x0210, 0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7,
            0x62d6, 0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c, 0xf3ff, 0xe3de,
            0x2462, 0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485, 0xa56a,
            0xb54b, 0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d, 0x3653, 0x2672,
            0x1611, 0x0630, 0x76d7, 0x66f6, 0x5695, 0x46b4, 0xb75b, 0xa77a, 0x9719,
            0x8738, 0xf7df, 0xe7fe, 0xd79d, 0xc7bc, 0x48c4, 0x58e5, 0x6886, 0x78a7,
            0x0840, 0x1861, 0x2802, 0x3823, 0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948,
            0x9969, 0xa90a, 0xb92b, 0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50,
            0x3a33, 0x2a12, 0xdbfd, 0xcbdc, 0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b,
            0xab1a, 0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41,
            0xedae, 0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49, 0x7e97,
            0x6eb6, 0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70, 0xff9f, 0xefbe,
            0xdfdd, 0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78, 0x9188, 0x81a9, 0xb1ca,
            0xa1eb, 0xd10c, 0xc12d, 0xf14e, 0xe16f, 0x1080, 0x00a1, 0x30c2, 0x20e3,
            0x5004, 0x4025, 0x7046, 0x6067, 0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d,
            0xd31c, 0xe37f, 0xf35e, 0x02b1, 0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214,
            0x6277, 0x7256, 0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c,
            0xc50d, 0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
            0xa7db, 0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e, 0xc71d, 0xd73c, 0x26d3,
            0x36f2, 0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634, 0xd94c, 0xc96d,
            0xf90e, 0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab, 0x5844, 0x4865, 0x7806,
            0x6827, 0x18c0, 0x08e1, 0x3882, 0x28a3, 0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e,
            0x8bf9, 0x9bd8, 0xabbb, 0xbb9a, 0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1,
            0x1ad0, 0x2ab3, 0x3a92, 0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b,
            0x9de8, 0x8dc9, 0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0,
            0x0cc1, 0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8,
            0x6e17, 0x7e36, 0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1, 0x1ef0 };


    Proxy::Proxy(const int32_t &argc, char **argv) :
	    ConferenceClientModule(argc, argv, "Proxy"),
        m_mapOfPointSensors(),
        m_sensorBoardData(),
        m_debug(false) {
    }

    Proxy::~Proxy() {
    }

    void Proxy::setUp() {
	    // This method will be call automatically _before_ running body().
    }

    void Proxy::tearDown() {
	    // This method will be call automatically _after_ return from body().
    }

    unsigned short Proxy::crc16(const unsigned char *buf, unsigned int len) const {
        unsigned int i;
        unsigned short cksum = 0;
        for (i = 0; i < len; i++) {
            cksum = crc16_tab[(((cksum >> 8) ^ *buf++) & 0xFF)] ^ (cksum << 8);
        }
        return cksum;
    }

    string Proxy::createPayloadForQueryOnboardData() const {
        stringstream strbuffer;
        strbuffer << (char)CAR_PACKET_RES;
        strbuffer << (char)CAR_PACKET_READ_VALUES;
        return strbuffer.str();
    }

    string Proxy::createPayloadForQueryUltraSonicData() const {
        stringstream strbuffer;
        strbuffer << (char)CAR_PACKET_RES;
        strbuffer << (char)CAR_PACKET_READ_SENS_ULTRA;
        return strbuffer.str();
    }

    string Proxy::createPayloadForQueryInfraRedData() const {
        stringstream strbuffer;
        strbuffer << (char)CAR_PACKET_RES;
        strbuffer << (char)CAR_PACKET_READ_SENS_IR;
        return strbuffer.str();
    }

    string Proxy::createPayloadForQueryPositionData() const {
        stringstream strbuffer;
        strbuffer << (char)CAR_PACKET_RES;
        strbuffer << (char)CAR_PACKET_READ_POS;
        return strbuffer.str();
    }

    string Proxy::createPayloadForSettingAccelerationAndSteering(const uint16_t &speed, const uint8_t &direction) const {
        stringstream strbuffer;
        strbuffer << (char)CAR_PACKET_NORES;
        strbuffer << (char)CAR_PACKET_SET_POWER_SERVO;

        uint16_t speed_int = speed;
        
        strbuffer << (char)(speed_int >> 8);
        strbuffer << (char)(speed_int);

        uint8_t dir = direction;
        strbuffer << (char)(dir);
        return strbuffer.str();
    }

    string Proxy::createPacket(const string &s) const {
        // Create packet for UDP_Server with crc16 checksum.
        uint16_t len = s.size();
        unsigned char buffer[len + 5];
        buffer[0] = 2;
        buffer[1] = len;

        memcpy(buffer + 2, s.c_str(), len);

        unsigned short crc = crc16((const unsigned char*)s.c_str(), len);
        buffer[len + 2] = crc >> 8;
        buffer[len + 3] = crc;
        buffer[len + 4] = 3;

        // Send to UDP_Server.
        string retVal((const char*)buffer, len+5);
        return retVal;
    }

    void Proxy::nextString(const string &s) {
        const char *data = s.c_str();
        // First byte is always 2. Skip it.
        data++;

        // Second byte is length.
        const uint16_t len = (uint16_t)(*data);
        data++;

        // Third byte is type of reply.
        CAR_RES_PACKET_ID reply = (enum CAR_RES_PACKET_ID)(uint16_t)(*data);

        // data+len is crc high.
        unsigned char crcHigh = *(data+len);
        // data+len+1 is crc low
        unsigned char crcLow = *(data+len+1);

        bool validCRC = (crc16((const unsigned char*)data, len) == ((unsigned short)crcHigh << 8 | (unsigned short)crcLow));

        // data+len+2 must be 3 according to Benjamin's protocol.
        bool packetTerminator = (*(data+len+2) == 3);

        if (m_debug) {
//            cerr << "Proxy received '" << s << "', length = " << len << ", type: " << reply << ", validCRC: " << validCRC << ", packetTerminator: " << packetTerminator << endl;
        }

        if (validCRC && packetTerminator) {
            switch (reply) {
                case CAR_PACKET_READ_VALUES:
                {
                    data++;
                    uint16_t i = 0;

                    VehicleData vd;

                    uint16_t tmp_us = (uint16_t)data[i] << 8 | (uint16_t)data[i + 1];
                    i += 2;
                    vd.setV_batt((double)tmp_us / 1000.0);

                    tmp_us = (uint16_t)data[i] << 8 | (uint16_t)data[i + 1];
                    i += 2;
                    vd.setV_log((double)tmp_us / 1000.0);

                    int16_t tmp_s = (int16_t)data[i] << 8 | (int16_t)data[i + 1];
                    i += 2;
                    vd.setTemp((double)tmp_s / 1000.0);

                    tmp_s = (int16_t)data[i] << 8 | (int16_t)data[i + 1];
                    i += 2;
                    vd.setSpeed((double)tmp_s / 1000.0);

                    Container c(Container::VEHICLEDATA, vd);
                    getConference().send(c);

                    break;
                }

                case CAR_PACKET_READ_POS:
                {
                    data++;
                    uint16_t i = 0;

                    double x = (double)((int32_t)data[i] << 24 | (int32_t)data[i + 1] << 16 | (int32_t)data[i + 2] << 8 | (int32_t)data[i + 3]);
                    i += 4;

                    double y = (double)((int32_t)data[i] << 24 | (int32_t)data[i + 1] << 16 | (int32_t)data[i + 2] << 8 | (int32_t)data[i + 3]);
                    i += 4;

                    double heading = (double)((uint16_t)data[i] << 8 | (uint16_t)data[i + 1]) / 10000.0;
                    i += 2;

                    if (m_debug) {
                        cout << "Position data: x=" << x << ", y=" << y << ", heading=" << heading << endl;
                    }

                    break;
                }

                case CAR_PACKET_READ_SENS_ULTRA:
                {
                    bool sensorBoardData_updated = false;
                    data++;
                    uint16_t tmp_us = (len - 1) / 3;

                    for (int i = 0; i < tmp_us; i++) {
                        uint8_t us_address = (uint8_t)data[i];
                        uint16_t us_value = ((uint16_t)data[i * 2 + tmp_us] << 8) | (uint16_t)data[i * 2 + tmp_us + 1];

                        if (m_debug) {
                            cout << "Ultra sonic: " << (int)us_address << ": " << us_value << endl;
                        }

                        // Find address of this sensor.
                        map<uint16_t, PointSensor*>::iterator it = m_mapOfPointSensors.find(us_address);
                        if(it != m_mapOfPointSensors.end()) {
                            // Address was configured in configuration file.
                            const uint16_t SENSOR_ID = m_mapOfPointSensors[us_address]->getID();

                            // Check if we need to clamp the distance to -1.
                            double distance = us_value/100.0;
                            if (distance > m_mapOfPointSensors[us_address]->getClampDistance()) {
                                distance = -1;
                            }

                            // Update SensorBoardData.
                            m_sensorBoardData.update(SENSOR_ID, distance);
                            if (m_debug) {
                                cerr << "Updated " << SENSOR_ID << " with " << distance << endl;
                            }
                            sensorBoardData_updated = true;
                        }
                    }

                    if (sensorBoardData_updated) {
                        // Distribute SensorBoardData.

                		// Create a container with user data Container::USER_DATA_0.
                		Container c(Container::USER_DATA_0, m_sensorBoardData);

                        // Send container.
                        getConference().send(c);
                    } 

                    break;
                }

                case CAR_PACKET_READ_SENS_IR:
                {
                    bool sensorBoardData_updated = false;
                    data++;
                    uint16_t tmp_ir = (len - 1) / 2;

                    for (int i = 0; i < tmp_ir; i++) {
                        uint8_t ir_address = (uint8_t)data[i];
                        uint16_t ir_value = ((uint16_t)data[i * 2 + tmp_ir] << 8) | (uint16_t)data[i * 2 + tmp_ir + 1];

                        if (m_debug) {
                            cout << "Infra red: " << (int)ir_address << ": " << ir_value << endl;
                        }

                        // Find address of this sensor.
                        map<uint16_t, PointSensor*>::iterator it = m_mapOfPointSensors.find(ir_address);
                        if(it != m_mapOfPointSensors.end()) {
                            // Address was configured in configuration file.
                            const uint16_t SENSOR_ID = m_mapOfPointSensors[ir_address]->getID();

                            // Check if we need to clamp the distance to -1.
                            double distance = ir_value/100.0;
                            if (distance > m_mapOfPointSensors[ir_address]->getClampDistance()) {
                                distance = -1;
                            }

                            // Update SensorBoardData.
                            m_sensorBoardData.update(SENSOR_ID, distance);
                            if (m_debug) {
                                cerr << "Updated " << SENSOR_ID << " with " << distance << endl;
                            }
                            sensorBoardData_updated = true;
                        }
                    }

                    if (sensorBoardData_updated) {
                        // Distribute SensorBoardData.

                		// Create a container with user data Container::USER_DATA_0.
                		Container c(Container::USER_DATA_0, m_sensorBoardData);

                        // Send container.
                        getConference().send(c);
                    } 

                    break;
                }

                case CAR_PACKET_PING:
                    break;

                case CAR_PACKET_ACK2:
                    break;

                default:
                    break;
            }
        }
    }

    // This method will do the main data processing job.
    ModuleState::MODULE_EXITCODE Proxy::body() {
        // Get configuration data.
        KeyValueConfiguration kv = getKeyValueConfiguration();
        m_debug = kv.getValue<uint32_t>("proxy.debug") == 1;
        const string host = kv.getValue<string>("proxy.host");
        const uint32_t server_port = kv.getValue<uint32_t>("proxy.port");
        const uint32_t client_port = server_port + 1;

        const int32_t STEERING_CENTER = kv.getValue<int32_t>("proxy.steering.center");
        const int32_t STEERING_MIN = kv.getValue<int32_t>("proxy.steering.min");
        const int32_t STEERING_MAX = kv.getValue<int32_t>("proxy.steering.max");
        const bool STEERING_INVERT = kv.getValue<int32_t>("proxy.steering.invert") == 1;

//        const int32_t ACCELERATION_HYSTERESIS = kv.getValue<int32_t>("proxy.acceleration.hysteresis");
//        const double ACCELERATION_MAX = kv.getValue<double>("proxy.acceleration.max");

        const string USER_START_BUTTON_FILE = kv.getValue<string>("proxy.user_start_button_file");

        // Setup all point sensors.
        for (uint32_t i = 0; i < getKeyValueConfiguration().getValue<uint32_t>("proxy.numberOfSensors"); i++) {
            stringstream sensorID;
            sensorID << "proxy.sensor" << i << ".id";
            uint16_t id(getKeyValueConfiguration().getValue<uint16_t>(sensorID.str()));

            stringstream sensorName;
            sensorName << "proxy.sensor" << i << ".name";
            string name(getKeyValueConfiguration().getValue<string>(sensorName.str()));

            stringstream sensorAddress;
            sensorAddress << "proxy.sensor" << i << ".address";
            uint16_t address(getKeyValueConfiguration().getValue<uint16_t>(sensorAddress.str()));

            stringstream sensorClampDistance;
            sensorClampDistance << "proxy.sensor" << i << ".clampDistance";
            double clampDistance(getKeyValueConfiguration().getValue<double>(sensorClampDistance.str()));

            PointSensor *ps = new PointSensor(id, name, address, clampDistance);

            if (ps != NULL) {
                // Save for later.
                m_mapOfPointSensors[ps->getAddress()] = ps;

                // Initialize m_sensorBoardData data structure for this sensor.
                m_sensorBoardData.update(ps->getID(), -1);

                if (m_debug) {
                    cerr << "Registered point sensor " << ps->getName() << "(" << ps->getID() << ")" << ": " << ps->getAddress() << endl;
                }
            }
        }

        // Create UDP sender.
        core::wrapper::UDPSender *connectionToUDPServer = core::wrapper::UDPFactory::createUDPSender(host, server_port);

        // Create UDP receiver.
        core::wrapper::UDPReceiver *connectionFromUDPServer = core::wrapper::UDPFactory::createUDPReceiver(host, client_port);
        // Register ourselves as string listeners so that we will receive any data send from UDP_Server.
        connectionFromUDPServer->setStringListener(this);
        // Start receiving.
        connectionFromUDPServer->start();

        // Create FIFO data store to receive containers.
	    core::base::FIFOQueue fifo;
	    addDataStoreFor(fifo);

        string payload = "";
        string packet = "";

        // The following lines are used to open the GPIO file specified in the configuration file to test if the user pressed the button to start.
        istream *in = NULL;
        const int16_t USER_START_BUTTON_PRESSED_VALUE = 0; // if the user pressed the button the value changes to 0.
        bool start_data_transmission_to_vehicle = false;
        URL url_start_button_file(USER_START_BUTTON_FILE);
        try {
            in = &(StreamFactory::getInstance().getInputStream(url_start_button_file));
        } catch(InvalidArgumentException &iae) {
            // The specified user start button file could not be opened. Assuming that there is not such file available and start right ahead.
            start_data_transmission_to_vehicle = true;

            cerr << "(Proxy) warning: '" << iae.toString() << "'. Enabling direct pass-through: " << start_data_transmission_to_vehicle << endl;
        }

        // This counter switches between the various requests from the car.
        uint32_t query_counter = 0;

        // This speed_counter enables an alternating speed setting of the motor.
        uint32_t speed_counter = 0;

	    while (getModuleState() == ModuleState::RUNNING) {
            // Try to wait for the "start" signal: The file "/sys/class/gpio/gpio138/value" is available and changes from 1 --> 0.
            if (!start_data_transmission_to_vehicle) {
                if (in != NULL) {
                    if (in->good()) {
                        int16_t input;
                        *in >> input;
                        if (m_debug) {
                            cout << "Read '" << input << "': ";
                        }

                        if (USER_START_BUTTON_PRESSED_VALUE == input) {
                            start_data_transmission_to_vehicle = true;
                            if (m_debug) {
                                cout << "button pressed!" << endl;
                            }
                        }
                        else {
                            if (m_debug) {
                                cout << "button still NOT pressed!" << endl;
                            }
                        }
                    }

                    // Clear any error states of the stream.
                    in->clear();
                    // Seek to the beginning of the input stream.
                    in->seekg(ios::beg);
                }
            }

            // Regular data processing.
		    while (!fifo.isEmpty()) {
			    // Read next received container.
			    Container con = fifo.leave();
                
                if (con.getDataType() == Container::FORCECONTROL) {
                    // Translate to UDP_Server specific format.
                    ForceControl fc = con.getData<ForceControl>();
                    if (m_debug) {
                        cout << "Received: " << fc.toString() << endl;
                    }

                    // Check if we need to decorate ourselves with the LEDs.
                    if (fc.getBrakeLights()) {
                        if (m_debug) {
                            cout << "Turn ON brake lights." << endl;
                        }
                    }
                    else {
                        if (m_debug) {
                            cout << "Turn OFF brake lights." << endl;
                        }
                    }

                    if (fc.getLeftFlashingLights()) {
                        if (m_debug) {
                            cout << "Turn ON left flashing lights." << endl;
                        }
                    }
                    else {
                        if (m_debug) {
                            cout << "Turn OFF left flashing lights." << endl;
                        }
                    }

                    if (fc.getRightFlashingLights()) {
                        if (m_debug) {
                            cout << "Turn ON right flashing lights." << endl;
                        }
                    }
                    else {
                        if (m_debug) {
                            cout << "Turn OFF right flashing lights." << endl;
                        }
                    }

                    // Transform data from ForceControl to UDP_Server packet data.
                    // This is specific for the gulliver cars (1:8). The
                    // steering servo will not be able to move from
                    // 0 -255, but about STEERING_MIN - STEERING_MAX, center at STEERING_CENTER.
                    // Also, the joystick gives values that would
                    // invert the steering direction, thus the
                    // (255 - STEERING_CENTER) for the center and the (255 - servo2)
                    // when sending the value to the car.
                    double steering = 0;

                    // Transform fc.getSteeringForce() to -127 .. 127.
                    if(fc.getSteeringForce()>0)
                    {
						steering =fc.getSteeringForce()*255/76 - 0.5;
					}else if(fc.getSteeringForce()<0 ){
						steering =fc.getSteeringForce()*255/76 + 0.5;
					}
					if(steering<-101){
						steering = -100;
					}

                    steering = (steering * (STEERING_MAX - STEERING_MIN)) / 255.0;
                    // In case of inverting the steering:
                    if (STEERING_INVERT) {
                        steering += (255 - STEERING_CENTER);
                        steering = (255 - steering);
                    }
                    else {
                        steering += STEERING_CENTER;
                    }

                    // Acceleration: -127 .. -1  : backwards
                    //                  1 .. 127 : forwards

                    // Transform fc.getBrakeForce() to 0 .. 127.
                    double acceleration = (-fc.getBrakeForce() + 5 )*35/5;
/*
                    if (acceleration > 35) {
                    	acceleration = 35;
                    }
                    if (acceleration < 0) {
                    	acceleration = 0;
                    }

                    const double SIGN = (acceleration < 0) ? -1.0 : 1.0;
                    if (fabs(acceleration) > ACCELERATION_HYSTERESIS) {
                        acceleration = (fabs(acceleration) - ACCELERATION_HYSTERESIS) * SIGN;
                    }
                    else {
                        acceleration = 0;
                    }
                    if (m_debug) {
                        cout << "acceleration: " << acceleration << endl;	
                    }

                    double speed = (ACCELERATION_MAX * acceleration) / (127.0 - ACCELERATION_HYSTERESIS);
*/

                    double speed = 0;

                    if (speed_counter == 0) { speed = 6.0;}
                    else {speed = 0;}

                    speed_counter++;
                    speed_counter%=2;

                    if (fabs(acceleration) < 5) {
                        speed = 0;
                    }

                    // Create a sendable packet.
                    payload = createPayloadForSettingAccelerationAndSteering((uint16_t)(speed * 100.0), (uint8_t)steering);
                    packet = createPacket(payload);

                    if (start_data_transmission_to_vehicle) {
                        connectionToUDPServer->send(packet);
                    }
                }
        	}

            // Now, query values from the UDP_Server: one at a time.
            query_counter++;
            switch (query_counter) {
                case 1:
                    // Query values from the vehicle.
                    payload = createPayloadForQueryOnboardData();
                break;

                case 2:
                    // Query ultra sonic values from the vehicle.
                    payload = createPayloadForQueryUltraSonicData();
                break;

                case 3:
                    // Query infra red values from the vehicle.
                    payload = createPayloadForQueryInfraRedData();
                break;

                case 4:
                    // Query position data from the vehicle.
                    payload = createPayloadForQueryPositionData();

                    // Reset counter. This call must be carried out in the last case of this switch statement.
                    query_counter = 0;
                break;

                default:
                    query_counter = 0;
            }

            // Send packet to car and wait for reply.
            packet = createPacket(payload);
            connectionToUDPServer->send(packet);
	    }

	    //Stop the car after stopping the Proxy
	    payload = createPayloadForSettingAccelerationAndSteering( 0 , 0 );
	    packet = createPacket(payload);
	    connectionToUDPServer->send(packet);

        // Destroy connections to UDP_Server.
        OPENDAVINCI_CORE_DELETE_POINTER(connectionToUDPServer);

        // Stop receiving.
        connectionFromUDPServer->stop();
        connectionFromUDPServer->setStringListener(NULL);
        OPENDAVINCI_CORE_DELETE_POINTER(connectionFromUDPServer);

	    return ModuleState::OKAY;
    }

} // msv

