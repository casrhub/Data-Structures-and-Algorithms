#include "HashTable.h"
#include <sstream>

Ht::Ht(){
    prime = 2029;
    table.resize(prime);


}
// algoritmo hash para pasar de string a código
// el número primo ayuda a evitar colisiones
int Ht::hash(std::string key){
    int hashValue = 0; // lista de listas 
    for (char c : key){
        hashValue = (hashValue * 31 + c) % prime; // n primo grande 
    }
    return hashValue;
}

// Insertar key, value pair OJO: hasheando el key (str)
void Ht::insert(std::string key, int value){
    int index = hash(key);// insertamos en lindex de llave ya con codigo hash 
    table[index].push_back(std::make_pair(key,value));
    
}

int Ht::salary(std::string jobDescription){
    std::istringstream iss(jobDescription);// usamos iss para tratar la descripción como un cin 
    std::string word;
    int salary = 0;
    while (iss >> word){ // mientras iss tenga datos de jobDescripion
        int hashWord = hash(word);
        for (auto i = table[hashWord].begin(); i != table[hashWord].end(); i++) // con las letras hasheadas empezamos desde el primer key 
        if (i->first == word){ // si el iterador en key es la misma que la palabra
            salary += i->second;
            break;
        } 
    }
    return salary;

}



