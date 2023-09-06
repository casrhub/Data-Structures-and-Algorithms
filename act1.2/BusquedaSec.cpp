#include <iostream>
#include <vector>

std::pair<int, int> busquedaSecuencial(std::vector<int>& v, int dato) {
    int comparaciones = 0;
    for (int i = 0; i < v.size(); i++) {
        comparaciones++;
        if (v[i] == dato) {
            return std::make_pair(i, comparaciones);
        }
    }
    // Si no se encontró el número, devolvemos -1 como posición y el número de comparaciones
    return std::make_pair(-1, comparaciones);
}

