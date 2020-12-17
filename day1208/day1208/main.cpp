#include<thread>
#include<mutex>
#include<chrono>
#include<condition_variable>
#include<iostream>
#include<queue>
#include<random>
#include<string>
#include<string.h>
std::mutex mutex_;
std::condition_variable cond_;
std::queue<std::string> news;

void users(char x)
{
	while (1)
	{
		std::unique_lock<std::mutex>t1(mutex_);
		cond_.wait(t1);
		//t1.lock();
		auto temp = news.front();
		news.pop();
		t1.unlock();
		std::cout << "users:" << x << "-------" << "producers:" << temp << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

void producers(std::string x)
{
	while (1)
	{

		std::default_random_engine nub;
		nub.seed(time(nullptr));
		auto temp=std::to_string(nub()%10)+x;
		std::unique_lock<std::mutex> t1(mutex_);
		news.push(temp);
		t1.unlock();
		std::cout << "prodoct:" << temp << std::endl;
		cond_.notify_one();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}


int main()
{
	auto p1 = std::thread(producers, "zs");
	auto p2 = std::thread(producers, "fb");
	auto ua = std::thread(users, 'a');
	auto ub = std::thread(users,'b');
	p1.join(); 
	p2.join();
	ua.join();
	ub.join();


	return 0;
}