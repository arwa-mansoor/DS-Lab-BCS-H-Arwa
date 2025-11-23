#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int val) : data(val), height(1), left(NULL), right(NULL) {}
};

int height(Node *root)
{
    if (!root)
        return -1;
    return 1 + max(height(root->left), height(root->right));
}

Node *rightRotation(Node *x)
{
    Node *y = x->left;
    Node *temp = y->right;

    y->right = x;
    x->left = temp;

    x->height = height(x);
    y->height = height(y);

    return y;
}

Node *leftRotation(Node *x)
{
    Node *y = x->right;
    Node *temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = height(x);
    y->height = height(y);

    return y;
}

int balanceFactor(Node *node)
{
    if (!node)
        return 0;
    return height(node->left) - height(node->right);
}

Node *insert(Node *root, int val)
{
    if (!root)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    else
        return root;

    root->height = height(root);
    cout << "Tree Height after inserting " << val << ": " << root->height << endl;
    cout << "Balance Factor of " << root->data << ": " << balanceFactor(root) << endl;

    int bf = balanceFactor(root);

    if (bf > 1 && val < root->left->data)
    {
        cout << "Right Rotation\n";
        return rightRotation(root);
    }
    if (bf < -1 && val > root->right->data)
    {
        cout << "Left Rotation\n";
        return leftRotation(root);
    }
    if (bf > 1 && val > root->left->data)
    {
        root->left = leftRotation(root->left);
        cout << "Left Rotation on Left Child, then Right Rotation\n";
        return rightRotation(root);
    }
    if (bf < -1 && val < root->right->data)
    {
        root->right = rightRotation(root->right);
        cout << "Right Rotation on Right Child, then Left Rotation\n";
        return leftRotation(root);
    }
    return root;
}

Node *findMin(Node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

Node *deleteNode(Node *root, int key)
{
    if (!root)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        else if (!root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    root->height = height(root);
    cout << "Tree Height after deleting " << key << ": " << root->height << endl;
    cout << "Balance Factor of " << root->data << ": " << balanceFactor(root) << endl;

    int bf = balanceFactor(root);

    if (bf > 1 && balanceFactor(root->left) >= 0)
    {
        cout << "Right Rotation\n";
        return rightRotation(root);
    }
    if (bf > 1 && balanceFactor(root->left) < 0)
    {
        root->left = leftRotation(root->left);
        cout << "Left Rotation on Left Child, then Right Rotation\n";
        return rightRotation(root);
    }
    if (bf < -1 && balanceFactor(root->right) <= 0)
    {
        cout << "Left Rotation\n";
        return leftRotation(root);
    }
    if (bf < -1 && balanceFactor(root->right) > 0)
    {
        root->right = rightRotation(root->right);
        cout << "Right Rotation on Right Child, then Left Rotation\n";
        return leftRotation(root);
    }
    return root;
}

void print(Node *root)
{
    if (!root)
        return;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

int main()
{
    Node *root = NULL;

    int rollNumbers[] = {50, 30, 70, 20, 40, 60, 80};
    for (int val : rollNumbers)
    {
        cout << "\nInserting " << val << "\n";
        root = insert(root, val);
        cout << "Inorder Traversal: ";
        print(root);
        cout << "\n";
    }

    int deletions[] = {20, 30, 50};
    int n = sizeof(deletions) / sizeof(deletions[0]);

    for (int i = 0; i < n; i++)
    {
        int key = deletions[i];
        cout << "\nDeleting " << key << "\n";
        root = deleteNode(root, key);
        cout << "Inorder Traversal: ";
        print(root);
        cout << "\n";
    }

    return 0;
}
