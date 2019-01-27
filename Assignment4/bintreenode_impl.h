#ifndef BINTREENODEIMPL
#define BINTREENODEIMPL
#include "bintreenode.h"
#include<iostream>
using namespace std;
template<typename T>
BinTreeNode<T>::BinTreeNode()
{
	leftChild = NULL;
	parent = NULL;
	rightChild =NULL;
	external = true;
	root = false;
}

template<typename T>
BinTreeNode<T>::BinTreeNode(T val)
{
	leftChild = NULL;
	parent = NULL;
	rightChild =NULL;
	external = false;
	root = false;
	this->val = val;
	
}
template<typename T>
T BinTreeNode<T>::Value()
{
	return val;
	
}
template<typename T>
BinTreeNode<T>* BinTreeNode<T>::Parent()
{
	return parent;
	
}
template<typename T>
BinTreeNode<T>* BinTreeNode<T>::Left()
{
	return leftChild;
	
}
template<typename T>
BinTreeNode<T>* BinTreeNode<T>::Right()
{
	return rightChild;
}
template<typename T>
int BinTreeNode<T>::Depth()
{
	if(this->root){
		return 0;
	}
	else{
		return 1+Depth(this->parent);
	}
	
}
template<typename T>
int BinTreeNode<T>::Height()
{
	if(isExternal()){
		return 0;
	}
	else{
		int max = Left()->Height();
		if(Right()->Height()>max){
			max=Right()->Height();
		}
		return 1+max;
		
	}
	
}

template<typename T>
bool BinTreeNode<T>::isExternal()
{
	return external;
}

template<typename T>
bool BinTreeNode<T>::isRoot()
{
	return root;

}

template<typename T>
void BinTreeNode<T>::SetParent(BinTreeNode<T>* p)
{
	this->parent = p;

}
template<typename T>
void BinTreeNode<T>::SetLeftChild(BinTreeNode<T>* p)
{
	this->leftChild = p;
}
template<typename T>
void BinTreeNode<T>::SetRightChild(BinTreeNode<T>* p)
{
	this->rightChild = p;
}

template<typename T>
void BinTreeNode<T>::SetRoot(bool f)
{
	this->root = f;

}

template<typename T>
void BinTreeNode<T>::SetExternal(bool f)
{
	this->external = f;
}

template<typename T>
void BinTreeNode<T>::SetValue(T val)
{
	this->val = val;

}

template<typename T>
void BinTreeNode<T>::visit()
{
	int depth = Depth();
	for (int i = 0 ; i < depth ; i++)
		cout << " ";
	cout << val << endl;	
}
#endif
