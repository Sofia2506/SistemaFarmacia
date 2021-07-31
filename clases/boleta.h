#include <string>
#include <iostream>
using namespace std;

struct Fila{
    string code;
    int cantProducto;
    string nombreProducto;
    double precioProducto;
};
class Boleta{
    private:
        string codigo;
        Fila filas; //sería un arreglo pero [n]
        double precio_final;
};
