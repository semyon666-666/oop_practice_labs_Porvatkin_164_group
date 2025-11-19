#include <iostream>
#include <stdexcept>

using namespace std;

class Vector2D {
private:
    double x;
    double y;

public:

    Vector2D(double x_val = 0, double y_val = 0) : x(x_val), y(y_val) {}


    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }


    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }


    double operator*(const Vector2D& other) const {
        return x * other.x + y * other.y;
    }


    Vector2D operator*(double scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }


    friend Vector2D operator*(double scalar, const Vector2D& vec) {
        return Vector2D(vec.x * scalar, vec.y * scalar);
    }


    double& operator[](int index) {
        if (index == 0) {
            return x;
        } else if (index == 1) {
            return y;
        } else {
            throw out_of_range("index libo 0 libo 1");
        }
    }


    const double& operator[](int index) const {
        if (index == 0) {
            return x;
        } else if (index == 1) {
            return y;
        } else {
            throw out_of_range("index libo 0 libo 1");
        }
    }


    friend ostream& operator<<(ostream& os, const Vector2D& vec) {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }


    double getX() const { return x; }
    double getY() const { return y; }
};

int main() {
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    Vector2D sum = v1 + v2;
    cout << "v1 + v2 = " << sum << endl;


    Vector2D diff = v1 - v2;
    cout << "v1 - v2 = " << diff << endl;


    double dotProduct = v1 * v2;
    cout << "v1 * v2 (skalyarnoe proizv) = " << dotProduct << endl;
    cout << "proverka: 3*1 + 4*2 = " << (3*1 + 4*2) << endl;


    Vector2D scaled_right = v1 * 2.5;
    cout << "v1 * 2.5 = " << scaled_right << endl;


    Vector2D scaled_left = 2.5 * v1;
    cout << "2.5 * v1 = " << scaled_left << endl;


    cout << "v1[0] = " << v1[0] << endl;
    cout << "v1[1] = " << v1[1] << endl;


    v1[0] = 5;
    v1[1] = 7;
    cout << "posle izmeneniya: v1 = " << v1 << endl;


    cout << "dop primery:" << endl;
    Vector2D v3(2, -1);
    Vector2D v4(-3, 5);

    cout << "v3 = " << v3 << endl;
    cout << "v4 = " << v4 << endl;
    cout << "v3 + v4 = " << (v3 + v4) << endl;
    cout << "v3 * v4 = " << (v3 * v4) << endl;
    cout << "v3 * 3 = " << (v3 * 3) << endl;

    return 0;
}
