#ifndef __QUEUE_CPP
#define __QUEUE_CPP
#include "queue.h"

template <typename T>
Queue<T>::Queue()
{
}
    
template <typename T>
Queue<T>::Queue(Queue<T>& otherQueue):list(otherQueue.list)
{
}

template <typename T>
Queue<T>::~Queue()
{
}

template <typename T>
void Queue<T>::Enqueue(T item)
{
	this->list.InsertAtHead(item);
}

template <typename T>
T Queue<T>::Peek()
{
	Node<T> *temp = this->list.GetTail();
	T value;
	if(temp!=NULL){
		value = temp->GetValue();
	}
	return value;
}

template <typename T>
T Queue<T>::Dequeue()
{
	T value = this->Peek();
	this->list.DeleteTail();
	return value; 
}

template <typename T>
int Queue<T>::Length()
{
	return this->list.Length();
}

#endif
