#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string brand;
    int year;
    int speed;
public:
    void setinfo(string b, int y, int s) {
        brand = b;
        year = y;
        speed = s;
    }
    void showinfo() {
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << " km/h" << endl;
        cout << "Year: " << year << endl;
    }
};

class car : public Vehicle {
private:
    int doors;
public:
    void setcarinfo(string b, int y, int s, int d) {
        setinfo(b, y, s);
        doors = d;
    }
    void showcarinfo() {
        cout << "\n=== automobile ===" << endl;
        showinfo();
        cout << "dveri: " << doors << endl;
    }
};

class bicycle : public Vehicle {
private:
    int Numb;
public:
    void setbicycleinfo(string b, int y, int s, int numb) {
        setinfo(b, y, s);
        Numb = numb;
    }
    void showbicycleinfo() {
        cout << "\n=== velosiped ===" << endl;
        showinfo();
        cout << "number of speeds: " << Numb << endl;
    }
};

int main() {
    while (true) {
        string input;
        cout << "\nVibirite (avto / velo / exit): ";
        cin >> input;

        if (input == "exit") {
            cout << "Exit success." << endl;
            break;
        }
        else if (input == "avto") {
            string brand;
            int speed, doors, year;

            cout << "Vvedite brand: ";
            cin >> brand;
            cout << "Vvedite year: ";
            cin >> year;
            cout << "Vvedite max speed km/h: ";
            cin >> speed;
            cout << "Vvedite count of doors: ";
            cin >> doors;

            car car;
            car.setcarinfo(brand, year, speed, doors);
            car.showcarinfo();
        }
        else if (input == "velo") {
            string brand;
            int speed, numb, year;

            cout << "Vvedite brand: ";
            cin >> brand;
            cout << "Vvedite year: ";
            cin >> year;
            cout << "Vvedite max speed km/h: ";
            cin >> speed;
            cout << "how many of speeds?: ";
            cin >> numb;

            bicycle bike;
            bike.setbicycleinfo(brand, year, speed, numb);
            bike.showbicycleinfo();
        }
        else {
            cout << "Nan. Try again" << endl;
        }
    }

    return 0;
}
