#include <iostream>

class Node { // Declaración de clase nodo 
    public:
    int value;
    Node *next; // apuntador hacia la dirección del siguinete valor 
};

void printL (Node* n){
    while( n != NULL){
        std::cout << n->value << std::endl;
        n = n->next; // actualizar n 
    }
}
void insertFront (Node**head, int insertValue){ // tenemos un puntero a puntero ya que se 
// modificara la dirección de la cabeza Si fuera Node * estrai apuntando al objeto node
// Node** apunta hacia la memoria donde el puntero head existe 
Node * newNode = new Node(); // Creación de nuevo nodo a inertar
newNode->value = insertValue; // Asignación de valor a nuevo nodo
newNode->next = *head; // El nuevo nodo ahora se asigna la dirección
*head = newNode; // la dirección de la cabeza ahora esta en su nuevo lugar
}

void insertEnd (Node**head, int insertValue){
    Node * newNode = new Node();
    newNode->value = insertValue;
    newNode->next = NULL;
    if(*head == NULL ){
        *head = newNode;
        return;
    }



}
int main ()
{
    Node* head = new Node(); // Creación de nodo cabeza 

    head ->value = 1; // primer valor = 1  
    head ->next = NULL; // Apunta a null ya que no existe un nuevo elemento al cual apuntar
    // CREATE
    // Insertar al principio
    insertFront (&head, 69); // la función recibe la dirección de la cabeza y el valor a insertar
    printL(head);


}

