#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        // Find the index of the minimum element
		// in the remaining unsorted portion of the array
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the current element
        swap(arr[i], arr[minIndex]);

        // Display the current state of the array after each swap
        cout << "Pass " << i + 1 << ": ";
        for (int k = 0; k < size; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter " << size << " integers, separated by spaces:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    cout << "Initial Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    selectionSort(arr, size);

    cout << "\nSorted Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

//Initial Array: 10 -5 5 55 23 0 -1 8 99 34 56 67 3 58 -9
//
//Pass 1: -9 -5 5 55 23 0 -1 8 99 34 56 67 3 58 10
//Pass 2: -9 -5 5 55 23 0 -1 8 99 34 56 67 3 58 10
//Pass 3: -9 -5 -1 55 23 0 5 8 99 34 56 67 3 58 10
//Pass 4: -9 -5 -1 0 23 55 5 8 99 34 56 67 3 58 10
//Pass 5: -9 -5 -1 0 3 55 5 8 99 34 56 67 23 58 10
//Pass 6: -9 -5 -1 0 3 5 55 8 99 34 56 67 23 58 10
//Pass 7: -9 -5 -1 0 3 5 8 55 99 34 56 67 23 58 10
//Pass 8: -9 -5 -1 0 3 5 8 10 99 34 56 67 23 58 55
//Pass 9: -9 -5 -1 0 3 5 8 10 23 34 56 67 99 58 55
//Pass 10: -9 -5 -1 0 3 5 8 10 23 34 56 67 99 58 55
//Pass 11: -9 -5 -1 0 3 5 8 10 23 34 55 67 99 58 56
//Pass 12: -9 -5 -1 0 3 5 8 10 23 34 55 56 99 58 67
//Pass 13: -9 -5 -1 0 3 5 8 10 23 34 55 56 58 99 67
//Pass 14: -9 -5 -1 0 3 5 8 10 23 34 55 56 58 67 99
//
//Sorted Array: -9 -5 -1 0 3 5 8 10 23 34 55 56 58 67 99
