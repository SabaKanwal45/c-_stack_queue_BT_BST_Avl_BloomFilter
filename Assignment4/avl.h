#ifndef AVLTREE
#define AVLTREE
#include "bst_impl.h"
template <typename T>
class AVL : public BST<T>
{
	private:
		void Rotate(BinTreeNode<T>* p);		
		bool isValid(BinTreeNode<T>* p);
	public:
		bool isValid();
		BinTreeNode<T>* Insert(T val);
		BinTreeNode<T>* Delete(T val);
};
#endif