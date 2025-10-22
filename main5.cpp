#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string fio;
    int age;
public:
    Person(string f, int a) : fio(f), age(a) {}
    virtual void print() {
        cout << fio << ", " << age << " years" << endl;
    }
    virtual ~Person() = default;
};

class Employee : public Person {
    string position;
    double salary;
public:
    Employee(string f, int a, string p, double s)
        : Person(f, a), position(p), salary(s) {}
    void print() override {
        cout << fio << ", " << age << " years, "
             << position << ", " << salary << " rub." << endl;
    }
};

class Student : public Person {
    string group;
    double avgGrade;
public:
    Student(string f, int a, string g, double avg)
        : Person(f, a), group(g), avgGrade(avg) {}
    void print() override {
        cout << fio << ", " << age << " years, "
             << group << ", sr.ball: " << avgGrade << endl;
    }
};

int main() {
    Person* people[] = {
        new Employee("Ivanov I.I.", 35, "manager", 50000),
        new Student("Petrov P.P.", 20, "it-21", 4.5),
        new Employee("Sidorova M.V.", 28, "bugalter", 45000)
    };

    for (auto p : people) {
        p->print();
        delete p;
    }

    return 0;
}
