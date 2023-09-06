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
