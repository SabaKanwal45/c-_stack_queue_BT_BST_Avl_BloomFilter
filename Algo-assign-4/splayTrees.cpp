// The code is adopted from http://goo.gl/SDH9hH 
#include<stdio.h> 
#include<stdlib.h> 
#include <string> 
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
  
// An AVL tree node 

int total_rotations = 0;
int total_comparsions = 0;
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
  
/* Helper function that allocates a new node with the given key and 
    NULL left and right pointers. */
struct node* newNode(int key) 
{ 
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->key   = key; 
    node->left  = node->right  = NULL; 
    return (node); 
} 
  
// A utility function to right rotate subtree rooted with y 
// See the diagram given above. 
struct node *rightRotate(struct node *x) 
{ 
    struct node *y = x->left; 
    x->left = y->right; 
    y->right = x; 
    total_rotations +=1;
    return y; 
} 
  
// A utility function to left rotate subtree rooted with x 
// See the diagram given above. 
struct node *leftRotate(struct node *x) 
{ 
    struct node *y = x->right; 
    x->right = y->left; 
    y->left = x; 
    total_rotations +=1;
    return y; 
} 

  
// This function brings the key at root if key is present in tree. 
// If key is not present, then it brings the last accessed item at 
// root.  This function modifies the tree and returns the new root 
struct node *splay(struct node *root, int key) 
{ 
    // Base cases: root is NULL or key is present at root 
    if (root == NULL || root->key == key) 
        return root; 
  
    // Key lies in left subtree 
    if (root->key > key) 
    {   total_comparsions +=1;
        // Key is not in tree, we are done 
        if (root->left == NULL) return root; 
  
        // Zig-Zig (Left Left) 
        if (root->left->key > key) 
        {
        	total_comparsions +=1;
            //total_rotations +=1;
            
            // First recursively bring the key as root of left-left 
            root->left->left = splay(root->left->left, key); 
  
            // Do first rotation for root, second rotation is done after else 
            root = rightRotate(root); 
        } 
        else if (root->left->key < key) // Zig-Zag (Left Right) 
        {
        	total_comparsions +=1;
            //total_rotations +=1;
            // First recursively bring the key as root of left-right 
            root->left->right = splay(root->left->right, key); 
            // Do first rotation for root->left 
            if (root->left->right != NULL) 
                root->left = leftRotate(root->left); 
        } 
  
        // Do second rotation for root 
        return (root->left == NULL)? root: rightRotate(root); 
    } 
    else // Key lies in right subtree 
    { 
        // Key is not in tree, we are done 
        total_comparsions +=1;
        if (root->right == NULL) return root; 
  
        // Zag-Zig (Right Left) 
        if (root->right->key > key) 
        {
        	total_comparsions +=1;
            //total_rotations +=1; 
            // Bring the key as root of right-left 
            root->right->left = splay(root->right->left, key); 
            // Do first rotation for root->right 
            if (root->right->left != NULL) 
                root->right = rightRotate(root->right); 
        } 
        else if (root->right->key < key)// Zag-Zag (Right Right) 
        {
        	total_comparsions +=1;
            //total_rotations +=1;
            // Bring the key as root of right-right and do first rotation 
            root->right->right = splay(root->right->right, key); 
            root = leftRotate(root); 
        } 
  
        // Do second rotation for root 
        return (root->right == NULL)? root: leftRotate(root); 
    } 
} 
  
// The search function for Splay tree.  Note that this function 
// returns the new root of Splay Tree.  If key is present in tree 
// then, it is moved to root. 
struct node *search(struct node *root, int key) 
{ 
    return splay(root, key); 
} 
  
// A utility function to print preorder traversal of the tree. 
// The function also prints height of every node 
void preOrder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        printf("%d ", root->key); 
        preOrder(root->left); 
        preOrder(root->right); 
    } 
} 
struct node *insert(struct node *root, int k) 
{ 
    // Simple Case: If tree is empty 
    if (root == NULL) return newNode(k); 
  
    // Bring the closest leaf node to root 
    root = splay(root, k); 
  
    // If key is already present, then return 
    if (root->key == k) return root; 
  
    // Otherwise allocate memory for new node 
    struct node *newnode  = newNode(k); 
  
    // If root's key is greater, make root as right child 
    // of newnode and copy the left child of root to newnode 
    if (root->key > k) 
    { 
        newnode->right = root; 
        newnode->left = root->left; 
        root->left = NULL; 
    } 
  
    // If root's key is smaller, make root as left child 
    // of newnode and copy the right child of root to newnode 
    else
    { 
        newnode->left = root; 
        newnode->right = root->right; 
        root->right = NULL; 
    } 
  
    return newnode; // newnode becomes new root 
} 
  
/* Drier program to test above function*/
int main() 
{ 
	/* Let us create following BST 
			50 
		/	 \ 
		30	 70 
		/ \ / \ 
	20 40 60 80 */
	ifstream myfile ("data-100000.txt");
	struct node *root =NULL;
	int i = 0;
	string line;
	if (myfile.is_open())
	{
		while ( getline (myfile,line)){
			root = insert(root,stoi(line));
			i+=1;
		}
		cout<<"total nodes in tree"<<i<<endl;
		ifstream searchdata ("zipf-100000.txt");
		i= 0;
		total_comparsions = 0;
		total_rotations = 0;
		int start_s=clock();
		if (searchdata.is_open())
		{
			while ( getline (searchdata,line)){
				search(root, stoi(line));
				i+=1;
			}
			cout<<"total searched items"<<i<<endl;
			cout<<"total comparisons: "<<total_comparsions<<endl;
			cout<<"Avg comparison per search operation: "<<total_comparsions/i<<endl;
			cout<<"total rotations: "<<total_rotations<<endl;
			cout<<"Avg rotations per search operation: "<<total_rotations/i<<endl;
		}
		int stop_s=clock();
		cout << "Execution time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
		cout << "Execution time per search operation " << ((stop_s-start_s)/double(CLOCKS_PER_SEC)*1000)/i<< endl;

	}
	myfile.close();

	// print inoder traversal of the BST 

	return 0; 
} 

