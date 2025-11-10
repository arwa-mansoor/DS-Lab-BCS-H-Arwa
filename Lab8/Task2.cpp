#include <iostream>
using namespace std;

struct Node{
    Node *left;
    Node *right;
    string songName;
    int playCount;
    Node(int count, string name) : songName(name), playCount(count), left(NULL), right(NULL){}
};

Node *insertSong(Node *root, int count, string name)
{
    if(root == NULL)
    {
        return new Node(count, name);
    }
    if(count < root->playCount){
        root->left = insertSong(root->left, count, name);
    }
    else if(count > root->playCount){
        root->right = insertSong(root->right, count, name);
    }
    return root;
}

bool searchSong(Node *root, int count){
    if(root == NULL){
        return false;
    }
    if(root->playCount == count){
        cout << root->songName << " with " <<  count << " play count found in the music app\n";
        return true;
    }
    if (count < root->playCount){
        return searchSong(root->left, count);
    }
    else{
        return searchSong(root->right, count);
    }
}

void inorderDisplay(Node *root){
    if(root == NULL){
        return;
    }
    inorderDisplay(root->left);
    cout << root->songName << ": " << root->playCount << " play count\n";
    inorderDisplay(root->right);
}

void postorderDisplay(Node *root){
    if(root == NULL){
        return;
    }
    postorderDisplay(root->left);
    postorderDisplay(root->right);
    cout << root->songName << ": " << root->playCount << " play count\n";
}

Node *findMinimumNode(Node *root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node *deletingSong(Node *root, int count){
    if(root == NULL){
        cout << "No songs in the music app\n";
        return root;
    }
    if(root->playCount < count){
        root->right = deletingSong(root->right, count);
    }
    else if(root->playCount > count){
        root->left = deletingSong(root->left, count);
    }
    else{
        if(root->left == NULL){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = findMinimumNode(root->right);
        root->playCount = temp->playCount;
        root->songName = temp->songName;
        root->right = deletingSong(root->right, temp->playCount);
    }
    return root;
}

int main(){
    Node *root = NULL;

    root = insertSong(root, 50, "ABC");
    root = insertSong(root, 30, "DEF");
    root = insertSong(root, 70, "GHI");
    root = insertSong(root, 20, "JKL");
    root = insertSong(root, 40, "MNO");

    if(!searchSong(root, 20)){
        cout << "No song with " << 20 << " play count found in the music app\n";
    }

    cout << "\nInorder:\n";
    inorderDisplay(root);

    cout << "\nPostorder:\n";
    postorderDisplay(root);

    cout << "\nDeleted song with 70 plays\n";
    root = deletingSong(root, 70);

    cout << "\nUpdated Inorder:\n";
    inorderDisplay(root);
    return 0;
}
