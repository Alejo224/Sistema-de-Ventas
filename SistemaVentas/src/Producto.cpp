#include "Producto.h"
#include <iostream>
using namespace std;

Producto::Producto()
{
    //ctor
}


void Producto::setMarca(){

    fflush(stdin);
    cout <<"Ingrese la marca del producto: ";
    getline(cin,marca);

};

void Producto::setCantidad(){
    cout <<"Ingrese la cantidad del producto: ";
    cin>> cantidad;
};

void Producto::setCantidad(int nuevaCantidad)
{
    cantidad = nuevaCantidad;
};

void Producto::setprecio(){
    cout <<"Ingrese el precio del producto: ";
    cin>> precio;

    };
void Producto::setFechaVencimiento(){
    fflush(stdin);
    cout << "Ingrese la fecha de vencimiento del producto: ";
    getline(cin,fechaVencimiento);
}

//getters
string  Producto::getMarca(){return marca;};

int Producto::getCantidad(){return cantidad;};

double Producto::getPrecio(){return precio;};

string Producto::getFechaVencimiento(){return fechaVencimiento;};

void Producto::descontarProducto(int cantidadVendida)
{
    if (cantidad >= cantidadVendida)
    {
        cantidad -= cantidadVendida;
        cout << "Cantidad descontada." << endl;
    }
    else{
        cout<<"NO hay producto disponible." <<endl;
    }

}

void Producto::getInfo(){
//    system("cls"); //Limpiar la consola

    cout<< "Marca: " << getMarca();
    cout<< "| Fecha Vencimiento: " << getFechaVencimiento();
    cout<<"| Cantidad del producto " << getMarca() << ": " << getCantidad();
    cout<< "| Precio: " << getPrecio()<< endl;

};

void Producto::setInfo(){
    setMarca();
    setFechaVencimiento();
    setCantidad();
    setprecio();

};
