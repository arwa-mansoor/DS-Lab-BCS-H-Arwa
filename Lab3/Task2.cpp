#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int data;

    Node() : next(NULL), data(0) {}
    Node(int value) : next(NULL), data(value) {}
};

class SinglyLinkedList
{
public:
    Node *head;
    Node *tail;

    SinglyLinkedList() : head(NULL), tail(NULL) {}

    void append(int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void displayLinkedList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->next == NULL)
            {
                cout << temp->data << endl;
                return;
            }
            cout << temp->data << " -> ";
            temp = temp->next;
        }
    }

    ~SinglyLinkedList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *current = temp;
            temp = current->next;
            delete current;
        }
    }
};

Node *sortingLinkedList(Node *head1, Node *head2){
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;

    if (head1->data <= head2->data){
        head1->next = sortingLinkedList(head1->next, head2);
        return head1;
    }
    else{
        head2->next = sortingLinkedList(head1, head2->next);
        return head2;
    }
}

SinglyLinkedList mergingLinkedList(SinglyLinkedList &l1, SinglyLinkedList &l2){
    SinglyLinkedList merged;
    merged.head = sortingLinkedList(l1.head, l2.head);

    Node *temp = merged.head;
    while (temp != NULL && temp->next != NULL){
        temp = temp->next;
    }
    merged.tail = temp;

    return merged;
}

    int main()
{

    SinglyLinkedList l1, l2;
    int n, value;
    for(int i = 0; i < 2; i++){
        cout << "Enter the total number of integers in list " << (i ? 'B' : 'A') << ": ";
        cin >> n;
        for(int j = 0; j < n; j++){
            cout << "Enter the value: ";
            cin >> value;
            i ? l2.append(value) : l1.append(value);
        }
    }
    for(int i = 0; i < 2; i++){
        cout << "List " << (i ? 'B' : 'A') << ": ";
        i ? l2.displayLinkedList() : l1.displayLinkedList();
    }
    cout << "Merged List: ";
    mergingLinkedList(l1, l2).displayLinkedList();

    return 0;
}
