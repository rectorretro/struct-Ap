#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
using namespace std;
///CONSTANTES UTILIZADAS EN TODO EL PROYECTO
const int SAL = 1;
struct Saldo
{
    int saldo;

};
Saldo compras[SAL];
struct Almacen
{
    int Clave;
    int cantidad;
    double Precio;
};
struct COMPRADAS
{
    string NombreProducto;
    string Distribuidor;
    string Tipo;
    string Contenido;
    struct Almacen almacen;
    struct COMPRADAS *siguiente_C;
}*inicio_C,*aux_C,*actual_C;


struct Productos
{
    string NombreProducto;
    string Distribuidor;
    string Tipo;
    string Contenido;
    struct Almacen almacen;
    struct Productos *siguiente;
}*inicio,*aux_p,*actual,*anterior;


void ordenarNodos();
void insertarNodo(int, string,string,string,string,int,double);
void mostrarNodo();
void ordenar(int);
void especifico(int);
void borrar(int);
///funciones antiguas
string reemplazarEspacios(string);
string reemplazarSharp(string);
void escribirEnArchivo();
void recuperarDeArchivo();
void pedirDatos();

void menu();
void menu2();




void restarCantidad(int);

void menuAdmin(int);
void menuComprador(int);



///Funciones para el saldo
void escribirEnArchivoS();
void abonarSaldo();
void restarsaldo(int);
void obtenersaldo();
void insertarS(int);
void inicializarS();
void recuperarDeArchivoS();

///Funciones del comprador
void escribirEnArchivoComp();
void recuperarDeArchivoComp();
void DatosCompradas(int);
void insertarC(int, string,string,string,string,int,double);
void mostrarDatosC();

int main()
{
    char*locale;
    locale=setlocale(LC_ALL,"");
    int opcion, resultado, caso0;
    string contrasena,tipo;
    do
    {
        caso0=0;
        cout << "Administador (Admin) o Comprador (Cons); (Salir): ";
        getline(cin, tipo);
        system("cls");
        if (tipo == "Salir")
        {
            return 0;
        }
        if (tipo == "Admin")
        {
            caso0 = 1;
        }
        if (tipo == "Cons")
        {
            caso0 = 2;
        }
        switch(caso0)
        {
        case 1:
                menu();
            break;
        case 2:
                menu2();
            break;

        }


    }
    while (opcion != 3);
    system("cls");


    return 0;
}

void menuAdmin(int caso1)
{

    recuperarDeArchivo();
    escribirEnArchivo();
    int resultado,buscar;
    //menu();
    switch (caso1)
    {
    case 1:

        pedirDatos();
        escribirEnArchivo();
        system("pause");
        system("cls");
        break;
    case 2:
        ordenarNodos();
        mostrarNodo();
    default:
        cout << "Opcion no valida" << endl;
        system("pause");
        system("cls");

        break;
    }

}

void menuComprador(int caso2)
{
    //actual=inicio;
    recuperarDeArchivo();
    escribirEnArchivo();
    inicializarS();
    recuperarDeArchivoComp();
    escribirEnArchivoComp();
    recuperarDeArchivoS();
    int resultado = 0,buscar,compra;
    switch(caso2)
    {
        //recuperarDeArchivo();
    case 1:
        mostrarNodo();
        cout << "Tu saldo es: ";
        obtenersaldo();
        cout << endl;
        cout << "Introdusca la clave del producto: " ;
        cin >> compra;

        //DatosCompradas(compra);
        restarsaldo(compra);
        escribirEnArchivoComp();
       // restarCantidad(compra);
        cout << endl;
        cout << "Saldo actual: ";
        obtenersaldo();
        cout << endl;
        system("pause");
        system("cls");


        break;
    case 2:
        cout << "SALDO ACTUAL: ";
        obtenersaldo();
        cout << endl;
        abonarSaldo();
        escribirEnArchivoS();
        obtenersaldo();
        cout << endl;
        system("pause");
        system("cls");
        break;
    case 3:
        mostrarDatosC();
        break;
    default:
        cout << "Opcion no valida" << endl;
        system("pause");
        system("cls");

        break;
    }
}
void menu()
{
    int caso = 0;
    do
    {
        cout << "E L I G E   T U  O P C I O N" << endl;
        cout << "1.-Agregar producto" << endl;
        cout << "2.-Ver productos" << endl;
        cout << "3.- Salir "<< endl;
        cout << "opción: ";
        cin >> caso;
        system("cls");
        //system("pause");
        menuAdmin(caso);
    }
    while (caso != 3);
}
void menu2()
{
    int caso2 = 0;
    do
    {
        cout << "ELIGE UNA OPCIÓN" << endl;
        cout << "1.-Comprar producto" << endl;
        cout << "2.-Abonar saldo" << endl;
        cout << "3.-Productos comprados" << endl;
        cout << "4.- Salir" << endl;
        cout << "opción: ";
        cin >> caso2;
        system("cls");
        menuComprador(caso2);

    }while (caso2 != 4);
}

