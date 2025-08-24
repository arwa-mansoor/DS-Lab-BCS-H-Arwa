#include <iostream>
using namespace std;

class Box{
    private:
        int *value;
    public:
        Box(){
            value = new int(0);
        }
        Box(int val){
            value = new int(val);
        }
        Box(const Box &otherBox){
            value = new int(*otherBox.value);
        }
        Box& operator=(const Box& otherBox){
            if (this != &otherBox)
            {
                value = new int(*otherBox.value);
            }
            return *this;

        }
        int getValue() { 
            return *value; 
        }
        void setValue(int val){ 
            *value = val;
        }
        ~Box() {
            cout << "Destructor Called" << endl;
            cout << "Box Value: " << *value << " destroyed\n";
            delete value;
        }
};

int main(){
    Box b1(5);
    cout << "Box 1: " << b1.getValue() << endl;

    Box b2 = b1;
    cout << "Box 2: " << b2.getValue() << endl;

    b2.setValue(10);
    cout << "Box 2: " << b2.getValue() << endl;
}
