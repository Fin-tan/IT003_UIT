
#include <iostream>
#include <math.h>

using namespace std;

void inputArray(char a[], int& n) {

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}


void removeDups(char a[], int& n) {
    for (int i = 0; i < n; i++)
    {
        a[i] = tolower(a[i]);
    }

    bool hashTable[26] = { false };
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 'a' && a[i] <= 'z')
        {
            hashTable[a[i] - 'a'] = true;
        }
    }
    int dem = 0;
    for (int i = 0; i < 26; i++)
    {
        if (!hashTable[i]) dem++;
    }
    cout << dem;
}


int main()
{
    char a[1000];
    int  n;
    inputArray(a, n);
    
    removeDups(a, n);

    return 0;
}
