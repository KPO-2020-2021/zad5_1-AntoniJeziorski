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

        Drone();

        Drone(Vector3D scale, Vector3D loc);

        bool SaveBody( const char *sFileName);

        void VerticalFlight(Vector3D translation, PzG::LaczeDoGNUPlota& Link, int droneNumber);

        void HorizontalFlight(double distance, double angle, PzG::LaczeDoGNUPlota& Link, int droneNumber);

        void PlanPath(double angle, double distance); 

};