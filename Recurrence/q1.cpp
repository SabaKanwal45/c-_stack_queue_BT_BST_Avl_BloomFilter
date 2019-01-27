#include<iostream>
using namespace std;

int fibonacci_number(int n){
	if(n<=0)
	return 0;
	if(n==1)
	return 1;
	return fibonacci_number(n-1)+fibonacci_number(n-2);	
}

void print_nth_fibonacci(int number){
	if(number>=0){
		cout<<"Nth Fibonacci Number: "<<fibonacci_number(number)<<endl;
	}
	else{
		cout<<"Please entered a non negative integer "<<endl;
	}
}


int main(){
	int number;
	cout<<"Please Enter a Positive Integer"<<endl;
	cin>>number;
	print_nth_fibonacci(number);
	return 0;
}
