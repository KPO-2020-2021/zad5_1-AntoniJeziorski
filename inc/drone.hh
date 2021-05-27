#pragma once

#include "cuboid.hh"
#include <fstream>

class Drone {

    double rotationAngle;

    Cuboid body;

    public:

        bool ZapisWspolrzednychDoPliku( const char *sNazwaPliku);

};