#pragma once 
#include <vector>

int ordenamientoIntercambio(std::vector<int> vector){
  int aux;
  int comparisons = 0;
  for (std::vector<int>::size_type i = 0; i < vector.size() - 1; i++){
    for (std::vector<int>::size_type j = i + 1; j < vector.size(); j++){
    comparisons++;
      if (vector[i] > vector[j]){
        aux = vector[i];
        vector[i] = vector[j];
        vector[j] = aux;
      }
    }
  }
  return comparisons;
  
}