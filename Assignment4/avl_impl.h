#ifndef AVL_IMPL
#define AVL_IMPL
#include "avl.h"
#include<iostream>
using namespace std;
template<typename T>
void AVL<T>::Rotate(BinTreeNode<T>* p)
{
	while(p!=NULL){
		int lh = p->Left()->Height();
		int rh = p->Right()->Height();
		if(abs(lh-rh)>1){
			break;
		}
		p = p->Parent();
	}
	BinTreeNode<T>* z = p;
	BinTreeNode<T>* y = NULL;
	BinTreeNode<T>* x = NULL;
	BinTreeNode<T>* T0 = NULL;
	BinTreeNode<T>* T1 = NULL;
	BinTreeNode<T>* T2 = NULL;
	BinTreeNode<T>* T3 = NULL;
	T a,b,c;
	if(p!=NULL){
		cout<<"INside balancing........"<<endl;
		int lh = z->Left()->Height();
		int rh = z->Right()->Height();
		cout<<lh<<endl;
		cout<<rh<<endl;
		if(lh-rh>1){
			y = z->Left();
			T0 = z->Right();
			int llh = y->Left()->Height();
			int lrh = y->Right()->Height();
			if(llh-lrh>0){
				x = y->Left();
				T3= y->Right();
			}
			else{
				x = y->Right();
				T3= y->Left();
			}
			
		}
		else if(lh-rh<-1){
			y = z->Right();
			T0 = z->Left();
			int rlh = y->Left()->Height();
			int rrh = y->Right()->Height();
			if(rlh-rrh>0){
				x = y->Left();
				T3= y->Right();
			}
			else{
				x = y->Right();
				T3= y->Left();
			}
		}
		if(abs(lh-rh)>1){
			T1 = x->Left();
			T2 = x->Right();
			if(x->Value()>y->Value()){
				if(x->Value()>z->Value()){
					c = x->Value();
					if(z->Value()>y->Value()){
						b = z->Value();
						a = y->Value();
					}
					else{
						b = y->Value();
						a = z->Value();
					}
				}
				else{
					c = z->Value();
					b = x->Value();
					a = y->Value();
				}
				
			}
			else{
				if(y->Value()>z->Value()){
					c= y->Value();
					if(x->Value()>z->Value()){
						b = x->Value();
						a = z->Value();
					}
					else{
						a = x->Value();
						b = z->Value();
					}
					
				}
				else{
					c = z->Value();
					b = y->Value();
					a = x->Value();
				}
				
			}
			z->SetValue(b);
			if(z->Left()==NULL){
				BinTreeNode<T>* temp = new BinTreeNode<T>(a);
				z->SetLeftChild(temp);
			}
			else if(!z->Left()->isExternal()){
				z->Left()->SetValue(a);
			}
			else{
				z->Left()->SetValue(a);
				z->SetExternal(false);
			}
			if(z->Right()==NULL){
				BinTreeNode<T>* temp = new BinTreeNode<T>(c);
				z->SetRightChild(temp);
			}
			else if(!z->Right()->isExternal()){
				z->Right()->SetValue(c);
			}
			else{
				z->Right()->SetValue(a);
				z->SetExternal(false);
			}
		    T0->SetParent(z->Left());
		    T1->SetParent(z->Left());
		    T2->SetParent(z->Right());
		    T3->SetParent(z->Right());
		    z->Left()->SetLeftChild(T0);
		    z->Left()->SetRightChild(T1);
		    z->Right()->SetLeftChild(T2);
		    z->Right()->SetRightChild(T3);
		}
	}
			
}
template<typename T>
bool AVL<T>::isValid()
{
	return isValid(this->root);	
}

template<typename T>
bool AVL<T>::isValid(BinTreeNode<T>* p)
{	
	int lh;
	int rh;
	if(p == NULL){
		return 1;
	} 
	if(p->isExternal()){
		return 1;
	}
	lh = p->Left()->Height(); 
	rh = p->Right()->Height(); 
	if( abs(lh-rh) <= 1 && isValid(p->Left()) && isValid(p->Left())) 
	return 1; 
	return 0;	
}

template<typename T>
BinTreeNode<T>* AVL<T>::Insert(T val)
{
	BinTreeNode<T>* w = BST<T>::Insert(val);
	/*if (w)
		Rotate(w);*/	
	return w;
}

template<typename T>
BinTreeNode<T>* AVL<T>::Delete(T val)
{
	BinTreeNode<T>* w = BST<T>::Delete(val);
	/*if(w)
		Rotate(w);*/
	return w;	
}
#endif
