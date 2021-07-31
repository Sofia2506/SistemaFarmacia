#include "añadir.cpp"

int main(){

    Producto producto1;
    producto1.codigo = "79653A";
    producto1.categoria = "Categoria";
    producto1.fecha_vencimiento.anio = 2021;
    producto1.fecha_vencimiento.mes = 07;
    producto1.fecha_vencimiento.dia = 29;
    producto1.nombre = "Naproxeno";
    producto1.precio_venta = 0.20;
    producto1.unidad_medida = "unidad";
    producto1.descripcion = "null";
    producto1.stock = 500;

    aniadirProducto(producto1);


}