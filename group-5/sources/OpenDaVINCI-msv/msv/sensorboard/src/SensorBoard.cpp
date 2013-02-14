/*
 * Mini-Smart-Vehicles.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#include <iostream>

#include "core/data/Container.h"
#include "core/io/ContainerConference.h"

#include "SensorBoardData.h"

#include "SensorBoard.h"

namespace msv {

    using namespace std;
    using namespace core::base;
    using namespace core::data;

    SensorBoard::SensorBoard(const int32_t &argc, char **argv) :
        ConferenceClientModule(argc, argv, "SensorBoard"),
        m_fifo()
	{}

    SensorBoard::~SensorBoard() {}

    void SensorBoard::setUp() {
        // This method will be call automatically _before_ running body().
    }

    void SensorBoard::tearDown() {
        // This method will be call automatically _after_ return from body().
    }

    bool SensorBoard::processContainerExample(Container &c) {
        bool retVal = false;

		if (c.getDataType() == Container::USER_DATA_0) {
			SensorBoardData data = c.getData<SensorBoardData>();

            cout << "Received SensorBoardData: " << data.toString() << endl;
			retVal = true;
    	}

        return retVal;
    }

    // This method will do the main data processing job.
    ModuleState::MODULE_EXITCODE SensorBoard::body() {
        // Automatically receive _all_ sent data in the FIFO manner.
    	addDataStoreFor(m_fifo);

    	while (getModuleState() == ModuleState::RUNNING) {
    		// Process _all_ received entries.
    		while (!m_fifo.isEmpty()) {
    			Container c = m_fifo.leave();

                // Example for processing the received container.
                processContainerExample(c);
    		}
    	}

    	return ModuleState::OKAY;
    }

} // msv

