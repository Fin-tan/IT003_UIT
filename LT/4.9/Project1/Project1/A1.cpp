#include <iostream>
using namespace std;
int main()
{
	int n,x,sum;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int m; cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		for (int j = 0; j < n; j++)
		{
			sum = 0;
			if (x == a[j])
			{
				cout << j << endl;
				sum++;
				break;
			}
		}
		if (sum == 0) cout << -1 << endl;
		
	}
	return 0;
}
