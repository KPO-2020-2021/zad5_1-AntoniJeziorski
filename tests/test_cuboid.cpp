#include "../tests/doctest/doctest.h"
#include "cuboid.hh"
#include "vector.hh"
TEST_CASE("test metody GetRotationAngle") {

    Cuboid test;

    CHECK(test.GetRotationAngle() == 0);

}

TEST_CASE("test konstruktora klasy Coubid oraz przeciazenia operatora []") {

    double a[3]={-0.5,-0.5,-0.5},b[3] = {0.5,-0.5,-0.5},c[3] = {-0.5, 0.5, -0.5},d[3] = {0.5, 0.5, -0.5},e[3] = {-0.5, 0.5, 0.5},f[3] = {0.5, 0.5, 0.5},g[3] = {-0.5, -0.5, 0.5},h[3] = {0.5, -0.5, 0.5};
    Vector3D c1(a), c2(b), c3(c), c4(d), c5(e), c6(f), c7(g), c8(h);

    Cuboid test;

    CHECK((test[0] == c1 && test[1] == c2 && test[2] == c3 && test[3] == c4 && test[4] == c5 && test[5] == c6 && test[6] == c7 && test[7] == c8 && test.GetRotationAngle() == 0));

}

TEST_CASE("test metody GetLocation") {

    Vector3D v;

    Cuboid test;

    CHECK((test.GetLocation() == v));
}

TEST_CASE("test metody Rotate") {

    double x = 10;

    Cuboid test;

    test.Rotate(x);

    CHECK((test.GetRotationAngle() == 10));
}

TEST_CASE("test metody ToGlobal oraz przeciazenia operatora ()") {

    double a[3]={-0.5,-0.5,-0.5},b[3] = {0.5,-0.5,-0.5},c[3] = {-0.5, 0.5, -0.5},d[3] = {0.5, 0.5, -0.5},e[3] = {-0.5, 0.5, 0.5},f[3] = {0.5, 0.5, 0.5},g[3] = {-0.5, -0.5, 0.5},h[3] = {0.5, -0.5, 0.5}, S[3] = {1,1,1};
    Vector3D c1(a), c2(b), c3(c), c4(d), c5(e), c6(f), c7(g), c8(h);

    Vector3D t, s(S);

    Cuboid test;

    test.Scale(s);

    test.Rotate(90);

    test.ToGlobal(t);

    CHECK((test(0) == c2 && test(1) == c4 && test(2) == c1 && test(3) == c3 && test(4) == c7 && test(5) == c5 && test(6) == c8 && test(7) == c6));

} 