void restarCantidad(int a){
    int conter=0;
    actual = inicio;
    while(actual->siguiente != NULL){
        if(actual->almacen.Clave == a ){
                if( actual->almacen.cantidad == 0) {
            cout << "Ya no hay producto" << endl;
    return;
    }else{
       conter = actual->almacen.cantidad - 1;
       actual->almacen.cantidad = conter;
        }
     actual= actual->siguiente;
    }

}
}
void borrar(int valor){
    actual=inicio;
    if(actual->almacen.Clave==valor){
        inicio = actual->siguiente;
        delete actual;
    }else{
    while(actual->siguiente->almacen.Clave != valor){
    actual=actual->siguiente;
    }
        aux_p = actual->siguiente;
        actual->siguiente = aux_p->siguiente;
        delete aux_p;
    }
}
/// Funciones del usuario
void DatosCompradas(int clave)
{
    actual = inicio;
    int Clavez;// = actual->almacen.Clave;
    string NombreProductoz;// = actual->NombreProducto;
    string Distribuidorz;// = actual->Distribuidor;
    string Tipoz;// = actual->Tipo;
    string Contenidoz;// = actual->Contenido;
    double cantidadz;// = actual->almacen.cantidad;
    double Precioz;// = actual->almacen.Precio;

    while(actual->siguiente != NULL){
            if(actual->almacen.Clave == clave){
                                    Clavez = actual->almacen.Clave;
                                    NombreProductoz = actual->NombreProducto;
                                    Distribuidorz = actual->Distribuidor;
    Tipoz = actual->Tipo;
    Contenidoz = actual->Contenido;
    cantidadz = actual->almacen.cantidad;
    Precioz = actual->almacen.Precio;

    insertarC(Clavez,NombreProductoz,Distribuidorz,Tipoz,Contenidoz,cantidadz,Precioz);
    return;
            }else{
                cout << "Producto no existente" << endl;
                return;
            }

            //cout << actual->almacen.Clave;
    actual=actual->siguiente;
    cout << "Clave: " << actual->almacen.Clave << endl;
    }



}




void mostrarDatosC()
{
    actual_C = inicio_C;
    int contador=0;
    if(actual_C== NULL){
                cout << "No hay productos" << endl;
         return;

         }
    cout << "PRODUCTOS COMPRADOS"<< endl;
    cout << endl;
    cout << setw(6) << "Clave"
         << setw(30) << "Nombre del producto"
         //<< setw(25) << "Distribuidor"
         //<< setw(15) << "Contenido"
         //<< setw(14) << "Tipo"
         //<< setw(15) << "Cantidad"
         << setw(15) << "Precio" << endl;

    do{
            cout << endl;
    cout << setw(6) << actual_C->almacen.Clave
         << setw(30) << actual_C->NombreProducto
         //<< setw(25) << actual_C->Distribuidor
         //<< setw(15) << actual_C->Contenido
         //<< setw(14) << actual_C->Tipo
         //<< setw(15) << actual_C->almacen.cantidad
         << setw(15) << actual_C->almacen.Precio << endl;

    actual_C=actual_C->siguiente_C;
    }while(actual_C != NULL);

}

