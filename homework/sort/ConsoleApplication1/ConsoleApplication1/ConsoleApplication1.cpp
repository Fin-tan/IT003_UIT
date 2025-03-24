#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;


vector<int> generateArray(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 20001 - 10000; 
    }
    return arr;
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

void interchangeSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
// source merge sort : https://www.geeksforgeeks.org/merge-sort/
void merge(vector<int>& arr, int left,
    int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

  
    vector<int> L(n1), R(n2);

   
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

  
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
// source heap sort https://www.geeksforgeeks.org/heap-sort/
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
//source shell 
void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
void binaryInsertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int left = 0, right = i - 1;


        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > key)
                right = mid - 1;
            else
                left = mid + 1;
        }


        for (int j = i - 1; j >= left; --j) {
            arr[j + 1] = arr[j];
        }
        arr[left] = key;
    }
}
//source  radix sort https://www.geeksforgeeks.org/radix-sort/
void countingSortForRadix(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = { 0 };

    for (int i = 0; i < n; ++i)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; ++i)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; ++i)
        arr[i] = output[i];
}

void radixSort(vector<int>& arr) {
    vector<int> negatives, positives;

    for (int num : arr) {
        if (num < 0)
            negatives.push_back(-num);
        else
            positives.push_back(num);
    }

    int maxVal = *max_element(positives.begin(), positives.end());
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortForRadix(positives, exp);
    }

    maxVal = *max_element(negatives.begin(), negatives.end());
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortForRadix(negatives, exp);
    }

    int idx = 0;
    for (int i = negatives.size() - 1; i >= 0; --i) {
        arr[idx++] = -negatives[i];
    }
    for (int num : positives) {
        arr[idx++] = num;
    }
}


void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (arr[j] < pivot) {
                ++i;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
//source tham khao cach shakersort hoat dong khong lay code https://clbketnoitre.wordpress.com/2019/02/25/thuat-toan-sap-xep-shakersort/
void shakerSort(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;
    while (left < right) {
        for (int i = left; i < right; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
        --right;
        for (int i = right; i > left; --i) {
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
            }
        }
        ++left;
    }
}
//source open AI
void countingSort(vector<int>& arr) {
    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    vector<int> count(range, 0);
    vector<int> output(arr.size());

    for (int num : arr) {
        count[num - minVal]++;
    }

    for (int i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; --i) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    arr = output;
}


void showMenu() {
    cout << "**************MENU***************\n";
    cout << "1. Selection Sort\n";
    cout << "2. Interchange Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Binary Insertion Sort\n";
    cout << "5. Bubble Sort\n";
    cout << "6. Shake/Shaker Sort\n";
    cout << "7. Counting Sort\n";
    cout << "8. Quick Sort\n";
    cout << "9. Merge Sort\n";
    cout << "10. Heap Sort\n";
    cout << "11. Shell Sort\n";
    cout << "12. Radix Sort\n";
    cout << "Enter your choice (1-12, others to exit): ";
}



int main() {
    srand(static_cast<unsigned>(time(0)));

    int n;
    while (true) {
        cout << "Please enter a number in range 1 .. 100,000,000: ";
        cin >> n;
        if (cin.fail() || n <= 0 || n > 100000000) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again.\n";
        }
        else {
            break;
        }
    }

    vector<int> arr = generateArray(n);
    vector<int> temp;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        if (choice < 1 || choice >12) {
            cout << "See you again!\n";
            break;
        }

        temp = arr; // Copy original array

        clock_t start = clock();

        switch (choice) {
        case 1:
            selectionSort(temp);
            break;
        case 2:
            interchangeSort(temp);
            break;
        case 3:
            insertionSort(temp);
            break;
        case 4:
            binaryInsertionSort(temp);
            break;
        case 5:
            bubbleSort(temp);
            break;
        case 6:
            shakerSort(temp);
            break;
        case 7:
            countingSort(temp);
            break;
        case 8:
            quickSort(temp, 0, temp.size() - 1);
            break;
        case 9:
            mergeSort(temp, 0, temp.size() - 1);
            break;
        case 10:
            heapSort(temp);
            break;
        case 11:
            shellSort(temp);
            break;
        case 12:
            radixSort(temp);
            break;
        default:
            cout << "See you again!\n";
            break;
        }


        clock_t end = clock();
        double elapsed = double(end - start) / CLOCKS_PER_SEC;

        cout << "Sorting completed in " << elapsed << " seconds.\n";

        char cont;
        cout << "Do you want to continue (y/n): ";
        cin >> cont;
        if (cont != 'y' && cont != 'Y') {
            cout << "See you again!\n";
            break;
        }

        arr = generateArray(n); 
    }

    return 0;
}
