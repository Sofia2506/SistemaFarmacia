#include <iostream>
#include <ctime>
#include <time.h> 
using namespace std;
 
void fecha(){
    struct tm *tiempo;
    int dia;
    int mes;
    int anio;
     
    time_t fecha_sistema;
    time(&fecha_sistema);
    tiempo = localtime(&fecha_sistema);
     
    anio = tiempo->tm_year + 1900;
    mes = tiempo->tm_mon + 1;
    dia = tiempo->tm_mday;
 
    cout << dia << "/" << mes << "/" << anio;
}
string Fecha(){
 time_t t;
    struct tm *tm;
    char fecha[100];
 
    t = time(NULL);
    tm = localtime(&t);
    strftime(fecha, 100, "%d/%m/%y", tm);
    return fecha;
}
 
string Hora(){
 time_t t;
    struct tm *tm;
    char hora[100];
 
    t = time(NULL);
    tm = localtime(&t);
    strftime(hora, 100, "%I:%M:%S", tm);
    return hora;
}