#include<array>
#include<iostream>
#include<string>
#include<tuple>
int main()
{
	{
		using namespace std;
		array<int,10>p;
		for (int i = 0; i < 10; i++)
		{
			p[i] = i;
		}
		for (auto x : p)
		{
			cout << x << endl;
		}
		auto zhs = make_pair("zhs", 22);
		cout << zhs.first<<":"<<zhs.second<< endl;
		tuple<string, int> lis("lis", 25);
		cout << get<1>(lis) << endl;
		string a; int x;
		tie(a, x) = lis;
	
	}

}