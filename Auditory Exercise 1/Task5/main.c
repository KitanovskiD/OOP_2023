#include <stdio.h>

typedef struct city {
    char name[50];
    int citizens;
}City;

typedef struct president{
    char first_name[30];
    char last_name[30];
    char party[50];
}President;

typedef struct country{
    char name[50];
    President president;
    City capital_city;
    int citizens;
}Country;

void insert_country(Country *c){
    scanf("%s", c->name);
    //President
    scanf("%s", c->president.first_name);
    scanf("%s", c->president.last_name);
    scanf("%s", c->president.party);

    //City

    scanf("%s", c->capital_city.name);
    scanf("%d", &c->capital_city.citizens);

    scanf("%d", &c->citizens);
}

void print_country_president(Country c) {
    printf("President: %s %s", c.president.first_name, c.president.last_name);
}

int main() {
    int n;

    scanf("%d", &n);

    Country country_array[n];


    for (int i = 0; i < n; ++i) {
        insert_country(&country_array[i]);
    }


    int maxi = 0;
    int max_citizens = 0;

    for (int i = 0; i < n; ++i) {
        if(max_citizens <= country_array[i].capital_city.citizens) {
            max_citizens = country_array[i].capital_city.citizens;
            maxi = i;
        }
    }


    print_country_president(country_array[maxi]);

    return 0;
}
