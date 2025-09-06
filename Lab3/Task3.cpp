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

void reverseNodesInGroups(SinglyLinkedList &list, int k)
{
    if (k <= 1 || list.head == NULL)
    {
        return;
    }
    Node *current = list.head;
    Node *previousTail = NULL;
    Node *newHead = NULL;

    while (current != NULL)
    {
        Node *groupHead = current;
        Node *previous = NULL;
        int count = 0;

        while (current != NULL && count < k)
        {
            Node *next = current->next;
            current->next = previous;
            previous = current;
            current = next;
            count++;
        }

        if (newHead == NULL)
            newHead = previous;

        if (previousTail != NULL)
            previousTail->next = previous;

        previousTail = groupHead;
    }

    list.head = newHead;
    list.tail = previousTail;
}

int main()
{
    SinglyLinkedList l1, l2;
    int n, value, k;
    cout << "Enter the total number of integers in the list: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value: ";
        cin >> value;
        l1.append(value);
    }
    cout << "Enter the groups of size: ";
    cin >> k;
    cout << "List: ";
    l1.displayLinkedList();
    cout << "Reversed List in Groups of " << "k: ";
    reverseNodesInGroups(l1, k);
    l1.displayLinkedList();

    return 0;
}
