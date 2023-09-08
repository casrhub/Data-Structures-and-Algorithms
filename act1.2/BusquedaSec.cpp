#include <iostream>
#include <vector>
#include "globals.h"

// Esta busqueda fue utilzada para sacar los indexes por eso retorna posiciones

int busquedaSecuencial(std::vector<int>& v, int dato) {
    for (int i = 0; i < v.size(); i++) {
        comparacionesGlobales++;
        if (v[i] == dato) {
            return i; 
        }
    
    }
    return -1;
}