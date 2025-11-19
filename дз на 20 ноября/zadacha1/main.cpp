#include <iostream>

class Number {
private:
    int value;

public:

    Number(int val = 0) : value(val) {}


    int getValue() const { return value; }


    void setValue(int val) { value = val; }


    Number operator+(const Number& other) const {
        return Number(value + other.value);
    }


    Number operator-(const Number& other) const {
        return Number(value - other.value);
    }


    Number operator*(const Number& other) const {
        return Number(value * other.value);
    }


    friend std::ostream& operator<<(std::ostream& os, const Number& num);
};


std::ostream& operator<<(std::ostream& os, const Number& num) {
    os << num.value;
    return os;
}


int main() {

    Number a(5), b(3);


    Number c = a + b;
    Number d = a - b;
    Number e = a * b;


    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "a + b = " << c << std::endl;
    std::cout << "a - b = " << d << std::endl;
    std::cout << "a * b = " << e << std::endl;






    return 0;
}
