#pragma once

#include "matrix3D.hh"
#include "solid.hh"

class Cuboid: public Solid {

    Vector3D localCorners[8];

    Vector3D globalCorners[8];

    Vector3D standardCorners[8];

    Vector3D location;

    double rotationAngle;

    public:

        Cuboid();

        void ToGlobal(Vector3D Translation);
    
        Vector3D &operator () (int index);

        Vector3D GetLocation();

        void Rotate(double angle);

};
