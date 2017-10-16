#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(5);
	v.push_back(30);
	v.pop_back();
	v[0] = 3;
	v.insert(v.begin()+1,8);
	v.insert(v.end()-1,20);
	v.erase(v.end()-2,v.end());
	v.clear();
	for(auto it = v.begin(); it!=v.end(); it++)
	{

		cout << *it << endl;
	}
} 
