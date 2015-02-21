class Vector3D {
    float coords[3];
public:
    // no need to provide copy constructors and
    // assignment operator, the compiler generated
    // defaults will work fine since this class doesn't
    // allocate memory dynamically.
    Vector3D() {
        coords[0] = coords[1] = coords[2] = 0;
    }

    Vector3D(float x, float y, float z) {
        coords[0] = x;
        coords[1] = y;
        coords[2] = z;
    }

    Vector3D& operator+=(Vector3D &other);
    Vector3D& operator-=(Vector3D &other);
    const Vector3D operator+(Vector3D &other) const;
    const Vector3D operator-(Vector3D &other) const;
    Vector3D& operator*=(float scalar);
    Vector3D& operator/=(float scalar);
    const Vector3D operator*(float scalar) const;
    const Vector3D operator/(float scalar) const;
    const Vector3D operator-() const;
};

const Vector3D operator*(float scalar, Vector3D &other);
