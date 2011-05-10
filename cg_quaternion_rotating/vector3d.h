#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D {
public:
    Vector3D() ;
    Vector3D(double x, double y, double z);

public:
    double x() const  { return myX; }
    double y() const  { return myY; }
    double z() const  { return myZ; }
    void setX(double x) { myX = x; }
    void setY(double y) { myY = y; }
    void setZ(double z)  { myZ = z; }
public:
    void multiply(double m );


private:
    double myX,myY,myZ;
};

#endif // VECTOR3D_H
