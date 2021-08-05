#include "../clases/carrito.h"
#include <stdlib.h>
int contador=0;
void Carrito::aniadirProductoCarrito(ProdCant fila){    
    punt[contador] = fila;
    contador++;
}
//función que modifica la cantidad de un producto a llevar
void Carrito::modificar(ProdCant fila, int cantNueva){
    cout << "fila: " << fila.p.nombre<<endl;
    fila.cant = cantNueva;
}
void Carrito::modificar(){
    int cantNueva, num;
    cout << "Ingrese el numero del producto a modificar: ";
    cin >> num;
    cout << "Ingrese la cantidad nueva: ";
    cin >> cantNueva;
    Carrito::modificar(punt[num-1], cantNueva);
}
void Carrito::eliminarProductoCarrito(){

}
void Carrito::aniadirProductoCarrito(){
    cout << "";
}
void Carrito::verProductos(){
    for(int i=0; i<contador+1; i++){
        cout<<i+1<<"\t"<<punt[i].p.nombre << "\t" << punt[i].cant <<endl;
    }
}