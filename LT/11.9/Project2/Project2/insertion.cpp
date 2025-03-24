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
void Output(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void insertionsort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = a[i];
		int j = i - 1;
		for (; j >= 0; j--)
		{
			if (key < a[j])
				a[j + 1] = a[j];
			Output(a, n);
		}
		a[j + 1] = key;
		Output(a, n);
	}
}
int main()
{
	int* a = NULL;
	int n;
	Input(a, n);
	insertionsort(a, n);
	return 0;
}