#include <iostream>
#include <cstring>

using namespace std;

class Team {
protected:
    char team_name[100];
    char stadium_name[50];
    char city[50];

    void copy(const Team &t) {
        strcpy(this->team_name, t.team_name);
        strcpy(this->stadium_name, t.stadium_name);
        strcpy(this->city, t.city);
    }
public:
    Team(const char *team_name="", const char *stadium_name="", const char *city="") {
        strcpy(this->team_name, team_name);
        strcpy(this->stadium_name, stadium_name);
        strcpy(this->city, city);
    }

    Team(const Team &t) {
        copy(t);
    }

    const char *getTeamName() const {
        return team_name;
    }

    const char *getStadiumName() const {
        return stadium_name;
    }

    const char *getCity() const {
        return city;
    }

    void setTeamName(const char *team_name) {
        strcpy(this->team_name, team_name);
    }

    ~Team(){}
};

//class Match {
//private:
//  Team *host, *guest;
//  int hostGoals, guestGoals;
//
//  void copy(const Match &m) {
//      this->host = new Team(*m.host);
//      this->guest = new Team(*m.guest);
//      this->hostGoals = m.hostGoals;
//      this->guestGoals = m.guestGoals;
//  }
//public:
//
//   Match(const Team &host=NULL, const Team &guest=NULL, int hostGoals=0, int guestGoals=0) {
//       this->host = new Team(host);
//       this->guest = new Team(guest);
//       this->hostGoals = hostGoals;
//       this->guestGoals = guestGoals;
//   }
//
//    Team *getHost() const;
//
//    Team *getGuest() const;
//
//    Match(const Match &m) {
//       copy(m);
//   }
//
//   friend bool isTip(const Match &m, const char c);
//
//   ~Match(){}
//};
//
//bool isTip(const Match &m, const char tip){
//    if (m.hostGoals == m.guestGoals && tip == 'X') return true;
//    else if (m.hostGoals > m.guestGoals && tip == '1') return true;
//    else if (m.hostGoals < m.guestGoals && tip == '2') return true;
//    else return false;
//}
//
//Team *Match::getHost() const {
//    return host;
//}
//
//Team *Match::getGuest() const {
//    return guest;
//}

void sort(Team *team_array, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(team_array[i].getTeamName(), team_array[j].getTeamName()) > 0) {
                Team pom = team_array[i];
                team_array[i] = team_array[j];
                team_array[j] = pom;
            }
        }
    }
}

int main() {

    int n;

    char team_name[100];
    char stadium_name[50];
    char city[50];

    cout<<"Vnesete broj na timovi: " << endl;
    cin>>n;
    Team *team_array = new Team[n];

    for (int i = 0; i < n; ++i) {
        cin>>team_name;
        cin>>stadium_name;
        cin>>city;
        team_array[i] = Team(team_name, stadium_name, city);
    }

    sort(team_array, n);

    for (int i = 0; i < n; ++i) {
        cout<<"Team: " + (i+1) << team_array[i].getTeamName()<<endl;
    }

    delete [] team_array;
    return 0;
}
