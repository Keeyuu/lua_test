#pragma once
#include<thread>
#include<queue>
#include<mutex>
#include<condition_variable>
namespace keeyu 
{
	template<typename T>
	class thread_pool
	{
		safe_queue<T>* queue_;
		int level;
	public:
		thread_pool(int n = 2) :level(n)
		{
			queue_ = new keeyu::safe_queue<T>;
		}
		int get_level()
		{
			return level;
		}
		int get_surplus()
		{
			return queue_->size();
		}
		~thread_pool()
		{
			if (this->queue_ != nullptr)
			{
				delete queue_;
				queue_ = nullptr;
			}
		}

	};
	template<typename T>
	class safe_queue
	{
		std::mutex* mutex_;
		std::queue<T>* queue_;
		std::condition_variable* cond_;
	public:
		safe_queue()
		{
			mutex_ = new std::mutex;
			queue_ = new std::queue<T>;
			cond_ = new std::condition_variable;
		}
		void push(T&& t)
		{
			std::unique_lock<mutex>lock_(*mutex_);
			queue_->emplace(t);
			cond_->notify_one();
		}
		void operator<<(T&& t)
		{
			std::unique_lock<mutex>lock_(*mutex_);
			queue_->emplace(t);
			cond_->notify_one();
		}
		void push(T& t)
		{
			std::unique_lock<mutex>lock_(*mutex_);
			queue_->push(t);
			cond_->notify_one();
		}
		decltype(auto) pop_()
		{
			std::unique_lock<mutex>lock_(*mutex_);
			cond_->wait(lock_);
			T temp = this->queue_->front();
			this->queue_->pop();
			return temp;
		}
		int size()
		{
			return this->queue_->size();
		}
		~safe_queue()
		{
			if (queue_ != nullptr)
			{
				delete queue_;
			}
			if (mutex_ != nullptr)
			{
				delete mutex_;
			}
		}
	};
}

