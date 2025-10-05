#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        struct Node *next;
        Node() : next(NULL), data(-1){}
};

class Stack{
    public:
        Node *top;
        Stack() : top(NULL) {}
        void push(int data){
            Node *temp = new Node();
            if(!temp){
                cout << "Heap Overflow\n";
                return;
            }
            temp->data = data;
            temp->next = top;
            top = temp;
            cout << data << " is pushed into the stack\n";
        } 

        int pop(){
            if(top == NULL){
                cout << "Stack is Empty!\n";
                return 0;
            }
            Node *temp = top;
            int value = temp->data;
            top = top->next;
            delete temp;
            cout << value << " is popped out of the stack\n";
            return value;
        }

        int peek(){
            if(top == NULL){
                cout << "Stack is Empty!\n";
                return 0;
            }
            return top->data;
        }

        void displayStack(){
            if(top == NULL){
                cout << "Stack is empty!\n";
                return;
            }
            Node *temp = top;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main(){
    Stack s1;
    s1.pop();
    s1.peek();
    s1.push(10);
    s1.push(20);
    s1.push(25);
    cout << "Top element is: " << s1.peek() << endl;
    s1.pop();
    s1.push(30);
    s1.displayStack();

    return 0;
}
