#include "../funciones/extraer.cpp"
struct ProdCant{
    Producto p;
    int cant;
};

class Carrito{
    private:
        int tamArreglo = 0;
        ProdCant *punt = new ProdCant[100];

    public:
        void generarBoleta();
        void aniadirProductoCarrito(ProdCant fila);
        void modificar(ProdCant fila, int cantNueva);
        void modificar();
        void verProductos();
        void eliminarProductoCarrito();
        void aniadirProductoCarrito();
};


