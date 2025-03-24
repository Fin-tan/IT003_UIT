/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

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
void quicksort(int* a, int l, int r)
{
	if (l >= r) return;
	int i, j;
	i = l;
	j = r;
	int mid = a[l + (r - l) / 2];
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
void quicksort2(int* a, int l, int r)
{
	if (l >= r) return;
	int i, j;
	i = l;
	j = r;
	int mid = a[l + (r - l) / 2];
	while (i <= j)
	{
		while (a[i] > mid) i++;
		while (a[j] < mid) j--;
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
void sort(int* a, int n)
{
	int* b = new int[n];
	int* c = new int[n];
	int* d = new int[n];
	int* e = new int[n];
	int demb = 0;
	int demc = 0;
	int demd = 0;
	int deme = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			b[demb] = a[i];
			demb++;
			c[demc] = i;
			demc++;
		}
		else {
			d[demd] = a[i];
			demd++;
			e[deme] = i;
			deme++;
		}
	}
	quicksort(b, 0, demb - 1);
	quicksort2(d, 0, demd - 1);
	for (int i = 0; i < demc; i++)
	{
		a[c[i]] = b[i];
	}
	for (int i = 0; i < deme; i++)
	{
		a[e[i]] = d[i];
	}
}

int main() {
	int* a, n; cin >> n;
	a = new int[n];



	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, n);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}


