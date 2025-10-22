#include <iostream>
#include <string>
using namespace std;

class Human {
protected:
    string name;
    int age;

public:
    Human(string n = "", int a = 0) : name(n), age(a) {}

    void display() const {
        cout << name << ", " << age << " years";
    }
};

class Employee : public Human {
    string position;

public:
    Employee(string n = "", int a = 0, string pos = "")
        : Human(n, a), position(pos) {}

    void display() const {
        Human::display();
        cout << ", " << position;
    }
};

int main() {
    Human person("masha", 25);
    Employee worker("maks", 30, "razrabotchik");

    cout << "chelovek: ";
    person.display();
    cout << endl;

    cout << "sotrudnik: ";
    worker.display();
    cout << endl;

    return 0;
}
