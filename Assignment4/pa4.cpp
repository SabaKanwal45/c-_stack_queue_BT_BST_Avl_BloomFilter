#include <iostream>
using namespace std;
#include "avl_impl.h"
int main()
{
	int a[] = {
		8,4,12,2,6,10,14,1,3,5,7,9,11,13,15
	};
	cout << "Starting ..." << endl;
	AVL<unsigned int> t;
	for (int i = 0 ; i < 15 ; i++)
	{
		cout << "Inserting " << i << endl;
		t.Insert(i);
		t.PreOrder();
		cout << "Height is " << t.Height()<<endl;
	}	
	cout << "This is ";
	if (!t.isValid())
		cout << "not ";
	cout << "an AVL tree!" << endl;
	cout << "Pre order..."<<endl;
	t.PreOrder();
	cout << "Post order..." << endl;
	t.PostOrder();
	cout << "In order..." << endl;
	t.InOrder();
	cout << "Deleting 20..."<<endl;
	t.Delete(20);
	cout << "Pre order..." << endl;
	t.PreOrder();
	cout << "Deleting 3..." << endl;
	t.Delete(3);
	cout << "Pre order..." << endl;
	t.PreOrder();
	cout << "Deleting 12..." << endl;
	t.Delete(12);
	cout << "Pre order..." << endl;
	t.PreOrder();
	cout << "Deleting 6..." << endl;
	t.Delete(6);
	cout << "Pre order..." << endl;
	t.PreOrder();
	for (int i = 0 ; i < 15 ; i++)
	{
		cout << "Deleting " << i << endl;
		t.Delete(i);
	}
	for (int i = 0 ; i < 15 ; i++)
	{
		cout << "Inserting " << a[i] << endl;
		t.Insert(a[i]);
		t.PreOrder();
		cout << "Height is " << t.Height()<<endl;
	}	
	cout << "This is ";
	if (!t.isValid())
		cout << "not ";
	cout << "an AVL tree!" << endl;
	cout << "Pre order..."<<endl;
	t.PreOrder();
	cout << "Post order..." << endl;
	t.PostOrder();
	cout << "In order..." << endl;
	t.InOrder();
	cout << "Running big test..." << endl;
	cout << "BST Height\tAVL Height\tAVL Status"<<endl;
	AVL<int> t1;
	BST<int> t2;
	for (int i = 0 ; i < 100 ; i++)
	{
		t1.Insert(i);
		t2.Insert(i);
		cout << t1.Height() << '\t' << t2.Height() << '\t';
		if (!t1.isValid())
			cout <<	"Not ";
		cout << "OK" << endl;
	}
	return 0;
}
