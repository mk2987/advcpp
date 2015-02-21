#include <iostream>
#include <cassert>
#include "vector3d.hh"
using namespace std;

Vector3D& Vector3D::operator+=(Vector3D &other) {
    for (int i = 0; i < 3; i++) {
        coords[i] += other.coords[i];
    }

    return *this;
}

Vector3D& Vector3D::operator-=(Vector3D &other) {
    for (int i = 0; i < 3; i++) {
        coords[i] -= other.coords[i];
    }

    return *this;
}

const Vector3D Vector3D::operator+(Vector3D &other) const {
    return (Vector3D(*this) += other);
}

const Vector3D Vector3D::operator-(Vector3D &other) const {
    return (Vector3D(*this) -= other);
}

Vector3D& Vector3D::operator*=(float scalar) {
    for (int i = 0; i < 3; i++) {
        coords[i] *= scalar;
    }

    return *this;
}

Vector3D& Vector3D::operator/=(float scalar) {
    assert(scalar != 0);

    for (int i = 0; i < 3; i++) {
        coords[i] /= scalar;
    }

    return *this;
}

const Vector3D Vector3D::operator*(float scalar) const {
    return (Vector3D(*this) *= other);
}

const Vector3D Vector3D::operator/(float scalar) const {
    return (Vector3D(*this) /= other);
}

const Vector3D Vector3D::operator*(float scalar, Vector3D &other) const {
    return (Vector3D(other) *= other);
}
