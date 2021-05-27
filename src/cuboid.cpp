#include "cuboid.hh"

Cuboid::Cuboid() {

    double a[3]={-0.5,-0.5,-0.5},b[3] = {0.5,-0.5,-0.5},c[3] = {-0.5, 0.5, -0.5},d[3] = {0.5, 0.5, -0.5},e[3] = {-0.5, 0.5, 0.5},f[3] = {0.5, 0.5, 0.5},g[3] = {-0.5, -0.5, 0.5},h[3] = {0.5, -0.5, 0.5};
    Vector3D c1(a), c2(b), c3(c), c4(d), c5(e), c6(f), c7(g), c8(h);

    localCorners[0];
    localCorners[1];
    localCorners[2];
    localCorners[3];
    localCorners[4];
    localCorners[5];
    localCorners[6];
    localCorners[7];

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; i < 3; ++j)
        {
            localCorners[i][j] = localCorners[i][j] * scaleVector[j];
        }
    }
}

void Cuboid::ToGlobal(Matrix3D Rotation) {

    for (int i = 0; i < CUBE; ++i)
    {
        globalCorners[i] = Rotation * localCorners[i] + location;
    }
    
}

Vector3D &Cuboid::operator () (int index) {
    if (index < 0 || index >= CUBE) {
        throw std::runtime_error("Error:  Blad ilosci wierzcholkow!");
    }
    return globalCorners[index];
}