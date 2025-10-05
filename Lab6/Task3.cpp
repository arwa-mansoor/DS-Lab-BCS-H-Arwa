#include <iostream>
using namespace std;

class Queue{
    public:
        int *arr;
        int rear;
        int front;
        int size;

        Queue(int size) : rear(-1), front(-1), size(size) {
            arr = new int[size];
        }

        void enqueue(int data)
        {
            if (rear >= size - 1)
            {
                cout << "Queue Overflow!\n";
                return;
            }
            if (front == -1)
            {
                front = 0;
            }
            arr[++rear] = data;
            cout << data << " is added to the queue\n";
        }

        int dequeue()
        {
            if (front == -1 || front > rear)
            {
                cout << "Queue is Empty!\n";
                return 0;
            }
            int value = arr[front++];
            cout << value << " is removed from the queue\n";
            if (front > rear)
            {
                front = rear = -1;
            }
            return value;
        }

        void displayQueue(){
            if(front == -1){
                cout << "Queue is Empty!\n";
                return;
            }
            for(int i = front; i <= rear; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        bool isEmpty(){
            if(front == -1 && rear == -1){
                return true;
            }
            return false;
        }

        bool isFull()
        {
            if(rear == size - 1){
                return true;
            }
            return false;
        }
};

int main(){
    Queue q(5);
    q.dequeue();
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.displayQueue();
    q.dequeue();
    q.dequeue();
    q.displayQueue();
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is queue full? " << (q.isFull() ? "Yes" : "No") << endl;
    return 0;
}
