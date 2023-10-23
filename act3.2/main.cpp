#include <vector>
#include <iostream>
#include <stdexcept>

class priority_queue {
public:
    priority_queue() {}

    void push(int value) {
        heap.push_back(value);// se mete el nuevo valor
        int index = heap.size() - 1; // se calcula el index
        while (index > 0) { 
            int parentIndex = (index - 1) / 2; // se calcual el index mayor
            if (heap[index] > heap[parentIndex]) { // si el index actual es mayor que el index padre entonces swap
                std::swap(heap[index], heap[parentIndex]);
                index = parentIndex; // y el index actual se vuelve el nuevo padre
            } else {
                break;
            }
        }
    }


    int pop() {
        if (isEmpty()) {
            throw std::runtime_error("La lista priorizada esta vacía");
        }

        int top = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        // Se checan los elementos para reordenar

        int index = 0;
        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
                largest = leftChild;
            }

            if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
                largest = rightChild;
            }

            if (largest != index) {
                std::swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }

        return top;
    }

    int top() const {
        if (isEmpty()) {
            throw std::runtime_error("La lista priorizada esta vacía");
        }
        return heap[0]; // se regresa el primer elemento
    }

    bool isEmpty() const {
        return heap.empty(); // se checa si esta vacía con función 
    }

    size_t size() const {
        return heap.size(); // se checa el tamaño con función 
    }

private:
    std::vector<int> heap; // Solo debe de ser accsesada dentro de la misma clase
};

int main() {
    priority_queue pq;

// Agregamos elementos
    pq.push(299);
    pq.push(792);
    pq.push(420);
    pq.push(2);
// Sacamos el elemento de mayor prioridad 
    pq.pop();
  


    if (!pq.isEmpty()) {
// Se checa si la fila esta vacía 
    std::cout << "La fila no esta vacía" <<std::endl; 
// Se regresa la cantidad de datos en la fila   
    std::cout << "Existen " << pq.size() << " datos en la fila priorizada" <<std::endl; 
// Se devuelve el elemento con mayor prioridad  
    std::cout << "El elemento con mayor prioridad es: " << pq.top() << std::endl;    
    std::cout << "Elementos en la fila priorizada: ";
    while (!pq.isEmpty()) {
        std::cout << pq.top() << " ";
        pq.pop();
     }
    std::cout << std::endl;
    } else {
        std::cout << "La lista esta vacía" << std::endl;
    }


    



   

    return 0;
}
