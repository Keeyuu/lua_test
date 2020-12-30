// day1229.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<functional>
#include <iostream>
#include"test.hpp"
void test(int n)
{
    std::cout << n << std::endl;
}


int main()
{
    std::cout << "Hello World!\n";
    auto p = std::bind(test, 10);

    p();
}

