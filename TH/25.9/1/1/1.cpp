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
void sort(int* a, int n)
{
	int* b = new int[n];
	int* c = new int[n];
	int demb = 0;
	int demc = 0;

	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			b[demb] = a[i];
			demb++;
			c[demc] = i;
			demc++;
		}
	}
	quicksort(b, 0, demb - 1);
		int j = 0;
	for (int i=0;i<demb;i++)
	{
		a[c[j]] = b[i];
		j++;
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
