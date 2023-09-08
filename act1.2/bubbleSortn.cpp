#include <vector>
using namespace std;

int bubbleSort(std::vector<int>& vect, int numDatos)
{
    int n = numDatos;
    int comparaciones = 0;
    bool interruptor = true;
    for (int i = 0; i < n - 1 && interruptor; i++) {
        interruptor = false;
        for (int j = 0; j < n - 1 - i; j++) {
            comparaciones++;
            if (vect[j + 1] < vect[j]) {
                int aux = vect[j];
                vect[j] = vect[j + 1];
                vect[j + 1] = aux;
                interruptor = true;
            }
        }
    }
    
    return comparaciones;
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

