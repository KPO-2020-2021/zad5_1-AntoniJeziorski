#pragma once

#include "matrix3D.hh"
#include "solid.hh"

class Cuboid: public Solid {

    Vector3D localCorners[8];

    Vector3D globalCorners[8];

    Vector3D location;

    public:

        Cuboid();

        void ToGlobal(Matrix3D Rotation);
    
        Vector3D &operator () (int index);

};
