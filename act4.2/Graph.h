#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <vector>
#include <stack>

class Grafo {
private:
    int V; // Número de vértices
    std::vector<std::vector<int>> matrizAdj; // Matriz de adyacencia
    std::map<int, std::list<int>> listaAdj; // Lista de adyacencia

    // Función auxiliar para DFS
    void DFSUtil(int v, std::vector<bool>& visited);

public:
    // Constructor
    Grafo(int V);

    // Función para cargar el grafo
    void loadGraph(int n, int m, std::vector<std::pair<int, int>>& edges);


    // Función para verificar si el grafo es un árbol
    bool isTree();

    
    // Función para realizar un ordenamiento topológico del grafo
    void topologicalSort();
    // Función auxiliar para realizar un ordenamiento topológico del grafo
    void topologicalSortUtil(int v, std::vector<bool>& visited, std::stack<int>& Stack);

    // Función para verificar si el grafo es bipartito
    bool bipartiteGraph();
    // Función auxiliar para verificar si el grafo es bipartito
    bool isBipartiteUtil(int v, std::vector<int>& color);



    // Función para imprimir el grafo
    void printGraph();
    // Función auxiliar para verificar si el grafo es un árbol
    bool isCyclicUtil(int v, std::vector<bool>& visited, int parent);
};

#endif 
