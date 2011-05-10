#include "quaternion.h"
#include "math.h"
#include <QDebug>

Quaternion::Quaternion() {
    myScalar = 0;
    myVector = Vector3D(0,0,0);
}

Quaternion::Quaternion(double scalar, Vector3D vector) {
    myScalar = scalar;
    myVector = vector;
}

void Quaternion::normalize() {
    double magnitude = sqrt(myScalar*myScalar + myVector.x()*myVector.x() + myVector.y()*myVector.y() + myVector.z()*myVector.z() );
    if (magnitude == 0) {
        return;
    }
    myScalar /= magnitude;
    myVector.setX( myVector.x()/magnitude );
    myVector.setY( myVector.y()/magnitude );
    myVector.setZ( myVector.z()/magnitude );
}


Quaternion operator*(const Quaternion& q1, const Quaternion& q2) {
    Quaternion q(q1);
    q *= q2;
    return q;
}

Quaternion& Quaternion::operator*=(const Quaternion& q) {
  // algorithm of fast quaternion multiplying
    double A, B, C, D, E, F, G, H;

    double w1,x1,y1,z1, w2,x2,y2,z2;
    w1 = myScalar; w2 = q.myScalar;
    x1 = myVector.x(); x2 = q.myVector.x();
    y1 = myVector.y(); y2 = q.myVector.y();
    z1 = myVector.z(); z2 = q.myVector.z();

    A = (w1 + x1) * (w2 + x2);
    B = (z1 - y1) * (y2 - z2);
    C = (x1 - w1) * (y2 + z2);
    D = (y1 + z1) * (x2 - w2);
    E = (x1 + z1) * (x2 + y2);
    F = (x1 - z1) * (x2 - y2);
    G = (w1 + y1) * (w2 - z2);
    H = (w1 - y1) * (w2 + z2);

    myScalar = B + (-E - F + G + H) * 0.5;
    myVector.setX(  A - ( E + F + G + H) * 0.5 );
    myVector.setY( -C + ( E - F + G - H) * 0.5 );
    myVector.setZ( -D + ( E - F - G + H) * 0.5 );

    return *this;
}

RotateQuaternion& RotateQuaternion::operator*=(const RotateQuaternion& q) {
    Quaternion::operator *=(q);
    normalize();
    return *this;
}


RotateQuaternion::RotateQuaternion(double angle, Vector3D vector) {
    double angle_rad =  angle * M_PI / 180; // to radians
    vector.multiply( sin(angle_rad/2) );
    myScalar = cos(angle_rad/2);
    myVector = vector;
    normalize();
}

void RotateQuaternion::toRotateMatrix(double resultM[16]) const {
    double m[4][4];
    double wx, wy, wz, xx, yy, yz, xy, xz, zz, x2, y2, z2;
    x2 = 2*myVector.x();
    y2 = 2*myVector.y();
    z2 = 2*myVector.z();

    xx = myVector.x() * x2;   xy =  myVector.x() * y2;   xz =  myVector.x() * z2;
    yy = myVector.y() * y2;   yz = myVector.y() * z2;   zz = myVector.z() * z2;
    wx = myScalar * x2;   wy = myScalar * y2;   wz = myScalar * z2;

    m[0][0]=1.0f-(yy+zz); m[0][1]=xy-wz;        m[0][2]=xz+wy;
    m[1][0]=xy+wz;        m[1][1]=1.0f-(xx+zz); m[1][2]=yz-wx;
    m[2][0]=xz-wy;        m[2][1]=yz+wx;        m[2][2]=1.0f-(xx+yy);

    m[0][3] = m[1][3] = m[2][3] = 0;
    m[3][0] = m[3][1] = m[3][2] = 0;
    m[3][3] = 1;

    for (int i=0;i<4;++i) {
        for (int j=0;j<4;++j) {
            resultM[j*4+i] = m[i][j]; // make one-dimension array, and transpose it due to OpenGL's matrix presentation
        }
    }

}


RotateQuaternion RotateQuaternion::interpolate(const RotateQuaternion& q1, const RotateQuaternion& q2, double t) {
  // SLERP  (Spherical Linear intERPolation) algorithm
  double p1[4];
  double omega, cosom, sinom, scale0, scale1;
  const double DELTA = 0.01;

  double w1,x1,y1,z1, w2,x2,y2,z2;
  w1 = q1.myScalar; w2 = q2.myScalar;
  x1 = q1.myVector.x(); x2 = q2.myVector.x();
  y1 = q1.myVector.y(); y2 = q2.myVector.y();
  z1 = q1.myVector.z(); z2 = q2.myVector.z();

  // косинус угла
  cosom = w1*w2+x1*x2+y1*y2+z1*z2;

  if ( cosom < 0.0 )   {
    cosom = -cosom;
    p1[0] = - x2;  p1[1] = - y2;
    p1[2] = - z2;  p1[3] = - w2;
  } else {
    p1[0] = x2;    p1[1] = y2;
    p1[2] = z2;    p1[3] = w2;
  }

  if ( (1.0 - cosom) > DELTA )  {
    // стандартный случай (slerp)
    omega = acos(cosom);
    sinom = sin(omega);
    scale0 = sin((1.0 - t) * omega) / sinom;
    scale1 = sin(t * omega) / sinom;
  }  else  {
    // если маленький угол - линейная интерполяция
    scale0 = 1.0 - t;
    scale1 = t;
  }

  RotateQuaternion result;
  result.myVector.setX( scale0 * x1 + scale1 * p1[0] );
  result.myVector.setY( scale0 * y1 + scale1 * p1[1] );
  result.myVector.setZ( scale0 * z1 + scale1 * p1[2] );
  result.myScalar =  scale0 * w1 + scale1 * p1[3];
  return result;
}
