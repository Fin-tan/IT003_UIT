#include<iostream>
#include<vector>
using namespace std;
struct Point
{
	long x, y;
};
bool compareXY(Point& a, Point& b)
{
	if (a.x != b.x)
		return a.x < b.x;
	return a.y > b.y;
}
void quickSort(vector<Point>& a, int l, int r)
{
	int i = l;
	int j = r;
	Point mid = a[(l + r) / 2];
	while (i <= j)
	{
		while (compareXY(a[i], mid)) i++;
		while (compareXY(mid,a[j])) j--;
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
int main()
{
	int n;
	scanf_s("%d", &n);
	vector<Point> a(n);
	for (int i=0;i<n;i++)
		scanf_s("%ld %ld", &a[i].x, &a[i].y);
	quickSort(a, 0, n - 1);
	for (int i=0;i<n;i++) printf("%ld %ld\n", a[i].x, a[i].y);
	return 0;
}