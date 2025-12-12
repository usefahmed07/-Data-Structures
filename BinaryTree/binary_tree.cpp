
// Binary Search Tree;

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// ------- Function Prototypes -------
Node* createNode(int value);
Node* insertNode(Node* root, int value);
Node* searchNode(Node* root, int key);
Node* deleteNode(Node* root, int key);
Node* findMin(Node* root);
void inorder(Node* root);

// -----------------------------------

int main() 
{
    Node* root = NULL; // empty tree

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    cout << "Inorder Traversal:\n";
    inorder(root);
    cout << "\n";

    cout << "\nSearching for 40:\n";
    Node* found = searchNode(root, 40);
    if (found != NULL)
        cout << "Found: " << found->data << "\n";
    else
        cout << "Not found\n";

    cout << "\nDeleting 30...\n";
    root = deleteNode(root, 30);

    cout << "Inorder After Deletion:\n";
    inorder(root);
    cout << "\n";

    return 0;
}
 
// ----------- Functions Implementation ------------

// Create new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}



// Insert value in BST
Node* insertNode(Node* root, int value) {

    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);

    else if (value > root->data)
        root->right = insertNode(root->right, value);

    return root;
}



// Search in BST
Node* searchNode(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return searchNode(root->left, key);

    return searchNode(root->right, key);
}



// Find minimum node in right subtree
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}



// Delete node from BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        // Node with 1 or 0 child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with 2 children → find inorder successor
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}


// Inorder Traversal (sorted order)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Done  DS of Term;
