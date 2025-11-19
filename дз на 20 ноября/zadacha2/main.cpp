#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

    using namespace std;

class Student {
private:
    string name;
    int grade;

public:

    Student(string n, int g) : name(n), grade(g) {}


    bool operator==(const Student& other) const {
        return name == other.name;
    }


    bool operator>(const Student& other) const {
        return grade > other.grade;
    }


    bool operator<=(const Student& other) const {
        return grade <= other.grade;
    }


    bool operator<(const Student& other) const {
        return grade < other.grade;
    }

    string getName() const { return name; }
    int getGrade() const { return grade; }


    void print() const {
        cout << name << " - " << grade << endl;
    }
};

int main() {
    vector<Student> students = {{"Alisa", 85}, {"boris", 90}, {"Semyon", 78}};

    cout << "do sortirovki:" << endl;
    for (const auto& student : students) {
        student.print();
    }


    sort(students.begin(), students.end());

    cout << "posle sortirovki po ocenke:" << endl;
    for (const auto& student : students) {
        student.print();
    }

    cout << "demonstracia operatorov:" << endl;
    Student alisa("Alisa", 85);
    Student boris("boris", 90);

    cout << "Alisa == boris: " << (alisa == boris) << endl;
    cout << "Alisa > boris: " << (alisa > boris) << endl;
    cout << "Alisa <= boris: " << (alisa <= boris) << endl;

    return 0;
}
