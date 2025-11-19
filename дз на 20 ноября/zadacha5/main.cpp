#include <iostream>
#include <stdexcept>


class Vector2D {
private:
    double x, y;

public:
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}


    double getX() const { return x; }
    double getY() const { return y; }


    void setX(double newX) { x = newX; }
    void setY(double newY) { y = newY; }


    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};


class Matrix2x2 {
private:
    double data[2][2];

public:

    Matrix2x2() {
        data[0][0] = data[0][1] = data[1][0] = data[1][1] = 0.0;
    }


    Matrix2x2(double a00, double a01, double a10, double a11) {
        data[0][0] = a00;
        data[0][1] = a01;
        data[1][0] = a10;
        data[1][1] = a11;
    }


    Matrix2x2(const double arr[2][2]) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                data[i][j] = arr[i][j];
            }
        }
    }


    Matrix2x2(std::initializer_list<std::initializer_list<double>> list) {
        if (list.size() != 2) {
            throw std::invalid_argument("Matrix2x2 requires 2 rows");
        }

        int i = 0;
        for (const auto& row : list) {
            if (row.size() != 2) {
                throw std::invalid_argument("Matrix2x2 requires 2 columns");
            }
            int j = 0;
            for (double value : row) {
                data[i][j] = value;
                j++;
            }
            i++;
        }
    }


    Matrix2x2 operator+(const Matrix2x2& other) const {
        Matrix2x2 result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }


    Matrix2x2 operator*(const Matrix2x2& other) const {
        Matrix2x2 result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }


    Vector2D operator*(const Vector2D& vec) const {
        double x = data[0][0] * vec.getX() + data[0][1] * vec.getY();
        double y = data[1][0] * vec.getX() + data[1][1] * vec.getY();
        return Vector2D(x, y);
    }


    double& operator()(int row, int col) {
        if (row < 0 || row >= 2 || col < 0 || col >= 2) {
            throw std::out_of_range("Matrix indices out of range");
        }
        return data[row][col];
    }


    const double& operator()(int row, int col) const {
        if (row < 0 || row >= 2 || col < 0 || col >= 2) {
            throw std::out_of_range("Matrix indices out of range");
        }
        return data[row][col];
    }


    void print() const {
        std::cout << "[[" << data[0][0] << ", " << data[0][1] << "],\n";
        std::cout << " [" << data[1][0] << ", " << data[1][1] << "]]" << std::endl;
    }
};


int main() {
    try {

        Matrix2x2 m1({{1, 2}, {3, 4}});
        Matrix2x2 m2({{5, 6}, {7, 8}});

        std::cout << "Matrix m1:" << std::endl;
        m1.print();
        std::cout << "Matrix m2:" << std::endl;
        m2.print();


        Matrix2x2 product = m1 * m2;
        std::cout << "Matrix product m1 * m2:" << std::endl;
        product.print();


        Matrix2x2 sum = m1 + m2;
        std::cout << "Matrix sum m1 + m2:" << std::endl;
        sum.print();


        Vector2D v1(2, 3);
        std::cout << "Vector v1: ";
        v1.print();

        Vector2D result = m1 * v1;
        std::cout << "Matrix * Vector result: ";
        result.print();


        std::cout << "Element m1(0, 1) = " << m1(0, 1) << std::endl;


        m1(1, 0) = 10;
        std::cout << "After m1(1, 0) = 10:" << std::endl;
        m1.print();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
