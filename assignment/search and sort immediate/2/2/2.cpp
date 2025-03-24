#include<iostream>
using namespace std;
int binarysearch(int* a, int l, int r,int&x,int &dem)
{
	int mid;
	while (l <= r)
	{
		dem++;
		mid = (l + r) / 2;
		if (a[mid] == x) return mid;
		if (a[mid] < x) l = mid+1;
		else r = mid-1;
	}
	return -1;
}
int main()
{
	int dem=0,n,x;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> x;
	int d = binarysearch(a, 0, n-1, x,dem);
	if (d != -1)
	{
		cout <<d<<endl;
		cout << dem;
	}
	else cout << d;
	
	delete[] a;
	return 0;
}