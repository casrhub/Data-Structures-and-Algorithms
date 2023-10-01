#include <iostream>

class Node { // Clase nodo para cada elemento 
    public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {} // constructor inicializado con puntero a nullptr ya que
    // el stack comienza vacio

};

class Stack { // clase Stack 
    private: 
    Node * top;
    int size;
    int max_size;
    public:
    Stack(int max_size) : top (nullptr), size(0),max_size(max_size) {} // constructor inicializado 

    bool isFull (){
        if (max_size == 0){
            return false;
        } else if (size >= max_size){
            std::cout << "El stack esta lleno" << std::endl;
        }
        return size >= max_size;
    }
    bool isEmpty (){
        if (size == 0){
            std::cout << "El stack esta vacio" << std::endl;
        } else if (size != 0){
            std::cout << "El stack no esta vacio :)" << std::endl;  
        }
        return size == 0; 
    }

    void push (int value){
        Node * newNode = new Node(value); // Crear nuevo nodo a isnertar 
        std::cout << "Se ha pusheado el elemento: " <<value <<std::endl;
        newNode->next = top; // El puntero del nuevo nodo siguinete es top
        top = newNode; // El tope ahora es el nuevo nodo 
        size ++; // incrementanr la variable size cada vez que se cree un nuevo nodo 
    }

    void pop (){
        if (size == 0){
            std::cout << "El stack esta vacío, métele valores con push()" << std::endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        std::cout << "Se ha popeado el elemnto: " << temp->data << std::endl;
        delete temp;
        size--;  
    }

    void Top (){
        if (size == 0){
            std::cout << "El stack esta vacio." << std::endl;
            return;
        }

        std::cout << "El elemento hasta arriba del stack es: " << top->data <<std::endl;
       
    }

    void printStack (){
        Node* current = top;
        std::cout << "El contenido del stack es: " << std::endl;
        while (current != nullptr){
            std::cout << current->data << " " <<std::endl;
            current = current->next;
        }
    }

};



int main()
{
    // El stack se lee como si fuera una torre, el elemnto hasta arriba es el último elemento agregado mientras
    // que el de hasta abajo fue el primer elemento agregado
    Stack stack(5);
    // push() 
    stack.push(3);
    stack.push(420);
    stack.push(777);
    stack.push(666);
    stack.push(1000);
    // Top ()
    stack.Top();
    // isFull()
    stack.isFull();
    stack.printStack();
    // pop()
    stack.pop();
    stack.pop();
    stack.printStack();
    stack.pop();
    stack.pop();
    stack.pop();
    // isEmpty()
    stack.isEmpty();
}

