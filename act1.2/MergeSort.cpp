#include <iostream>

// Merge function to merge two sorted vectors and count comparisons
#include <iostream>
#include <vector>

int merge(std::vector<int>& vect, int inicio, int medio, int fin) {
    int comparaciones = 0;

    int n1 = medio - inicio + 1;
    int n2 = fin - medio;

    std::vector<int> izq(n1);
    std::vector<int> der(n2);

    for (int i = 0; i < n1; i++) {
        izq[i] = vect[inicio + i];
    }
    for (int i = 0; i < n2; i++) {
        der[i] = vect[medio + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = inicio;

    while (i < n1 && j < n2) {
        if (izq[i] <= der[j]) {
            vect[k] = izq[i];
            i++;
        } else {
            vect[k] = der[j];
            j++;
        }

        k++;
        comparaciones++;
    }

    while (i < n1) {
        vect[k] = izq[i];
        i++;
        k++;
    }

    while (j < n2) {
        vect[k] = der[j];
        j++;
        k++;
    }

    return comparaciones;
}

int mergeSort(std::vector<int>& vect, int inicio, int fin) {
    int comparaciones = 0;

    if (inicio < fin) {
        int medio = inicio + (fin - inicio) / 2;

        comparaciones += mergeSort(vect, inicio, medio);
        comparaciones += mergeSort(vect, medio + 1, fin);

        comparaciones += merge(vect, inicio, medio, fin);
    }

    return comparaciones;
}
