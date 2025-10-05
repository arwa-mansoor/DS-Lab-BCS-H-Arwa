#include <iostream>
using namespace std;

class CircularQueue
{
    int *arr;
    int front, rear;
    int size;

public:
    CircularQueue(int size) : size(size), front(-1), rear(-1)
    {
        arr = new int[size];
    }

    bool isFull()
    {
        if(front == (rear + 1) % size){
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if(front == -1){
            return true;
        }
        return false;
    }

    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue Overflow!\n";
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        arr[rear] = data;
        cout << data << " is added to the queue\n";
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!\n";
            return -1;
        }
        int value = arr[front];
        if (front == rear)
        {
            front = rear = -1; // Queue becomes empty
        }
        else
        {
            front = (front + 1) % size;
        }
        cout << value << " is removed from the queue\n";
        return value;
    }

    void displayQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue contents: ";
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }

    ~CircularQueue()
    {
        delete[] arr;
    }
};

int main()
{
    CircularQueue q(5);
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
    q.enqueue(60);
    q.enqueue(70);
    q.displayQueue();
    return 0;
}
