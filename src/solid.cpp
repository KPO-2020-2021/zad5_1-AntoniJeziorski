#include "solid.hh"

/*!
 *
 * \file solid.cpp
 * \brief Plik zawierajacy definicje metod klasy Solid
 */

Solid::Solid() {

    filename = "../datasets/";

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