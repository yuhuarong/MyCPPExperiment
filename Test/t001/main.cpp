#include <iostream>
#include <cstring>

using namespace std;

class Student {
public:
    Student();//考虑这里为什么不缺省无参构造?
    Student(const Student &o);

    explicit Student(const char *n);

    Student &operator=(const Student &o);

    ~Student();

    char *GetName();

    void ChangeName(const char *n);

private:
    char name[20];
};

Student::Student() {
    strcpy(name, "");
}

Student::Student(const char *n) {
    strcpy(name, n);
}

Student::Student(const Student &o) {
    strcpy(name, o.name);
}

Student &Student::operator=(const Student &o) {
    strcpy(name, o.name);
    return *this;
}

Student::~Student() {
//    delete name;
}

char* Student::GetName() {
    return name;
}

void Student::ChangeName(const char *n) {
    strcpy(name, n);
}

int main() {
    Student stu1, stu2("Jennie Mao"), stu3(stu2), stu4("John Smith");
    cout << "stu1:" << stu1.GetName() << endl;
    cout << "stu2:" << stu2.GetName() << endl;
    cout << "stu3:" << stu3.GetName() << endl;
    cout << "stu4:" << stu4.GetName() << endl;

    stu1 = stu4;

    cout << "stu1:" << stu1.GetName() << endl;

    stu1.ChangeName("Peter");
    cout << "stu1:" << stu1.GetName() << endl;

    stu3.ChangeName("Tom");
    cout << "stu3:" << stu3.GetName() << endl;

    return 0;
}
