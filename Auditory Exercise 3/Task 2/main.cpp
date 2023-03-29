#include <iostream>
#include <cstring>

using namespace std;

enum Position{
    employee, manager, owner
};

//Employee -> 0
// Manager -> 1
// Owner -> 2

class Employee {
protected:
    char name[100];
    float salary;
    Position position;
public:
    Employee(const char *name="", float salary = 18000, unsigned short position=0) {
        strcpy(this->name, name);
        this->salary = salary;
        this->position = (Position)position;
    }

    void setName(const char *name) {
        strcpy(this->name, name);
    }

    void setSalary(float salary) {
        this->salary = salary;
    }

    void setPosition(short position) {
        this->position = (Position)position;
    }

    const float getSalary() const {
        return this->salary;
    }

    void printEmployee() {
        cout<< this->name << " " << this->salary << " ";
        if(this->position == Position::employee) {
            cout<< "Employee" <<endl;
        }
        else if(this->position == Position::manager) {
            cout<< "Manager" <<endl;
        }
        else  {
            cout<< "Owner" <<endl;
        }
    }

    ~Employee(){}
};

void sortEmployees(Employee *employees, int n) {
    Employee tmp;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if(employees[i].getSalary() < employees[j].getSalary()) {
                tmp = employees[i];
                employees[i] = employees[j];
                employees[j] = tmp;
            }
        }
    }
}

int main() {

    int n;
    char name[100];
    float salary;
    short position;

    cout<<"Enter the number of employees:"<<endl;
    cin>>n;

    Employee employee_array[n];

    for (int i = 0; i < n; ++i) {
        cout<<"Enter information for " << (i+1) << " employee:"<<endl;
        cin>> name;
        cin>>salary;
        cin>>position;
        employee_array[i].setName(name);
        employee_array[i].setSalary(salary);
        employee_array[i].setPosition(position);
    }


    sortEmployees(employee_array, n);

    for (int i = 0; i < n; ++i) {
        employee_array[i].printEmployee();
    }
    return 0;
}
