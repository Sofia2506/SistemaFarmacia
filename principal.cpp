
#include "funciones/carrito.cpp"
#include <stdlib.h>
void agregarProducto();
bool buscarProducto();
bool busquedaPorCodigo();
void verCarrito();
void mostrarProductos();
void mostrarMenu();

Producto *productos ; //Productos registrados en el sistema
Carrito *carrito=new Carrito();// Carrito de Compras
int main(){

    cout<<"-----Bienvenido al sistema de control de ventas de la farmacia----"<<endl;
    productos = extraerProductos();
    while(true){
        mostrarMenu();
    }
}

//Menu principal del Sistema
void mostrarMenu(){
    //Opciones
    cout<<"Menu principal"<<endl;
    cout<<"\t1.Agregar producto"<<endl;
    cout<<"\t2.Buscar producto"<<endl;
    cout<<"\t3.Salir"<<endl;
    int opcion;
    cin>>opcion;
    switch (opcion){
        case 1:{
            agregarProducto();
        } 
        break;
        case 2 :{
            bool confirm = true;
            while(confirm){
                confirm = buscarProducto();
            }
        }  
        break;
        case 3:{
            cout<<"Hasta pronto :3"<<endl;
            exit(-1);
        }
        break;
        default:
            cout<<"Ingreso una opcion invalida";
    }
    
}
//Pide caracteristicas del producto y lo agrega.
void agregarProducto(){
    static Producto producto;
    cout<<"Para agregar un producto al almacen llene todos los dostos necesarios:"<<endl;
    cout<<"Ingrese codigo de producto:"<<endl;
    string codigo;
    cin >>codigo;
    producto.codigo = codigo;
    cout<<"Ingrese la categoria del producto:"<<endl;
    string categoria;
    cin>>categoria;
    producto.categoria =categoria;
    cout<<"Ingrese le fecha vencimiento del producto(DIA):"<<endl;
    int dia;
    cin>>dia;
    producto.fecha_vencimiento.dia = dia;
    cout<<"Ingrese le fecha vencimiento del producto(MES):"<<endl;
    int mes;
    cin>>mes;
    producto.fecha_vencimiento.mes = mes;
    cout<<"Ingrese le fecha vencimiento del producto(ANIO):"<<endl;
    int anio;
    cin>>anio;
    producto.fecha_vencimiento.dia = anio;
    cout<<"Ingrese el nombre del producto:"<<endl;
    string nombre;
    cin>>nombre;
    producto.nombre=nombre;
    cout<<"Ingrese precio de venta:"<<endl;
    double venta;
    cin>>venta;
    producto.precio_venta = venta;
    cout<<"Ingrese la unidad de medida:"<<endl;
    string unidad;
    cin>>unidad;
    producto.unidad_medida = unidad;
    cout<<"Ingrese el stock del producto:"<<endl;
    int stock;
    cin>>stock;
    producto.stock = stock;
    //Añade producto en el txt;
    aniadirProducto(producto);
}

//Mostrar todos los productos 
void mostrarProductos(){
    for (int i = 0; i < 100; i++){
        Producto *prod = &productos[i];
        if ( prod->precio_venta != 0){
            cout << (i+1) << ". " << prod->nombre << " " << prod->precio_venta << endl;
        }
        else{
            break;
        }
    }
}

//Menu de venta buscar producto o mostrar carrito
bool buscarProducto(){
    //Opciones
    cout<<"\t1.Busqueda"<<endl;
    cout<<"\t2.Mostrar Carrito"<<endl;
    int respuesta;           
    cin>>respuesta;
    switch (respuesta)
    {
        case 1:
            {
            bool confirm=true;
            while(confirm){
             confirm = busquedaPorCodigo();
            }
            }
        break;
        case 2:
            {
            verCarrito();
            }
        break;
        default:
            {cout<<"Ingreso un valor no valido";}
        break;
    }
    cout<<"¿Desea seguir buscando Producto o ver su carrito?(SI=1,No=0)"<<endl;
    cin>>respuesta;
    if(respuesta==1){
        return true;
    }
    else{
        return false;
    }
  
}


//Realiza busqueda del producto.
bool busquedaPorCodigo(){
    mostrarProductos();
    cout<<"Ingrese el codigo del producto que desea buscar"<<endl;
    string code;
    cin>>code;
   
    Producto producto = productos[atoi(code.c_str())-1];
    cout <<"¿Cuantos desea comprar?"<<endl;
    int cantidadCompra;
    cin>>cantidadCompra;
    ProdCant productoComprado = {producto,cantidadCompra};
    carrito->aniadirProductoCarrito(productoComprado);
    cout<<"¿Desea seguir buscando por codigo?(SI=1,No=0)"<<endl;
    int respuesta;
    cin>>respuesta;
    if(respuesta==1)
        return true;
    else
        return false;
    
}

//Menu del carrito de compras
void verCarrito(){
    carrito->verProductos();
    //Opciones
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
        {
        carrito->eliminarProductoCarrito();
        }
        break;
    case 2:
        {
        carrito->generarBoleta();
        cout << "Venta Exitosa!!"<<endl;
        }
        break;
    case 3:
        {
        bool confirm=true;
        while(confirm){
            buscarProducto;
        }
        verCarrito();
        }
        break;
    case 4:
        {
        carrito->modificar();
        }
    case 5:
        break;
    default:
        break;
    }
}