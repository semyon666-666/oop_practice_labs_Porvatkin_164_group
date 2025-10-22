#include <iostream>
#include <string>
using namespace std;

struct Point {
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    void print() const {
        cout << "(" << x << ", " << y << ")";
    }
};

class ColoredPoint : public Point {
    string color;

public:
    ColoredPoint(double x = 0, double y = 0, string c = "black")
        : Point(x, y), color(c) {}

    string getColor() const { return color; }
    void setColor(string c) { color = c; }

    void print() const {
        Point::print();
        cout << " color: " << color;
    }
};

int main() {
    Point p1(3, 4);
    ColoredPoint cp1(1, 2, "red");
    ColoredPoint cp2(5, 7, "blue");

    cout << "tochka: ";
    p1.print();
    cout << endl;

    cout << "cvetnaya tochka: ";
    cp1.print();
    cout << endl;

    cout << "drugaya cvetnaya tochka: ";
    cp2.print();
    cout << endl;

    cp1.setColor("green");
    cout << "posle smeny cveta: ";
    cp1.print();

    return 0;
}
