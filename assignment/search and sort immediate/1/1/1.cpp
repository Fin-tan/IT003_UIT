#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nhapMang(vector<int>& a, int& n)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
}
void xuatmang(vector<int> &a, int&n)
{
	for (int i=0;i<n;i++)
		cout << a[i] << " ";
	cout << endl;
}
void xulymang(vector<int>& a, int n)
{
	auto chandau = find_if(a.begin(), a.end(), [](int x)
		{
			return x % 2 == 0;
		});
	if (chandau != a.end())
	{
		int index = distance(a.begin(), chandau);
		cout << *chandau << " la so chan dau tien,co chi so " << index << " trong mang "<<endl;
	}
	auto chancuoi = find_if(a.rbegin(), a.rend(), [](int x)
		{
			return x % 2 == 0;
		});
	if (chancuoi != a.rend())
	{
		int index = distance(a.begin(), chancuoi.base()) - 1;  // Chuy?n iterator ng??c thành iterator bình th??ng
		cout << *chancuoi << " la so chan cuoi cung, co chi so " << index << " trong mang" << endl;
	}
}
void xulymang1(vector<int>& a, int n)
{
	vector<int> chan;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0) {
			chan.push_back(a[i]);
		}
	}
	if (!chan.empty())
	{
		int chan_max = *max_element(chan.begin(), chan.end());
		cout << "So chan lon nhat: " << chan_max << endl;
	}
	else
	{
		cout << "Mang khong co so chan" << endl;
	}
}
int main()
{
	vector<int> a;
	int n;
	nhapMang(a, n);
	cout << "Mang vua nhap:" << endl;
	xuatmang(a, n);
	xulymang(a, n);
	xulymang1(a, n);
	return 0;
}
