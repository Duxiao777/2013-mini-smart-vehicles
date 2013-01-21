/*
 * Mini-Smart-VehiclesMini-Smart-Vehicles.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#include "TestSensorBoardSender.h"

int32_t main(int32_t argc, char **argv) {
    msv::TestSensorBoardSender tsbs(argc, argv);
    return tsbs.runModule();
}
