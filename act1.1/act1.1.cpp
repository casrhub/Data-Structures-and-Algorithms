// Cálculo de sumatorias hasta n utilizando recursividad, iteración y suma directa  

// Problema: Calcular la suma desde 1 hasta un numero determinado n 
//Input: número entero positivo 
//Output: número entero positivo como suma 

// Ejemplos
// Input: 3
// Output: 6
// 1 + 2 + 3 = 6

#include <iostream>
#include <fstream>
using namespace std; 

// Imaginarse este for como un array creado aparte, es decir no se itera sobre n si no que se itera
// Utilizando n 
int sumaIterativa (int n){ // O(n)
    int sum = 0;
    for (int i = 1; i <= n ; i++){
        sum += i;
    }
    return sum; 
}

// Son niveles imaginarse una forma "iterativa" en la que n va disminuyendo 

int sumaRecursiva(int n){ //O(n)
    if (n <= 0){
        return 0;
    }
    else return n + sumaRecursiva(n-1);
}
// Forma matematica de resolverlo  O(1)
int sumaDirecta(int n){
    if ( n > 0){
        return n * (n + 1)/2;
    }else{
        return 0; 

    }
    
}

int main (){
    ifstream myFile;
    myFile.open("ns.txt");
    if (myFile.is_open()) {
        int num;
        while (myFile >> num) {
            if (num >= 0) {
                cout << "---------------------------------------------------" << endl;
                cout << "La suma de 1 hasta " << num << " de manera iterativa es: " << sumaIterativa(num) << endl;
                cout << "La suma de 1 hasta " << num << " de manera recursiva es: " << sumaRecursiva(num) << endl;
                cout << "La suma de 1 hasta " << num << " de manera directa es: " << sumaDirecta(num) << endl;
            } else {
                cout << "---------------------------------------------------" << endl;
                cout << "Se ingreso el número negativo "<< num << " .Por favor ingrese un entero positivo en el archivo." << endl;
            }
        }
        myFile.close();
    }

    return 0;
 
 
}


