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

    Vector3F& operator+=(Vector3F &other);
    Vector3F& operator-=(Vector3F &other);
    const Vector3F operator+(Vector3F &other) const;
    const Vector3F operator-(Vector3F &other) const;
    Vector3F& operator*=(float scalar);
    Vector3F& operator/=(float scalar);
    const Vector3F operator*(float scalar) const;
    const Vector3F operator/(float scalar) const;
    const Vector3F operator-() const;
};

const Vector3F operator*(float scalar, Vector3F &other);
