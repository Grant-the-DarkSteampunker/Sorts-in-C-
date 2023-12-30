#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform bucket sort
void bucketSort(vector<int>& arr, int minRange, int maxRange, int numBuckets) {
    if (arr.empty() || minRange > maxRange || numBuckets <= 0) {
        return;
    }

    // Calculate the range of values in each bucket
    double bucketRange = static_cast<double>(maxRange - minRange + 1) / numBuckets;

    // Create buckets
    vector<vector<int>> buckets(numBuckets);

    // Scatter elements into buckets
    for (int num : arr) {
        int bucketIndex = static_cast<int>((num - minRange) / bucketRange);
        // Ensure the index is within bounds
        bucketIndex = min(bucketIndex, numBuckets - 1);
        buckets[bucketIndex].push_back(num);
    	for (int i = 0; i < numBuckets; i++) {
    	cout << " Bucket " << i + 1 << ": ";
    	for (int num : buckets[i]) {
        cout << num << " ";
    		}
		}
		cout << endl;
    }
    
    // Gather elements from buckets back into the original array
    arr.clear();
    for (vector<int>& bucket : buckets) {
        for (int num : bucket) {
            arr.push_back(num);
        }
    }
    
    
    // Sort elements within each bucket
    for (vector<int>& bucket : buckets) {
    sort(bucket.begin(), bucket.end());
    }
    
    // Gather elements from buckets back into the original array
    arr.clear();
    for (vector<int>& bucket : buckets) {
        for (int num : bucket) {
            arr.push_back(num);
        }
    }
    
}

// Function to display the contents of a vector
void displayVector(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10, 5, -5, 55, 23, 0, -1, 8, 99, 34, 56, 67, 3, 58, -9};
    int minRange = -10; // Minimum value in your range
    int maxRange = 100; // Maximum value in your range
    int numBuckets = 9; // Number of buckets to use
	int qou = (maxRange - minRange)/numBuckets;
	
	cout << "Range: " << minRange << '-' << maxRange << endl;
	cout << "Bucket Range: " << 0 << '-' << qou << endl << endl;
	
    cout << "Original Array: ";
    displayVector(arr);
    cout << endl;
    
    bucketSort(arr, minRange, maxRange, numBuckets);
	
	cout << "Bucket Sort Output: ";
    displayVector(arr);
    cout << endl;

    return 0;
}

