#ifndef BST_IMPL
#define BST_IMPL
#include "bst.h"
#include<iostream>
using namespace std;
template<typename T>
BinTreeNode<T>* BST<T>::Insert(T val)
{
	BinTreeNode<T>* temp = this->root;
	BinTreeNode<T>* parent = NULL;
	if(temp){
		while(!temp->isExternal()){
			if(temp->Value() == val){
				return NULL;
			}
			else if(temp->Value() > val){
				parent = temp;
				temp=temp->Left();
			}
			else{
				parent =temp;
				temp=temp->Right();
			}
		}
		
	}
	BinTreeNode<T>* newNode = new BinTreeNode<T>(val);
	BinTreeNode<T>* leftNode = new BinTreeNode<T>();
	BinTreeNode<T>* rightNode=new BinTreeNode<T>();
	rightNode->SetParent(newNode);
	leftNode->SetParent(newNode);
	newNode->SetLeftChild(leftNode);
	newNode->SetRightChild(rightNode);
	if(parent==NULL){
		this->root = newNode;
	}
	else if(parent->Value()>val){
		parent->SetLeftChild(newNode);
	}
	else{
		parent->SetRightChild(newNode);
	}
	newNode->SetParent(parent);
	this->size+=3;
	return newNode;
}

template<typename T>
BinTreeNode<T>* BST<T>::Delete(T val)
{
	BinTreeNode<T>* temp = Search(val);
	BinTreeNode<T>* parent =NULL;
	if(temp!=NULL){
		parent = temp->Parent();
		if(temp->Left()->isExternal()){
			this->RemoveAboveExternal(temp->Left());
		}
		else if(temp->Right()->isExternal()){
			this->RemoveAboveExternal(temp->Right());
		}
		else{
			BinTreeNode<T>* helper = temp->Left();
			while(!helper->isExternal()){
				helper = helper->Right();
			}
			temp->SetValue(helper->Parent()->Value());
			this->RemoveAboveExternal(helper);
		}
	}
	
	
}

template<typename T>
BinTreeNode<T>* BST<T>::Search(T val)
{
	BinTreeNode<T>* temp = this->root;
	if(temp){
		while(!temp->isExternal()){
			if(temp->Value() == val){
			return temp;
			}
			else if(temp->Value() > val){
				temp=temp->Left();
			}
			else{
				temp=temp->Right();
			}
		}
		
	}
	return NULL;
	
}
#endif
