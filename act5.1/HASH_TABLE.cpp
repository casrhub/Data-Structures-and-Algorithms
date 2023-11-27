#include "HASH_TABLE.h"
#include <cmath>
#include <iostream>


HASH_TABLE::HASH_TABLE(int size) : table(size) {} // O(n)

int HASH_TABLE::hash_tech(int key) { 
    return key % table.size(); 
}

void HASH_TABLE::disp_tab() { 
    for (const auto& lista : table) {
            if(lista.empty()){
                std::cout<<"null"<<std::endl;
            }
            else{
                for (const auto& elemento : lista) {
                std::cout << elemento << " ";
                }
                std::cout << std::endl;
            }
    
        }
        std::cout << std::endl;

}

void HASH_TABLE::quadratic(int key) { // O(n)
    int index_hash = hash_tech(key); // O(1)
    if (table[index_hash].empty()) { // O(1)
        table[index_hash].push_back(key); // O(1)
    } else {
        int i = 1; // O(1)
        while (!table[(index_hash + i*i) % table.size()].empty()) { // O(n)
            i++; // O(1)
        }
        table[(index_hash + i*i) % table.size()].push_back(key); // O(1)
    }
}

void HASH_TABLE::chain(int key) { // O(1)
    int index_hash = hash_tech(key); // O(1)
    table[index_hash].push_back(key); // O(1)
}