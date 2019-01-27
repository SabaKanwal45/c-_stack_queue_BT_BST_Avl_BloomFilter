#ifndef __STACK_CPP
#define __STACK_CPP
#include "stack.h"

template <typename T>
Stack<T>::Stack()
{
}
    
template <typename T>
Stack<T>::Stack(Stack<T>& otherStack):list(otherStack.list)
{
}

template <typename T>
Stack<T>::~Stack()
{
}

template <typename T>
void Stack<T>::Push(T item)
{
	this->list.InsertAtHead(item);
}

template <typename T>
T Stack<T>::Peek()
{
	Node<T> *temp = this->list.GetHead();
	T value;
	if(temp != NULL){
		value = temp->GetValue();
	}
	return value;
}

template <typename T>
T Stack<T>::Pop()
{
	Node<T> *temp = this->list.GetHead();
	T value;
	if(temp!=NULL){
		value = temp->GetValue();
		this->list.DeleteHead();
	}
	return value;
	
}

template <typename T>
int Stack<T>::Length()
{
	return this->list.Length();
}

#endif
