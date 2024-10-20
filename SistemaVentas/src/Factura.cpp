#include "Factura.h"
#include <iostream>
#include <ctime> //libreria para obtener la hora de factur
#include<vector>

using namespace std;

Factura::Factura() {
    // Constructor
    }

void Factura::setIdCliente()
{
//    int indice;
    cout <<"Digite el ID del cliente: ";
    cin >>idCliente;
    if (idCliente> 0 && idCliente<= clientes.size())
    {
        cout<<"Cliente elegido."<< endl;
        cout << "Nombre: "<< clientes[idCliente -1].getNombre() << endl;
    }
    else
    {
        cout<<"ID invalido, no se pudo elegir el cliente."<<endl;
    }
};


void Factura::setIdEmpleado()
{
//    int indice;
    cout <<"Digite el ID del Empleado que te atendio: ";
    cin >>idEmpleado;
    if (idEmpleado> 0 && idEmpleado<= empleados.size())
    {
        cout<<"Empleado elegido."<< endl;
        cout <<"Nombre: " <<empleados[idEmpleado - 1].getNombre() << endl;
    }
    else
    {
        cout<<"ID invalido, no se pudo elegir el Empleado."<<endl;
    }
};


void Factura::setIdProducto()
{
    char opcion = 's';
    do
    {
        cout << "Digite el ID del producto: ";
        cin >> idProducto;

        if (idProducto > 0 && idProducto <= productos.size())
        {
            cout << "Producto elegido." << endl;
            cout << "Nombre: " << productos.at(idProducto - 1).getMarca() << endl;

            // Método para obtener la cantidad que desea comprar
            setCantidadVendida();

            // Verificar si hay suficiente cantidad disponible
            if (productos.at(idProducto - 1).getCantidad() >= getCantidadVendida())
            {
                cout << "El producto se puede comprar." << endl;

                // Decrementar la cantidad disponible del producto
                int nuevaCantidad = productos.at(idProducto - 1).getCantidad() - getCantidadVendida();
                productos.at(idProducto - 1).setCantidad(nuevaCantidad);  // Actualización de la cantidad

                //llamar el metedo setTotalFactura
                setTotalFactura();

                // Mostrar la nueva cantidad disponible
                cout << "Nueva cantidad disponible del producto: " << productos.at(idProducto - 1).getCantidad() << endl;
                cout << "Subtotal hasta ahora: $" << getTotalFactura() << " COP." <<endl;

            }
            else
            {
                cout << "No tenemos suficiente cantidad del producto que elegiste." << endl;
            }
        }
        else
        {
            cout << "No se puede comprar el producto." << endl;
        }

        // Preguntar si desea elegir otro producto
        cout << "¿Deseas elegir otro producto? (s/n): ";
        cin >> opcion;

    }
    while (opcion == 's');   // Condición para repetir el proceso

    cout << "Facturación completada." << endl;
}
void Factura::setFechaFactura()
{

    time_t now = time(nullptr);
    // Obtener la fecha y hora actuales
    tm* localTime = localtime(&now);
    char buffer[128];

    // Formatear la fecha y la hora
    strftime(buffer, sizeof(buffer), "%m-%d-%Y %X", localTime);

    // Guardar la fecha formateada en el atributo 'fechaFactura'
    fechaFactura = buffer;
};

void Factura::setTotalFactura()
{
    double precioProducto = productos.at(getIdProducto()-1).getPrecio();
    totalFactura += precioProducto*getCantidadVendida();        // Actualizar el total

// Crear un nuevo objeto de ProductosSeleccionados
    ProductosSeleccionados seleProducto; // Crear una instancia de la estructura

    // Asignar valores a la instancia
    seleProducto.marca = productos.at(idProducto - 1).getMarca(); // Obtener la marca del producto
    seleProducto.cantidad = getCantidadVendida(); // Obtener la cantidad vendida
    seleProducto.precio = precioProducto; // Obtener el precio del producto
    seleProducto.fechaVencimiento = productos.at(idProducto - 1).getFechaVencimiento(); // Obtener la fecha de vencimiento

    // Añadir a la lista de productos seleccionados
    productosSeleccionados.push_back(seleProducto); // Usa la instancia creada
};

double Factura::getTotalFactura()
{
    return totalFactura;
};

void Factura::setCantidadVendida()
{
    cout<< "Ingrese la cantidad que desea comprar: ";
    cin>>cantidadVendida;

};

int  Factura::getCantidadVendida()
{
    return cantidadVendida;
};

//getters
int Factura::getIdFactura() {return idFactura; };
int  Factura::getIdCliente(){return idCliente; };
int  Factura::getIdEmpleado(){return idEmpleado; };
int Factura::getIdProducto(){return idProducto; };

string Factura::getFechaFactura()
{
    return fechaFactura;
};

void Factura::MostrarProductosSeleccionados() {
    cout << "------------ PRODUCTOS SELECCIONADOS------------" << endl;
    if (productosSeleccionados.empty()) {
        cout << "No hay productos seleccionados." << endl;
    } else {
        for (const auto& producto : productosSeleccionados) {
            cout << "Producto: " << producto.marca << endl;
            cout << "Cantidad: " << producto.cantidad << endl;
            cout << "Precio Unitario: $" << producto.precio << endl;
            cout << "Subtotal: $" << producto.precio * producto.cantidad << endl;
            cout << "Fecha de Vencimiento: " << producto.fechaVencimiento << endl;
            cout << "--------------------------------------------" << endl;
        }
    }

    // Mostrar el total de la factura
    cout << "Total de la factura: $" << getTotalFactura() << endl;
    cout << endl;
}


void Factura::setInfo()
{
    setIdEmpleado();
    setIdCliente();
    setIdProducto();
    setFechaFactura();
};

void Factura::getInfo()
{
    cout<<"* * * * * * * * * * *FACTURA* * * * * * * * * * *"<< endl;

    cout<<"Factura creada: " << getFechaFactura() << endl;
    cout<<"------------Empleado selecionado------------"<<endl;
    cout <<"Nombre: "<<empleados[getIdEmpleado() -1].getNombre() << "| ";
    cout <<"Documneto: "<<empleados[getIdEmpleado() -1].getDocumento()<< "| ";
    cout <<"Puesto Otorgado: "<<empleados[getIdEmpleado() -1].getPuestoEmpleado()<<endl;
    cout<<"------------Cliente selecionado------------"<<endl;
    clientes[getIdCliente() -1].getInfo();
    MostrarProductosSeleccionados();
};

