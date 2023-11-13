#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

void loadGraph(int n, vector<vector<int>>& adjacencyMatrix, vector<list<int>>& adjacencyList, ifstream& inputFile) {
    adjacencyMatrix.assign(n, vector<int>(n, 0));

    int i, j;
    while (inputFile >> i >> j) {
        adjacencyMatrix[i][j] = 1;
        adjacencyMatrix[j][i] = 1;

        adjacencyList[i].push_back(j);
        adjacencyList[j].push_back(i);
    }
}

void DFSUtil(int vertex, vector<bool>& visited, const vector<list<int>>& adjacencyList) {
    visited[vertex] = true;
    cout << vertex << " ";

    for (const auto& neighbor : adjacencyList[vertex]) {
        if (!visited[neighbor]) {
            DFSUtil(neighbor, visited, adjacencyList);
        }
    }
}

void DFS(const vector<list<int>>& adjacencyList, int initialNode) {
    int n = adjacencyList.size();
    vector<bool> visited(n, false);

    DFSUtil(initialNode, visited, adjacencyList);
}

void BFS(const vector<list<int>>& adjacencyList, int initialNode) {
    int n = adjacencyList.size();
    vector<bool> visited(n, false);

    // creación de queue para BFS
    queue<int> bfsQueue;

    // marcamos el nodo visitado 
    visited[initialNode] = true;
    bfsQueue.push(initialNode);

    cout << "\nBFS: " << endl;

    while (!bfsQueue.empty()) {
        // se saca el vertice y es impreso 
        int currentVertex = bfsQueue.front();
        bfsQueue.pop();
        cout << currentVertex << " ";

        for (const auto& neighbor : adjacencyList[currentVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                bfsQueue.push(neighbor);
            }
        }
    }

    cout << endl;
}


int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "No se pudo abrir el archivo" << endl;
        return 1;
    }

    int n, m;
    inputFile >> n >> m;

    vector<vector<int>> adjacencyMatrix;
    vector<list<int>> adjacencyList(n);

    loadGraph(n, adjacencyMatrix, adjacencyList, inputFile);

    cout << "Matriz de adyacencia:" << endl;
    for (const auto& row : adjacencyMatrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << "\nLista de adyacencia:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Vertice " << i << ": ";
        for (const auto& neighbor : adjacencyList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    int initialNode = 0;  // Nodo inicial 
    cout << "\nDFS " << ":" << endl;
    DFS(adjacencyList, initialNode);
    cout << " " << endl; 

    BFS (adjacencyList, initialNode);

    inputFile.close();

    return 0;
}
