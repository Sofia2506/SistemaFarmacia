#include "../funciones/extraer.cpp"
struct ProdCant{
    Producto p;
    int cant;
};

class Carrito{
    private:
        int tamArreglo;
        ProdCant *punt = new ProdCant[100];

    public:
        void generarBoleta();
        void aniadirProductoCarrito(ProdCant fila);
        void modificar(int pos, int cantNueva);
        void modificar();
        void verProductos();
        void eliminarProductoCarrito();
        void eliminarProductoCarrito(int pos);
        void aniadirProductoCarrito();
};


