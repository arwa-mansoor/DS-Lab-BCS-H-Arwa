#include <iostream>
using namespace std;

class Node{
    public:
        Node *next;
        int data;

        Node() : next(NULL), data(0){}
        Node(int value) : next(NULL), data(value){}
};

class SinglyLinkedList{
    public:
        Node *head;
        Node *tail;

        SinglyLinkedList() : head(NULL), tail(NULL){}

        void append(int value){
            Node *newNode = new Node(value);
            if(head == NULL){
                head = tail = newNode;
                return;
            }
            tail->next = newNode;
            tail = newNode;
        }

        void displayLinkedList(){
            Node *temp = head;
            while(temp != NULL){
                if(temp->next == NULL){
                    cout << temp->data << endl;
                    return;
                }
                cout << temp->data << " -> ";
                temp = temp->next;
            }
        }

        ~SinglyLinkedList(){
            Node *temp = head;
            while(temp != NULL){
                Node *current = temp;
                temp = current->next;
                delete current;
            }
        }
};

bool isPalindrome(SinglyLinkedList &list){
    if (list.head == NULL){
        return true;
    }

    Node *middle = list.head, *last = list.head;
    while(last != NULL && last->next != NULL){
        middle = middle->next;
        last = last->next->next;
    }

    Node *previous = NULL, *current = middle, *nxt = NULL;
    while(current != NULL){
        nxt = current->next;
        current->next = previous;
        previous = current;
        current = nxt;
    }
    Node *first = list.head, *second = previous;
    while(second != NULL){
        if(first->data != second->data){
            return false;
        }
        first = first->next;
        second = second->next;
    }
    current = previous;
    previous = NULL;
    while (current != NULL)
    {
        nxt = current->next;
        current->next = previous;
        previous = current;
        current = nxt;
    }
    
    return true;
}

int main(){

    SinglyLinkedList l1, l2;
    int n, value;
    cout << "Enter the total number of integers in the list: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "Enter the value: ";
        cin >> value;
        l1.append(value);
    }
    cout << "List: ";
    l1.displayLinkedList();
    if(isPalindrome(l1)){
        cout << "This list is a palindrome\n";
    }
    else{
        cout << "This list is not a palindrome\n";
    }
    
    return 0;
}
