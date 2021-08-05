#include "funciones/extraer.cpp"
#include "clases/carrito.h"
void mostrarMenu();
void agregarProducto();
bool buscarProducto();
bool busquedaPorCodigo();
void verCarrito();
Carrito *carrito=new Carrito();
int main(){

    cout<<"-----Bienvenido al sistema de control de ventas de la farmacia----"<<endl;
    
    while(true){
        mostrarMenu();
    }
}

void mostrarMenu(){
    cout<<"Menu principal"<<endl;
    cout<<"\t1.Agregar producto"<<endl;
    cout<<"\t2.Buscar produocto"<<endl;
    cout<<"\t3.Salir"<<endl;
    //Selecciona una opción
    int opcion;
    cin>>opcion;
    switch (opcion)
    {
    case 1: agregarProducto();
        break;
    case 2 :  
        bool confirm=true;
        while(confirm){
           confirm = buscarProducto();
        }
        break;
    case 3: cout<<"Hasta pronto :3"<<endl;
        exit(-1);
    default:cout<<"Ingreso una opcion invalida";
        break;
    }
    
}

void agregarProducto(){
    Producto producto;
    cout<<"Para agregar un producto al almacen llene todos los dostos necesarios"<<endl;
    cout<<"Ingrese codigo de producto"<<endl;
    string codigo;
    cin >>codigo;
    producto.codigo = codigo;
    cout<<"Ingrese la categoria del producto"<<endl;
    string categoria;
    cin>>categoria;
    producto.categoria =categoria;
    cout<<"Ingrese le fecha vencimiento del producto(DIA)"<<endl;
    int dia;
    cin>>dia;
    producto.fecha_vencimiento.dia = dia;
    cout<<"Ingrese le fecha vencimiento del producto(MES)"<<endl;
    int mes;
    cin>>mes;
    producto.fecha_vencimiento.mes = mes;
    cout<<"Ingrese le fecha vencimiento del producto(ANIO)"<<endl;
    int anio;
    cin>>anio;
    producto.fecha_vencimiento.dia = anio;
    cout<<"Ingrese el nombre del producto"<<endl;
    string nombre;
    cin>>nombre;
    producto.nombre=nombre;
    cout<<"Ingrese precio de venta";
    double venta;
    cin>>venta;
    producto.precio_venta = venta;
    cout<<"Ingrese la unidad de medida";
    string unidad;
    cin>>unidad;
    producto.unidad_medida = unidad;
    //falta descripcción
    producto.descripcion ="null";
    cout<<"Ingrese el stock del producto";
    int stock;
    cin>>stock;
    producto.stock = stock;
    aniadirProducto(producto);
}
bool buscarProducto(){
    cout<<"\t1.Busqueda por codigo "<<endl;
    cout<<"\t2.Mostrar Carrito"<<endl;
    int respuesta;
    cin>>respuesta;
    switch (respuesta)
    {
    case 1:
        bool confirm=true;
        while(confirm){
        busquedaPorCodigo();
        }
        break;
    case 2:
        verCarrito();
        break;
    default:cout<<"Ingreso un valor no valido";
        break;
    }
    cout<<"¿Desea seguir buscando?(SI=1,No=0)"<<endl;
    int respuesta;
    if(respuesta==0){
        return true;
    }
    else{
        return false;
    }
    /*
    extraerProducto("79653A;Categoria;2021;7;29;Naproxeno;0.200000;unidad;null;500");
    */
}
bool busquedaPorCodigo(){
    cout<<"Ingrese el codigo del producto que desea buscar"<<endl;
    string code;
    cin>>code;
    //empieza a buscar el producto y luego obtienes un producto
    //--Insertar code--
    //obtienes producto y lo añades al carrito
    Producto producto;
    cout<<"¿Cuantos desea comprar?"<<endl;
    int cantidadCompra;
    cin>>cantidadCompra;
    ProdCant productoComprado = {producto,cantidadCompra};
    //:"v no se añade al carrito
    
    carrito->aniadirProductoCarrito(productoComprado); 
    cout<<"¿Desea seguir buscando?(SI=1,No=0)"<<endl;
    int respuesta;
    if(respuesta==0){
        return true;
    }
    else{
        return false;
    }
}

void verCarrito(){
    carrito->verProductos();
    cout<<"¿Que desea hacer?"<<endl;
    cout<<"\t1.Quitar un producto del carrito"<<endl;
    cout<<"\t2.Confirmar venta"<<endl;
    cout<<"\t3.Aniadir otro producto"<<endl;
    cout<<"\t4.Modificar compra"<<endl;
    cout<<"\t5.Cancelar todo"<<endl;
    int respuesta;
    cin>>respuesta;
    switch (respuesta)
    {
    case 1:
        carrito->eliminarProductoCarrito();
        break;
    case 2:
        carrito->generarBoleta();
        break;
    case 3:
        bool confirm=true;
        while(confirm){
            buscarProducto;
        }
        verCarrito();
        break;
    case 4:
        carrito->modificar();
    case 5:
        break;
    default:
        break;
    }
}