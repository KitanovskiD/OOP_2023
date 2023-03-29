#include <iostream>
using namespace std;

class Array {
private:
    int *array;
    int size;
    int capacity;

    void copy(const Array & ref) {
        this->array = new int[ref.capacity];
        this->size=ref.size;
        this->capacity = ref.capacity;

        for (int i = 0; i < ref.size; ++i) {
            this->array[i] = ref.array[i];
        }
    }
public:
    Array(int capacity = 5) {
        this->array = new int[capacity];
        this->size=0;
        this->capacity = capacity;
    }

    Array(const Array &ref) {
        copy(ref);
    }


    void printArray() {
        for (int i = 0; i < this->size; ++i) {
            cout << this->array[i] << " ";
        }

        for (int i = this->size; i < this->capacity; ++i) {
            cout<<"- ";
        }

        cout << endl;
    }

    void add(int element) {
        if(this->capacity == this->size) {
            int *newArray = new int[2*this->capacity];
            for (int i = 0; i < this->size; ++i) {
                newArray[i] = this->array[i];
            }
            delete [] this->array;
            this->array = newArray;
            this->capacity *= 2;
        }
        this->array[this->size] = element;
        this->size++;
    }

    void deleteAll(int element) {
        int newSize = 0;
        for (int i = 0; i < this->size; ++i) {
            if(this->array[i] != element) {
               this->array[newSize++] = this->array[i];
            }
        }
        this->size = newSize;
    }

    void change(int a, int b) {
        for (int i = 0; i < this->size; ++i) {
            if(this->array[i] == a) {
                this->array[i] = b;
            }
        }
    }

    ~Array() {
        delete [] this->array;
    }
};

int main() {

    Array a(5);

    a.add(1);
    a.add(2);
    a.add(1);
    a.add(4);
    a.add(1);
    a.add(6);
    a.add(7);

    a.printArray();

    a.deleteAll(1);

    a.printArray();

    a.change(2, 1);

    a.printArray();

    return 0;
}
