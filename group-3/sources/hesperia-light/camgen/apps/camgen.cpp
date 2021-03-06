/*
 * Copyright (c) Christian Berger and Bernhard Rumpe, Rheinisch-Westfaelische Technische Hochschule Aachen, Germany.
 *
 * The Hesperia Framework.
 */

#include "CamGen.h"

int32_t main(int32_t argc, char **argv) {
    camgen::CamGen cg(argc, argv);
    return cg.runModule();
}
