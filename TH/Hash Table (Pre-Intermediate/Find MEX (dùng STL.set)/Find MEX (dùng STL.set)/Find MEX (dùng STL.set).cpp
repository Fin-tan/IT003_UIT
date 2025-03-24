/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
map
vector
###End banned keyword*/


#include<set>
#include<iostream>
using namespace std;

int main()
{
    set<int> b;
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        b.insert(a[i]);
    for (int i = 0;; i++)
    {
        if (b.find(i) == b.end())
        {
            cout << i; break;
        }
    }
    return 0;

}



