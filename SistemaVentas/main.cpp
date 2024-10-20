#include <iostream>
#include "Menu.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Inventario.h"
#include "Factura.h"
#include "MenuFactura.h"
#include "Producto.h"

using namespace std;

//inicialización de vectores de forma global para no perder los datos
vector<Cliente> clientes;
vector<Empleado> empleados;
vector<Producto> productos;


int main()
{
     cout << "************ MENU ************" << endl;
    int opc;

    //creaciones de las instancias de las clases. Cliente,Empleado,Inventario,Factura
    Inventario inventario;
    Empleado empleado;
    Cliente cliente;
    MenuFactura factura;

    do
    {
        cout << "<1> Cliente" << endl;
        cout << "<2> Empleado" << endl;
        cout << "<3> Inventario" << endl;
        cout << "<4> factura" << endl;
        cout << "<0> Salir." << endl;
        cout << "Elige una opcion" << endl;
        cin>>opc;

        switch(opc)
        {
        case 1:{
//            system("cls"); //Limpiar la consola
            cout <<"Estas en Cliente" << endl;
//            cliente.agregar();
            cliente.menuClase();

            break;
        }
        case 2:{
//            system("cls"); //Limpiar la consola
            cout <<"Estas en Empleado" << endl;
            empleado.menuClase();

            break;

        }
        case 3:{
//            system("cls"); //Limpiar la consola
            cout <<"Estas en Inventario" << endl;
//            Inventario inventario;
            inventario.menuClase();
            break;
        }
        case 4:
            {
                cout<<"Estas en factura. " << endl;
                factura.menuClase();
                break;
            }

        default: cout<<"Presionaste mal"<<endl;

        }
    }while(opc != 0);

    return 0;
}
