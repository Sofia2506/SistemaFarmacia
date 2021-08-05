#include <fstream>
#include "../clases/producto.h"

string transformarProductoAstring(Producto &producto){
    string line = producto.codigo + ";" + producto.categoria + ";" + 
                    to_string(producto.fecha_vencimiento.anio) + ";" +
                    to_string(producto.fecha_vencimiento.mes) + ";" +
                    to_string(producto.fecha_vencimiento.dia) + ";" +
                    producto.nombre + ";" + to_string(producto.precio_venta)+ ";" +
                    producto.unidad_medida + ";" + producto.descripcion + ";"+
                    to_string(producto.stock);

    return line;
}

void aniadirProducto(Producto &producto){
    ofstream archivo;
    archivo.open("database-txt/productos.txt", ios::app);
    if(archivo.fail()){
        cout << "No se pudo abrir el archivo";
    }
    string line = transformarProductoAstring(producto);
    archivo<<line<<endl;

    archivo.close();

}
