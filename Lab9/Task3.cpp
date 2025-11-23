#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    int height;
    Node(int val) : data(val), left(NULL), right(NULL), height(1) {}
};

int height(Node *root)
{
    return root ? root->height : 0;
}

int balanceFactor(Node *node)
{
    return node ? height(node->left) - height(node->right) : 0;
}

Node *rightRotation(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    cout << "Rotation: Right Rotation\n";
    return x;
}

Node *leftRotation(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    cout << "Rotation: Left Rotation\n";
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
        return root; // no duplicates

    root->height = max(height(root->left), height(root->right)) + 1;
    int bf = balanceFactor(root);

    if (bf > 1 && val < root->left->data)
        return rightRotation(root);
    if (bf < -1 && val > root->right->data)
        return leftRotation(root);
    if (bf > 1 && val > root->left->data)
    {
        root->left = leftRotation(root->left);
        cout << "Rotation: Left-Right Rotation\n";
        return rightRotation(root);
    }
    if (bf < -1 && val < root->right->data)
    {
        root->right = rightRotation(root->right);
        cout << "Rotation: Right-Left Rotation\n";
        return leftRotation(root);
    }

    return root;
}

Node *findMin(Node *root)
{
    while (root->left)
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
        if (!root->left || !root->right)
        {
            Node *temp = root->left ? root->left : root->right;
            if (!temp)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
            delete temp;
        }
        else
        {
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (!root)
        return root;

    root->height = max(height(root->left), height(root->right)) + 1;
    int bf = balanceFactor(root);

    if (bf > 1 && balanceFactor(root->left) >= 0)
        return rightRotation(root);
    if (bf > 1 && balanceFactor(root->left) < 0)
    {
        root->left = leftRotation(root->left);
        cout << "Rotation: Left-Right Rotation\n";
        return rightRotation(root);
    }
    if (bf < -1 && balanceFactor(root->right) <= 0)
        return leftRotation(root);
    if (bf < -1 && balanceFactor(root->right) > 0)
    {
        root->right = rightRotation(root->right);
        cout << "Rotation: Right-Left Rotation\n";
        return leftRotation(root);
    }

    return root;
}

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int highestSeverity(Node *root)
{
    while (root && root->right)
        root = root->right;
    return root ? root->data : -1;
}

int main()
{
    Node *root = NULL;

    int arrivals[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(arrivals) / sizeof(arrivals[0]);

    cout << "Patient Arrivals\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nInserting severity score " << arrivals[i] << "\n";
        root = insert(root, arrivals[i]);
        cout << "Tree Height: " << height(root) << endl;
        cout << "Highest Severity Patient: " << highestSeverity(root) << endl;
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << "\n";
    }

    int discharges[] = {20, 30, 50};
    int m = sizeof(discharges) / sizeof(discharges[0]);

    cout << "\nPatient Discharges\n";
    for (int i = 0; i < m; i++)
    {
        cout << "\nDeleting severity score " << discharges[i] << "\n";
        root = deleteNode(root, discharges[i]);
        cout << "Tree Height: " << height(root) << endl;
        cout << "Highest Severity Patient: " << highestSeverity(root) << endl;
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << "\n";
    }

    return 0;
}
