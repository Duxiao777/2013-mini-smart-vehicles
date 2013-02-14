/*
 * Mini-Smart-Vehicles.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#include "SensorBoard.h"

int32_t main(int32_t argc, char **argv) {
    msv::SensorBoard sb(argc, argv);
    return sb.runModule();
}
