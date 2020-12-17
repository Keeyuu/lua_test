#include<atomic>
#include<iostream>
#include<thread>
std::atomic<int>n1;
void test()
{
	for (int i = 0; i < 500 * 500; i++) {
		n1++;


	}
}

void test1()
{
	for (int i = 0; i < 500 * 500; i++) {
		n1++;
	}
}

int main()

{
	using namespace std;
	
	atomic_init(&n1, 0);
	auto p1 = thread(test);
	auto p2 = thread(test1);
	p1.join(); p2.join();
	cout << n1.load() << endl;

}
