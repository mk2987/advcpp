#include <iostream>
#include <cassert>
#include "vector3d.hh"
using namespace std;

Vector3F& Vector3F::operator+=(Vector3F &other) {
    for (int i = 0; i < 3; i++) {
        coords[i] += other.coords[i];
    }

    return *this;
}

Vector3F& Vector3F::operator-=(Vector3F &other) {
    for (int i = 0; i < 3; i++) {
        coords[i] -= other.coords[i];
    }

    return *this;
}

const Vector3F Vector3F::operator+(Vector3F &other) const {
    return (Vector3F(*this) += other);
}

const Vector3F Vector3F::operator-(Vector3F &other) const {
    return (Vector3F(*this) -= other);
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
    return (Vector3F(*this) *= other);
}

const Vector3F Vector3F::operator/(float scalar) const {
    return (Vector3F(*this) /= other);
}

const Vector3F Vector3F::operator*(float scalar, Vector3F &other) const {
    return (Vector3F(other) *= other);
}

const Vector3F Vector3F::operator-() const {
    return (Vector3F(*this) *= (-1));
}
