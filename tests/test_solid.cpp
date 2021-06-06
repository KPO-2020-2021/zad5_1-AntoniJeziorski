#include "../tests/doctest/doctest.h"
#include "solid.hh"

TEST_CASE("test konstruktora klasy solid") {

    Solid test;

    CHECK((test.scaleVector[0] == 1 && test.scaleVector[1] == 1 && test.scaleVector[2] == 1));

}

TEST_CASE("test metody Scale") {

    double tab[3] = {2,3,4};
    Vector3D v(tab);
    Solid test;
    test.Scale(v);

    CHECK((test.scaleVector[0] == 2 && test.scaleVector[1] == 3 && test.scaleVector[2] == 4));

}
