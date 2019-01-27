// C program to demonstrate insert operation in binary search tree 
#include<stdio.h> 
#include<stdlib.h> 
#include <string> 
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int total_comparsions = 0;
struct node 
{ 
	int key; 
	struct node *left, *right; 
}; 

// A utility function to create a new BST node 
struct node *newNode(int item) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// A utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
	if (root != NULL) 
	{
		cout<<"Inside print inorder";
	
		inorder(root->left); 
		printf("%d \n", root->key); 
		inorder(root->right); 
	} 
} 

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key) 
{ 
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key); 

	/* Otherwise, recur down the tree */
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 

	/* return the (unchanged) node pointer */
	return node; 
} 

struct node* search(struct node* root, int key) 
{ 
    // Base Cases: root is null or key is present at root 
    if (root == NULL || root->key == key) 
       return root; 
     
    // Key is greater than root's key 
    if (root->key < key){
    	total_comparsions +=1;
    	return search(root->right, key); 
	}
  
    // Key is smaller than root's key 
    return search(root->left, key); 
} 

// Driver Program to test above functions 
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
		}
		int stop_s=clock();
		cout << "Execution time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
		cout << "Execution time per search operation " << ((stop_s-start_s)/double(CLOCKS_PER_SEC)*1000)/i<< endl;

	}
	myfile.close();

	// print inoder traversal of the BST 

	return 0; 
} 

