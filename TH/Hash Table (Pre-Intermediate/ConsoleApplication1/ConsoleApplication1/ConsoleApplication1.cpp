
#include <iostream>
#include <math.h>


using namespace std;
void inputArray(int a[], int& n) {
    
    cin >> n;
   
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}


void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int findMaxValue(int a[], int n) {
    int maxVal = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > maxVal) {
            maxVal = a[i];
        }
    }
    return maxVal;
}


void removeDups(int a[], int& n) {
    int maxValue = findMaxValue(a, n);
    int* hashTable = new int[maxValue + 1] {0};  
    

    
    for (int i = 0; i < n; i++) {
        if (hashTable[a[i]] == 0) {  
            hashTable[a[i]] = 1;   
           
        }
    }

    
    
    for (int i = 0; i <= maxValue; i++)
        if (hashTable[i] == 1) cout << i<< " ";
    cout << endl;
}

int main()
{
    int a[100], n;
    inputArray(a, n);

    // In mang ban dau
    printArray(a, n);

    /* Goi ham thuc hien xuat mang nhung chi xuat nhung gia tri xuat hien lan dau tien,
    *  khong xuat nhung gia tri bi lap lai/bi trung
    */


    cout << "After removing the duplicate elements:" << endl;

    removeDups(a, n);

    return 0;
}
    