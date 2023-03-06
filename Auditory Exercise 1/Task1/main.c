#include <stdio.h>

typedef struct date {
    int day;
    int month;
    int year;
}Date;


void insert_date(Date *d){
    scanf("%d %d %d", &d->day, &d->month, &d->year);
}

void print_date(Date d) {
    printf("Day: %02d, Month: %02d, Year: %02d", d.day, d.month, d.year);
}

int compare_dates(Date d1, Date d2) {
    if(d1.year > d2.year) return 1;
    else if(d1.year < d2.year) return -1;
    else {
        if(d1.month > d2.month) return 1;
        else if(d1.month < d2.month) return -1;
        else {
            if(d1.day > d2.day) return 1;
            else if(d1.day < d2.day) return -1;
            else return 0;
        }
    }
}

int days(Date d1, Date d2) {
    int num_of_days = d1.day - d2.day;
    num_of_days += (d1.month*30) - (d2.month*30);
    num_of_days += (d1.year*365) - (d2.year*365);
}

int main() {

    Date first_date;
    Date second_date;

    insert_date(&first_date);
    insert_date(&second_date);

    if(compare_dates(first_date, second_date) == -1) {
        printf("Days: %d", days(second_date, first_date));
    }
    else if(compare_dates(first_date, second_date) == 1) {
        printf("Days: %d", days(first_date, second_date));
    }
    else {
        printf("Datumite se ednakvi!");
    }
    return 0;
}
