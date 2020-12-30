
#include<iostream>


class test {
public:
	void test1()
	{
		std::cout << "--------------" << std::endl;
	}
	~test()
	{
		std::cout << "ooooooooooooo" << std::endl;
	}
};

test get_()
{
	return test();
}


int main()
{
	auto x = get_();
	x.test1();
}