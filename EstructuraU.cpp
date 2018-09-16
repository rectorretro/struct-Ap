#include <iostream>
#include <conio.h>
using namespace std;

//void insertarLista(Nodo *&,int)
void nodos(int);
void nodos2(int);

struct nodo{
    int valor;
    struct nodo *siguiente;
}*aux, *inicio, *actual;

int main(){
    inicio = NULL;
    int dato;
       //insertarLista(nodo *&inicio,dato);
    do{
            if (inicio == NULL){
        cout << "Inserte un numero: ";
        cin >> dato;
                nodos(dato);
            }else{
             actual=inicio->siguiente;
                if(actual==NULL){
        cout << "Inserte un numero: ";
        cin >> dato;
                    nodos2(dato);
                }else{
                    actual=actual->siguiente;
                }
            }

    }while(actual != NULL);
    //cout << actual->valor;
    return 0;
}

void nodos(int dato){
    aux = new struct nodo;
    aux->valor= dato;
    aux->siguiente=NULL;
    inicio = aux;

}

void nodos2(int dato){
    aux = new struct nodo;
    aux->valor= dato;
    aux->siguiente=NULL;
    actual = aux;

}

