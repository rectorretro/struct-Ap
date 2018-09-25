#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct nodo{
    int dato;
    //string nombre;
    //string ambiente;
    struct nodo *siguiente;
}*inicio,*aux,*actual;

void insertarNodo(int);
void mostrarNodo();
void borrar(int);


int main(){
    inicio = NULL;
    int dato;
    char salida;
    do{
    cout << "Ingresa el dato: ";
    cin >> dato;
    insertarNodo(dato);

    cout << "Salir (y/n): ";
    cin >> salida;
    }while (salida == 'y');

    mostrarNodo();
   //cin.get();
    return 0;
}

void insertarNodo(int valor){
    actual=inicio;
    if(actual==NULL){
        aux = new nodo();
        aux->dato = valor;
        aux->siguiente=NULL;
        inicio = aux;
    }else{
    while(actual->siguiente != NULL){
    actual=actual->siguiente;
    }
        aux = new nodo();
        aux->dato = valor;
        aux->siguiente=NULL;
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
    }while(actual!= NULL );

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
