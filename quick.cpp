#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high, int pivot, int index) { //handler
	if (arr[index] == arr[low]) { //if equal, proceed
        low++;
    } else if (arr[index] == arr[high]) {
        high--;
    } else {
    }

    while (low <= high) {
    	if (arr[low] <= pivot && arr[high] <= pivot) { //low & high <= pivot
            low++;
        } else if (arr[low] >= pivot && arr[high] >= pivot) { //low & high >= pivot
            high--;
        } else if (arr[low] <= pivot && arr[high] >= pivot) { //low <= pivot >= high
            high--;
            low++;
        } else if (arr[low] >= pivot && arr[high] <= pivot) { //low >= pivot <= pivot
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
    }

    if (index < high) { //swap gate
        swap(arr[index], arr[high]);
    } else if (index >= high) {
        swap(arr[index], arr[high]);
    }

    return low;
}

void QuickSort(int arr[], int low, int high) {
    bool sort = true;

    if (low < high) {
        cout << "\nCurrent Array: ";
        for (int i = low; i <= high - 1; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "Chose Pivot Value: ";
        int pivot;
        cin >> pivot;

        int index;
        for (int a = 0; a < high; a++) {
            if (arr[a] == pivot) {
                index = a;
            }
        }

        int partitionIndex = partition(arr, low, high, pivot, index);

        for (int a = low; a < high - 1; a++) {
            if (arr[a] > arr[a + 1]) {
                sort = false;
            }
        }

        if (sort) {
            for (int a = low; a <= high; a++) {
                low++;
            }
        }

        QuickSort(arr, low, partitionIndex - 1);
        QuickSort(arr, partitionIndex, high);
    }
}

int main() {
    int arr[] = {45, 3, -2, 55, 66, 1, 0, 5, 89, 38, 24, 78, 2, 9, 8, 4, 79, 58};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Initial Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    QuickSort(arr, 0, n - 1);

    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

