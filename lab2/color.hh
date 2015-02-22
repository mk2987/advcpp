#include <ostream>
using namespace std;

class Color {
    float red, green, blue;
public:
    // no need to provide copy constructors and
    // assignment operator, the compiler generated
    // defaults will work fine since this class doesn't
    // allocate memory dynamically.
    Color() {
        red = green = blue = 0;
    }

    Color(float red, float green, float blue): red(red), green(green), blue(blue) {}

    Color& operator+=(const Color &c);
    Color& operator-=(const Color &c);
    Color& operator*=(const Color &c);
    const Color operator+(const Color &c) const;
    const Color operator-(const Color &c) const;
    const Color operator*(const Color &c) const;
    Color& operator*=(float scalar);
    Color& operator/=(float scalar);
    const Color operator*(float scalar) const;
    const Color operator/(float scalar) const;

    float getRed() const { return red; }
    float getGreen() const { return green; }
    float getBlue() const { return blue; }
    void setRed(float red)  { this->red = red; }
    void setGreen(float green) { this->green = green; }
    void setBlue(float blue) { this->blue = blue; }
};

const Color operator*(float scalar, const Color &c);
ostream& operator<<(ostream& os, const Color &c);
