#include<iostream>

class base
{
public:
    virtual void test()
    {
        std::cout << "base" << std::endl;
    }
};

class fuck :public base
{
public:
    void test()
    {
        std::cout << "fuck" << std::endl;
    }

};

int  main()
{
    base* a = new fuck;
    base* b = new base;
    a->test();
    b->test();
}