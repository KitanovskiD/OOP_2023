#include <iostream>
#include <cstring>

using namespace std;

class Boy {
public:
    char firstName[50];
    char lastName[50];
    int age;

public:

    Boy(const char *firstName="", const char *lastName="", int age = 0) {
        strcpy(this->firstName, firstName);
        strcpy(this->lastName, lastName);
        this->age = age;
    }

    void print() {
        cout<< "Momche: " << this->firstName << " " << this->lastName << " " << this->age << " ";
    }

    ~Boy(){}

};

class Girl {
public:
    char firstName[50];
    char lastName[50];
    int age;

public:

    Girl(const char *firstName="", const char *lastName="", int age = 0) {
        strcpy(this->firstName, firstName);
        strcpy(this->lastName, lastName);
        this->age = age;
    }

    void print() {
        cout<< "Devojche: " << this->firstName << " " << this->lastName << " " << this->age << ".";
    }

    ~Girl(){}

};

class Date {
protected:
    Boy boy;
    Girl girl;
public:
    Date(const Boy boy = NULL, const Girl girl = NULL) {
        this->boy = boy;
        this->girl = girl;
    }

    void print() {
        cout<< "Sredba: ";
        this->boy.print();
        this->girl.print();
    }

    void daliSiOdgovaraat() {
        if(abs(this->boy.age - this->girl.age) <= 5) {
            cout << "Si odgovaraat" << endl;
        }
        else {
            cout << "Ne si odgovaraat" << endl;
        }
    }

    ~Date(){}
};



int main() {

    char firstName[50];
    char lastName[50];
    int age;
    cout << "Vnesete informacii za momche: " << endl;
    cin>> firstName >> lastName;
    cin>>age;
    Boy boy(firstName, lastName, age);

    cout << "Vnesete informacii za devojche: " << endl;
    cin>> firstName >> lastName;
    cin>>age;
    Girl girl(firstName, lastName, age);

    Date d(boy, girl);

    d.daliSiOdgovaraat();
    return 0;
}
