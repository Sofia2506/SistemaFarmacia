#include <string>
#include <iostream>
using namespace std;

struct Fecha{
    int dia, mes, anio;
};
class Producto{
    public:
        string codigo;
        string categoria;
        Fecha fecha_vencimiento;
        string nombre;
        double precio_venta;
        string unidad_medida;
        string descripcion;
        int stock;
    
};
