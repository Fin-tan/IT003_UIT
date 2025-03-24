#include <iostream>
using namespace std;
void Input(int*& a, int& n)
{
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << endl;
}
void output(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void quicksort(int* a,int l,int r,int &dem)
{
	if (l >= r) return;
	int i, j;
	i = l;
	j = r;
	int mid = a[l + (r-l) / 2];
	while (i <=j)
	{
		while (a[i] > mid) i++;
		while (a[j] < mid) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			dem++;
			i++;
			j--;
		}
	}
	if (l < j) quicksort(a, l, j,dem);
	if (i < r) quicksort(a, i, r,dem);
}
int main()
{
	int* a = NULL;
	int n,dem=0;
	Input(a, n);
	quicksort(a,0,n-1,dem);
	cout<< "Sorted Array: "; 
	output(a, n);
	cout <<"Number of times to swap 2 numbers: "<< dem;
	delete[] a;
	return 0;
}