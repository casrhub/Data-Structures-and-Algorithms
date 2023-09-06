#include <iostream>
#include <fstream>
#include <vector>
// funciones de ordenamiento 
#include "bubbleSortn.cpp"
#include "ordenamientoInt.cpp"
#include "MergeSort.cpp"
// funciones de busqueda 
#include "BusquedaSec.cpp"
#include "binarySearch.h"
 
// Variables para comparaciones de ordenamiento 


int main(){

    // Lectura de archivo

    std::ifstream inputFile("input.txt");
    int numElementosOrdenar; // Cantidad de elementos a ordenar
    inputFile >> numElementosOrdenar;
    std::cout << "El número de elementos a buscar es: " << numElementosOrdenar << std::endl;

// Lectura de elemntos del vector y print de ellos
    std::vector<int> numbers;

    for (int i = 0; i < numElementosOrdenar; i++ ){
        int number;
        if (inputFile >> number){
            numbers.push_back(number);
        }
    }

    std::cout << "Los elementos del vector son:";
    for (int i = 0; i < numbers.size(); i++) {
    std::cout << " " << numbers[i];
    }
    std::cout << std::endl;

    // Uso funciones de ordenamiento en vector (numbers)

    std::cout << bubbleSort(numbers, numElementosOrdenar) << std::endl;
    std::cout << ordenamientoIntercambio(numbers) << std::endl;
    std::cout << recursiveMergeSort(numbers) << std::endl;

    // Uso de funciones de busqueda 
// Pendientes: 
// 1. hacer que las funciones de busqueda sirvan 
// 2. leer del .txt los numeros que faltan
// 3. imprimir el output en un .txt
// 4. checar si son correctas las comparaciones de las funciones de busqueda





    // file close 








}