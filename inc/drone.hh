#pragma once

#include "lacze_do_gnuplota.hh"
#include "cuboid.hh"
#include "hexagonal_prism.hh"
#include <unistd.h>
#include <fstream>

class Drone {

    double rotationAngle;

    Cuboid body;

    Vector3D location;

    HexPrism rotor[4];

    public:

        Drone();

        Drone(Vector3D scale, Vector3D rotorScale, Vector3D loc);

        bool SaveBody(int droneNumber);

        bool SaveRotor(int droneNumber, int rotorNumber, Vector3D Translation);

        void SaveDrone(int droneNumber);

        void VerticalFlight(Vector3D translation, PzG::LaczeDoGNUPlota& Link, int droneNumber);

        void HorizontalFlight(double distance, double angle, PzG::LaczeDoGNUPlota& Link, int droneNumber);

        void PlanPath(double angle, double distance); 

        void RotorToGlobal(int rotorNumber, Vector3D Translation);

        void Recce(int droneNumber, PzG::LaczeDoGNUPlota& Link);

};