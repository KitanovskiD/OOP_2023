#include <iostream>

using namespace std;


struct City {
    char name[100];
    int population;

    void print_city() {
        cout<< "\t Name:" << name <<endl;
        cout<< "\t City population:" << population <<endl;
    }
};

struct Country {
    char name[100];
    char president[100];
    City capital_city;
    int population;

    void print_country() {
        cout << "Name: " << name << endl;
        cout << "President: " << president << endl;
        cout << "Capital City: " << endl;
        capital_city.print_city();
        cout<< "Country population: " << population;
    }
};

void read_info(Country &c) {
    cin>> c.name;
    cin>> c.president;
    cin>> c.capital_city.name;
    cin>> c.capital_city.population;
    cin>> c.population;
}

void sort_countries(Country c[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if(c[i].capital_city.population < c[j].capital_city.population){
                Country tmp = c[i];
                c[i] = c[j];
                c[j] = tmp;
            }
        }
    }
}

int main() {
    Country countries[100];

    int n;

    cin>>n;

    for (int i = 0; i < n; ++i) {
        read_info(countries[i]);
    }

    sort_countries(countries, n);

    for (int i = 0; i < n; ++i) {
        countries[i].print_country();
    }

    return 0;
}
