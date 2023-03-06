#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct student{
    char first_name[30];
    char last_name[30];
    int index;
    int points;
} Student;

void insert_student(Student *s) {
    scanf("%s", s->first_name);
    scanf("%s", s->last_name);
    scanf("%d", &s->index);
    s->points=0;
    int poeni;
    for (int i = 0; i < 4; ++i) {
        scanf("%d", &poeni);
        s->points += poeni;
    }
}

void print_student(Student s) {
    printf("%s %s %d %d\n", s.last_name, s.first_name, s.index, s.points);
}

void norm(char *student) {
    *student = toupper(*student);
    while (*(++student) != '\0') {
        *student = tolower(*student);
    }
}

void sort_students(Student *student_array, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if(student_array[i].points < student_array[j].points) {
                Student tmp = student_array[i];
                student_array[i] = student_array[j];
                student_array[j] = tmp;
            }
        }
    }
}

int main() {
    int n;

    scanf("%d", &n);

    Student student_array[n];

    for (int i = 0; i < n; ++i) {
        insert_student(&student_array[i]);
        norm(student_array[i].first_name);
        norm(student_array[i].last_name);
    }

    sort_students(student_array, n);

    for (int i = 0; i < n; ++i) {
        print_student(student_array[i]);
    }

    return 0;
}
