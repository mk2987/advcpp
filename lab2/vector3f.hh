#include <ostream>
using namespace std;

class Vector3F {
    float coords[3];
public:
    // no need to provide copy constructors and
    // assignment operator, the compiler generated
    // defaults will work fine since this class doesn't
    // allocate memory dynamically.
    Vector3F() {
        coords[0] = coords[1] = coords[2] = 0;
    }

    Vector3F(float x, float y, float z) {
        coords[0] = x;
        coords[1] = y;
        coords[2] = z;
    }

    Vector3F& operator+=(const Vector3F &v);
    Vector3F& operator-=(const Vector3F &v);
    const Vector3F operator+(const Vector3F &v) const;
    const Vector3F operator-(const Vector3F &v) const;
    Vector3F& operator*=(float scalar);
    Vector3F& operator/=(float scalar);
    const Vector3F operator*(float scalar) const;
    const Vector3F operator/(float scalar) const;
    const Vector3F operator-() const;
    float operator[](int i) const;
    float& operator[](int i);

    // dot product
    float operator*(const Vector3F &v) const;
    // cross product
    const Vector3F operator%(const Vector3F &v) const;

    float magSq() const;
    float mag() const;
    const Vector3F norm() const;
};

const Vector3F operator*(float scalar, const Vector3F &v);
ostream& operator<<(ostream &os, const Vector3F &v);
