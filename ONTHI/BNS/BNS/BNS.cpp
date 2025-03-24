#include <iostream>
using namespace std;
int BNS(int* a, int l, int r, int x,int dem)
{
	
	int mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (a[mid] == x)
		{
			dem++;
			return dem;
		}
		else
		{
			dem = dem + 1;
			if (a[mid] > x) r = mid - 1;
			else l = mid + 1;
		}
	}
	return -1;
}
void quicksort(int* a, int l, int r)
{
	if (l >= r) return;
	int i = l;
	int j = r;
	int mid = a[(l + r) / 2];
	while (i <= j)
	{
		while (a[i] < mid) i++;
		while (a[j] > mid) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (l < j) quicksort(a, l, j);
	if (i < r) quicksort(a, i, r);
}
int main()
{
	int* a;
	int n;
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int x;
	cin >> x;
	quicksort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << BNS(a, 0, n - 1, x,0);
}