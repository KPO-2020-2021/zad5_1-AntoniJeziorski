#include "cuboid.hh"

Cuboid::Cuboid() {

    double a[3]={-0.5,-0.5,-0.5},b[3] = {0.5,-0.5,-0.5},c[3] = {-0.5, 0.5, -0.5},d[3] = {0.5, 0.5, -0.5},e[3] = {-0.5, 0.5, 0.5},f[3] = {0.5, 0.5, 0.5},g[3] = {-0.5, -0.5, 0.5},h[3] = {0.5, -0.5, 0.5};
    Vector3D c1(a), c2(b), c3(c), c4(d), c5(e), c6(f), c7(g), c8(h);

    localCorners[0] = c1;
    localCorners[1] = c2;
    localCorners[2] = c3;
    localCorners[3] = c4;
    localCorners[4] = c5;
    localCorners[5] = c6;
    localCorners[6] = c7;
    localCorners[7] = c8;

    rotationAngle = 0;
    
}

void Cuboid::ToGlobal(Vector3D& Translation) {

    location = Translation;

    Matrix3D Rotation = RotationMatrix_Z(rotationAngle);

    for (int i = 0; i < CUBE; ++i) {
    
        for (int j = 0; j < SIZE; ++j) {
        
            globalCorners[i][j] = localCorners[i][j] * scaleVector[j];
        }
    }

    for (int i = 0; i < CUBE; ++i) {
    
        globalCorners[i] = Rotation * globalCorners[i] + location;
    }
    
}

Vector3D &Cuboid::operator [] (int index) {

    if (index < 0 || index >= CUBE) {
        throw std::runtime_error("Error:  Blad ilosci wierzcholkow!");
    }
    return localCorners[index];
}

Vector3D &Cuboid::operator () (int index) {

    if (index < 0 || index >= CUBE) {
        throw std::runtime_error("Error:  Blad ilosci wierzcholkow!");
    }
    return globalCorners[index];
}

void Cuboid::Rotate(double angle) {

    rotationAngle += angle;

}

Vector3D Cuboid::GetLocation() {
    
    return location;

}

double Cuboid::GetRotationAngle() {

    return rotationAngle;

}

