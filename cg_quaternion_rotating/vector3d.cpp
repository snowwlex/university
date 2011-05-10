#include "vector3d.h"

Vector3D::Vector3D() {
    myX = myY = myZ = 0;
}

Vector3D::Vector3D(double x, double y, double z) {
    myX = x;
    myY = y;
    myZ = z;
}

void Vector3D::multiply(double m) {
    myX *= m;
    myY *= m;
    myZ *= m;
}
