#include <iostream>
using namespace std;

struct Node{
    Node *mother;
    Node *father;
    string name;
    Node(string name) : name(name), mother(NULL), father(NULL){}
};

void displayRoot(Node *root){
    cout << "Root: " << root->name << endl;
}

void displayLeafNodes(Node *root){
    if(root == NULL){
        return;
    }
    if(root->mother == NULL && root->father == NULL){
        cout << root->name << endl;
    }
    displayLeafNodes(root->mother);
    displayLeafNodes(root->father);
}

int treeHeight(Node *root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(treeHeight(root->mother), treeHeight(root->father));
}

void displayLevel(Node *root, int level = 0){
    if(root == NULL){
        return;
    }
    cout << root->name << ": " << level << endl;
    displayLevel(root->mother, level + 1);
    displayLevel(root->father, level + 1);

}

int main(){
    Node *root = new Node("Ali");
    root->mother = new Node("Sara");
    root->father = new Node("Bilal");
    root->mother->mother = new Node("Fatima");
    root->mother->father = new Node("Zain");
    root->father->mother = new Node("Hania");
    root->father->father = new Node("Asim");
    displayRoot(root);
    cout << endl;
    cout << "Leaf Nodes:\n";
    displayLeafNodes(root);
    cout << endl;
    cout << "Height of the Tree: " << treeHeight(root) << endl;
    cout << endl;
    cout << "Level of each Member:\n";
    displayLevel(root);
    return 0;
}
