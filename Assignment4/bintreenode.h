#ifndef BINTREENODE
#define BINTREENODE

template <typename T>
class BinTreeNode
{
	protected:	
		T val;
		BinTreeNode<T>* leftChild, *parent, *rightChild;
		bool external;
		bool root;
	public:
		BinTreeNode<T>();
		BinTreeNode<T>(T val);
		T Value();
		BinTreeNode<T>* Parent();
		BinTreeNode<T>* Left();
		BinTreeNode<T>* Right();
		int Depth();
		int Height();
		bool isExternal();
		bool isRoot();
		void SetParent(BinTreeNode<T>* p);
		void SetLeftChild(BinTreeNode<T>* p);
		void SetRightChild(BinTreeNode<T>* p);
		void SetRoot(bool f);
		void SetExternal(bool f);
		void SetValue(T val);
		void visit();
};
#endif
