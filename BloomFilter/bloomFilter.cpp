#include<iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <cmath>
#include <time.h>
#include <string>
#include <stdlib.h>
using namespace std;
class BitVector {
	private:
		int size = 0;
		bool* vector=NULL;
	public:
		BitVector(){
			this->size=0;
			this->vector=NULL;
		}
		BitVector(int size){
			this->size= size;
			this->vector = new bool[this->size];
			reset();
		}
		BitVector(BitVector&dis){
			this->size= dis.size;
			if(this->vector)
			delete[] this->vector;
			this->vector = new bool[this->size];
			for(int i=0;i<this->size;i++){
				this->vector[i] = dis.vector[i];
			}	
		}
		~BitVector(){
			delete[] vector;
		}
		void setBit(int index){
			if(index<this->size&&index>=0){
				this->vector[index] = 1;
			}
			
		}
		bool checkBit(int index){
			if(this->vector[index])
			return true;
			else
			return false;
		}
		void reset(){
			for(int i=0;i<this->size;i++){
				this->vector[i] = 0;
			}
		}
		int getNumber(){
			int number = 0;
			for(int index=0;index<this->size;index++){
				number+=this->vector[index]*pow(2,index);	
			}
			return number;
		}
		void resetBit(int index){
			if(index<this->size&&index>=0){
				this->vector[index] = 0;
			}
		}
		void uniform_bits_set(){
			for(int i=0;i<this->size;i++){
				int val=rand()%2;
				if(val==1){
					this->setBit(i);
				}
			}
		}
  
};
int power(int a,int b,int p){
	int val = a % p;
	long long int prod = 1;
	for(int i=0;i<b;i++){
		prod = (prod * val)%p;
	}
	return (int)prod;
}

class Bloomfilter {
	private:
		int m;
		int k;
		int p = 16777213;
		int* hash_functions;
		BitVector bloom;
	public:
		Bloomfilter(int k,int m){
			this->k = k;
			this->m =m;
			//uniformly select k functions from hash family
			this->hash_functions= new int[k];
			for(int index=0;index<k;index++){
				BitVector temp(23);
				temp.uniform_bits_set();
				this->hash_functions[index]=temp.getNumber();
				cout<<this->hash_functions[index]<<endl;
			}
			BitVector bloom(this->m);
			this->bloom = bloom;
		}
		~Bloomfilter(){
			delete[] hash_functions;
		}
		int compute_hash_code(int hash_index,string url){
			int length = url.length();
			int d = 0;
			int sum = 0;
			for(int index=length-1;index>=0;index--){
				int temp = ((int)url[index]*power(this->hash_functions[hash_index],d,this->p))%this->p;
				sum+=temp;
				d +=1;
			}
			sum = sum%this->p;
			sum = sum%this->m;
			return sum;
		}
		void insert(string url){
			for(int i=0;i<this->k;i++){
				int index = this->compute_hash_code(i,url);
				//cout<<"index "<<index<<endl;
				this->bloom.setBit(index);
			}
			
		}
		bool lookup(string url){
			for(int i=0;i<this->k;i++){
				int index = this->compute_hash_code(i,url);
				if(!this->bloom.checkBit(index)){
					return true;
				}
			}
			return false;
			
		}
		void print_bloom(){
			cout<<endl;
			cout<<"print bloom filter ";
			cout<<"value of m "<<this->m<<endl;
			for(int i=0;i<this->m;i++){
				if(this->bloom.checkBit(i)){
					cout<<1<<" ";
				}
				else{
					cout<<0<<" ";
				}
			}
			cout<<endl;
		}
  
};
 
int calculate_k(int b){
	float k;
	k = 0.69314718*b;
	
	return round(k);
}

std::vector<string> readFile(string filename){
	ifstream myfile (filename+".txt");
	int i = 0;
	string line;
	std::vector<string> vect;
	if (myfile.is_open())
	{
		while ( getline (myfile,line)){
			vect.push_back(line);
			i+=1;
		}

	}
	else{
		cout<<"file open error"<<endl;
	}
	myfile.close();
	return vect;
}

int main(){
	srand (time(NULL));
	int b,k;
	int p = 16777213;//Largest Prime number
	cout<<"Enter number of bits per object(b): ";
	cin>>b;
	if(b>=4&b<=10){
		k = calculate_k(b);
		cout<<"value of k "<<k<<" "<<endl;
		cout<<"Enter text file name to load data "<<endl;
		string filename;
		cin>>filename;
		std::vector<string> vect=readFile(filename);
		if(vect.size()==0){
			return 0;
		}
		int m = b*vect.size();
		cout<<"Value of m "<<m<<endl;
		//cout<<"total lines of file "<<i<<endl;
		//url_to_number("navigator",3,p,30);
		Bloomfilter bloom(k,m);
		bloom.print_bloom();
		for(int i=0;i<vect.size();i++){
			bloom.insert(vect.at(i));
		}
		cout<<"Data Loaded Successfully.....";
		
		bloom.print_bloom();
		while(true){
			cout<<"Enter new URL "<<endl;
			string url;
			cin>>url;
			if(bloom.lookup(url)){
				cout<<"Success..........";
				break;
			}
			else{
				cout<<"Malicious"<<endl;
			}
		}
		
	}
	else{
		cout<<"b must be positive integer in the range 4-10";
	}
}
