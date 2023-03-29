#include <iostream>
#include <cstring>

using namespace std;

class Date {
protected:
    int day;
    int month;
    int year;

    void copy(const Date &d) {
        this->day = d.day;
        this->month = d.month;
        this->year = d.year;
    }
public:
    Date(int day=1, int month=1, int year=1) {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    Date(const Date &d){
        copy(d);
    }

    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

    ~Date(){};
};

class Employee {
protected:
    char name[20];
    float salary;
    Date birth_date;

    void copy(const Employee &e) {
        strcpy(this->name, e.name);
        this->salary = e.salary;
        this->birth_date = e.birth_date;
    }
public:

    Employee(){}

    Employee(char *name, float salary, const Date &birth_date) {
        strcpy(this->name, name);
        this->salary = salary;
        this->birth_date = birth_date;
    }

    Employee(const Employee &e) {
        copy(e);
    }

    float getSalary() const {
        return salary;
    }

    const Date &getBirthDate() const {
        return birth_date;
    }

    void print() {
        cout << this->name << " - " << this->salary<<endl;
    }

    ~Employee(){}
};

Employee getEmployeeWithHigherSalary(Employee *employee_array, int n){
    int max_index=-1;
    int max_salary=0;

    for (int i = 0; i < n; ++i) {
        if(max_salary <= employee_array[i].getSalary()) {
            max_salary = employee_array[i].getSalary();
            max_index = i;
        }
    }

    if(max_index!=-1) {
        return employee_array[max_index];
    }
    else {
        cout<<"Ne postoi takov vraboten!" <<endl;
    }
}

int compareDates(const Date &d1, const Date &d2) {
    if(d1.getYear() < d2.getYear()) {
        return -1;
    }
    else if(d1.getYear() > d2.getYear()){
        return 1;
    }
    else {
        if(d1.getMonth() < d2.getMonth()) {
            return -1;
        }
        else if(d1.getMonth() > d2.getMonth()){
            return 1;
        }
        else {
            if(d1.getDay() < d2.getDay()) {
                return -1;
            }
            else if(d1.getDay() > d2.getDay()){
                return 1;
            }
            else {
                return 0;
            }
        }
    }
}

Employee getYoungestEmployee(Employee *employee_array, int n) {
    int index = -1;
    Date date = employee_array[0].getBirthDate();

    for (int i = 0; i < n; ++i) {
        if(compareDates(date, employee_array[i].getBirthDate())==-1) {
            date = employee_array[i].getBirthDate();
            index = i;
        }
    }

    if(index != -1) {
        return employee_array[index];
    }
    else {
        cout<<"Ne postoi takov vraboten!" <<endl;
    }
}

int main() {
    Date d1(1, 1, 1980);
    Date d2(1, 2, 1983);
    Date d3(11, 12, 1984);
    Employee v[3];
    Employee v1("Marjan", 40000, d1);
    Employee v2("Stefan", 30000, d2);
    Employee v3("Marko", 20000, d3);
    v[0] = v1; v[1] = v2; v[2] = v3;
    cout << "Najmlad vraboten: " << endl;
    getYoungestEmployee(v, 3).print();
    cout << "Vraboten so najgolema plata: " << endl;
    getEmployeeWithHigherSalary(v, 3).print();
    return 0;
}
