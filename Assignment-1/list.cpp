#ifndef __LIST_CPP
#define __LIST_CPP

#include <cstdlib>
#include "list.h"

template <typename T>
List<T>::List()
{
	this->head = NULL;
	this->tail = NULL;
}

template <typename T>
List<T>::List(List<T>& otherList)
{
	if(otherList.head == NULL){
		this->head = NULL;
		this->tail = NULL;
	}
	else{
		Node<T> *temp = otherList.head;
		Node<T> *prevNode = NULL;
		while(temp != NULL){
			Node<T> *current = new Node<T>(temp->GetValue());
			if(prevNode==NULL){
				this->head = current;
			}
			else{
				prevNode->SetNext(current);
			}
			if(temp->GetNext()==NULL){
				this->tail = current;
			}
			current->SetPrev(prevNode);
			prevNode = current;
			temp= temp->GetNext();
			
		}
		
	}
}

template <typename T>
List<T>::~List()
{
	this->tail = NULL;
	while(this->head!=NULL){
		Node<T> *temp = this->head;
		this->head = this->head->GetNext();
		delete temp;
	}
}

template <typename T>
void List<T>::InsertAtHead(T item)
{
	Node<T> *newNode= new Node<T>(item);
	if(this->head!=NULL){
		newNode->SetNext(this->head);
		this->head->SetPrev(newNode);
	}
	else{
		this->tail = newNode;
	}
	this->head= newNode;
}

template <typename T>
void List<T>::InsertAtTail(T item)
{
	Node<T> *newNode= new Node<T>(item);
	if(this->tail!=NULL){
		newNode->SetPrev(this->tail);
		this->tail->SetNext(newNode);
	}
	else{
		this->head = newNode;
	}
	this->tail= newNode;
}

template <typename T>
void List<T>::InsertAfter(T toInsert, T afterWhat)
{
	Node<T> *temp = this->SearchFor(afterWhat);
	if(temp!=NULL){
		Node<T> *newNode = new Node<T>(toInsert);
		Node<T> *tempnext = temp->GetNext();
		newNode->SetNext(tempnext);
		newNode->SetPrev(temp);
		if(tempnext!=NULL){
			tempnext->SetPrev(newNode);
		}
		temp->SetNext(newNode);
	}
	else{
		this->InsertAtTail(toInsert);
	}
	
}

template <typename T>
Node<T>* List<T>::GetHead()
{
	return this->head;
}

template <typename T>
Node<T>* List<T>::GetTail()
{
	return this->tail;
}

template <typename T>
Node<T> *List<T>::SearchFor(T item)
{
	Node<T> *temp = this->head;
	while(temp!=NULL&&temp->GetValue()!=item){
		temp= temp->GetNext();
	}

	return temp;
}

template <typename T>
void List<T>::DeleteElement(T item)
{
	Node<T> *temp = this->SearchFor(item);
	if(temp!=NULL){
		Node<T> *nextn = temp->GetNext();
		Node<T> *prevn = temp->GetPrev();
		if(nextn!=NULL){
			nextn->SetPrev(prevn);
		}
		else{
			this->tail = prevn;
		}
		if(prevn!=NULL){
			prevn->SetNext(nextn);
		}
		else{
			this->head = nextn;
		}

	}
}

template <typename T>
void List<T>::DeleteHead()
{
	if(this->head!=NULL){
		Node<T> *temp = this->head->GetNext();
		if(temp!=NULL){
			temp->SetPrev(NULL);
		}
		else{
			this->tail = NULL;
		}
		delete this->head;
		this->head = temp;
	}
}

template <typename T>
void List<T>::DeleteTail()
{
	if(this->tail!=NULL){
		Node<T> *temp = this->tail->GetPrev();
		if(temp!=NULL){
			temp->SetNext(NULL);
		}
		else{
			this->head=NULL;
		}
		delete this->tail;
		this->tail = temp;
	}
}

template <typename T>
int List<T>::Length()
{
	Node<T> *temp = this->head;
	int size = 0;
	while(temp!=NULL){
		size+=1;
		temp=temp->GetNext();
	}
	return size;
}

#endif
