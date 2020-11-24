// C program to delete a node from AVL Tree 
#include<stdio.h> 
#include<stdlib.h> 

// AVL node
struct Node 
{ 
	int key; 
	struct Node *left; 
	struct Node *right; 
	int height; 
}; 

// function  for maximum returning
int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 

// for calculating the tree node
int height(struct Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 

// functionm  to create a new node
struct Node* newNode(int key) 
{ 
	struct Node* node = (struct Node*) 
						malloc(sizeof(struct Node)); 
	node->key = key; 
	node->left = NULL; 
	node->right = NULL; 
	node->height = 1; // new node is initially added at leaf 
	return(node); 
} 

// function  to rotate tree right
struct Node *rightRotate(struct Node *y) 
{ 
	struct Node *x = y->left; 
	struct Node *T2 = x->right; 

	// Perform rotation 
	x->right = y; 
	y->left = T2; 

	// Update heights 
	y->height = max(height(y->left), height(y->right))+1; 
	x->height = max(height(x->left), height(x->right))+1; 

	// Return new root 
	return x; 
} 

// for left rotate
struct Node *leftRotate(struct Node *x) 
{ 
	struct Node *y = x->right; 
	struct Node *T2 = y->left; 

	// Perform rotation 
	y->left = x; 
	x->right = T2; 

	// Update heights 
	x->height = max(height(x->left), height(x->right))+1; 
	y->height = max(height(y->left), height(y->right))+1; 

	// Return new root 
	return y; 
} 

// getting the balance nodfe
int Balance(struct Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
} 

struct Node* insert(struct Node* node, int key) 
{ 
	if (node == NULL) 
		return(newNode(key)); 

	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	else
		return node; 

	node->height = 1 + max(height(node->left), 
						height(node->right)); 

	int balance = Balance(node); 

	// If this node becomes unbalanced, then there are 4 cases 

	// LL
	if (balance > 1 && key < node->left->key) 
		return rightRotate(node); 

	// RR
	if (balance < -1 && key > node->right->key) 
		return leftRotate(node); 

	// LR
	if (balance > 1 && key > node->left->key) 
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 

	// RL
	if (balance < -1 && key < node->right->key) 
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 
	return node; 
} 

// to calculate the minimum value of node
struct Node * minValueNode(struct Node* node) 
{ 
	struct Node* current = node; 

	/* loop down to find the leftmost leaf */
	while (current->left != NULL) 
		current = current->left; 

	return current; 
} 

// delete function for all 3 cases
struct Node* DeleteNode(struct Node* root, int key) 
{ 
	// STEP 1: PERFORM STANDARD BST DELETE 

	if (root == NULL) 
		return root; 

	if ( key < root->key ) 
		root->left = DeleteNode(root->left, key); 

 
	else if( key > root->key ) 
		root->right = DeleteNode(root->right, key); 

	else
	{ 
		// node with only one child or no child 
		if( (root->left == NULL) || (root->right == NULL) ) 
		{ 
			struct Node *temp = root->left ? root->left : 
											root->right; 

			// No child case 
			if (temp == NULL) 
			{ 
				temp = root; 
				root = NULL; 
			} 
			else  
				*root = *temp;
			free(temp); 
		} 
		else
		{ 
			struct Node* temp = minValueNode(root->right); 

			// Copy the inorder successor's data to this node 
			root->key = temp->key; 

			// Delete the inorder successor 
			root->right = DeleteNode(root->right, temp->key); 
		} 
	} 

	// If the tree had only one node then return 
	if (root == NULL) 
	return root; 

	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE 
	root->height = 1 + max(height(root->left), 
						height(root->right)); 

	int balance = Balance(root); 

	if (balance > 1 && Balance(root->left) >= 0) 
		return rightRotate(root); 

	// Left Right Case 
	if (balance > 1 && Balance(root->left) < 0) 
	{ 
		root->left = leftRotate(root->left); 
		return rightRotate(root); 
	} 

	// Right Right Case 
	if (balance < -1 && Balance(root->right) <= 0) 
		return leftRotate(root); 

	// Right Left Case 
	if (balance < -1 && Balance(root->right) > 0) 
	{ 
		root->right = rightRotate(root->right); 
		return leftRotate(root); 
	} 

	return root; 
} 

// for printing the Predorer traversal
void Predorer(struct Node *root) 
{ 
	if(root != NULL) 
	{ 
		printf("%d ", root->key); 
		Predorer(root->left); 
		Predorer(root->right); 
	} 
} 

// main function begins here
int main() 
{ 
	struct Node *root = NULL;
	int data; // the value to be inserted
	printf("\nAVL TREE\n\n");
	printf("Enter the value for contructing the binary tree...\n");
	while(1)
	{
		printf("Enter the number to be inserted: ");
		scanf("%d",&data);
		insert(root,data);
		printf("\nTask completed!\n");
		printf("Due you want to continue(y-1/n-0): ");
		scanf("%d",&data);
		if(data == 0)
			break;
	}

	printf("The final Tree after AVL conversion(presorder traversal): ");
	Predorer(root); 

	while(1)
	{
		printf("Enter the number to be Deleted: ");
		scanf("%d",&data);
		DeleteNode(root, data);
		printf("\nTask completed!\n");
		printf("Due you want to continue(y-1/n-0): ");
		scanf("%d",&data);

		printf("The status of tree after deletion(Predorer traversal): \n");
		Predorer(root);
		if(data == 0)
			break;
	}
	printf("\nExiting...\n");
	return 0; // successfull completion
} 
