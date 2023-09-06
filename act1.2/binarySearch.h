#ifndef MY_COMPUTATIONS_HPP
#define MY_COMPUTATIONS_HPP

#include <vector>

int busquedaBin(std::vector<int>& vec_data, int clave) {
    int central, bajo, alto, valorCentral;
    bajo = 0;
    alto = vec_data.size() - 1;
    while (bajo <= alto) {
        central = (bajo + alto) / 2;
        valorCentral = vec_data[central];
        if (clave == valorCentral)
            return central;
        else if (clave < valorCentral)
            alto = central - 1;
        else
            bajo = central + 1;
    }
    return -1;
}

#endif
