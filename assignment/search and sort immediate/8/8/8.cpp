#include <iostream>
#include <vector>
using namespace std;
void quickSort(vector<string>& a, int l,int r)
{
	if (l > r) return;
	int i = l;
	int j = r;
	string mid = a[(l + r) / 2];
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
void kiemke(vector<string>a, int n)
{
	quickSort(a, 0, n - 1);
	int dem = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i]!=a[i-1]) dem++;
	}
	cout << dem+1;
}
int main()
{
	int n;
	cin >> n;
	vector <string>a(n);
	for (int i=0;i<n;i++)
		cin >> a[i];
		kiemke(a, n);
	return 0;
}