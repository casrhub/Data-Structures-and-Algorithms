#include <iostream>

class Node { // Declaración de clase nodo 
    public:
    int value;
    Node *next; // apuntador hacia la dirección del siguinete valor 
};

void deleteFromMiddle(Node* prev){
    if (prev == nullptr || prev->next == nullptr){
        return;
    }
    Node* ndelete = prev->next;
    prev->next = ndelete->next;
    delete ndelete;

}

void deleteFromEnd(Node *head){
    Node * temp = head;
    while (temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next = NULL;
}

void updateData (Node * head, int target, int updateValue){
    Node* current = head;
    while (current != NULL){
        if (current->value == target){
            current->value = updateValue; 
        }
        current = current->next;
    }

}

bool search (Node * head, int target){
    Node* current = head;
    while(current != NULL){
        if (current->value == target){
            std::cout << "Se encontro el elemento " << target << " en la lista" << std::endl;
            return true;
        }
        current = current->next;
    }
    std::cout << "No se encontro el elemento" <<target << "en la lista" << std::endl;
    return false;
}
void insertGivenNode (Node*prev, int insertValue){
    if (prev == NULL){
        std::cout << "No se pude instertar en el nodo especifíco si la lista esta vacía";
        return;
    }
    Node * newNode = new Node();
    newNode->value = insertValue;

    newNode->next=prev->next;
    prev->next = newNode;

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
    Node * newNode = new Node(); // Preparamos nodo a insertar ; es decir el nuevo nodo
    newNode->value = insertValue; // El valor del nuevo nodo va a depneder del parametro insertValue que le pasemos
    newNode->next = NULL; // El nuevo nodo a insertar va a apunar a NULL ya que será el ultimo
    if(*head == NULL ){ // Si el puntero de la cabeza apunta a  NULL signfica que la lista esta vacía 
        *head = newNode; // el puntero de la cabeza apuntara al nuevo nodo
        return; 
    }
    Node *lastNode = *head; // vamos a empzar la busqueda del utlimo nodo desde el principio por lo tanto *ultimo = *cabeza 
    while (lastNode->next != NULL){ // Mientras el apuntador del utlimo nodo no sea igual a NULL, sigue iternado 
        lastNode = lastNode->next; 
    } 
    lastNode->next = newNode;  
}

void printL (Node* n){
    while( n != NULL){
        std::cout << n->value << std::endl;
        n = n->next; // actualizar n 
    }
}
int main ()
{
    Node* head = new Node(); // Creación de nodo cabeza 

    head ->value = 1; // primer valor = 1  
    head ->next = NULL; // Apunta a null ya que no existe un nuevo elemento al cual apuntar
    // CREATE
    std::cout << "Creacion de datos, principio, en medio, final" << std::endl; 
    // Insertar al principio
    insertFront (&head, 696); // la función recibe la dirección de la cabeza y el valor a insertar
    // Insertar al final 
    insertEnd (&head, 420);
    insertEnd (&head,3333);

    // Insertar en medio 
    insertGivenNode(head,22);
    // READ
    std::cout << "Busqeda de datos" << std::endl;
    search(head, 696);
    // UPDATE
    printL(head);
    std::cout << "---------------------------" <<std::endl;
    std::cout << "Actualizacion de valor" <<std::endl;  
    updateData(head, 420, 555);
    printL(head);
    // DELETE
    std::cout << " " << std::endl;
    std::cout << "Eliminacion de datos" <<std::endl;
    std::cout << "---------------------------principio" <<std::endl;
    head = head->next;
    printL(head);
    std::cout << "---------------------------final" <<std::endl;
    deleteFromEnd(head);
    printL(head);
    std::cout << "---------------------------En medio" <<std::endl;
    deleteFromMiddle(head);
    printL(head);
}

