/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

void quicksort(int*& a, int l, int r)
{
    if (l > r) return;
    int mid = a[(l + r) / 2];
    int i = l;
    int j = r;
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
void sort(int*& a, int& n)
{
    int* b = new int[n];
    int* c = new int[n];
    int cc = 0;
    int cb = 0;
    for (int i=0;i<n;i++)
        if (a[i] % 2 == 0)
        {
            b[cb] = a[i];
            cb++;
            c[cc] = i;
            cc++;
        }
    quicksort(b, 0, cb - 1);
    for (int i = 0; i < cb; i++)
        a[c[i]] = b[i];
           
}
int main(){
    int *a, n; cin >> n;
    a = new int [n];



    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    sort(a, n);

    for(int i = 0; i < n; i ++){
        cout << a[i] << " ";
    }
}
