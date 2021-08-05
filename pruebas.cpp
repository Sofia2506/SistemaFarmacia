#include "funciones/carrito.cpp"
int main(){
    Producto p1, p2;
    p1.nombre = "medicina";
    ProdCant fila, fila2;
    fila.p = p1;
    fila.cant = 2;
    p2.nombre = "Safari";
    fila2.cant = 5;
    fila2.p = p2;
    Carrito *c1 = new Carrito();
    c1->aniadirProductoCarrito(fila);
    c1->aniadirProductoCarrito(fila2);
    c1->verProductos();
    c1->modificar();
    c1->verProductos();
}