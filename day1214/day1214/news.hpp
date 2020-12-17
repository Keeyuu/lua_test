#pragma once
#include<queue>
#include<mutex>
namespace keeyu {
template<typename T>	
	class news
	{
		std::queue<T>* queue_;
		std::mutex *mutex_;
		public:
			news()
			{
				this->queue_ = new std::queue<T>;
				this->mutex_ = new std::mutex;
			}
			~news()
			{
				if (queue_ != nullptr)
				{
					delete queue_;
					queue_ = nullptr;
				}
			}
			int get_size()
			{
				return this->queue_->size();
			}
			void push(T&&t)
			{
				std::lock_guard temp_lock(mutex_);
				queue_->emplace(t);
			}
			decltype(auto)pop()
			{
				std::lock_guard temp_lock(mutex_)
				auto temp = queue_->front();
				queue_->pop();
				return temp;
			}

	};
}
