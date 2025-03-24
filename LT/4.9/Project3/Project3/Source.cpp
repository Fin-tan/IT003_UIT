#include <iostream>
using namespace std;
void inputA(int*&a, int& n)
{
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
int binarysearch(int* a, int left, int right, int&x)
{
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == x) return mid;
		if (a[mid] > x) right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}
int main()
{
	int n,m,x;
	int* a = NULL;
	inputA(a, n);
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		cout<<binarysearch(a, 0, n - 1, x)<<endl;
	}
	delete[]a;
	return 0;
}