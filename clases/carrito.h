#include "producto.h"
struct ProdCant{
    Producto p;
    int cant;
};

class Carrito{
    private:
        int tamArreglo, * punt;

    public:
        void generarBoleta();
        void añadirProducto(ProdCant fila);
        void modificar(ProdCant fila);
};


