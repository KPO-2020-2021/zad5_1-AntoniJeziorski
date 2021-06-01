#include "solid.hh"
#include "matrix3D.hh"

class HexPrism: public Solid {

    Vector3D localCorners[12];

    Vector3D cuboidSystemCorners[12];

    Vector3D globalCorners[12];

    Vector3D location;

    double rotationAngle;

    public:

        HexPrism();

        void  ToCubeSystem(Vector3D Translation);

        Vector3D &operator () (int index);

        Vector3D &operator [] (int index);

        void Rotate(double angle); 

};