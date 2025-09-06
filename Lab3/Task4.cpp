#include <iostream>
using namespace std;

class Node{
public:
    Node *next;
    int data;

    Node() : next(NULL), data(0) {}
    Node(int value) : next(NULL), data(value) {}
};

class CircularLinkedList{
public:
    Node *head;
    Node *tail;

    CircularLinkedList() : head(NULL), tail(NULL) {}

    void append(int value){
        Node *newNode = new Node(value);
        if (head == NULL){
            head = tail = newNode;
            tail->next = head;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }

    void deleteAtPositon(int pos){
        if (pos < 1){
            cout << "Invalid Position\n";
            return;
        }
        if (head == NULL){
            return;
        }
        if (pos == 1){
            Node *deleteNode = head;
            head = head->next;
            if (head == NULL)
            {
                tail = NULL;
            }
            delete deleteNode;
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++){
            temp = temp->next;
        }
        if (temp == NULL){
            cout << "Invalid Position\n";
            return;
        }
        Node *deleteNode = temp->next;
        temp->next = deleteNode->next;
        if (deleteNode == tail){
            tail = temp;
            tail->next = head;
        }
        delete deleteNode;
    }

    void displayLinkedList(){
        if (head == NULL)
            return;
        Node *temp = head;
        do
        {
            cout << temp->data;
            temp = temp->next;
            if (temp != head)
                cout << " -> ";
        } while (temp != head);
        cout << endl;
    }

    ~CircularLinkedList(){
        Node *temp = head;
        while (temp != tail)
        {
            Node *current = temp;
            temp = current->next;
            delete current;
        }
    }
};

int elimination(CircularLinkedList &list, int pos){
    if(list.head == NULL || pos < 1){
        return -1;
    }
    Node *previous = list.tail;
    Node *current = list.head;

    while(current->next != current){
        for (int count = 1; count < pos; count++){
            previous = current;
            current = current->next;
        }
        cout << "Eliminating: " << current->data << endl;
        previous->next = current->next;

        if (current == list.head)
            list.head = current->next;
        if (current == list.tail)
            list.tail = previous;

        delete current;
        current = previous->next;
    }

    list.head = list.tail = current;
    return current->data;
}

int main(){
    CircularLinkedList l1;
    int n, k, pos;
    cout << "Enter the total number of people in the circle: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        l1.append(i);
    }
    cout << "Enter the position to eliminate every person: ";
    cin >> k;
    pos = elimination(l1, k);
    cout << "Position of Survivor: " << pos << endl;
    return 0;
}
