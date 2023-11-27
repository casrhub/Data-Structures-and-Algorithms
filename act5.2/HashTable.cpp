#include "HashTable.h"
#include <sstream>

Ht::Ht(){
    prime = 2029;
    table.resize(prime);


}
// algoritmo hash para pasar de string a código
// el número primo ayuda a evitar colisiones
int Ht::hash(std::string key){
    int hashValue = 0;
    for (char c : key){
        hashValue = (hashValue * 31 + c) % prime;
    }
    return hashValue;
}

// Insertar key, value pair OJO: hasheando el key (string)
void Ht::insert(std::string key, int value){
    int index = hash(key);
    table[index].push_back(std::make_pair(key,value));
    
}

