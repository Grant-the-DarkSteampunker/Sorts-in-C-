#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Display the current state of the array after each pass
        cout << "Pass " << i + 1 << ": ";
        for (int k = 0; k < size; k++) {
            cout << arr[k] << " ";
        }
        cout << endl; 
    }
    cout << "Last Pass: ";
        for (int k = 0; k < size; k++) {
            cout << arr[k] << " ";
        }
        cout << endl; 
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

    bubbleSort(arr, size);

    cout << "\nSorted Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

//Initial Array: 10 -5 5 55 23 0 -1 8 99 34 56 67 3 58 -9

//Pass 1: -5 5 10 23 0 -1 8 55 34 56 67 3 58 -9 99
//Pass 2: -5 5 10 0 -1 8 23 34 55 56 3 58 -9 67 99
//Pass 3: -5 5 0 -1 8 10 23 34 55 3 56 -9 58 67 99
//Pass 4: -5 0 -1 5 8 10 23 34 3 55 -9 56 58 67 99
//Pass 5: -5 -1 0 5 8 10 23 3 34 -9 55 56 58 67 99
//Pass 6: -5 -1 0 5 8 10 3 23 -9 34 55 56 58 67 99
//Pass 7: -5 -1 0 5 8 3 10 -9 23 34 55 56 58 67 99
//Pass 8: -5 -1 0 5 3 8 -9 10 23 34 55 56 58 67 99
//Pass 9: -5 -1 0 3 5 -9 8 10 23 34 55 56 58 67 99
//Pass 10: -5 -1 0 3 -9 5 8 10 23 34 55 56 58 67 99
//Pass 11: -5 -1 0 -9 3 5 8 10 23 34 55 56 58 67 99
//Pass 12: -5 -1 -9 0 3 5 8 10 23 34 55 56 58 67 99
//Pass 13: -5 -9 -1 0 3 5 8 10 23 34 55 56 58 67 99
//Pass 14: -9 -5 -1 0 3 5 8 10 23 34 55 56 58 67 99
//Last Pass: -9 -5 -1 0 3 5 8 10 23 34 55 56 58 67 99
//
//Sorted Array: -9 -5 -1 0 3 5 8 10 23 34 55 56 58 67 99
