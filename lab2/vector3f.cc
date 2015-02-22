#include <iostream>
#include <cmath>
#include <cassert>
#include "vector3d.hh"
using namespace std;

Vector3F& Vector3F::operator+=(const Vector3F &v) {
    for (int i = 0; i < 3; i++) {
        coords[i] += v.coords[i];
    }

    return *this;
}

Vector3F& Vector3F::operator-=(const Vector3F &v) {
    for (int i = 0; i < 3; i++) {
        coords[i] -= v.coords[i];
    }

    return *this;
}

const Vector3F Vector3F::operator+(const Vector3F &v) const {
    return (Vector3F(*this) += v);
}

const Vector3F Vector3F::operator-(const Vector3F &v) const {
    return (Vector3F(*this) -= v);
}

Vector3F& Vector3F::operator*=(float scalar) {
    for (int i = 0; i < 3; i++) {
        coords[i] *= scalar;
    }

    return *this;
}

Vector3F& Vector3F::operator/=(float scalar) {
    assert(scalar != 0);

    for (int i = 0; i < 3; i++) {
        coords[i] /= scalar;
    }

    return *this;
}

const Vector3F Vector3F::operator*(float scalar) const {
    return (Vector3F(*this) *= v);
}

const Vector3F Vector3F::operator/(float scalar) const {
    return (Vector3F(*this) /= v);
}

const Vector3F Vector3F::operator*(float scalar, const Vector3F &v) const {
    return (Vector3F(v) *= scalar); 
}

const Vector3F Vector3F::operator-() const {
    return (Vector3F(*this) *= (-1));
}

const Vector3F::operator[](int i) const {
    assert(i >= 0);
    assert(i < 3);
    return coords[i];
}

float& Vector3F::operator[](int i) const {
    assert(i >= 0);
    assert(i < 3);
    return coords[i];
}

ostream& operator<<(ostream& os, const Vector3F &v) {
    os << "( " << v[0] << ", " << v[1] << ", " << v[2] << ")";
    return os;
}

const Vector3F::operator*(const Vector3F &v) const {
    return this->coords[0] * v.coords[0] +
           this->coords[1] * v.coords[1] +
           this->coords[2] * v.coords[2];
}

const Vector3F Vector3F::operator%(const Vector3F &v) const {
    float Ux = this->coords[0];
    float Uy = this->coords[1];
    float Uz = this->coords[2];
    float Vx = v.coords[0];
    float Vy = v.coords[1];
    float Vz = v.coords[2];
    return Vector3F((Uy*Vz - Uz*Vy),
                    (Uz*Vx - Ux*Vz),
                    (Ux*Vy - Uy*Vx));
}

float Vector3F::magSq() const {
    return (*this) * (*this);
}

float Vector3F::mag() const {
    return sqrtf(magSq());
}

const Vector3F::norm() const {
    return Vector3F(*this) * (1f / mag());
}
