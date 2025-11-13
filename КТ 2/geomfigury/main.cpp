#include <iostream>
#include <vector>
#include <string>


class Shape {
protected:
    std::string name;
    std::string color;

public:
    Shape(const std::string& name, const std::string& color) : name(name), color(color) {}

    virtual double area() const = 0;
    virtual void draw() const = 0;

    const std::string& getName() const { return name; }
    const std::string& getColor() const { return color; }

    bool operator==(const Shape& other) const {
        return (name == other.name) && (color == other.color);
    }

    virtual ~Shape() {}
};


class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius, const std::string& color) : Shape("Circle", color), radius(radius) {}

    double area() const override {
        return 3.14 * radius * radius;
    }

    void draw() const override {
        std::cout << "Drawing a " << color << " circle with radius: " << radius << std::endl;
    }

    Circle operator+(const Circle& other) const {
        return Circle(radius + other.radius, color);
    }
};


class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double width, double height, const std::string& color) : Shape("Rectangle", color), width(width), height(height) {}

    double area() const override {
        return width * height;
    }

    void draw() const override {
        std::cout << "Drawing a " << color << " rectangle with width: " << width << " and height: " << height << std::endl;
    }
};


void printInfo(const Shape& shape) {
    std::cout << "Name: " << shape.getName() << ", Color: " << shape.getColor() << ", Area: " << shape.area() << std::endl;
}

void printInfo(const Shape& shape, bool detailed) {
    printInfo(shape);
    if (detailed) {
        shape.draw();
    }
}

std::ostream& operator<<(std::ostream& os, const Shape& shape) {
    os << "Name: " << shape.getName() << ", Color: " << shape.getColor() << ", Area: " << shape.area();
    return os;
}

int main() {
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(5.0, "Red"));
    shapes.push_back(new Rectangle(4.0, 6.0, "Blue"));


    for (const auto& shape : shapes) {
        printInfo(*shape, true);
    }


    Circle circle1(3.0, "Green");
    Circle circle2(4.0, "Green");
    Circle circle3 = circle1 + circle2;
    std::cout << circle3 << std::endl;


    for (const auto& shape : shapes) {
        delete shape;
    }

    return 0;
}
