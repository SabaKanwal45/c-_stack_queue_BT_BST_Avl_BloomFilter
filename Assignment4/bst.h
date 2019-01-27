#ifndef BST_H
#define BST_H
#include "bintree_impl.h"

template<typename T>
class BST : public BinaryTree<T>
{
public:
	BinTreeNode<T>* Insert(T val);
	BinTreeNode<T>* Delete(T val);
	BinTreeNode<T>* Search(T val);	
};
#endif