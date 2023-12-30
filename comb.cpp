#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int getNextGap(int gap) {
    gap = (gap * 10) / 13;
    if (gap < 1) {
        return 1;
    }
    return gap;
}

void combSort(int arr[], int size) {
    int gap = size;
    bool swapped = true;

    while (gap != 1 || swapped) {
        gap = getNextGap(gap);
        swapped = false;

        for (int i = 0; i < size - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }

        // Display the current state of the array after each pass
        cout << "Gap " << gap << ": ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[] = {10, -5, 5, 55, 23, 0, -1, 8, 99, 34, 56, 67, 3, 58, -9};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Initial Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    combSort(arr, size);

    cout << "\nSorted Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


//Initial Array: 10 -5 5 55 23 0 -1 8 99 34 56 67 3 58 -9
//
//Gap 11: 10 -5 5 -9 23 0 -1 8 99 34 56 67 3 58 55
//Gap 8: 10 -5 5 -9 3 0 -1 8 99 34 56 67 23 58 55
//Gap 6: -1 -5 5 -9 3 0 10 8 55 34 56 67 23 58 99
//Gap 4: -1 -5 5 -9 3 0 10 8 23 34 56 67 55 58 99
//Gap 3: -9 -5 0 -1 3 5 10 8 23 34 56 67 55 58 99
//Gap 2: -9 -5 0 -1 3 5 10 8 23 34 55 58 56 67 99
//Gap 1: -9 -5 -1 0 3 5 8 10 23 34 55 56 58 67 99
//Gap 1: -9 -5 -1 0 3 5 8 10 23 34 55 56 58 67 99
//
//Sorted Array: -9 -5 -1 0 3 5 8 10 23 34 55 56 58 67 99
