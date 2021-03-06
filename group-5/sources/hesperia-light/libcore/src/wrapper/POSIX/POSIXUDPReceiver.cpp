/*
 * Copyright (c) Christian Berger and Bernhard Rumpe, Rheinisch-Westfaelische Technische Hochschule Aachen, Germany.
 *
 * The Hesperia Framework.
 */

#include <arpa/inet.h>

#include <cstring>
#include <sstream>

#include "core/wrapper/Packet.h"
#include "core/wrapper/ConcurrencyFactory.h"
#include "core/wrapper/POSIX/POSIXUDPReceiver.h"

namespace core {
    namespace wrapper {
        namespace POSIX {

            using namespace std;

            POSIXUDPReceiver::POSIXUDPReceiver(const string &address, const uint32_t port, const bool &isMulticast) :
                    m_isMulticast(isMulticast),
                    m_address(),
                    m_mreq(),
                    m_fd(),
                    m_buffer(NULL),
                    m_thread(NULL) {
                m_buffer = new char[BUFFER_SIZE];
                if (m_buffer == NULL) {
                    stringstream s;
                    s << "Error while allocating memory for buffer at " << __FILE__ << ": " << __LINE__;
                    throw s.str();
                }

                // Create socket for sending.
                m_fd = socket(PF_INET, SOCK_DGRAM, 0);
                if (m_fd < 0) {
                    stringstream s;
                    s << "Error while creating file descriptor at " << __FILE__ << ": " << __LINE__;
                    throw s.str();
                }

                // Allow reusing of ports by multiple sockets.
                uint32_t yes = 1;
                if (setsockopt(m_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) < 0) {
                    stringstream s;
                    s << "Error while setting socket options at " << __FILE__ << ": " << __LINE__;
                    throw s.str();
                }

                // Setup address and port.
                memset(&m_address, 0, sizeof(m_address));
                m_address.sin_family = AF_INET;
                // Bind to given address.
                m_address.sin_addr.s_addr = inet_addr(address.c_str());
                m_address.sin_port = htons(port);

                // Bind to receive address/port.
                if (bind(m_fd, (struct sockaddr *) &m_address, sizeof(m_address)) < 0) {
                    stringstream s;
                    s << "Error while binding socket at " << __FILE__ << ": " << __LINE__;
                    throw s.str();
                }

                if (m_isMulticast) {
                    // Join the multicast group.
                    m_mreq.imr_multiaddr.s_addr = inet_addr(address.c_str());
                    m_mreq.imr_interface.s_addr = htonl(INADDR_ANY);
                    if (setsockopt(m_fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &m_mreq, sizeof(m_mreq)) < 0) {
                        stringstream s;
                        s << "Error while joining multicast group at " << __FILE__ << ": " << __LINE__;
                        throw s.str();
                    }
                }

                // Create thread for encapsulating waiting for receiving data.
                m_thread = ConcurrencyFactory::getInstance().createThread(*this);
                if (m_thread == NULL) {
                    stringstream s;
                    s << "Error while creating thread at " << __FILE__ << ": " << __LINE__;
                    throw s.str();
                }
            }

            POSIXUDPReceiver::~POSIXUDPReceiver() {
                // Stop receiving.
                stop();

                // Close file descriptor.
                close(m_fd);

                if (m_buffer != NULL) {
                    delete [] m_buffer;
                }
                m_buffer = NULL;

                if (m_thread != NULL) {
                    delete m_thread;
                }
                m_thread = NULL;
            }

            void POSIXUDPReceiver::run() {
                int32_t nbytes = 0;

                struct sockaddr_storage remote;

                while (isRunning()) {
                    // Get data and sender address.
                    size_t addrLength = sizeof(remote);
                    nbytes = recvfrom(m_fd, m_buffer, BUFFER_SIZE, 0, (struct sockaddr *)&remote, (socklen_t*)&addrLength);

                    if (nbytes > 0) {
                        // Get sender address.
                        const uint32_t MAX_ADDR_SIZE = 65535;
                        char remoteAddr[MAX_ADDR_SIZE];
                        inet_ntop(remote.ss_family, &(((struct sockaddr_in*)&remote)->sin_addr), remoteAddr, sizeof(remoteAddr));

                        // ------------------------v (remote address)-----v (data)
                        nextPacket(Packet(string(remoteAddr), string(m_buffer, nbytes)));
                    }
                }
            }

            void POSIXUDPReceiver::start() {
                m_thread->start();
            }

            void POSIXUDPReceiver::stop() {
                if (m_isMulticast) {
                    // Remove ourselves from membership.
                    setsockopt(m_fd, IPPROTO_IP, IP_DROP_MEMBERSHIP, &m_mreq, sizeof(m_mreq));
                }

                // Interrupt socket.
                shutdown(m_fd, SHUT_RDWR);

                m_thread->stop();
            }

            bool POSIXUDPReceiver::isRunning() {
                return m_thread->isRunning();
            }
        }
    }
} // core::wrapper::POSIX
