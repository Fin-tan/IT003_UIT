/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

void quicksort(int*& a, int l,int r)
{
	if (l >= r) return;
	int i = l;
	int j = r;
	int mid = a[l+(r -l) / 2];
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
void sort(int*& a, int n)
{
	int* b = new int[n];
	int* c = new int[n];
	int* d = new int[n];
	int* e = new int[n];
	int cb = 0;
	int cc = 0;
	int cd = 0;
	int ce = 0;
	for (int i=0;i<n;i++)
		if (a[i] % 2 == 0)
		{
			b[cb] = a[i];
			c[cb] = i;
			cb++;
		}
		else
		{
			d[cd] = a[i];
			e[cd] = i;
			cd++;
			ce++;
		}
	quicksort(b, 0, cb - 1);
	quicksort(d, 0, cd - 1);
	for (int i = 0; i < cb; i++)
		a[c[i]] = b[i];
	for (int i = 0; i < ce; i++)
	{
		cd--;
		a[e[i]] = d[cd];
	}
}
int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, n);
	cout << "Sortted Array: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	delete[] a;
}



