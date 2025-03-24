#include <iostream>
#include <string>
#include <stack>
using namespace std;
void DecimalToBinary(stack<int> s,int x)
{
	while (x)
	{
		int temp = x % 2;
		s.push(temp);
		x = x / 2;
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}
bool BracketMatching(stack<int> s,string n)
{
	
	for (char ch : n)
	{
		if (ch == '(')
		{
			s.push(ch);
		}
		else
		{
			if (s.empty()) return false;
			else
			{
				s.pop();
			}
		}
	}
	return !s.empty();
}
int main()
{
	stack<int> s;

	string n;
	cin >> n;
	cout << BracketMatching(s, n);
	return 0;
}