/******************************************************************************
TREE TRAVERSALS (CPP)

Test case:
Input:
5
1 2 3 4 5

Ouput: (PreOrder, InOrder, PostOrder)
1 2 3 4 5
1 2 3 4 5 
5 4 3 2 1
*******************************************************************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Create tree data structure
class tree
{
public:
    int data;
    tree *left, *right;
};

// Create single Node
tree *createNode(int x)
{
    tree *n = new tree();
    n->data = x;
    (*n).left = NULL;
    n->right = NULL;
    return n;
}

// Create/Insert into BinarySearchTree
tree *binarySearchTree(tree *root, int x)
{
    if (root == NULL)
        return createNode(x);
    if (x < root->data)
        root->left = binarySearchTree(root->left, x);
    else
        root->right = binarySearchTree(root->right, x);

    return root;
}

// Prints Pre-Order Traversal
// 1. Print data, 2. Goto left node 3. Goto right node
void preorderTraversal(tree *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Prints in-Order Traversal
// 1. Goto left node, 2. Print data, 3. Goto right node
void inorderTraversal(tree *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Prints Post-Order Traversal
// 1. Goto left node, 2. Goto right node, 3. Print data
void postorderTraversal(tree *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main()
{
    // Read the size of the array
    int n;
    cin >> n;

    // Read the array elements and create a BST out of it
    tree *root = NULL;
    while (n--)
    {
        int x;
        cin >> x;
        root = binarySearchTree(root, x);
    }

    // Print PreOrder Traversal
    preorderTraversal(root);
    cout << "\n";

    // Print In-Order Traversal
    inorderTraversal(root);
    cout << "\n";

    // Print Post-Order Traversal
    postorderTraversal(root);
    cout << "\n";

    return 0;
}