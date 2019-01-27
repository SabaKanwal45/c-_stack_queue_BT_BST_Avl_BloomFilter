#ifndef NODE_IMPL_H
#define NODE_IMPL_H
#include "node.h"

template<typename T>
TreeNode<T>::TreeNode()
{

}
template<typename T>
TreeNode<T>::TreeNode(T val)
{

}
template<typename T>
bool TreeNode<T>::IsRoot()
{

}
template<typename T>
bool TreeNode<T>::IsExternal()
{

}
template<typename T>
int TreeNode<T>::GetHeight()
{

}
template<typename T>
int TreeNode<T>::GetDepth()
{

}
template<typename T>
T TreeNode<T>::GetValue()
{

}
template<typename T>
void TreeNode<T>::SetValue (T val)
{

}
template<typename T>
bool TreeNode<T>::AddChild(T val)
{

}
template<typename T>
void TreeNode<T>::DeleteChild(T val)
{

}
template<typename T>
TreeNode<T>* TreeNode<T>::SearchChild(T val)
{

}
template<typename T>
TreeNode<T>* TreeNode<T>::GetParent()
{

}
template <typename T>
TreeNode<T>* TreeNode<T>::GetNextSibling()
{

}
template <typename T>
TreeNode<T>* TreeNode<T>::GetPrevSibling()
{

}
template <typename T>
TreeNode<T>* TreeNode<T>::GetFirstChild()
{

}
#endif