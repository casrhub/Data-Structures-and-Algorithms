#include "HashTable.cpp"
#include "HashTable.h"
#include <iostream>
#include <fstream>

int main (){
    for (int inputFileN = 1; inputFileN <=4; ++inputFileN){
        std::ifstream inputFile("input" + std::to_string(inputFileN) + ".txt");
        if (!inputFile){
            std::cerr << "El archivo de entrada " << inputFileN << " no existe" << std::endl;
            return 1; 
        }
        Ht hashTable;
        int m , n; 
        inputFile >> m >> n; // leemos m cantidad de key/value y n descripciones

        for (int i = 0; i < m; ++i){// dependiendo de la cantidad de key/values que existan en el .txt llenarmeos la tabla hash hasta que no existan mas ms
            std::string key;
            int value;
            inputFile >> key >> value;
            hashTable.insert(key,value);
        }

          std::cout << "Prueba número " << inputFileN << std::endl; 

          for (int i = 0; i < n; ++i){
            std::string jobDescription, l;
            while(std::getline(inputFile, l) && l != "."){
                jobDescription += l + " "; // se guarda la linea y el string 
            }
            int salary = hashTable.salary(jobDescription);
            std::cout << salary << std::endl;
          }
          inputFile.close();
          std::cout << "---------------------" << std::endl;
    }
    return 0;
}