#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

class Triangle {
protected:
    int a, b, c;
public:
    Triangle(int a = 0, int b = 0, int c = 0) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    int perimeter() {
        return a+b+c;
    }

    float area() {
        float s = (a+b+c)/2.0;
        return sqrt(s * (s-a) * (s-b) * (s-c));
    }

    ~Triangle(){}
};

int main() {

    int a, b, c;

    cout<<"Enter triangle information:"<<endl;
    cin>>a>>b>>c;

    Triangle t(a, b, c);

    cout<<"Perimeter: " << t.perimeter() << endl;
    cout<<"Area: " << t.area() << endl;

    return 0;
}
