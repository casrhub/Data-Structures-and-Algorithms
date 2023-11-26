#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

class Grafo {
    map<string, vector<string>> listaAdyacencia;

public:
    void agregarArista(const string& origen, const string& destino) {
        listaAdyacencia[origen].push_back(destino);
        listaAdyacencia[destino].push_back(origen);
    }

    int contarPuertosInaccesibles(const string& inicio, int mnp) {
        set<string> visitados;
        set<string> alcanzables;
        busquedaProfundidad(inicio, mnp, visitados, alcanzables);
        return listaAdyacencia.size() - alcanzables.size();
    }

    void imprimirGrafo() {
        for (const auto& par : listaAdyacencia) {
            for (const auto& vecino : par.second) {
                cout << par.first << " -> " << vecino << endl;
            }
        }
    }

private:
    void busquedaProfundidad(const string& nodo, int mnp, set<string>& visitados, set<string>& alcanzables) {
        if (mnp < 0) return;
        if (visitados.find(nodo) != visitados.end()) return;

        visitados.insert(nodo);
        alcanzables.insert(nodo);

        for (const string& vecino : listaAdyacencia[nodo]) {
            if (visitados.find(vecino) == visitados.end()) {
                set<string> ramaVisitada = visitados; // Crea una copia para cada rama
                busquedaProfundidad(vecino, mnp - 1, ramaVisitada, alcanzables);
            }
        }
    }

};

int main() {
    ifstream archivo("input.txt");
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    Grafo g;
    int numConexiones;
    archivo >> numConexiones;

    if (numConexiones > 30) {
        cerr << "Error: el número de puertos excede el máximo permitido de 30." << endl;
        return 1;
    }

    for (int i = 0; i < numConexiones; ++i) {
        string origen, destino;
        archivo >> origen >> destino;
        g.agregarArista(origen, destino);
    }

    cout << "Estructura del Grafo:" << endl;
    g.imprimirGrafo();

    int numConsultas;
    archivo >> numConsultas;

    for (int i = 1; i <= numConsultas; ++i) {
        string inicio;
        int mnp;
        archivo >> inicio >> mnp;
        cout << "Caso " << i << ": " << g.contarPuertosInaccesibles(inicio, mnp)
            << " puertos no accesibles desde el puerto " << inicio << " con MNP = " << mnp << "." << endl;
    }

    archivo.close();
    return 0;
}
