#include <iostream>
#include <cmath>
#include <cassert>
#include "vector3d.hh"
using namespace std;

Color& Color::operator+=(const Color &c) {
    this->red += c.red;
    this->green += c.green;
    this->blue += c.blue;

    return *this;
}

Color& Color::operator-=(const Color &c) {
    this->red -= c.red;
    this->green -= c.green;
    this->blue -= c.blue;

    return *this;
}

Color& Color::operator*=(const Color &c) {
    this->red *= c.red;
    this->green *= c.green;
    this->blue *= c.blue;

    return *this;
}

const Color Color::operator+(const Color &c) const {
    return (Color(*this) += c);
}

const Color Color::operator-(const Color &c) const {
    return (Color(*this) -= c);
}

const Color Color::operator*(const Color &c) const {
    return (Color(*this) *= c);
}

Color& Color::operator*=(float scalar) {
    red *= scalar;
    green *= scalar;
    blue *= scalar;

    return *this;
}

Color& Color::operator/=(float scalar) {
    red /= scalar;
    green /= scalar;
    blue /= scalar;

    return *this;
}

const Color Color::operator*(float scalar) const {
    return (Color(*this) *= v);
}

const Color Color::operator*(float scalar, const Color &c) const {
    return (Color(v) *= scalar); 
}

ostream& operator<<(ostream& os, const Color &c) {
    os << "( " << v[0] << ", " << v[1] << ", " << v[2] << ")";
    return os;
}

const Color::operator*(const Color &c) const {
    return this->red * c.red +
           this->green * c.green +
           this->blue * c.blue;
}
