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

int balanceFactor(Node *node)
{
    if (!node)
        return 0;
    return height(node->left) - height(node->right);
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
    int bf = balanceFactor(root);

    if (bf > 1 && val < root->left->data)
        return rightRotation(root);
    if (bf < -1 && val > root->right->data)
        return leftRotation(root);
    if (bf > 1 && val > root->left->data)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    if (bf < -1 && val < root->right->data)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    return root;
}

void rangeQuery(Node *root, int X, int Y)
{
    if (!root)
        return;

    if (root->data > X)
        rangeQuery(root->left, X, Y);

    if (root->data >= X && root->data <= Y)
        cout << root->data << " ";

    if (root->data < Y)
        rangeQuery(root->right, X, Y);
}

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;

    int prices[] = {100, 40, 200, 150, 250, 60, 30};
    int n = sizeof(prices) / sizeof(prices[0]);

    for (int i = 0; i < n; i++)
    {
        root = insert(root, prices[i]);
    }

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << "\n";

    int X = 50, Y = 200;
    cout << "Prices between " << X << " and " << Y << ": ";
    rangeQuery(root, X, Y);
    cout << "\n";

    return 0;
}
