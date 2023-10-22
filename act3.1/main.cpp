#include <iostream>
#include <queue>
#include <vector>

// Definición de la estructura del nodo del BST
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Función para crear un nuevo nodo
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr; // Los nuevos nodos no aountan a nada 
    return newNode; // retoneamos el nuevo nodo
}

// Obtener altura BST - Función recursiva 
int getHeight(Node* root) {
    if (root == nullptr) {
        return 0; // Si el root apunta a null la altura es 0 
    } else {
        int leftHeight = getHeight(root->left);// Recursión hasta alcanzar un nodo hoja por la parte izquierda
        int rightHeight = getHeight(root->right); // Recursión hasta alcanzar nodo hoja parte deerecha
        return 1 + std::max(leftHeight, rightHeight); // el +1 represenat cada nivel alcanzado de la parte derecha e izquierda 
    }
}

// Encontrar el nivel de un dato 
int findLevel(Node* root, int target, int level) {
    if (root == nullptr) {
        return -1; // El dato no se encuentra en el árbol
    }

    if (root->data == target) { // Se checa si el dato se encuentra en root 
        return level; // Se encontró el dato en este nivel
    }

    // Realiza una búsqueda en los subárboles izquierdo y derecho
    int leftLevel = findLevel(root->left, target, level + 1); // busqueda recursiva
    if (leftLevel != -1) {
        return leftLevel;
    }

    int rightLevel = findLevel(root->right, target, level + 1);
    return rightLevel;
}


// Función para obetener ancestros de un nodo
bool findAncestors(Node* root, int target, std::vector<int>& ancestors) {
    if (root == nullptr) {
        return false;
    }
    
    if (root->data == target) {
        return true;
    }

    if (findAncestors(root->left, target, ancestors) || findAncestors(root->right, target, ancestors)) {
        ancestors.push_back(root->data);
        return true;
    }

    return false;
}


// Función para realizar un recorrido preorder en el BST
void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->data << " "; // Procesar el nodo actual
    preorderTraversal(root->left);  // Recorrer el subárbol izquierdo
    preorderTraversal(root->right); // Recorrer el subárbol derecho
}

// Función para realizar un recorrido inorder en el BST
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);   // Recorrer el subárbol izquierdo
    std::cout << root->data << " "; // Procesar el nodo actual
    inorderTraversal(root->right);  // Recorrer el subárbol derecho
}

// Función para realizar un recorrido postorder en el BST
void postorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    postorderTraversal(root->left);  // Recorrer el subárbol izquierdo
    postorderTraversal(root->right); // Recorrer el subárbol derecho
    std::cout << root->data << " ";  // Procesar el nodo actual
}

// Función para realizar un recorrido por niveles en el BST
void levelOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        std::cout << current->data << " ";
        q.pop();
        if (current->left) {
            q.push(current->left);
        }
        if (current->right) {
            q.push(current->right);
        }
    }
}

// Función para realizar un tipo de recorrido basado en un número de entrada
void performTraversal(Node* root, int choice) {
    switch (choice) {
        case 1:
            std::cout << "Recorrido Preorder del BST: ";
            preorderTraversal(root);
            break;
        case 2:
            std::cout << "Recorrido Inorder del BST: ";
            inorderTraversal(root);
            break;
        case 3:
            std::cout << "Recorrido Postorder del BST: ";
            postorderTraversal(root);
            break;
        case 4:
            std::cout << "Recorrido por Niveles del BST: ";
            levelOrderTraversal(root);
            break;
        default:
            std::cout << "Opción no válida." << std::endl;
            return;
    }
    std::cout << std::endl;
}

int main() {
    // Crear un ejemplo de BST:
    //        4
    //       / \
    //      2   6
    //     / \   \
    //    1   3   7

// Creación de BST
    Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->right = createNode(7);
    root->right->left = createNode(5);
// Altura de BST
    int height = getHeight(root);
    std::cout << "La altura del BST es: " << height << std::endl;
// Tipos de recorridos en un BST
    int choice;
    std::cout << "Elije un tipo de recorrido (1-4): ";
    std::cin >> choice;
    performTraversal(root, choice);
// Ancestros de un nodo
int target = 7;
  std::vector<int> ancestors;
    if (findAncestors(root, target, ancestors)) {
        std::cout << "Ancestros de " << target << ": ";
        for (int i = 0; i < ancestors.size(); i++) {
            std::cout << ancestors[i] << ", ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Nodo no encontrado en el BST." << std::endl;
    }
// Nivel de un nodo 

    int level = findLevel(root, target, 1);
    if (level != -1) {
        std::cout << "El nivel de " << target << " es: " << level << std::endl;
    } else {
        std::cout << target << " no se encuentra en el BST." << std::endl;
    }

    return 0;
}


