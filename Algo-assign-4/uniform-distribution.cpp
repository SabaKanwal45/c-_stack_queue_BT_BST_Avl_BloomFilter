#include <random>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
int main()
{
	ofstream myfile ("search-uni-10000000.txt");
	if (myfile.is_open())
	{
		unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count(); //Get current time
		std::random_device rd; 
		std::mt19937 gen(seed1); //Standard mersenne_twister_engine seeded with rd()
		std::uniform_int_distribution<> dis(1, 10000000);
		for (int n=0; n<10000000; ++n)
		myfile << dis(gen)<<endl;
		myfile.close();
	}
}
