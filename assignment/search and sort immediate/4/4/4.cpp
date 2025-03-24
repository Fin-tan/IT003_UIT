#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void xulimang(vector<int>& a, int &n)
{
	while (1)
	{
		cin >> n;
		if (n == -2) break;
		if (n == -1)
		{
			auto maxx = *max_element(a.begin(), a.end());

			a.erase(remove_if(a.begin(), a.end(), [maxx](int x) { return x == maxx; }), a.end());
		}
		else if (n > 0) a.push_back(n);
	}
	cout << a.size()<<endl;
	sort(a.begin(), a.end(), greater<int>());
	for (int x : a)
		cout << x <<endl;
}
int main()
{
	int n;
	vector<int> a;
	xulimang(a, n);
	return 0;
}
