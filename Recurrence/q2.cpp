#include<iostream>
#include <cmath>
using namespace std;


//Display a Way to represent a number as power of natural numbers
void print_way(int x, int digits,int n){
	cout<<x<<"=";
	while(digits>0){
		if(digits%10==0){
			cout<<10<<"^"<<n<<"+";
			digits = digits - 10;
		}
		else{
			cout<<digits%10<<"^"<<n<<"+";
		}
		digits = digits /10;
	}
	cout<<"\b \b";
	cout<<endl;
	return;
}

//Recursive function to find all possible ways to represent a number as power of other natural numbers between 2 and 10(both inclusive)
int number_as_power_others(int x, int n,int num = 2, float sum = 0,int digits=0) 
{ 
    int total_ways = 0; 
    float p = pow(num, n);
    while (pow(num, n) + sum < x && num <10) 
    {
        total_ways += number_as_power_others(x, n,++num, p+sum,digits*10+num); 
        p = pow(num, n);
    } 
    sum = sum+p;
    if ((int)sum == x){
    	digits = digits*10+num; 
    	print_way(x,digits,n);
    	total_ways++;
	} 
    return total_ways; 
}

//Function that calls the recursive function
void display_all_ways(int x,int n){
	if(x>0&x<=100){
		int total_ways = 0;
		total_ways = number_as_power_others(x, n, 2, 0) ;
		if(total_ways==0){
			cout<<"No way to represent X as nth Power of Numbers between 2 and 10 both inclusive"<<endl;
		}
		else{
			cout<<"Total Ways to represent X as nth Power = "<<total_ways;
		}
	}
	else{
		cout<<"X value out of range";
	}
	return;
	
}
int main(){
	cout<<"Enter value of X between 1 and 100 both inclusive"<<endl;
	int x,n;
	cin>>x;
	cout<<"Enter value of N"<<endl;
	cin>>n;
	display_all_ways(x,n);
	
}
