#ifndef QUATERNION_H
#define QUATERNION_H

#include "vector3d.h"

class Quaternion {
public:
    Quaternion();
    Quaternion(double scalar, Vector3D vector);
    Quaternion& operator*=(const Quaternion& q);
public:
    double getScalar() const { return myScalar; }
    const Vector3D& getVector() const { return myVector; }
public:
    void normalize();
protected:
    double myScalar;
    Vector3D myVector;

friend Quaternion operator*(const Quaternion& q1, const Quaternion& q2);

};

class RotateQuaternion : public Quaternion {
public:
    RotateQuaternion(double angle=0, Vector3D vector=Vector3D(0,0,0));
    static RotateQuaternion interpolate(const RotateQuaternion& q, const RotateQuaternion& p, double t);
    RotateQuaternion& operator*=(const RotateQuaternion& q);
public:
    void toRotateMatrix(double m[16]) const;

};

#endif // QUATERNION_H
