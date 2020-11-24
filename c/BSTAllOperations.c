// program for BST insertion, transversal, min, max, searching and deletion

#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *left, *right, *head;
}*pred = NULL, *succ = NULL;

// function for creation of new node
struct node *NewNode(int item){
    struct node *temp = (struct node *)malloc(sizeof(struct node));  // will create a struct node type UD variable temp    
    temp -> info = item;  // data storage
    temp -> left = temp -> right = NULL; // assign the leafs to NULL

    return temp; // will return the creted node
}

/* --Listing out all the displat functions
-----------------------------------------*/

// function for inorder transversal
void Inorder(struct node *root){
    if (root != NULL){
        Inorder(root -> left);
        printf("%d -> ", root -> info);
        Inorder(root -> right);
    }
}

// function for preorder transversal
void Preorder(struct node *root){
    // base case
    if (root == NULL)
        return;
    // printing the leaf
    printf("%d -> ", root -> info);
    // moving to left subtree
    Preorder(root -> left);    
    // moving to right subtree
    Preorder(root -> right);
}

// function to postorder transversal
void Postorder(struct node *root){
    // base case
    if(root == NULL)
        return;
    // moving to left subtree
    Postorder(root -> left);
    // moving to right subtree
    Postorder(root -> right);
    // printing the leaf
    printf("%d -> ", root -> info);
}

/*-------------------------------------
all displpay functions completes here */

// function for insertion of new node
struct node* Insert(struct node* node, int info){    
    // if the tree is empty
    if(node == NULL)
        return NewNode(info);
    // for getting to bottom leaves
    if (info < node -> info)
        node -> left = Insert(node -> left, info);    
    else
        node -> right = Insert(node -> right, info);

    return node;
}

// this function will give the minimum value in the given tree
struct node* MinVal(struct node* node){
    struct node* current = node;
    while(current && current -> left != NULL)  // finding the leftmost leaf
        current = current -> left;

    return current;
}

// function to delete the node
struct node* Delete(struct node* root, int info){
    // for the base case
    if (root == NULL)
        return root;
    // if the node is smaller, will lie on left subtree
    if(info < root -> info)
        root -> left = Delete(root -> left, info);
    // if the node is greater, it will lie on the right subtree
    else if(info > root -> info)
        root -> right = Delete(root -> right, info);
    // if node is same as root key
    else{
        // now here applying all the conditions
        // root with only one child or no child
        if(root -> left == NULL){
            struct node *temp = root -> right;
            free(root);
            return temp;
        }
        else if(root -> right == NULL){
            struct node *temp = root -> left;
            free(root);
            return temp;
        }

        // for node with 2 children
        struct node* temp = MinVal(root -> right);

        // replicating the inorder successor's content to thre node
        root -> info = temp -> info;

        // deleting the successor
        root -> right = Delete(root -> right, temp -> info);
    }
    return root;
}

// function to get the maximum element
int Maximum(struct node* root){
    if(root -> right == NULL)
        return root -> info;
    return Maximum(root -> right);  // for recursive call to reach the right most leaf
}

// function to get the minimum element
int Minimum(struct node* root){
    if(root -> left == NULL)
        return root -> info;
    return Minimum(root -> left);
}

// function  for searching the element
int Search(struct node* root, int x){
    // base case
    if(root == NULL)
        return -1;
    else if(root -> info == x)
        return 1;
    else if(x > root -> info == x)
        return Search(root -> right, x);
    else
        return Search(root -> left, x);
    
}

// combined function to find the both successor and predecessor
void FindPS(struct node* root, int op){
    // Base case
    if (root == NULL)  
        return ;
 
    // for node to be present
    if (root -> info == op){
        // predecessor calculation
        if (root -> left != NULL)
        {
            struct node* temp = root -> left;
            while (temp -> right)
                temp = temp -> right;
            pred = temp ;
        }
 
        // successor calculation
        if (root -> right != NULL)
        {
            struct node* temp = root -> right ;
            while (temp -> left)
                temp = temp -> left ;
            succ = temp ;
        }
        // for the case above all
        return ;
    }
 
    // moving to left subtree for successor calculations
    if (root->info > op){
        succ = root ;
        FindPS(root->left, op) ;
    }
    // moving to right subtree for predecessor calcualtions
    else{
        pred = root ;
        FindPS(root->right, op) ;
    }
}

// main function begins here
int main(){
    printf("------------------\n");
    printf("Binary Search Tree\n");
    printf("------------------\n\n\n");

    // variable declarations here
    int op = 0, flag = 0;  // for storing value and option
    struct node *root = NULL;

    while(1){
        printf("Select the option to be executed - \n");
        printf("1. Insert\n2. Delete\n3. Display(all orders)\n4. Minimum Value\n5. Maximum Value\n6. Search\n7.Inorder Successor\n8.Preorder Predecessor\n9.Exit\n");
        printf("\noption: ");
        scanf("%d", &op);

        // codition checking and menudriven execution
        switch(op){

            // for insertion
            case 1: 
                printf("\nPerforming Insertion...\n");
                printf("Enter the number to be inserted: ");
                scanf("%d", &op);
                root = Insert(root, op);
                printf("\nAfter insertion(inorder): ");
                Inorder(root);
                printf("\n\n");
                break;

            // for deletion    
            case 2:
                printf("\nPerforming deletion...\n");
                printf("Enter the number to be deleted: ");
                scanf("%d", &op);
                root = Delete(root, op);
                printf("After deletion(inorder): ");
                Inorder(root);
                printf("\n\n");
                break;

            // for displaying
            case 3:
                printf("\nDisplaying all methods...\n");
                printf("\nInorder - ");
                Inorder(root);
                printf("\nPreorder - ");
                Preorder(root);
                printf("\nPostorder - ");
                Postorder(root);
                printf("\n\n");
                break;

            // for minimum value
            case 4:
                printf("The minimum value in the tree is: ");
                op = Minimum(root);
                printf("%d\n\n", op);
                break;

            // for maximum value
            case 5:
                printf("The maximum value in the tree is: ");
                op = Maximum(root);
                printf("%d\n\n", op);
                break;

            // for searching node
            case 6:
                printf("Enter the value to be searched for: ");
                scanf("%d", &op);
                op = Search(root, op);
                if(op == 1)
                    printf("The given node exists!\n\n");
                else 
                    printf("The given node doesn't exists!!\n\n");
                break;

            // for inorder successor
            case 7:
                printf("Enter the node whose inorder successor you want: ");
                scanf("%d", &op);

                FindPS(root, op);
                if (succ != NULL)
                    printf("It's successor is: %d\n\n", succ -> info);
                else  
                    printf("Oh!, No successor exists!\n\n");
                break;

            // for inorder predecessor
            case 8:
                printf("Enter the node whose inorder predecessor you want: ");
                scanf("%d", &op);

                FindPS(root, op);
                if (pred != NULL)
                    printf("It's predecessor is: %d\n\n", pred -> info);
                else  
                    printf("Oh!, No predecessor exists!\n\n");
                break;

            // for exiting
            case 9:
                printf("\nExiting from module...\n");
                return 0;  // for successfull completion

            default:
                printf("\nOops!, Wrong option selected, Try again please...\n\n");
                break;
        }
    }
    return 1; // for unsuccessful execution of code
}
 

