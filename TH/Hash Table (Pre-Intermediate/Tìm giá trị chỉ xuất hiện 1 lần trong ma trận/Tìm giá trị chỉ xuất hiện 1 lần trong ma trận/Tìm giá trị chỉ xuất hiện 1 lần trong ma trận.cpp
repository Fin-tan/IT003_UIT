

#include <iostream>
using namespace std;

void inputMatrix(int a[][50], int &n, int& m)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
}
void outputMatrix(int a[][50], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j]<<" ";
        cout << endl;
    }
}
int findMaxValue(int a[][50], int n, int m) {
    int maxVal = a[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] > maxVal)
                maxVal = a[i][j];  
        }
    }
    return maxVal;
}
void uniqueElements(int a[][50], int& n, int& m) {
    int maxvalue = findMaxValue(a, n, m);  
    int* hashTable = new int[maxvalue + 1] {0};  

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            hashTable[a[i][j]]++; 
        }
    }
    
    int dem = 0;
    for (int i = 0; i <= maxvalue; i++) {
        if (hashTable[i] == 1) {  
            dem++;  
        }
    }
    if (dem == 0) cout << "No unique element in the matrix"; else
    {
        cout << "Unique elements in the matrix:\n";
        for (int i = 0; i <= maxvalue; i++) {
            if (hashTable[i] == 1) {
                cout << i << " ";
            }
        }
    }
  
}
int main()
{
    int m,n, a[50][50];
    inputMatrix(a, n, m);
    cout << "Matrix:\n";
    outputMatrix(a, n, m);
    uniqueElements(a, n, m);
    return 0;
}



