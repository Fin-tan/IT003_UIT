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
		while (mid < a[j]) j--;
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
void xuli(vector<int>a, int n,int k)
{
	quickSort(a, 0, n - 1);
	int dem = 1;
	for (int i = 1; i < n; i++)
	{
		if (a[i] != a[i - 1]) dem++;
	}
	if (dem <=2*k) cout << "YES"; else cout << "NO";
}
int main()
{
	int n, k, c = 0, T;
	cin >> T;
	while (1)
	{
		if (c == T) break;
		cin >> n>>k;
		
		vector <int>a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		xuli(a, n, k);
		c++;
	}
	return 0;
}