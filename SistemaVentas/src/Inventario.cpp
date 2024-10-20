#include "Inventario.h"
#include "Producto.h"
#include<iostream>
using namespace std;

Inventario::Inventario()
{
    //ctor
}

void Inventario::agregar()
{
    cout<<"polimorfismo en agregar  "<<endl;
    Producto obj;

    obj.setInfo();
    productos.push_back(obj);

    cout<<"Producto creado con exito"<<endl;

}
void Inventario::actualizar() {
    Producto obj;
    int indice;
    cout <<"Dijite el numero del producto al actualizar: ";
    cin>>indice;
    obj.setInfo();
    productos.at(indice-1)= obj;
}

void Inventario::borrar() {
    int indice;
    cout <<"Dijite el numero del producto al eliminar: ";
    cin>>indice;
    productos.erase(productos.begin()+indice-1);
    cout<<"Producto eliminado. "<< endl;
}

void Inventario::mostrar()
{
    cout<<"\t\t*****PRODUCTOS REGISTRADOS*****"<<endl;
    //validacion de productos registrados
    if (productos.size()==NULL){cout<<"No se encuentran productos registrados"<<endl;}

    for(int i=0; i<productos.size(); i++)
    {
        cout<<"Id:"<<i + 1<<endl;
        productos.at(i).getInfo();
    }
    cout<<"--------------------------------------------------"<<endl;
}

void Inventario::menuClase()
{
    int opc;
    do
    {
        cout<<"   * * * Menu * * * "<<endl;
        cout<<"1. Crear Producto"<<endl;
        cout<<"2. Ver Producto"<<endl;
        cout<<"3. Actualizar Producto"<<endl;
        cout<<"4. Eliminar Producto"<<endl;
        cout<<"0. Para salir"<<endl;
        cout<<"Ingrese su eleccion: ";
        cin>>opc;

        switch(opc)
        {
        case 0:
            system("cls"); //limpiar la pantalla de la consola
            cout<<"Adios Producto..."<<endl;
            break;

        case 1:

            system("cls"); //limpiar la pantalla de la consola
            cout <<"Estas en crear Producto." << endl;
            agregar();

            break;

        case 2:
            system("cls"); //limpiar la pantalla de la consola
            cout <<"Estas en ver Producto." << endl;
            mostrar();
            break;
        case 3:
            system("cls"); //limpiar la pantalla de la consola
            cout <<"Estas en actualizar Producto." << endl;
            mostrar();
            actualizar();
            break;
        case 4:
            system("cls");  //limpiar la pantalla de la consola
            cout <<"Estas en eliminar Producto." << endl;
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
