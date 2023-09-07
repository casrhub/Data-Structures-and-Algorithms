#pragma once
#include <vector>

int bubbleSort(std::vector<int>& a, int n){
    int comparisons = 0;
    int tmp = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            comparisons++;
            if(a[j+1]<a[j]){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    return comparisons;
}


std::vector<int> bubbleSortVector(std::vector<int> input) {
    int n = input.size();
    bool swapped;

    do {
        swapped = false;

        for (int i = 0; i < n - 1; i++) {
            if (input[i] > input[i + 1]) {
                // Swap elements if they are in the wrong order
                std::swap(input[i], input[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);

    return input;
}

