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
#include "globals.h"

// Complejidad de algoritmos de ordenamiento:

// Bubble Sort: Este algoritmo cuenta con una complejidad de O(n^2) ya que cuenta con dos fors anidados.
// El primer bucle recorre todo el vector mientras que el segundo for se ejecuta con respecto a la cantidad de elemntos
// n del primer ciclo. Entonces tenemos que ambas iteraciones dependen del tamaño n del vector, en el peor de los casos se harían n^2
// comparaciones.

// Ordenamiento de intercambio: Cuenta con una complejidad de O(n^2). Ya que como bubble sort, este tiene dos ciclos for anidados, lo que 
// causa n^2 comparaciones. De igual manera el primer bucle recorre todo el vector mientras que el segundo se ejecuta con relación a la cantidad
// de elementos.

// Merge sort: En este algoritmo tenemos una mejora ya que su complejidad temporal es de O(nlog(n)), en el cual n representa el número de 
// elementos en el vector a ordenar. La recursión en el algoritmo se divide en log(n) niveles y en cada nivel se realizan n comparaciones
// en la fusión de mitades por lo tanto por cada log(n) como formas de divisones existe una n para comparar esa fusión de mitades.

// Complejidad de algoritmos de busqueda: 

// Busqueda binaria: Este algoritmo tiene una complejidad temporal de O(log(n)) donde n representa el número
// de elementos dentro del vector. Este, divide repetidamente el espacio de busqueda por la mitad , cada vez reduciendo el 
// número de elementos por iteración lo cual basícamnte se traduce a log(n). Por cada iteración tendremos reducción por mitades lo
// cual hace que sea bastante eficiente para buscar elementos en vectores arreglados.

// Busqueda Secuencial: En este algoritmo tenemos una complejidad de O(n) ya que contamos con solo un ciclo for
// dependiente de la cantidad de elementos del vector n, este for itera csobre cada elemento del vector donde ene el 
// peor de los casos el número a buscar se encotrara al final del vetor lo que resulta en una complejidad lineal O(n) 




int comparacionesGlobales = 0;

int main(){

    // Primer lectura para agrarrar los numeros que se leeran 
    std::ifstream inputFile("input.txt");
    int numElementosOrdenar; // Cantidad de elementos a ordenar
    inputFile >> numElementosOrdenar;
    std::cout << "El número de elementos a ordenar es: " << numElementosOrdenar << std::endl;

// Lectura de elemntos del vector de numeros a ordenar y print de ellos
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
    std::cout << "Los numeros de comparaciones de ordeanmiento de bubbleSort, Intercambio y Merge son: " << std::endl;

    std::cout << bubbleSort(numbers, numElementosOrdenar)  << " " << ordenamientoIntercambio(numbers) << " "<< mergeSort(numbers,0,numbers.size()-1) << std::endl;    


    int numElementosBuscar; // Cantidad de elementos a buscar
    inputFile >> numElementosBuscar;
    std::cout << "El contenido del vector de elementos a ordenar es: " << numElementosBuscar << std::endl;

// Lectura de elemntos del vector y print de ellos
    std::vector<int> numbersToSearch;

    for (int i = 0; i < numElementosBuscar; i++ ){
        int number;
        if (inputFile >> number){
            numbersToSearch.push_back(number);
        }
    }

    std::cout << "El contenido del vector de elementos a bucscar es: ";
    for (int i = 0; i < numbersToSearch.size(); i++) {
    std::cout << " " << numbersToSearch[i];
    }
    std::cout << std::endl;

    // Funcion para return de vector ordenado:
    std::vector<int> sortedNumbers = bubbleSortVector(numbers);

    

   // Busqueda de numeros del vector sortedNumbers

  for (int i = 0; i < numbersToSearch.size(); i++) {
    int elementToSearch = numbersToSearch[i];
    int indexes = busquedaSecuencial(sortedNumbers, elementToSearch);
    int comparacionesBinarias = busquedaBin(sortedNumbers, elementToSearch);
    //La linea de abajo imprime el index del numero, numero de comparaciones hechas con busqueda Secuenciual y comparaciones hechas con
    std::cout << "El index del elemento: " << elementToSearch << " es: " << indexes << " Numero de comparaciones con busqueda secuencial: " << comparacionesGlobales << " Número de comparaciones con Bubble Sort: " << comparacionesBinarias<<std::endl;
    comparacionesGlobales = 0;
}


// Info en un output.txt como lo pide el profe

 // Open the output file for writing
    std::ofstream outputFile("output.txt");

    if (outputFile.is_open()) {

        
        // Indez, comparaciones secuenciales y comparaciones binarias
        outputFile << bubbleSort(numbers, numElementosOrdenar) << " " << ordenamientoIntercambio(numbers) << " " << mergeSort(numbers, 0, numbers.size() - 1) << std::endl;
         for (int i = 0; i < numbersToSearch.size(); i++) {
            int elementToSearch = numbersToSearch[i];
            int indexes = busquedaSecuencial(sortedNumbers, elementToSearch);
            int comparacionesBinarias = busquedaBin(sortedNumbers, elementToSearch);
            
            // Escritura en output.txt
            outputFile <<  indexes << " " << comparacionesGlobales << " " << comparacionesBinarias << std::endl;
            
            comparacionesGlobales = 0;
        }
        std::cout << " " <<std::endl;
        std::cout << "Los resultados se han guardado en output.txt " <<std::endl;
    

        // Close the output file
        outputFile.close();
    } else {
        std::cerr << "Unable to open output file." << std::endl;
    }


}