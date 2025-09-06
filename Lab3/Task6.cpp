#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *child;

        Node() : data(0), next(NULL), child(NULL) {}
        Node(int value) : data(value), next(NULL), child(NULL) {}
};

class MultilevelLinkedList{
    public:
        Node *head;
        Node *tail;

        MultilevelLinkedList() : head(NULL), tail(NULL) {}

        void appendNode(int value){
            Node *newNode = new Node(value);
            if (head == NULL){
                head = tail = newNode;
                return;
            }
            tail->next = newNode;
            tail = newNode;
        }

        void appendChildNode(int value){
            Node *childNode = new Node(value);
            if (tail->child == NULL){
                tail->child = childNode;
            }
            else{
                Node *childTemp = tail->child;
                while (childTemp->next != NULL){
                    childTemp = childTemp->next;
                }
                childTemp->next = childNode;
            }
        }

        ~MultilevelLinkedList(){
            Node *temp = head;
            while (temp != NULL){
                Node *current = temp;
                temp = temp->next;

                Node *childTemp = current->child;
                while (childTemp != NULL){
                    Node *childCurrent = childTemp;
                    childTemp = childTemp->next;
                    delete childCurrent;
                }

                delete current;
            }
        }
};

void displayLinkedList(MultilevelLinkedList &list){
    Node *temp = list.head;
    while (temp != NULL){
        cout << temp->data;
        if (temp->next != NULL){
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

void flattenMultilevelLinkedList(MultilevelLinkedList &list){
    if (list.head == NULL){
        return;
    }
    Node *current = list.head;

    while (current != NULL){
        if (current->child != NULL){
            Node *nextNode = current->next;
            Node *childTail = current->child;

            while (childTail->next != NULL){
                childTail = childTail->next;
            }
            current->next = current->child;
            current->child = NULL;
            childTail->next = nextNode;

            if (nextNode == NULL){
                list.tail = childTail;
            }
        }
        current = current->next;
    }
}

int main(){
    MultilevelLinkedList list;
    int m, n, value;
    cout << "Enter the total number of Parent Nodes: ";
    cin >> n;
    cout << "\n";
    for(int i = 1; i <= n; i++){
        cout << "Enter the value for Parent Node " << i << ": ";
        cin >> value;
        list.appendNode(value);
        cout << "\n";
        cout << "Enter the total number of Child Nodes for Parent Node " << i << ": ";
        cin >> m;
        cout << "\n";
        for(int i = 1; i <= m; i++){
            cout << "Enter the value for Child Node " << i << ": ";
            cin >> value;
            list.appendChildNode(value);
        }
        cout << "\n";
    }
    cout << "Flattened List: ";
    flattenMultilevelLinkedList(list);
    displayLinkedList(list);

    return 0;
}
