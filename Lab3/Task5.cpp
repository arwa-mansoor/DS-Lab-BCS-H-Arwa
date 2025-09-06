#include <iostream>
using namespace std;

class Node{
    public:
        Node *next;
        int data;

        Node() : next(NULL), data(0) {}
        Node(int value) : next(NULL), data(value) {}
};

class SinglyLinkedList{
    public:
        Node *head;
        Node *tail;

        SinglyLinkedList() : head(NULL), tail(NULL) {}
        SinglyLinkedList(const SinglyLinkedList &other) : head(NULL), tail(NULL){
            Node *temp = other.head;
            while (temp != NULL){
                append(temp->data);
                temp = temp->next;
            }
        }

        void append(int value){
            Node *newNode = new Node(value);
            if (head == NULL){
                head = tail = newNode;
                return;
            }
            tail->next = newNode;
            tail = newNode;
        }

        void displayLinkedList(bool isCircular = false){
            if (head == NULL){
                return;
            }  

            Node *temp = head;
            do{
                cout << temp->data;
                temp = temp->next;
                if (temp != head && temp != NULL){
                    cout << " -> ";
                }
            } while (temp != head && temp != NULL);
            cout << endl;
        }

        void conversionToCircular(){
            if (head != NULL && tail != NULL){
                tail->next = head;
            }
        }

        void conversionToSingly(){
            if (head != NULL && tail != NULL && tail->next == head){
                tail->next = NULL;
            }
        }

        ~SinglyLinkedList(){
            if (head != NULL && tail != NULL && tail->next == head){
                tail->next = NULL;
            }

            Node *temp = head;
            while (temp != NULL){
                Node *current = temp;
                temp = current->next;
                delete current;
            }
        }
};

class DoublyNode
{
    public:
        int data;
        DoublyNode *next;
        DoublyNode *previous;

        DoublyNode() : data(0), next(NULL), previous(NULL) {}
        DoublyNode(int value) : data(value), next(NULL), previous(NULL) {}
};

class DoublyLinkedList
{
    public:
        DoublyNode *head;
        DoublyNode *tail;

        DoublyLinkedList() : head(NULL), tail(NULL) {}

        void append(int value){
            DoublyNode *newNode = new DoublyNode(value);
            if (head == NULL){
                head = tail = newNode;
                return;
            }
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }

        void displayForward(){
            DoublyNode *temp = head;
            while (temp != NULL){
                cout << temp->data;
                temp = temp->next;
                if (temp != NULL){
                    cout << " <-> ";
                }
            }
            cout << endl;
        }

        void displayBackward(){
            DoublyNode *temp = tail;
            while (temp != NULL){
                cout << temp->data;
                temp = temp->previous;
                if (temp != NULL){
                    cout << " <-> ";
                }   
            }
            cout << endl;
        }

        ~DoublyLinkedList(){
            DoublyNode *temp = head;
            while (temp != NULL){
                DoublyNode *current = temp;
                temp = temp->next;
                delete current;
            }
        }
};

DoublyLinkedList conversionToDoubly(SinglyLinkedList list){
    DoublyLinkedList doublyList;
    if (list.head == NULL){
        return doublyList;
    }
    Node *temp = list.head;
    while (temp){
        doublyList.append(temp->data);
        temp = temp->next;
    }
    return doublyList;
}

int main(){
    SinglyLinkedList l1;
    int n, value;
    cout << "Enter the total number of integers in the list: ";
    cin >> n;
    for (int i = 0; i < n; i++){
        cout << "Enter the value: ";
        cin >> value;
        l1.append(value);
    }
    cout << "Singly List: ";
    l1.displayLinkedList();

    DoublyLinkedList l3 = conversionToDoubly(l1);
    cout << "Doubly List Forward: ";
    l3.displayForward();
    cout << "Doubly List Backward: ";
    l3.displayBackward();

    SinglyLinkedList l2 = l1;
    l2.conversionToCircular();
    cout << "Circular List: ";
    l2.displayLinkedList(true);

    return 0;
}
