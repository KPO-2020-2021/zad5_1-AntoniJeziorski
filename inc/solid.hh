#pragma once

#include "vector3D.hh"
#include "size.hh"
#include <iostream>
#include <string>

class Solid {

    public:

        Vector3D scaleVector;

        std::string filename;

        Solid();

        void Scale(const Vector3D& s);

        std::string GetFilename();

};