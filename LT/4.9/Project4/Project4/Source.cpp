#include <iostream>
using namespace std;
void inputArray(int*& a, int& n)
{
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
int binarySearch2(int* a, int&n, int x)
{
    int mid, left = 0, right = n - 1;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (a[mid] == x)
        {
            while (a[mid] == x)  mid++;
            return mid-1;
        }
        if (a[mid] > x) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}
int main()
{
    int n, * a = NULL;
    inputArray(a, n); //Luu y van de tham chieu cho con tro a va n

    // nhap cac gia tri can tim, neu nhap -1 thi ket thuc viec tim kiem
    int x;
    while (1)
    {
        cin >> x;
        if (x == -1)break;
        cout << binarySearch2(a, n, x) << endl;

    }

    return 0;
}

