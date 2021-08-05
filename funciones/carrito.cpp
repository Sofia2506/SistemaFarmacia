#include "../clases/carrito.h"
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include "fecha.cpp" 
int contador=0;
void Carrito::aniadirProductoCarrito(ProdCant fila){    
    punt[contador] = fila;
    contador++;
}
//función que modifica la cantidad de un producto a llevar
void Carrito::modificar(int pos, int cantNueva){
    punt[pos].cant = cantNueva;
}

//Modifica algun producto del carrito
void Carrito::modificar(){
    int cantNueva, num;
    cout << "Ingrese el numero del producto a modificar: ";
    cin >> num;
    cout << "Ingrese la cantidad nueva: ";
    cin >> cantNueva;
    Carrito::modificar(num-1, cantNueva);
}


void Carrito::eliminarProductoCarrito(){

}

void Carrito::aniadirProductoCarrito(){
    cout << "";
}

//Muestra los productos del carrito
void Carrito::verProductos(){
    for(int i=0; i<contador; i++){
        cout<<i+1<<"\t"<<punt[i].p.nombre << "\t" << punt[i].cant <<endl;
    }
}

//Genera boleta
void Carrito::generarBoleta(){
    ofstream imprimir("boleta.txt");
	double total = 0;
	//imprimir.open("reporte.bat", ios::out | ios::app);
	imprimir << "\n Botica LOS DEL B" << endl;
	imprimir << " Av. Los No se quien y los no se cuantos " << endl;
	imprimir << " RUC:111111111  Tel:9742126060\n\n"
			 << endl;
	imprimir << " Fecha: "
			 << " " << Fecha() << " " << Hora() << endl;
	imprimir << " --------------------------------------------------------------------------" << endl;
	imprimir << " Cant Producto Precio Importe " << endl;
	imprimir << " --------------------------------------------------------------------------" << endl;
	for (int i = 0; i < contador; i++)
	{
		punt[i].p;
		imprimir << setw(5) << punt[i].cant;
		;
		imprimir << setw(11) << punt[i].p.nombre;
		imprimir << setw(31) << punt[i].p.precio_venta;
		imprimir << setw(20) << punt[i].cant * punt[i].p.precio_venta << endl;
		total += punt[i].cant * punt[i].p.precio_venta;
	}
	imprimir << " --------------------------------------------------------------------------" << endl;
	imprimir << "\n\n";
	imprimir << "TOTAL: "
			 << "S/. " << total << endl;
	imprimir << "\n\n";
	imprimir << " ¡GRACIAS POR SU COMPRA!" << endl;

	imprimir.close();
}