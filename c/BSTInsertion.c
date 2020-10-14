// Binary Tree transversal in c
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

// now there are three types of transversal
// inorder transversal
void inorderTransversal(struct node* root){

    if (root == NULL)
        return;
    
    inorderTransversal(root->left);
    printf("%d -> ", root->data);
    inorderTransversal(root->right);
}

// Preorder traversal
void preorderTraversal(struct node* root) {
  if (root == NULL) return;
  printf("%d ->", root->data);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(struct node* root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ->", root->data);
}

// creating a new node
struct node* createNode(int value){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}

// inserting on the left of the node
struct node* insertLeft(struct node* root, int value){
    root->left = createNode(value); // will create a new node
    return root->left;
}

// inserting on right of the node
struct node* insertRight(struct node* root, int value){
    root->right = createNode(value); // will create a new node
    return root->right;
}

// main function begins
int main(){
    struct node* root = createNode(1);
    insertLeft(root, 2);
    insertRight(root, 3);
    insertLeft(root->left, 4);

    printf("Inorder transversal \n");
    inorderTransversal(root);

    return 0; // completing successfully
}