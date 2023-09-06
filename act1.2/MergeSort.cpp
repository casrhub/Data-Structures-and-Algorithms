#include <iostream>
#include <vector>

// Merge function to merge two sorted vectors and count comparisons
int merge(std::vector<int>& arr, std::vector<int>& left, std::vector<int>& right) {
    int i = 0, j = 0, k = 0;
    int comparisons = 0; // Initialize comparison count

    while (i < left.size() && j < right.size()) {
        comparisons++; // Increment comparison count
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < left.size()) {
        arr[k++] = left[i++];
    }
    while (j < right.size()) {
        arr[k++] = right[j++];
    }

    return comparisons;
}

// Recursive Merge Sort function to sort the vector and count comparisons
int recursiveMergeSort(std::vector<int>& arr) {
    int size = arr.size();
    if (size <= 1) {
        return 0; // No comparisons needed for an empty vector or a single element
    }
    int mid = size / 2;

    // Split the vector into left and right halves
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());

    // Recursively sort the left and right halves and get their comparison counts
    int leftComparisons = recursiveMergeSort(left);
    int rightComparisons = recursiveMergeSort(right);

    // Merge the sorted halves back and count comparisons
    int mergeComparisons = merge(arr, left, right);

    // Return the total comparison count
    return leftComparisons + rightComparisons + mergeComparisons;
}

