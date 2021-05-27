#include "solid.hh"

Solid::Solid() {

    for (int i = 0; i < 3; i++)
    {
         scaleVector[i] = 1;
    }
    
}

void Solid::scale(const Vector3D& s) {

    for (int i = 0; i < 3; i++)
    {
        scaleVector[i] = scaleVector[i] * s[i];
    }

}