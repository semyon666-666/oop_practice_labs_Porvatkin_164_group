#include <iostream>
#include <string>

using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:

    Complex(double r = 0, double i = 0) : real(r), imaginary(i) {}


    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }


    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }


    Complex operator*(const Complex& other) const {

        return Complex(real * other.real - imaginary * other.imaginary,
                       real * other.imaginary + imaginary * other.real);
    }


    Complex operator~() const {
        return Complex(real, -imaginary);
    }


    friend ostream& operator<<(ostream& os, const Complex& c) {
        if (c.imaginary == 0) {
            os << c.real;
        } else if (c.real == 0) {
            os << c.imaginary << "i";
        } else if (c.imaginary > 0) {
            os << c.real << " + " << c.imaginary << "i";
        } else {
            os << c.real << " - " << -c.imaginary << "i";
        }
        return os;
    }


    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;


    Complex sum = c1 + c2;
    cout << "c1 + c2 = " << sum << endl;


    Complex diff = c1 - c2;
    cout << "c1 - c2 = " << diff << endl;


    Complex product = c1 * c2;
    cout << "c1 * c2 = " << product << endl;


    cout << "proverka: (3+4i)*(1+2i) = -5 + 10i" << endl;


    Complex conjugate1 = ~c1;
    Complex conjugate2 = ~c2;
    cout << "~c1 = " << conjugate1 << endl;
    cout << "~c2 = " << conjugate2 << endl;


    cout << "dop primery:" << endl;
    Complex c3(0, 5);
    Complex c4(2, 0);
    Complex c5(1, -3);

    cout << "c3 = " << c3 << endl;
    cout << "c4 = " << c4 << endl;
    cout << "c5 = " << c5 << endl;
    cout << "~c5 = " << ~c5 << endl;

    return 0;
}
