#include <iostream>
using namespace std;

#define MAX 10

struct Process
{
    int id;
    int priority;
};

class Queue
{
    Process arr[MAX];
    int front, rear;

public:
    Queue() : front(-1), rear(-1) {}

    bool isEmpty()
    {
        return front == -1 || front > rear;
    }

    bool isFull()
    {
        return rear == MAX - 1;
    }

    void enqueue(Process p)
    {
        if (isFull())
        {
            cout << "Queue Overflow!\n";
            return;
        }
        if (front == -1)
            front = 0;
        arr[++rear] = p;
        cout << "Process " << p.id << " with priority " << p.priority << " added to queue\n";
    }

    Process dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!\n";
            return {-1, -1};
        }
        return arr[front++];
    }
};

class Stack
{
    Process arr[MAX];
    int top;

public:
    Stack() : top(-1) {}

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX - 1;
    }

    void push(Process p)
    {
        if (isFull())
        {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = p;
        cout << "High-priority process " << p.id << " pushed to execution stack\n";
    }

    Process pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!\n";
            return {-1, -1};
        }
        return arr[top--];
    }
};

int main()
{
    Queue arrivalQueue;
    Stack executionStack;

    arrivalQueue.enqueue({101, 2});
    arrivalQueue.enqueue({102, 3});
    arrivalQueue.enqueue({103, 1});
    arrivalQueue.enqueue({104, 3});
    arrivalQueue.enqueue({105, 2});

    cout << "\nScheduling Execution:\n";

    while (!arrivalQueue.isEmpty())
    {
        Process p = arrivalQueue.dequeue();
        if (p.priority == 3)
        {
            executionStack.push(p);
        }
        else
        {
            cout << "Process " << p.id << " with priority " << p.priority << " executed directly\n";
        }
    }

    cout << "\nExecuting High-Priority Tasks:\n";
    while (!executionStack.isEmpty())
    {
        Process p = executionStack.pop();
        cout << "Executing high-priority process " << p.id << endl;
    }

    return 0;
}
