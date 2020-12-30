#include<stdlib.h>
#include<chrono>
#include<thread>

int main()
{
	for (int i = 0; i < 31; i++)
	{

		system("date 2020/12/"+i);
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

}