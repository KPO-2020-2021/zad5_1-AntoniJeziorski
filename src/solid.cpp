#include "solid.hh"

Solid::Solid() {

    for (int i = 0; i < SIZE; ++i)
    {
         scaleVector[i] = 1;
    }
    
}

void Solid::Scale(const Vector3D& s) {

    for (int i = 0; i < SIZE; i++)
    {
        scaleVector[i] = scaleVector[i] * s[i];
    }

}

std::string Solid::GetFilename() {

    return filename;

}