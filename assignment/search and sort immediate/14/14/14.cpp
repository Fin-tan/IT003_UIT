#include <iostream>
#include <vector>
using namespace std;
void quickSort(vector<int>& a, int l, int r)
{
	if (l > r) return;
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
	if (l < j) quickSort(a, l, j);
	if (i < r) quickSort(a, i, r);
}
void Input(vector<int>& a, int& n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void xuli(vector<int>a, int n, int x, int l, int r)
{
	int max_sum=0, sum;
	quickSort(a, 0, n - 1);
	while (l < r)
	{
		sum = a[l] + a[r];
		if (sum > x)
			r--;
		else
		{
			max_sum = max(sum, max_sum);
			l++;
		}
	}
	cout << max_sum;
}
int main()
{
	int n, x;
	cin >> n >> x;
	vector<int>a(n);
	Input(a, n);
	xuli(a, n, x, 0, n - 1);
	return 0;
}