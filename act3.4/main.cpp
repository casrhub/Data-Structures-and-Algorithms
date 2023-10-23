#include <iostream>
#include <fstream>


using namespace std;

//EN ESTA PARTE DEL CÓDIGO CREAMOS EL NODO CON EL QUE POSTERIORMENTE VAMOS A TRABAJAR PARA PODER LLEVAR A CABO DISTINTAS ACCIONES EN NUESTRO ARBOL BINARIO DE BUSQUEDA.
class tree_node {
    public:
        int data;
        tree_node* left;
        tree_node* right;
        tree_node(int value){
            data = value;
            left = nullptr;
            right = nullptr;
        }
    

};

tree_node* insert_leaf(tree_node* root, int value) {
    if (root == nullptr) {
        return new tree_node(value);
    }

    if (value < root->data) {
        root->left = insert_leaf(root->left, value);
    } else {
        root->right = insert_leaf(root->right, value);
    }

    return root;
}


 void inorden_recorre(tree_node* root,int &counter_var, int &counter_real_var, int &counter_var_2){
    if (root != nullptr){
        inorden_recorre(root->left,counter_var,counter_real_var,counter_var_2);
        counter_var = counter_var + root->data - 1;
        if(counter_var_2!=0){
        counter_real_var = counter_real_var + counter_var;
        }
        counter_var_2++;
        inorden_recorre(root->right,counter_var,counter_real_var,counter_var_2);
    }
} 
   

int main(){
    int counter_var_2 = 0;
    int counter_real_var = 0;
    int counter_var = 1;
    int num_listas = 0;
    tree_node* root = nullptr;
    ifstream archivo("listNumbers.txt");
    if (!archivo.is_open()){
        cerr << "No existe un archivo de lectura" << endl;
        return 1; 
    }
    int number;
    int count = 0;
    while (archivo >> number) {
        if(count == 0){
             num_listas = number;
        }
        else{
        root = insert_leaf(root, number);
        }
        count++;
    }
    archivo.close();

    //INORDER FUNCTION CALL:
    cout<<"Recorrido inorder"<<endl;
    cout<<"Número de listas a comparar: "<<num_listas<<endl;
    inorden_recorre(root,counter_var, counter_real_var, counter_var_2);
    cout<<"Comparaciones totales: "<<counter_real_var<<endl;
    

    return 0;
}