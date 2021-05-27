#pragma once

#include "vector3D.hh"
#include "size.hh"
#include <iostream>

class Solid {

    public:

        Vector3D scaleVector;

        Solid();

        void scale(const Vector3D& s);

};