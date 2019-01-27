#ifndef TREE_H
#define TREE_H

#include "node_impl.h"

	template <typename T>
	class Tree
	{
	private:
		TreeNode<T>* root;
		TreeNode<T>* cursor;
		int size;
	public:
		// Constructor
		Tree();
		// Destructor
		~Tree();
		// Helper function for the destructor
		void Deallocate(TreeNode<T>* p);
		// Return pointer to root node
		TreeNode<T>* Root();
		// Return true if the tree is empty, false otherwise
		bool IsEmpty();
		// Return the number of nodes in the tree
		int Size();
		// Preorder traversal of entire tree
		void PreOrder();
		// Postorder traversal of entire tree
		void PostOrder();
		// Preorder traversal of sub tree rooted at n
		void PreOrder(TreeNode<T>* n, int depth);
		// Postorder traversal of sub tree rooted at n
		void PostOrder(TreeNode<T>* n, int depth);
		// Search and return pointer to the first node storing element with value matching val in the entire tree 
		TreeNode<T>* Search(T val);
		// Search and return pointer to the first node storing element with value matching val in the subtree rooted at n
		TreeNode<T>* SearchBelow(TreeNode<T>* n, T val);
		// Search for a node with the value val among the children of the node n
		TreeNode<T>* SearchChildren(TreeNode<T>*n, T val);
		// Search for a node with the value val among the children of the node cursor
		TreeNode<T>* SearchChildren(T val);
		// Insert a child node with element value val below the node parent. 
		// Return a pointer to that node.
		// A node with that value might already exist. If so, don't create a new node. Just return the existing node's pointer
		TreeNode<T>* InsertChild(TreeNode<T>* parent, T val);
		// Insert a child node with value val under the node pointed to by cursor.
		// Return a pointer to the node.
		// A node with that value might already exist. If so, don't create a new node. Just return the existing node's pointer
		TreeNode<T>* InsertChild(T val);
		// Delete the child (and the subtree rooted at it) storing element with value matching val below the node n
		void Delete(TreeNode<T>* n, T val);
		// De-allocate all nodes in the tree
		void Destroy();
		// insert a root node, if one does not already exist
		void InsertRootNode(T val);
		// Move to the first child of the node pointed to by cursor. Update cursor or return false if this operation isn't possible.
		bool MoveDown();
		// Move to the next sibling. Update cursor or return false if this operation isn't possible
		bool MoveRight();
		// Move to the parent of the node pointed to by cursor. Update cursor or return false if this operation isn't possible.
		bool MoveUp();
		// Move to the previous sibling. Update cursor or return false if this operation isn't possible
		bool MoveLeft();
		// Return a pointer to the node pointed to by cursor
		TreeNode<T>* GetNode();
		// Reset cursor to the root node
		void ResetCursor();
	};
#endif