#include <iostream>
using namespace std;

void merge(int* a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = a[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}
void mergeSort(int* a, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        merge(a, left, mid, right);
    }
}
int binarySearch(int* a, int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x)
            return mid;
        if (a[mid] < x)
            left = mid + 1;

      
        else
            right = mid - 1;
    }

    
    return -1;
}

int main() {
    int n, x;
    
    cin >> n;

    int* a = new int[n];
    
    for (int i = 0; i < n; i++)
        cin >> a[i];

   
    cin >> x;

    
    mergeSort(a, 0, n - 1);

  
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

  
    int result = binarySearch(a, 0, n - 1, x);

    if (result != -1)
        cout<< x << " is found at the position " << result << endl;
    else
        cout << x << "is not found"endl;

    delete[] a;
    return 0;
}
