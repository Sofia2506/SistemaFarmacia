#include "../clases/carrito.h"
#include <stdlib.h>
int contador=0;
void Carrito::aniadirProductoCarrito(ProdCant fila){    
    punt[contador] = fila;
    contador++;
}

//función que modifica la cantidad de un producto a llevar
void Carrito::modificar(int pos, int cantNueva){
    punt[pos].cant = cantNueva;
}
void Carrito::modificar(){
    int cantNueva, num;
    cout << "Ingrese el numero del producto a modificar: ";
    cin >> num;
    cout << "Ingrese la cantidad nueva: ";
    cin >> cantNueva;
    Carrito::modificar(num-1, cantNueva);
}
void Carrito::eliminarProductoCarrito(int pos){
    for(int i=pos+1; i<contador;pos++, i++){
        punt[pos] = punt[pos+1];
    }
    contador--;
}
void Carrito::eliminarProductoCarrito(){
    int num;
    cout << "Ingrese el numero del producto a eliminar: ";
    cin >> num;
    Carrito::eliminarProductoCarrito(num-1);
}
void Carrito::verProductos(){
    for(int i=0; i<contador; i++){
        cout<<i+1<<"\t"<<punt[i].p.nombre << "\t" << punt[i].cant <<endl;
    }
}