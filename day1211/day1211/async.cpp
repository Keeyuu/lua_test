#include<future>
#include<iostream>
#include<chrono>
#include<thread>

int test()
{
	int n=100;
	std::this_thread::sleep_for(std::chrono::seconds(5));
		return n;
}
int test1()
{
	int n = 200;
	std::this_thread::sleep_for(std::chrono::seconds(5));
	return n;
}
int main1()
{
	{
		using namespace std;
		shared_future<int>rust(async(test));
		cout << test1() + rust.get() << endl;
	}


	return 0;
}