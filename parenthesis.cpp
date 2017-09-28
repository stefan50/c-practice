#include <iostream>
#include <cstdio>
#define STACK_SIZE 10

using namespace std;

class Stack
{
	int top_;
	char arr_[STACK_SIZE];
public:
	Stack()
	{
		top_ = 0;
	}
	bool empty()
	{
		return top_ == 0;
	}
	bool full()
	{
		return top_ == STACK_SIZE;
	}
	char pop()
	{
		if(!empty())
		{
			return arr_[--top_]; 
		}
		else 
		{
			return 'n';
		}
	}
	void push(char val)
	{
		if(!full())
		{
			arr[top_++] = val;
		}
		else
		{
			cout << "Full!" << endl;
		}
	}
};

int main()
{
	Stack brackets;
	char val;
	int flag = 1;
	while(1)
	{
		val = fgetc(stdin);
		if(val == '{')
		{
			brackets.push(val);
		}
		else if(val == '}')
		{
			if(brackets.pop() != '{')
			{
				flag--;
				break;
			}
		}
		else { break;} 
	}
	if(!brackets.empty() || flag == 0)
	{
		cout << "Not balanced!" << endl;
	}
	else
	{
		cout << "Balanced!" << endl;
	}
	return 0;
}
