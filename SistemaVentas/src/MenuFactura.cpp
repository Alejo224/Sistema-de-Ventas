#include "MenuFactura.h"
#include "Factura.h"
#include<iostream>
#include "Cliente.h"
#include "Inventario.h"
#include "Producto.h"

using namespace std;

MenuFactura::MenuFactura()
{
    //ctor
}

int indice;
//Intancias de las clases
//INSTANCIA de los objectos de forma global para que la información sean persistente
Cliente objcliente;
Empleado objEmpleado;
Inventario objInventario;
Producto objProducto;

void MenuFactura::agregar()
{
    cout<<"--------------AGREGANDO FACTURA--------------"<<endl;
    Factura objFactura;
    objFactura.setInfo();
    facturas.push_back(objFactura);

    cout<<"Factura creado con exito"<<endl;

}
void MenuFactura::actualizar() {
    cout <<"Dijite el numero de la factura al actualizar: ";
    cin>>indice;
    Factura objFactura;
    objFactura.setInfo();
    facturas.at(indice - 1)= objFactura;

}

void MenuFactura::borrar() {
    cout <<"Dijite el numero de la factura a eliminar: ";
    cin>>indice;
    facturas.erase(facturas.begin()+indice -1);

    cout<<"Factura eliminada. "<< endl;
}

void MenuFactura::mostrar()
{
    cout<<"\t\t* * * * *FACTURAS* * * * *"<<endl;
    if (facturas.size() == NULL){cout<<"No hay facturas registradas"<<endl;}
    else{
    for(int i=0; i<facturas.size(); i++)
    {
        cout<<"ID: "<< i +1<<" ";
        facturas.at(i).getInfo();

    }
    cout<<"--------------------------------------------------"<<endl;
    }
}

void MenuFactura::menuClase()
{
    int opc;
    do
    {
        cout<<"   * * * Menu * * * "<<endl;
        cout<<"1. Crear Factura"<<endl;
        cout<<"2. Ver Factura"<<endl;
        cout<<"3. Actualizar Factura"<<endl;
        cout<<"4. Eliminar Factura"<<endl;
        cout<<"0. Para salir"<<endl;
        cout<<"Ingrese su eleccion: ";
        cin>>opc;

        switch(opc)
        {
        case 0:
            system("cls"); //limpiar la pantalla de la consola
            cout<<"Adios Factura..."<<endl;
            break;

        case 1:

            system("cls"); //limpiar la pantalla de la consola
            cout <<"Estas en crear Factura." << endl;
            objEmpleado.mostrar();
            objcliente.mostrar();
            objInventario.mostrar();
            agregar();

            break;

        case 2:
            system("cls"); //limpiar la pantalla de la consola
            cout <<"Estas en ver Factura." << endl;
            mostrar();
            break;
        case 3:
            system("cls"); //limpiar la pantalla de la consola
            cout <<"Estas en actualizar Factura." << endl;
            mostrar();
            objEmpleado.mostrar();
            objcliente.mostrar();
            objInventario.mostrar();
            actualizar();
            break;
        case 4:
            system("cls");  //limpiar la pantalla de la consola
            cout <<"Estas en eliminar Factura." << endl;
            mostrar();
            borrar();
            break;

        default:
            cout<<"Presionaste mal"<<endl;
            break;
        }
    }
    while(opc != 0);
}
