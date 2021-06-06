#include "../tests/doctest/doctest.h"
#include "drone.hh"

TEST_CASE("test metody RotorToGlobal") {

    double S[3] = {1,1,1}, a[3] = {0.5, 0, -0.5},b[3] = {0.5, 0, 0.5},c[3] = {0.25, 0.433, -0.5},d[3] = {0.25, 0.433, 0.5},e[3] = {-0.25, 0.433, -0.5},f[3] = {-0.25, 0.433, 0.5},g[3] = {-0.5, 0, -0.5},h[3] = {-0.5, 0, 0.5},i[3] = {-0.25, -0.433, -0.5},j[3] = {-0.25, -0.433, 0.5},k[3] = {0.25, -0.433, -0.5},l[3] = {0.25, -0.433, 0.5};
    Vector3D v, s(S), c1(a),c2(b),c3(c),c4(d),c5(e),c6(f),c7(g),c8(h),c9(i),c10(j),c11(k),c12(l);

    Drone test(s,s,v);

    test.RotorToGlobal(0,v);

    CHECK((test[0][0] == c1 && test[0][1] == c2 && test[0][2] == c3 && test[0][3] == c4 && test[0][4] == c5 && test[0][5] == c6 && test[0][6] == c7 && test[0][7] == c8 && test[0][8] == c9 && test[0][9] == c10 && test[0][10] == c11 && test[0][11] == c12));

}