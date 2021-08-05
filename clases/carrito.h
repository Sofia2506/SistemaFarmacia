#include "../funciones/extraer.cpp"
struct ProdCant{
    Producto p;
    int cant;
};

class Carrito{
    private:
        int tamArreglo, * punt;

    public:
        void generarBoleta();
        void aniadirProductoCarrito(ProdCant fila);
        void modificar(ProdCant fila);
        void modificar();
        void verProductos();
        void eliminarProductoCarrito();
};


