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
		cout << a[i]<<" ";
}
void selectionsort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min]) 
			min = j;
		}
		swap(a[i], a[min]);
	}
	Output(a, n);
}
int main()
{
	int* a = NULL;
	int n;
	Input(a, n);
	selectionsort(a, n);
	return 0;
}