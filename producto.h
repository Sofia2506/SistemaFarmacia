#include <string>
#include <iostream>
using namespace std;

struct Fecha{
    int dia, mes, anio;
};
class producto{
    private:
        string codigo;
        string categoría;
        Fecha fecha_vencimiento;
        string nombre;
        double precio_venta;
        string unidad_medida;
        string descripción;
        int stock;
};
