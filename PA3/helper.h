#ifndef HELPER_H
#define HELPER_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
#include "tree_impl.h"

struct Record{
	string storeID, deptID, year, month, day, sales;
};

bool readRecord(string s, Record& r)
{
	string::size_type n1=0, n2;
	string tok;
	Record n;
	// read the store ID
	n2 = s.find(',');
	if (n2!= string::npos)
	{
		tok = s.substr(n1, n2-n1);
		r.storeID=tok;
		s.erase(n1, n2-n1+1);
	}
	else 
		return false;
	n2 = s.find(',');
	if (n2!= string::npos)
	{
		tok = s.substr(n1, n2-n1);
		r.deptID = tok;
		s.erase(n1, n2-n1+1);
	}
	else
		return false;
	n2 = s.find(',');
	if (n2!= string::npos)
	{
		tok = s.substr(n1, n2-n1);
		n2 = s.find('-');
		if (n2!= string::npos)
		{
			tok = s.substr(n1, n2-n1);		
			r.year = tok;
			s.erase(n1, n2-n1+1);
			n2 = s.find('-');
			if (n2!= string::npos)
			{
				tok = s.substr(n1, n2-n1);		
				r.month = tok;
				s.erase(n1, n2-n1+1);
				n2 = s.find(',');
				if (n2!= string::npos)
				{
					tok = s.substr(n1, n2-n1);		
					r.day = tok;
					s.erase(n1, n2-n1+1);
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
	n2 = s.find('.');
	if(n2 != string::npos)
		r.sales = s.substr(n1, n2 - n1);
	else
	{
		n2 = s.find(',');
		if(n2 != string::npos)
			r.sales = s.substr(n1, n2 - n1);
		else
			return false;
	}
	return true;
}

bool ReadFile(string filename, Tree<unsigned long>& t)
{
	TreeNode<unsigned long> *p;
	string line;
	Record r;
	ifstream datafile(filename);
	t.InsertRootNode(0);
	if(datafile.is_open())
	{
		cout << "File opened!" <<endl;
		getline(datafile, line);
		while(getline(datafile, line))
		{
			if (readRecord(line, r))
			{
				// Process the record
				//cout << r.storeID << " " << r.deptID << " " << r.year << " " << r.month << " " << r.day << " " << r.sales << endl;
				p = t.InsertChild(t.Root(), stoi(r.year));
				//cout << "Tree size (year): " << t.Size() << endl;
				if(p != NULL)
				{
					p = t.InsertChild(p, stoi(r.month));
					//cout << "Tree size (month): " << t.Size() << endl;
					if(p != NULL)
					{
						p = t.InsertChild(p, stoi(r.day));
						//cout << "Tree size (day): " << t.Size() << endl;
						if(p != NULL)
						{
							p = t.InsertChild(p, stoi(r.storeID));
							//cout << "Tree size (storeID): " << t.Size() << endl;
							if(p!= NULL)
							{
								p = t.InsertChild(p, stoi(r.deptID));
								//cout << "Tree size (dept): " << t.Size() << endl;
								if(p!= NULL)
								{
									p = t.InsertChild(p, stoi(r.sales));
									//cout << "Tree size (sales): " << t.Size() << endl;
									if(p == NULL)
										cout << "Unable to insert sales " << r.sales << endl;
								}
								else
									cout << "Unable to insert departhment ID " << r.deptID << endl;
							}
							else
								cout << "Unable to insert stored ID " << r.storeID << endl;
						}
						else
							cout << "Unable to insert day " << r.day << endl;
					}
					else
						cout << "Unable to insert month " << r.month << endl;
				}
				else
					cout << "Unable to insert year " << r.year << endl;
			}
			else
				cout << "Record " << line << " is corrupt!"  << endl;
		}
		datafile.close();
		return true;
	}
	else
	{
		//cout << "Couldn't open data file for reading"  << endl;
		return false;
	}
}
#endif