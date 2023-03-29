#include <iostream>
#include <cstring>

using namespace std;

class Team {
public:
    char name[100];
    int year;
    char city[50];

    void copy(const Team &t) {
        strcpy(this->name, t.name);
        this->year = t.year;
        strcpy(this->city, t.city);
    }
public:
    Team(const char *name="", int year = 2023, const char *city="") {
        strcpy(this->name, name);
        this->year = year;
        strcpy(this->city, city);
    }

    Team(const Team &t) {
        copy(t);
    }

    ~Team(){}
};

class Match {
public:
    Team host;
    Team guest;
    int hostGoals;
    int guestGoals;

    void copy(const Match &m) {
        this->host = m.host;
        this->guest = m.guest;
        this->hostGoals = m.hostGoals;
        this->guestGoals = m.guestGoals;
    }
public:
    Match(const Team host=NULL, const Team guest=NULL,
          int hostGoals=0, int guestGoals=0) {
        this->host = host;
        this->guest = guest;
        this->hostGoals = hostGoals;
        this->guestGoals = guestGoals;
    }

    Match(const Match &m) {
        copy(m);
    }

    ~Match(){}
};

bool revans(const Match &m1, const Match &m2) {
    if(strcmp(m1.host.name, m2.guest.name) == 0 &&
       strcmp(m1.guest.name, m2.host.name) == 0) {
        return true;
    }
    else {
        return false;
    }
}

Team duel(const Match &m1, const Match &m2){
    if(revans(m1, m2)) {
        int firstTeam = m1.hostGoals + m2.guestGoals;
        int secondTeam = m1.guestGoals + m2.hostGoals;
        if(firstTeam > secondTeam) {
            return m1.host;
        }
        else if(firstTeam < secondTeam) {
            return m2.host;
        }
        else if (m1.guestGoals > m2.guestGoals) return m1.guest;
        else if (m1.guestGoals < m2.guestGoals) return m1.host;
        else {
            return 0;
        }
    }
    else {
        cout <<"Natprevarite ne se sovpagjaat!" <<endl;
        return 0;
    }
}

int main() {

    Team e1("Real Madrid", 1880, "Madrid");
    Team e2("FC Barcelona", 1880, "Barcelona");
    Match n1(e1, e2, 1, 2);
    Match n2(e2, e1, 1, 0);
    cout << duel(n1, n2).name;

    return 0;
}
