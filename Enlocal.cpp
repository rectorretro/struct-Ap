#include <iostream>
using namespace std;

struct nodo{
    int valor;
    struct nodo *ptr;
};

int main(){
        struct nodo *inicio;
        struct nodo *nodo;

        nodo = new struct nodo;
        inicio=nodo;
        inicio->ptr=NULL;
        inicio-> valor= 10;

        cout << "Imprimir: " << inicio->valor;
        cout << endl;
//        cout << "Imprimir: " << inicio->ptr->valor;

        nodo = new struct nodo;
        inicio->ptr=nodo;
        inicio->ptr->ptr=NULL;
        inicio-> ptr-> valor= 20;

        cout << "Imprimir: " << inicio->ptr->valor;




    return 0;
}
