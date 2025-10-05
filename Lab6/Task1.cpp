#include <iostream>
using namespace std;

class Stack{
    int size;
    int top;
    int *arr;

    public:
    Stack(int size) : size(size), top(-1){
        arr = new int[size];
    }

    bool push(int x){
        if (top >= size - 1){
            cout << "Stack Overflow!\n";
            return false;
        }
        arr[++top] = x;
        cout << x << " is pushed into the stack\n";
        return true;
    }

    int pop(){
        if(top < 0){
            cout << "Stack Underflow!\n";
            return 0;
        }
        int value = arr[top--];
        cout << value << " is popped out of the stack\n";
        return value;
    }

    int peek(){
        if(top < 0){
            cout << "Stack is empty!\n";
            return 0;
        }
        return arr[top];
        
    }

    void displayStack()
    {
        if(top < 0){
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Stack:\n";
        for(int i = top; i > -1; i--){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~Stack()
    {
        delete[] arr;
    }
};

int main(){
    Stack s1(5);
    s1.pop();
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);
    cout << "Top element is: " << s1.peek() << endl;
    s1.pop();
    s1.pop();
    s1.displayStack();
    return 0;
}
