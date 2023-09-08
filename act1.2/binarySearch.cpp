#include <vector>
int busquedaBin(std::vector<int>& vec_data, int clave) {
    int central, bajo, alto, valorCentral;
    int comparaciones = 0; 
    bajo = 0;
    alto = vec_data.size() - 1;

    while (bajo <= alto) {
        central = (bajo + alto) / 2;
        valorCentral = vec_data[central];
        comparaciones++;

        if (clave == valorCentral)
            return comparaciones; 
        else if (clave < valorCentral)
            alto = central - 1;
        else
            bajo = central + 1;
    }
    return comparaciones; 
}
