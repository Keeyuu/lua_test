#include<iostream>
#include<vector>
#include<tuple>


int main()
{
    typedef std::tuple<int, int> tuple_;
    std::vector<tuple_> p;
    p.push_back(std::make_tuple(10, 20));
    p.push_back(std::make_tuple(11, 20));
    p.push_back(std::make_tuple(12, 20));
    p.push_back(std::make_tuple(13, 20));
    std::sort(p.begin(), p.end(), [](tuple_ p1, tuple_ p2)
        {
            return std::get<1>(p1) >= std::get<1>(p2);
        });

    for(auto info:p)
        {
        auto [x, y] = info;
        std::cout << x <<":"<< y << std::endl;
        }
}