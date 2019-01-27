#ifndef TREE_IMPL_H
#define TREE_IMPL_H

#include "tree.h"
// Constructor
template<typename T>
Tree<T>::Tree()
{
	
}
// Destructor
template<typename T>
Tree<T>::~Tree()
{
	
}

// Return pointer to root node
template<typename T>
TreeNode<T>* Tree<T>::Root()
{
	
}
// Return true if the tree is empty, false otherwise
template<typename T>
bool Tree<T>::IsEmpty()
{
	
}
// Return the size of the tree
template<typename T>
int Tree<T>::Size()
{
	
}
// Preorder traversal of entire tree
template<typename T>
void Tree<T>::PreOrder()
{
	
}
// Postorder traversal of entire tree
template<typename T>
void Tree<T>::PostOrder()
{
	
}
// Preorder traversal of sub tree rooted at n
template<typename T>
void Tree<T>::PreOrder(TreeNode<T>* p, int depth)
{
		
}
// Postorder traversal of sub tree rooted at n
template<typename T>
void Tree<T>::PostOrder(TreeNode<T>* p, int depth)
{
	
}
// Search and return pointer to the first node storing element with value matching val in the entire tree 
template<typename T>
TreeNode<T>* Tree<T>::Search(T val)
{
	
}
// Search and return pointer to node storing element with value matching val in the subtree rooted at n
template<typename T>
TreeNode<T>* Tree<T>::SearchBelow(TreeNode<T>* n, T val)
{
	
}
template<typename T>
TreeNode<T>* Tree<T>::SearchChildren(TreeNode<T>*n, T val)
{
		
}

template<typename T>
TreeNode<T>* Tree<T>::SearchChildren(T val)
{
	
}

// Insert a child node with element value val below the node parent
template<typename T>
TreeNode<T>* Tree<T>::InsertChild(TreeNode<T>* parent, T val)
{

}
// Delete the child (and the subtree rooted at it) storing element with value matching val below the node n
template<typename T>
void Tree<T>::Delete(TreeNode<T>* n, T val)
{
	
}
// De-allocate all nodes in the tree
template<typename T>
void Tree<T>::Destroy()
{
	
}
// insert a root node, if one does not already exist
template<typename T>
void Tree<T>::InsertRootNode(T val)
{

}

template<typename T>
TreeNode<T>* Tree<T>::InsertChild(T val)
{

}

template<typename T>
void Tree<T>::Deallocate(TreeNode<T>* p)
{

}
// Move to the first child of the node pointed to by cursor. Update cursor or return false if this operation isn't possible.
template<typename T>
bool Tree<T>::MoveDown()
{
	
}
// Move to the next sibling. Update cursor or return false if this operation isn't possible
template<typename T>
bool Tree<T>::MoveRight()
{
	
}

// Move to the parent of the node pointed to by cursor. Update cursor or return false if this operation isn't possible.
template<typename T>
bool Tree<T>::MoveUp()
{
	
}
// Move to the previous sibling. Update cursor or return false if this operation isn't possible
template<typename T>
bool Tree<T>::MoveLeft()
{
	
}

// Return a pointer to the node pointed to by cursor
template<typename T>
TreeNode<T>* Tree<T>::GetNode()
{
	
}
template<typename T>
void Tree<T>::ResetCursor()
{
	
}
#endif