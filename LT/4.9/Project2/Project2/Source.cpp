#include <iostream>
using namespace std;
void inputArray(int *&a,int &n)
{
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
void findElements(int* a, int &n, int &m)
{
    int x;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        cin >> x;
        int j = 0;
        for (; j < n; j++)
        {
            if (x == a[j])
            {
                cout << j << endl;
                break;
                sum++;
            }
        }if (j == n) cout << -1 << endl;
    }
}

int main()
{
    int n, m;
    int* a = NULL;
    inputArray(a, n);
    findElements(a, n, m);

    return 0;
}
