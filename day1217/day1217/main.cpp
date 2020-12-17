#include<iostream>
#include"safe_queue.hpp"

int main()
{
	keeyu::safe_queue<int> queue_;
	std::cout << queue_.size()<<std::endl;
	queue_.push(100);
	std::cout << queue_.size() << std::endl;
	//std::cout << queue_.pop_()<< std::endl;
	queue_.pop_();
	std::cout << queue_.size() << std::endl;


}