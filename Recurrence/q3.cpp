#include<iostream>
using namespace std;


int sum_digit(int number){
	if(number<0){
		return 0;
	}
	if(number<10){
		return number;
	}
	else{
		number = number%10+sum_digit(number/10);
		sum_digit(number);
	}
}

void display(int n){
	if(n>=0){
		cout<<"Digit Sum of "<<n<<" is ";
		cout<<sum_digit(n);
		cout<<endl;
	}
	else{
		cout<<"You entered a negative number";
	}
}

int main(){
	cout<<"Enter Number for digit_sum ";
	cout<<endl;
	int n;
	cin>>n;
	display(n);
	return 0;
}
