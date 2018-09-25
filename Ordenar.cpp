#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
struct nodo{
    int dato;
    struct nodo *siguiente;
}*inicio,*aux,*actual;

void insertarNodo(int);
void mostrarNodo();
void ordenar(int);
void especifico(int);
void borrar(int);

int main(){
    inicio = NULL;
    int dato;
    int salida,conter=0;
    cout << "Si desea salir terminar incerte -1" << endl;
    do{
    cout << "Ingresa el dato: ";
    cin >> dato;
    if(dato != -1){
        conter++;
    insertarNodo(dato);
    }


    }while (dato != -1 );

    mostrarNodo();
    cout << endl;
    especifico(2);
    ordenar(conter);
    //ordenar();
    cout << endl;
    mostrarNodo();
    cout << endl;
    especifico(2);
   //cin.get();
   borrar(1);
   mostrarNodo();
    return 0;
}

void insertarNodo(int valor){
    actual=inicio;
    if(actual == NULL){
        aux = new nodo();
        aux->dato = valor;
        aux->siguiente = NULL;
        inicio = aux;
    }else{
    while(actual->siguiente != NULL){
    actual=actual->siguiente;
    }
        aux = new nodo();
        aux->dato = valor;
        aux->siguiente = NULL;
        actual->siguiente = aux;
    }

}

void mostrarNodo(){
    actual = inicio;
    int contador=0;
    do{
            contador++;
        cout << contador <<".- " << actual->dato << " " << endl;
    actual=actual->siguiente;
    }while(actual!= NULL);

}

void especifico(int valor){
    actual = inicio;
    int contador=0;
    do{
            contador++;
            if(contador == valor){
               cout << contador <<".- " << actual->dato << " " << endl;
            }

    actual=actual->siguiente;
    }while(actual!= NULL);
}
void ordenar(int cantidad){
    nodo *aux1;
    //aux1 = inicio;

do{
    actual=inicio;
        while (actual->siguiente != NULL){

        aux = actual->siguiente;

        while(aux != NULL){

            if(actual->dato > actual->siguiente->dato){

                aux1->dato = actual->dato;
                actual->dato = actual->siguiente->dato;
                actual->siguiente->dato = aux1->dato;

            }
            aux = aux->siguiente;
        }
        actual = actual->siguiente;
    }

 cantidad--;
}while(cantidad != 0);
}

void borrar(int valor){
    actual=inicio;
    if(actual->dato==valor){
        inicio = actual->siguiente;
        delete actual;
    }else{
    while(actual->siguiente->dato != valor){
    actual=actual->siguiente;
    }
        aux = actual->siguiente;
        actual->siguiente = aux->siguiente;
        delete aux;
    }
}
