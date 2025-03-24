#include <iostream>
#include <map>

using namespace std;
int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	map<int, bool> b;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	for (int i = 0; i <n; i++)
	{
		b[a[i]] = true;
	}
	int* maxElement = max_element(a, a + n);
	int mex = 0;
	while (b[mex])
	{
		mex++;
	}
	cout << mex;
	return 0;
	

}