#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct nodo{
    int dato;
    string nombre;
    string ambiente;
    struct nodo *siguiente;
}*inicio,*aux,*actual;

void insertarNodo(int,string,string);
void mostrarNodo();

int main(){
    inicio = NULL;
    int dato;
    string nombre;
    string ambiente;
    char salida;
    cout << "DATOS ANIMALES DEL ZOOLOGICO" <<endl;
    do{
    cout << "Ingresa número de animales: ";
    cin >> dato;
    fflush(stdin);
    cout << "Inserte nombre: ";
    getline(cin, nombre);
    fflush(stdin);
    cout << "Inserte ambiente: ";
    getline(cin, ambiente);
    insertarNodo(dato,nombre,ambiente);

    cout << "Salir (y/n): ";
    cin >> salida;
    }while (salida == 'y');

    mostrarNodo();


    return 0;
}

void insertarNodo(int valor,string nombre, string ambiente){
    actual=inicio;
    if(actual==NULL){
        aux = new nodo();
        aux->dato = valor;
        aux->nombre = nombre;
        aux->ambiente = ambiente;
        aux->siguiente=NULL;
        inicio = aux;
    }else{
    while(actual->siguiente != NULL){
    actual=actual->siguiente;
    }
        aux = new nodo();
        aux->dato = valor;
        aux->nombre = nombre;
        aux->ambiente = ambiente;
        aux->siguiente=NULL;
        actual->siguiente = aux;
    }

}


void mostrarNodo(){
    actual = inicio;
    int contador=0;
    cout << "DATOS INTRODUCCIDOS" << endl;
    do{
            contador++;

        cout << contador <<".- " << actual->dato << " " << endl;
        cout << contador <<".- " << actual->nombre << " " << endl;
        cout << contador <<".- " << actual->ambiente << " " << endl;
        cout << endl;
    actual=actual->siguiente;
    }while(actual!=inicio);

}
