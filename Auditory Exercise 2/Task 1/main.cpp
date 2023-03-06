#include <iostream>

using namespace std;

struct Student{
    char firstName[50];
    char lastName[50];
    int number;
    int total_points;

    void print_student() {
        cout << "Id: " << number<<endl;
        cout<<"Full Name: " << firstName << " " << lastName << endl;
        cout << "Total Points: " << total_points << endl;
    }
};

void read_student(Student &currentStudent) {
    cin>> currentStudent.firstName;
    cin>> currentStudent.lastName;
    cin>> currentStudent.number;
    currentStudent.total_points = 0;
    for (int i = 0; i < 4; ++i) {
        int points;
        cin>>points;
        currentStudent.total_points += points;
    }
}

void normalize(char *student_info, bool isUpper=false) {
    *student_info = toupper(*student_info);
    student_info++;
    while (*student_info) {
        if(isUpper) {
            *student_info = toupper(*student_info);
        }
        else {
            *student_info = tolower(*student_info);
        }
        student_info++;
    }
}

void sort_students(Student students[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if(students[i].total_points < students[j].total_points) {
                Student tmp = students[i];
                students[i] = students[j];
                students[j] = tmp;
            }
        }
    }
}

int main() {

    Student student_array[100];

    int n;

    cin>>n;

    for (int i = 0; i < n; ++i) {
        read_student(student_array[i]);
        normalize(student_array[i].firstName, true);
        normalize(student_array[i].lastName, true);
    }

    //sort array

    sort_students(student_array, n);

    cout<<"============ORDERED=============="<<endl;

    for (int i = 0; i < n; ++i) {
        student_array[i].print_student();
    }

    return 0;
}
