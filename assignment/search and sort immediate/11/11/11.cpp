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
void Input(vector<int>&a, int &n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void xuly(vector<int>&a, int n)
{
	quickSort(a, 0, n - 1);
	if (n <= 3)
	{
		cout << -a[0] + a[n - 1];
	}
	else cout << (a[n - 1] - a[0]) + (a[n - 2] - a[1]);
}
int main()
{
	int T,c=0;
	cin >> T;
	while (1)
	{
		if (c == T) break;
		else
		{
			int n;
			cin >> n;
			vector <int> a(n);
			Input(a, n);
			xuly(a, n);
			c++;
		}
		cout << endl;
	}
	return 0;
}