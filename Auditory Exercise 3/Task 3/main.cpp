#include <iostream>
#include <cstring>

using namespace std;

class Email {
protected:
    char to[100];
    char from[100];
    char subject[200];
    char body[1000];
public:
    Email(const char *to="", const char *from="",
          const char *subject="", const char *body=""){
        strncpy(this->to, to, strlen(to)-1);
        strncpy(this->from, from, strlen(from)-1);
        strncpy(this->subject, subject, strlen(subject)-1);
        strncpy(this->body, body, strlen(body)-1);
    }

    void printEmail() {
        cout<< "To: " << this->to << endl;
        cout<< "From: " << this->from << endl;
        cout<< "Subject: " << this->subject << endl;
        cout<< "Body: \n" << this->body << endl;
    }

    ~Email(){}
};

bool checkEmail(const char *email) {
    int counter = 0;
    while (*email != 0) {
        if('@' == *email){
            counter++;
        }
        email++;
    }

    return  (1 == counter);
}

int main() {
    char to[100];
    char from[100];
    char subject[200];
    char body[1000];

    cout<<"To: " << endl;
    cin>>to;

    cout<<"From: " << endl;
    cin>>from;

    if(checkEmail(to) && checkEmail(from)) {
        cout<<"Enter subject: "<<endl;
        fgets(subject, 199, stdin);
        cout<<"Enter body:"<<endl;
        fgets(body, 999, stdin);

        Email mail(to, from, subject, body);

        mail.printEmail();
    }
    else{
        cout<<"Invalid email address!!!"<<endl;
    }

    return 0;
}