void escribirEnArchivoComp()
{
    actual_C = inicio_C;
    ofstream salidaArchivo("productosComp.txt", ios::out);
    if (!salidaArchivo)
    {
        cerr << "No se pudo abrir el archivo";
        exit(1);
    }
    while (actual_C != NULL){
        if (actual_C->almacen.Clave != 0)
        {
            salidaArchivo << actual_C->almacen.Clave << ' '
                          << reemplazarEspacios(actual_C->NombreProducto) << ' '
                          << reemplazarEspacios(actual_C->Distribuidor) << ' '
                          << reemplazarEspacios(actual_C->Contenido) << ' '
                          << reemplazarEspacios(actual_C->Tipo) << ' '
                          << actual_C->almacen.cantidad << ' '
                          << actual_C->almacen.Precio << ' ' << endl;

        }
        actual_C=actual_C->siguiente_C;
    }
}

void recuperarDeArchivoComp()
{
    ifstream lecturaArchivo("productosComp.txt", ios::in);
    if (!lecturaArchivo)
    {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
     int Clavex;
    string NombreProductox;
    string Distribuidorx ;
    string Tipox ;
    string Contenidox;
    int cantidadx;
    double Preciox;
    if(inicio_C == NULL){
    while(lecturaArchivo >> Clavex >> NombreProductox >> Distribuidorx >> Tipox >> Contenidox >> cantidadx >>Preciox)
    {
        insertarC(Clavex, reemplazarSharp(NombreProductox), reemplazarSharp(Distribuidorx), reemplazarSharp(Tipox),reemplazarSharp(Contenidox), cantidadx,Preciox);
    }
    }
}

///Funciones del Administrador


void pedirDatos()
{
    actual = inicio;
    int Clavex;
    string NombreProductox;
    string Distribuidorx;
    string Tipox;
    string Contenidox;
    int cantidadx;
    double Preciox;
    cout << "Escribe datos de los prodcutos " << endl;
    cout << "Dame clave: ";
    cin >> Clavex;
    fflush(stdin);
if(actual != NULL){
  while (actual->siguiente != NULL)
    {
        if(actual->almacen.Clave == Clavex || actual->siguiente->almacen.Clave == Clavex )
        {
            cout << endl;
            cout << "Se repitio la clave: " << actual->almacen.Clave << " que pertenece al producto: " << actual->NombreProducto << endl;
            cout << "Reingresar clave del nuevo producto"<< endl;
            cout << "Nueva clave: ";
            Clavex = 0;
            cin >> Clavex;
        }
        actual=actual->siguiente;
    }
}

    cout << "Dame nombre del producto: ";
    getline(cin, NombreProductox);
    fflush(stdin);
    cout << "Dame distribuidor: ";
    getline(cin, Distribuidorx);
    fflush(stdin);
    cout << "Dame tipo: ";
    getline(cin, Tipox);
    fflush(stdin);
    cout << "Dame Contenido: ";
    getline(cin, Contenidox);
    fflush(stdin);
    cout << "Dame cantidad en almacen: ";
    cin >> cantidadx;
    cout << "Dame el precio: ";
    cin >> Preciox;
    insertarNodo(Clavex,NombreProductox,Distribuidorx,Tipox,Contenidox,cantidadx,Preciox);
}



string reemplazarEspacios(string texto)
{
    for (int i=0; i<(int)texto.length(); ++i)
    {
        if (texto[i] == ' ')
        {
            texto.replace(i,1,"#");
        }

    }
    return texto;
}

string reemplazarSharp(string texto)
{
    for (int i = 0; i < (int) texto.length(); ++i)
    {
        if (texto[i] == '#')
        {
            texto.replace(i, 1, " ");
        }
    }
    return texto;
}


void insertarNodo(int Clavex,string NombreProductox,string Distribuidorx,string Tipox,string Contenidox,int cantidadx, double Preciox){
    actual=inicio;
    if(actual == NULL){

        aux_p = new Productos();

        aux_p->almacen.Clave = Clavex;
        aux_p->NombreProducto = NombreProductox;
        aux_p->Distribuidor = Distribuidorx;
        aux_p->Tipo = Tipox;
        aux_p->Contenido = Contenidox;
        aux_p->almacen.cantidad = cantidadx;
        aux_p->almacen.Precio = Preciox;

        aux_p->siguiente = NULL;
        inicio = aux_p;
    }else{

    while(actual->siguiente != NULL){
    actual=actual->siguiente;
    }
        aux_p = new Productos();

        aux_p->almacen.Clave = Clavex;
        aux_p->NombreProducto = NombreProductox;
        aux_p->Distribuidor = Distribuidorx;
        aux_p->Tipo = Tipox;
        aux_p->Contenido = Contenidox;
        aux_p->almacen.cantidad = cantidadx;
        aux_p->almacen.Precio = Preciox;

        aux_p->siguiente = NULL;
        actual->siguiente = aux_p;
    }

}

void insertarC(int Clavex,string NombreProductox,string Distribuidorx,string Tipox,string Contenidox,int cantidadx, double Preciox){
    actual_C = inicio_C;
    if(actual_C == NULL){

        aux_C = new COMPRADAS();

        aux_C->almacen.Clave = Clavex;
        aux_C->NombreProducto = NombreProductox;
        aux_C->Distribuidor = Distribuidorx;
        aux_C->Tipo = Tipox;
        aux_C->Contenido = Contenidox;
        aux_C->almacen.cantidad = cantidadx;
        aux_C->almacen.Precio = Preciox;

        aux_C->siguiente_C = NULL;
        inicio_C = aux_C;
    }else{

    while(actual_C->siguiente_C != NULL){
    actual_C=actual_C->siguiente_C;
    }
        aux_C = new COMPRADAS();

        aux_C->almacen.Clave = Clavex;
        aux_C->NombreProducto = NombreProductox;
        aux_C->Distribuidor = Distribuidorx;
        aux_C->Tipo = Tipox;
        aux_C->Contenido = Contenidox;
        aux_C->almacen.cantidad = cantidadx;
        aux_C->almacen.Precio = Preciox;
        aux_C->siguiente_C = NULL;

        actual_C->siguiente_C = aux_C;
    }

}

void mostrarNodo(){
    actual = inicio;
    int contador=0;
    if(actual==NULL){
        cout << "No hay productos" << endl;
        return;
    }
    cout << endl;
    cout << setw(6) << "Clave"
         << setw(30) << "Nombre del producto"
         << setw(25) << "Distribuidor"
         << setw(15) << "Contenido"
         << setw(14) << "Tipo"
         << setw(15) << "Cantidad"
         << setw(15) << "Precio" << endl;
    do{
            cout << endl;
    cout << setw(6) << actual->almacen.Clave
         << setw(30) << actual->NombreProducto
         << setw(25) << actual->Distribuidor
         << setw(15) << actual->Contenido
         << setw(14) << actual->Tipo
         << setw(15) << actual->almacen.cantidad
         << setw(15) << actual->almacen.Precio << endl;

    actual=actual->siguiente;
    }while(actual!= NULL);

}


void recuperarDeArchivo()
{
    ifstream lecturaArchivo("productos.txt", ios::in);
    if (!lecturaArchivo)
    {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    int Clavex;
    string NombreProductox;
    string Distribuidorx ;
    string Tipox ;
    string Contenidox;
    int cantidadx;
    double Preciox;
    if(inicio == NULL){
        while(lecturaArchivo >> Clavex >> NombreProductox >> Distribuidorx >> Tipox >> Contenidox >> cantidadx >>Preciox){

        insertarNodo(Clavex, reemplazarSharp(NombreProductox), reemplazarSharp(Distribuidorx), reemplazarSharp(Tipox),reemplazarSharp(Contenidox), cantidadx,Preciox);
    }
    }

}


void escribirEnArchivo()
{
    actual = inicio;
    ofstream salidaArchivo("productos.txt", ios::out);
    if (!salidaArchivo)
    {
        cerr << "No se pudo abrir el archivo";
        exit(1);
    }
    while (actual != NULL){
        if (actual->almacen.Clave != 0)
        {
            salidaArchivo << actual->almacen.Clave << ' '
                          << reemplazarEspacios(actual->NombreProducto) << ' '
                          << reemplazarEspacios(actual->Distribuidor) << ' '
                          << reemplazarEspacios(actual->Contenido) << ' '
                          << reemplazarEspacios(actual->Tipo) << ' '
                          << actual->almacen.cantidad << ' '
                          << actual->almacen.Precio << ' ' << endl;

        }
        actual=actual->siguiente;
    }


}











///Funciones del saldo
void abonarSaldo()
{

    int nuevo;
    cout << "Abonar Saldo en pesos: ";
    cin >> nuevo;
    insertarS(nuevo);
    cout << "Saldo abonado correctamente: ";




}

void restarsaldo(int buscar)
{
    actual = inicio;
    //ordenacionBurbujaPorClave();
    //int resultado
    while(actual->siguiente != NULL){
        if(actual->almacen.Clave == buscar){


            if (actual->almacen.Precio > compras[0].saldo){
        cout << "Saldo insuficiente, favor de abonar" << endl;
    }
    else{

    int Clavez = actual->almacen.Clave;
    string NombreProductoz = actual->NombreProducto;
    string Distribuidorz = actual->Distribuidor;
    string Tipoz = actual->Tipo;
    string Contenidoz = actual->Contenido;
    int cantidadz = actual->almacen.cantidad;
    double Precioz = actual->almacen.Precio;

    insertarC(Clavez,NombreProductoz,Distribuidorz,Tipoz,Contenidoz,cantidadz,Precioz);

        cout << "Producto comprada, se ha agregado a tu carrito" << endl;
        compras[0].saldo=compras[0].saldo - actual->almacen.Precio;
        escribirEnArchivoS();
    }
        }
        actual=actual->siguiente;
    }






}

void obtenersaldo()
{

    cout << compras[0].saldo;

}



void escribirEnArchivoS()
{
    ofstream Archivo("saldo.txt", ios::out);
    if (!Archivo)
    {
        cerr << "No se pudo abrir el archivo";
        exit(1);
    }
    Archivo << compras[0].saldo;

}

void recuperarDeArchivoS()
{
    ifstream lecturaArchivo("saldo.txt", ios::in);
    if (!lecturaArchivo)
    {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    int saldox;
    while(lecturaArchivo >> saldox)
    {
        insertarS(saldox);
    }
}

void insertarS(int nuevo)
{

    compras[0].saldo = nuevo + compras[0].saldo;

}

void inicializarS()
{
    compras[0].saldo = 0;
}

void ordenarNodos(){
    actual=inicio;
		int conter=0;
		while(actual->siguiente!=NULL){
            conter++;
            actual=actual->siguiente;
            //cout << conter<< endl;
		}
		do{
	if(inicio!=NULL){
		anterior=NULL;
		aux_p=NULL;


		actual=inicio;


		while((actual->siguiente!=NULL) && (actual->almacen.Clave < actual->siguiente->almacen.Clave)){
				anterior=actual;
				actual=actual->siguiente;
		}
			if (actual->siguiente==NULL)
			{
				//cout<<"\nordenamiento terminado\n";
			}else if(anterior==NULL){
				aux_p=actual;
				actual=actual->siguiente;
				inicio=actual;
				aux_p->siguiente=actual->siguiente;
				actual->siguiente=aux_p;
			}else{
				aux_p=actual;
				actual=actual->siguiente;
				anterior->siguiente=actual;
				aux_p->siguiente=actual->siguiente;
				actual->siguiente=aux_p;
			}

        conter--;
	}
		}while(conter != 0);

	}

