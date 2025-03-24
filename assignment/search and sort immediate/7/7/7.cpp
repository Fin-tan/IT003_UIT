#include <iostream>
#include <vector>
using namespace std;
void quickSort(vector<long long>& a, int l, int r)
{
	if (l>r) return;
	int i = l;
	int j = r;
	long long mid = a[(l+r)/2];
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
void Mex(vector<long long> a, int&n)
{
	quickSort(a, 0, n - 1);
	if (a[0] != 0) cout << 0 << " ";else
	{
		for (int i = 1; i < n; i++)
		{
			if (a[i] - a[i - 1] > 1)
			{
				cout << a[i - 1] + 1 << " ";
				return;
			}
			if (i == (n - 1)) cout << a[i] + 1 << " ";
		}
	}
}
void findMex(vector<long long> a, int n)
{
	
	for (int i = 1; i <=n; i++)
	{
			Mex(a, i);
	}
}
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (a[0]==0) cout << 1 << " ";
	findMex(a, n);
	return 0;
}