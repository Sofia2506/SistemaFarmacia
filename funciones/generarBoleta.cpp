#include <iostream>
#include <fstream>
#include <iomanip>
//#include "fecha.cpp"
using namespace std;

void generarBoleta(){
	FILE *archivo;
	FILE *archivo2;
	//FILE *leer2;
	char caracter[100]; 
	ofstream imprimir;
	ifstream leer;
	ifstream leertodo;
	ofstream reporte;
	ofstream conteo;
	//ifstream leerconteo;
	//--> Factura es fichero DEL CARRITO 
	string texto;
	//float precio; solo en caso vuelv aa calcular el total
	//int cantidad;
	//float total; // Monto de compra total

	imprimir.open("carrito.txt", ios::out); 
	leer.open("carrito.bat", ios::in);
	leertodo.open("carrito.txt", ios::in);
	reporte.open("reporte.bat", ios::out | ios::app);
	//conteo.open("conteo.bat", ios::out);
	//leerconteo.open("conteo.bat", ios::in); && conteo.is_open() && leerconteo.is_open() --> para el if
	archivo = fopen("carrito.txt","r");
	archivo2 = fopen("reporte.bat", "r");
	//leer2 = fopen("conteo.bat", "r");
	if (imprimir.is_open() && leer.is_open() && leertodo.is_open() && reporte.is_open()){
        imprimir << "\n                                   Botica LOS DEL B" <<endl;
		imprimir << "                      Av. Los No se quien y los no se cuantos  " <<endl;
		imprimir << "                        RUC:111111111  Tel.:9742126060\n\n" << endl;
		//imprimir << "   Fecha: " << "          " <<Fecha()<< "  " << Hora()<<endl;
		imprimir << "   --------------------------------------------------------------------------" << endl;
		imprimir << "   Cant       Producto                    Precio              Importe        " << endl;
		imprimir << "   --------------------------------------------------------------------------" <<endl;
		leer >> texto;
		while(!leer.eof()){
			imprimir <<setw(5) <<  texto ; 
			leer >> texto;
			imprimir  << setw(11) << texto ;
			leer >> texto;
			imprimir << setw(31) << texto ;
			leer >> texto;
			imprimir << setw(20) << texto << endl;
			leer >> texto;
		}
		imprimir << "   --------------------------------------------------------------------------" <<endl;
		imprimir << "\n\n";
		//imprimir << "TOTAL:                                                     "<<"S/. "<< total << endl; no se como jalar esto por separado :'v o si calcularlo nuevamnete
		imprimir << "\n\n";
		imprimir << "                          ¡GRACIAS POR SU COMPRA!" << endl; 
		
		//Aqui seguimos
		while(!feof(archivo)){
			fgets(caracter, 100,  archivo);
			puts(caracter);
			reporte << caracter;
		}
		reporte << endl << endl << endl << endl;
		fclose(archivo);		 
	}
	imprimir.close();
	leer.close();
	leertodo.close();
	reporte.close();
	//conteo.close();
	//leerconteo.close();
}