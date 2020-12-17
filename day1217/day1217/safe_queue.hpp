#pragma once
#include<queue>
#include<mutex>


using namespace std;
namespace keeyu 
{
	template<typename T>
	class safe_queue
	{
		mutex* mutex_;
		queue<T>* queue_;
	public:
		safe_queue()
		{
			mutex_ = new mutex;
			queue_ = new queue<T>;
		}
		void push(T&& t)
		{
			unique_lock<mutex>lock_(mutex);
			this->queue_->emplace(t);
		}
		bool push(T& t)
		{
			unique_lock<mutex>lock_(mutex);
			this->queue_->push(t);
		}
		T pop_()
		{
			if (this->queue_->size() <= 0)
			{
				return NULL;
			}
			else
			{
				unique_lock<mutex>lock_(mutex);
				T temp = this->queue_->front();
				this->queue_->pop();
				return temp;
			}
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

