#include "Graph.cpp"
#include "Graph.h"

#include <vector>
// Notas
// Orden topológico:
// tipo de orden en grafos dirigidos en el cual por cada link de nodo A a B
// el nodo A debe de aparecer primero que el nodo B

// Para determinar si un gráfo es bipartito usar la regla de los dos colores (blanco, rojo)
// Para saber si un gráfo es árbol checar ciclicidad
int main() {
    // primer grafo: árbol y bipartito
    // 4---3---2---1---0
    int numVertices1 = 5;
    std::vector<std::pair<int, int>> arcos1 = {{4, 3}, {3, 2}, {2, 1}, {1, 0}};
    Grafo g1(numVertices1);
    g1.loadGraph(numVertices1, arcos1.size(), arcos1);
    g1.printGraph();
    std::cout << "El grafo 1 " << (g1.isTree() ? "sí es" : "no es") << " un árbol"<< std::endl;
    std::cout << "El grafo 1 " << (g1.bipartiteGraph() ? "sí es" : "no es") << " bipartito"<< std::endl;
    std::cout << "Orden topológico del grafo 1: ";
    g1.topologicalSort();
    std::cout << "\n";
    std::cout << "--------------------------------------------" <<std::endl;

    // segundo grafo: no árbol y no bipartito
    // 0---1---2---3
    // |           |
    // 4------6-----5
    int numVertices2 = 7;
     std::vector<std::pair<int, int>> arcos2 = {{0, 1}, {1, 2}, {2, 3}, {3,5},{5,6},{6,4},{4,0}};
    Grafo g2(numVertices2);
    g2.loadGraph(numVertices2, arcos2.size(), arcos2);
    g2.printGraph();
    std::cout << "El grafo 2 " << (g2.isTree() ? "sí es" : "no es") << " un árbol"<< std::endl;
    std::cout << "El grafo 2 " << (g2.bipartiteGraph() ? "sí es" : "no es") << " bipartito"<< std::endl;
    std::cout << "Orden topológico del grafo 2: ";
    g2.topologicalSort();
    std::cout << "\n";
    std::cout << "--------------------------------------------" <<std::endl;

    // tercer grafo: árbol y bipartito
    // 0---1---2---3 (árbol lineal) :)
    int numVertices3 = 4;
    std::vector<std::pair<int, int>> arcos3 = {{0, 1}, {1, 2}, {2, 3}};
    Grafo g3(numVertices3);
    g3.loadGraph(numVertices3, arcos3.size(), arcos3);
    g3.printGraph();
    std::cout << "El grafo 3 " << (g3.isTree() ? "sí es" : "no es") << " un árbol"<< std::endl;
    std::cout << "El grafo 3 " << (g3.bipartiteGraph() ? "sí es" : "no es") << " bipartito"<< std::endl;
    std::cout << "Orden topológico del grafo 3: ";
    g3.topologicalSort();
    std::cout << "\n";
    std::cout << "--------------------------------------------" <<std::endl;

    // cuarto grafo: no árbol y bipartito
    //     4
    //     |
    // 0---1---5
    // |   |
    // 3---2
    //    
    //     
    int numVertices4 = 6;
    std::vector<std::pair<int, int>> arcos4 = {{4,1},{1,2},{2,3},{3,0},{0,1},{1,5}};
    Grafo g4(numVertices4);
    g4.loadGraph(numVertices4, arcos4.size(), arcos4);
    g4.printGraph();
    std::cout << "El grafo 4 " << (g4.isTree() ? "sí es" : "no es") << " un árbol"<< std::endl;
    std::cout << "El grafo 4 " << (g4.bipartiteGraph() ? "sí es" : "no es") << " bipartito"<< std::endl;
    std::cout << "Orden topológico del grafo 4: ";
    g4.topologicalSort();
    std::cout << "\n";

    return 0;
}