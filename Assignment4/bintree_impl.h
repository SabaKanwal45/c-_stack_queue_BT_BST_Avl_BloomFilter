#ifndef BINTREEIMPL
#define BINTREEIMPL
#include "bintree.h"
#include<iostream>
using namespace std;
template<typename T>
void BinaryTree<T>::PreOrder(BinTreeNode<T>* p)
{
	if(p!=NULL){
		if (!p->isExternal() ) { 
		cout << p->Value() << " ";
		PreOrder( p->Left() );
		PreOrder( p->Right() );
		}
	}
	
}
template<typename T>
void BinaryTree<T>::PostOrder(BinTreeNode<T>* p)
{
	if(p!=NULL){
		if (!p->isExternal() ) { 
		PostOrder( p->Left() );
		PostOrder( p->Right() );
		cout << p->Value() << " ";
		}
	}
	
}
template<typename T>
void BinaryTree<T>::InOrder(BinTreeNode<T>* p)
{
		if(p!=NULL){
		if (!p->isExternal() ) { 
		InOrder( p->Left() );
		cout << p->Value()  << " ";
		InOrder( p->Right() );
		}
	}
	
}

template<typename T>
void BinaryTree<T>::Destroy(BinTreeNode<T>* p)
{
	if ( p != NULL ) { 
		Destroy( p->Left() );
		Destroy( p->Right() );
		delete p;
    }
	
}

template<typename T>
BinaryTree<T>::BinaryTree()
{
	root = NULL;
	size = 0;
	
}
template<typename T>
BinaryTree<T>::~BinaryTree()
{
	Destroy(this->root);
	
}
template<typename T>
void BinaryTree<T>::PreOrder()
{
	PreOrder(this->root);
}
template<typename T>
void  BinaryTree<T>::PostOrder()
{
	PostOrder(this->root);
}
template<typename T>
void BinaryTree<T>::InOrder()
{
	InOrder(this->root);
}

template<typename T>
int BinaryTree<T>::Size()
{
	return size;
}

template<typename T>
int BinaryTree<T>::Height()
{
	return this->root->Height();
	
}

template<typename T>
bool BinaryTree<T>::isEmpty()
{
	if(size==0){
		return true;
	}
	else{
		return false;
	}

}

template<typename T>
void BinaryTree<T>::AddRoot(T val)
{
	BinTreeNode<T> leftNode = new BinTreeNode<T>();
	BinTreeNode<T> rightNode = new BinTreeNode<T>();
	BinTreeNode<T> Node = new BinTreeNode<T>(val);
	Node.SetRoot(true);
	rightNode.SetParent(Node);
	leftNode.SetParent(Node);
	Node.SetLeftChild(leftNode);
	Node.SetRightChild(rightNode);
	size+=3;

}

template<typename T>
void BinaryTree<T>::ExpandExternal(BinTreeNode<T>* e, T val)
{
	if(e->isExternal()){
		e->SetValue(val);
		e->SetExternal(false);
		BinTreeNode<T>* leftNode = new BinTreeNode<T>();
		BinTreeNode<T>* rightNode = new BinTreeNode<T>();
		rightNode->SetParent(e);
		leftNode->SetParent(e);
		e->SetLeftChild(leftNode);
		e->SetRightChild(rightNode);
		size+=2;
	}
	
}

template<typename T>
void BinaryTree<T>::RemoveAboveExternal(BinTreeNode<T>* e)
{
	if(e->isExternal()){
		BinTreeNode<T>* parent = e->Parent();
		BinTreeNode<T>* grand_parent = NULL;
		BinTreeNode<T>* sibling = NULL;
		if(parent!=NULL){
			grand_parent = parent->Parent();
			if(parent->Left()==e){
				sibling = parent->Right();
			}
			else{
				sibling = parent->Left();
			}
		}
		if(grand_parent==NULL){
			sibling->SetParent(NULL);
			this->root = sibling;
		}
		else{
			if(grand_parent->Left()==parent){
				grand_parent->SetLeftChild(sibling);
			}
			else{
				grand_parent->SetRightChild(sibling);
			}
			sibling->SetParent(grand_parent);
		}
		size-=2;
		
	}
	
	
}
#endif 
