#include <iostream>
#include <vector>
using namespace std;

// Merge para MergeSort
void Merge(vector<int>& nums, int inicio, int mitad, int fin, int& comparaciones) {
    vector<int> aux(fin + 1); // Vector auxiliar para almacenar el resultado fusionado
    int i = inicio, j = mitad + 1, k = inicio;

    while (i <= mitad && j <= fin) {
        if (nums[i] < nums[j]) { // Comparar los elementos de los subarreglos
            aux[k] = nums[i];
            i++;
        }
        else {
            aux[k] = nums[j];
            j++;
        }
        k++;
        comparaciones++;
    }

    while (i <= mitad) {
        aux[k] = nums[i];
        i++;
        k++;
    }

    while (j <= fin) {
        aux[k] = nums[j];
        j++;
        k++;
    }

    for (k = inicio; k <= fin; k++) {
        nums[k] = aux[k];
    }
}

// Ordenamiento por MergeSort
void ordenaMerge(vector<int>& nums, int inicio, int fin, int& comparaciones) {
    if (inicio < fin) {
        int mitad = (inicio + fin) / 2;
        ordenaMerge(nums, inicio, mitad, comparaciones); // "Conquer"
        ordenaMerge(nums, mitad + 1, fin, comparaciones); // "Conquer"
        Merge(nums, inicio, mitad, fin, comparaciones); // "Combine"
    }
}
