#ifndef BINTREE
#define BINTREE
#include "bintreenode_impl.h"

template<typename T>
class BinaryTree
{
private:
	void PreOrder(BinTreeNode<T>* p);
	void PostOrder(BinTreeNode<T>* p);
	void InOrder(BinTreeNode<T>* p);
	void Destroy(BinTreeNode<T>* p);
protected:
	BinTreeNode<T>* root;
	int size;
public:
	BinaryTree<T>();
	~BinaryTree<T>();
	void PreOrder();
	void  PostOrder();
	void InOrder();
	int Size();
	int Height();
	bool isEmpty();
	void AddRoot(T val);
	void ExpandExternal(BinTreeNode<T>* e, T val);
	void RemoveAboveExternal(BinTreeNode<T>* e);
};
#endif