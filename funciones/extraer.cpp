#include "añadir.cpp"

string extraerDatoPro(string &line){
    int pos = line.find(";");
    string dato = line.substr(0, pos);
    line = line.substr(pos+1);
    return dato;
}

Producto extraerProducto(string line){
    
    string proCod = extraerDatoPro(line);
    
    string proCat = extraerDatoPro(line);
    
    string proAni = extraerDatoPro(line);

    string proMes = extraerDatoPro(line);

    string proDia = extraerDatoPro(line);

    string proNom = extraerDatoPro(line);
    
    string proPreVen = extraerDatoPro(line);

    string proUniMed = extraerDatoPro(line);

    string proDes = extraerDatoPro(line);
    
    string proSto = line;


    Producto producto;

    producto.codigo = proCod;
    producto.categoria = proCat;
    producto.fecha_vencimiento.anio = atoi(proAni.c_str());
    producto.fecha_vencimiento.mes = atoi(proMes.c_str());
    producto.fecha_vencimiento.dia = atoi(proDia.c_str());

    producto.nombre = proNom;
    producto.descripcion = proDes;
    producto.precio_venta = atof(proPreVen.c_str());
    producto.unidad_medida = proUniMed;
    producto.stock = atoi(proSto.c_str());

    return producto;
}





Producto* extraerProductos(){
    ifstream archivo;
    string productoLine;
    static Producto productos[100];
    archivo.open("database-txt/productos.txt", ios::in);

    if(archivo.fail()){
        cout << "No se pudo abrir el archivo";
    }
    int cont = 0;
    while (!archivo.eof()){
        getline(archivo, productoLine);
        productos[cont] = extraerProducto(productoLine);
        cont++;
    }

    archivo.close();

    return productos;

}
