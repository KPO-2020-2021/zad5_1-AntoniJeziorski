#include "../tests/doctest/doctest.h"
#include "hexagonal_prism.hh"
#include "vector.hh"

TEST_CASE("test metody GetAngle") {

    HexPrism test;

    CHECK((test.GetAngle() == 0));

}

TEST_CASE("test konstruktora klasy HexPrism oraz metody GetLocalCorners") {

    double a[3] = {0.5, 0, -0.5},b[3] = {0.5, 0, 0.5},c[3] = {0.25, 0.433, -0.5},d[3] = {0.25, 0.433, 0.5},e[3] = {-0.25, 0.433, -0.5},f[3] = {-0.25, 0.433, 0.5},g[3] = {-0.5, 0, -0.5},h[3] = {-0.5, 0, 0.5},i[3] = {-0.25, -0.433, -0.5},j[3] = {-0.25, -0.433, 0.5},k[3] = {0.25, -0.433, -0.5},l[3] = {0.25, -0.433, 0.5};
    
    Vector3D c1(a),c2(b),c3(c),c4(d),c5(e),c6(f),c7(g),c8(h),c9(i),c10(j),c11(k),c12(l), *tab;

    HexPrism test;

    tab = test.GetLocalCorners();

    CHECK((tab[0] == c1 && tab[1] == c2 && tab[2] == c3 && tab[3] == c4 && tab[4] == c5 && tab[5] == c6 && tab[6] == c7 && tab[7] == c8 && tab[8] == c9 && tab[9] == c10 && tab[10] == c11 && tab[11] == c12 && test.GetAngle() == 0));

}

TEST_CASE("test metody Rotate") {

    HexPrism test;

    double x = 10;

    test.Rotate(x);

    CHECK((test.GetAngle() == 10));
}


TEST_CASE("test metody ToCubeSystem oraz przeciazenia operatora ()") {

    double s[3] = {1,1,1}, a[3] = {0, 0.5, -0.5},b[3] = {0, 0.5, 0.5},c[3] = {-0.433, 0.25, -0.5},d[3] = {-0.433, 0.25, 0.5},e[3] = {-0.433, -0.25, -0.5},f[3] = {-0.433, -0.25, 0.5},g[3] = {-0, -0.5, -0.5},h[3] = {-0, -0.5, 0.5},i[3] = {0.433, -0.25, -0.5},j[3] = {0.433, -0.25, 0.5},k[3] = {0.433, 0.25, -0.5},l[3] = {0.433, 0.25, 0.5};
    Vector3D scale(s), t, c1(a),c2(b),c3(c),c4(d),c5(e),c6(f),c7(g),c8(h),c9(i),c10(j),c11(k),c12(l);
    HexPrism test;
    test.Scale(scale);
    test.Rotate(90);
    test.ToCubeSystem(t);

    CHECK((test(0) == c1 && test(1) == c2 && test(2) == c3 && test(3) == c4 && test(4) == c5 && test(5) == c6 && test(6) == c7 && test(7) == c8 && test(8) == c9 && test(9) == c10 && test(10) == c11 && test(11) == c12));

}

TEST_CASE("test przeciazenia operatora []") {

    HexPrism test;
    Vector3D v;

    CHECK((test[0] == v));

}
