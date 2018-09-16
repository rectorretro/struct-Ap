#include <iostream>
#include <conio.h>
using namespace std;

int main(){
    int *ptr=NULL;
    int  cantidad;
    cout << "Cuantos numeros desea guardar: ";
    cin >> cantidad;
    ptr = new int [cantidad];
    for (int i=0; i<cantidad; i++){
        cout << "Dame el numero "<<i+1<< ": ";
        cin >> ptr[i];
    }
    for (int i=0; i<cantidad; i++){
        cout << "Imprimiendo el numero "<<i+1<< ": " << ptr[i] << endl;
    }
    delete[]ptr;



 return 0;
}
