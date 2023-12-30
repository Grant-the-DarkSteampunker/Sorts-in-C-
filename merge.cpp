#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i != size - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

void merge(int arr[], int left, int middle, int right) {
    int size1 = middle - left + 1;
    int size2 = right - middle;

    int leftArray[size1];
    int rightArray[size2];

    for (int l = 0; l < size1; l++) {
        leftArray[l] = arr[left + l];
    }
    for (int r = 0; r < size2; r++) {
        rightArray[r] = arr[middle + 1 + r];
    }

    int l = 0;
    int r = 0;
    int k = left;

    while (l < size1 && r < size2) {
        if (leftArray[l] <= rightArray[r]) {
            arr[k] = leftArray[l];
            l++;
        } else {
            arr[k] = rightArray[r];
            r++;
        }
        k++;
    }

    while (l < size1) {
        arr[k] = leftArray[l];
        l++;
        k++;
    }

    while (r < size2) {
        arr[k] = rightArray[r];
        r++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        cout << "Split: "; // Disp current state of the array before splitting and sorting
        for (int i = left; i <= right; i++) {
            cout << arr[i];
            if (i != right) {
                cout << ", ";
            }
        }
        cout << endl;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);

        cout << "Merge: "; // Disp current state of the array after merging
        for (int i = left; i <= right; i++) {
            cout << arr[i];
            if (i != right) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

int main() {

    int arraySize; //input
    cout << "Enter the size of the array: ";
    cin >> arraySize;
    int arr[arraySize];
    cout << "Enter " << arraySize << " integers, separated by spaces:" << endl;
    for (int i = 0; i < arraySize; ++i) {
        cin >> arr[i];
    }
    int size = arraySize;
    mergeSort(arr, 0, size - 1);
    cout << "Sorted array: ";
    printArray(arr, size);
return 0;                      
}

//Enter the size of the array: 10
//Enter 10 integers, separated by spaces:
//9 4 66 32 99 21 50 21 67 39
//Split: 9, 4, 66, 32, 99, 21, 50, 21, 67, 39
//Split: 9, 4, 66, 32, 99
//Split: 9, 4, 66
//Split: 9, 4
//Merge: 4, 9
//Merge: 4, 9, 66
//Split: 32, 99
//Merge: 32, 99
//Merge: 4, 9, 32, 66, 99
//Split: 21, 50, 21, 67, 39
//Split: 21, 50, 21
//Split: 21, 50
//Merge: 21, 50
//Merge: 21, 21, 50
//Split: 67, 39
//Merge: 39, 67
//Merge: 21, 21, 39, 50, 67
//Merge: 4, 9, 21, 21, 32, 39, 50, 66, 67, 99
//Sorted array: 4, 9, 21, 21, 32, 39, 50, 66, 67, 99

