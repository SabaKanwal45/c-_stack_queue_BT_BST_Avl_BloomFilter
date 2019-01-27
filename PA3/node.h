#ifndef NODE_H
#define NODE_H

template <typename T>
class TreeNode 
{
private:
	T val;
	TreeNode<T>* parent;
	TreeNode<T>* firstChild;
	TreeNode<T>* nextSibling;
	TreeNode<T>* prevSibling;
public:
	TreeNode<T>();
	TreeNode<T>(T val);
	bool IsRoot();
	bool IsExternal();
	int GetHeight();
	int GetDepth();
	T GetValue();
	void SetValue (T val);
	bool AddChild(T val);
	void DeleteChild(T val);
	TreeNode<T>* SearchChild(T val);
	TreeNode<T>* GetParent();
	TreeNode<T>* GetNextSibling();
	TreeNode<T>* GetPrevSibling();
	TreeNode<T>* GetFirstChild();
};
#endif