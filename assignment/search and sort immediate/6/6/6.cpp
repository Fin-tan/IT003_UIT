////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;


void quickSort(vector <long long>& arr, int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}


////////////////////////////////////////////////
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);

    for (int i = 0; i <= n - 1; i++) cin >> a[i];
    quickSort(a, 0, n - 1);
    if (n == 0) cout << 0;
    else
        if (a[0] != 0) cout << 0;
        else
            for (int i = 1; i <= n - 1; i++)
            {
                if ((a[i] - a[i - 1]) > 1)
                {
                    cout << a[i - 1] + 1;
                    return 0;
                }
                if (i == (n - 1)) cout << a[i] + 1;
            }
    return 0;
}