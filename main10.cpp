#include <iostream>
#include <vector>
using namespace std;

class Shape {
protected:
    int x;
    int y;
public:
    Shape(int x, int y) : x(x), y(y) {
        cout << "Shape Constructor" << endl;
    }

    // ВИРТУАЛЬНЫЙ деструктор
    virtual ~Shape() {
        cout << "Shape Destructor" << endl;
    }

    virtual void draw() = 0;
    void move(int newX, int newY) { x = newX; y = newY; }
};

class Rectangle : public Shape {
public:

    Rectangle(int x, int y) : Shape(x, y) {
        cout << "Rectangle Constructor" << endl;
    }


    ~Rectangle() {
        cout << "Rectangle Destructor" << endl;
    }

    void draw() override {
        cout << "Drawing Rectangle at (" << x << "," << y << ")" << endl;
    }
};

class Circle : public Shape {
public:

    Circle(int x, int y) : Shape(x, y) {
        cout << "Circle Constructor" << endl;
    }


    ~Circle() {
        cout << "Circle Destructor" << endl;
    }

    void draw() override {
        cout << "Drawing Circle at (" << x << "," << y << ")" << endl;
    }
};

int main() {

    Shape* shapePtr = new Rectangle(10, 20);


    cout << "=== Deleting Rectangle through Shape* pointer ===" << endl;
    delete shapePtr;

    cout << "\n=== End of experiment with non-virtual destructor ===" << endl;

    return 0;
}
