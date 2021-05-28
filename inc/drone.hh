#pragma once

#include "lacze_do_gnuplota.hh"
#include "cuboid.hh"
#include <unistd.h>
#include <fstream>

class Drone {

    double rotationAngle;

    Cuboid body;

    Vector3D location;

    public:

        Drone(Vector3D scale, Vector3D loc);

        bool SaveBody( const char *sFileName);

        void VerticalFlight(Vector3D translation, PzG::LaczeDoGNUPlota& Link);

        void HorizontalFlight(double distance, PzG::LaczeDoGNUPlota& Link);

        void PlanPath(double angle, double distance); 

};