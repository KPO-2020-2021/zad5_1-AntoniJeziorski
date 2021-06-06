#include "hexagonal_prism.hh"

/*!
 *
 * \file hexagonal_prism.cpp
 * \brief Plik zawierajacy definicje metod klasy HexPrism
 */

HexPrism::HexPrism() {

    double a[3] = {0.5, 0, -0.5},b[3] = {0.5, 0, 0.5},c[3] = {0.25, 0.433, -0.5},d[3] = {0.25, 0.433, 0.5},e[3] = {-0.25, 0.433, -0.5},f[3] = {-0.25, 0.433, 0.5},g[3] = {-0.5, 0, -0.5},h[3] = {-0.5, 0, 0.5},i[3] = {-0.25, -0.433, -0.5},j[3] = {-0.25, -0.433, 0.5},k[3] = {0.25, -0.433, -0.5},l[3] = {0.25, -0.433, 0.5};
    
    Vector3D c1(a),c2(b),c3(c),c4(d),c5(e),c6(f),c7(g),c8(h),c9(i),c10(j),c11(k),c12(l);

    localCorners[0] = c1;
    localCorners[1] = c2;
    localCorners[2] = c3;
    localCorners[3] = c4;
    localCorners[4] = c5;
    localCorners[5] = c6;
    localCorners[6] = c7;
    localCorners[7] = c8;
    localCorners[8] = c9;
    localCorners[9] = c10;
    localCorners[10] = c11;
    localCorners[11] = c12;

    rotationAngle = 0;

}

Vector3D &HexPrism::operator () (int index) {

    if (index < 0 || index >= 12) {
        throw std::runtime_error("Error:  Blad ilosci wierzcholkow!");
    }
    return cuboidSystemCorners[index];
}

Vector3D &HexPrism::operator [] (int index) {

    if (index < 0 || index >= 12) {
        throw std::runtime_error("Error:  Blad ilosci wierzcholkow!");
    }
    return globalCorners[index];
}

void HexPrism::ToCubeSystem(Vector3D& Translation) {
    
    location = Translation;

    Matrix3D Rotation = RotationMatrix_Z(rotationAngle);

    for (int i = 0; i < 12; ++i) {
    
        for (int j = 0; j < SIZE; ++j) {
        
            cuboidSystemCorners[i][j] = localCorners[i][j] * scaleVector[j];
        }
    }

    for (int i = 0; i < 12; ++i) {
    
        cuboidSystemCorners[i] = Rotation * cuboidSystemCorners[i] + location;
    }

}

void HexPrism::Rotate(double angle) {

    if(rotationAngle > 360)
        rotationAngle =- 360;
    rotationAngle += angle;

}

double HexPrism::GetAngle() {

    return rotationAngle;

}

Vector3D* HexPrism::GetLocalCorners() {

    return localCorners;

}
