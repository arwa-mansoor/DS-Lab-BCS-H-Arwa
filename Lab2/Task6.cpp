#include <iostream>
using namespace std;

class SafePointer{
private:
    int* ptr;

public:
    SafePointer(){
        ptr = NULL;
    }

    SafePointer(int size){
        ptr = new int[size];
    }

    void setValue(int index, int value) {
        if (ptr != NULL) {
            ptr[index] = value;
        }
    }

    int getValue(int index) {
        if (ptr != NULL) {
            return ptr[index];
        }
        return -1;
    }

    void release() {
        delete[] ptr;
        ptr = NULL;
    }
    
    ~SafePointer(){
        delete[] ptr;
    }
};

int main() {
    int n = 5;
    SafePointer marks(n);
    for (int i = 0; i < n; i++) {
        int m;
        cout << "Enter marks of student " << i + 1 << ": ";
        cin >> m;
        marks.setValue(i, m);
    }
    cout << "Student Marks:\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": " << marks.getValue(i) << endl;
    }
    marks.release();

    return 0;
}