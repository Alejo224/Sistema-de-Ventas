#include "Cliente.h"
#include "Persona.h"
#include "Menu.h"
#include <iostream>
using namespace std;

Cliente::Cliente()
{
    //ctor
}

void Cliente::agregar()
{
    cout<<"polimorfismo en agregar  "<<endl;
    Cliente objCliente;
    objCliente.setInfo();
    clientes.push_back(objCliente);
    cout<<"Cliente creado con exito"<<endl;
}

void Cliente::mostrar()
{
    cout<<"\t\t*****CLIENTES REGISTRADOS*****"<<endl;
    //validacion de empleados registrados
    if(clientes.size()== NULL){cout<<"No hay clientes registrados."<<endl;}

    for(int i=0; i<clientes.size(); i++)
    {
        cout<<"Id:"<<i + 1<<endl;
        clientes.at(i).getInfo();
    }
    cout<<"-----------------------------------------------------------------------------"<<endl;
}
int Cliente::changeId(int valor)
{
    return idCliente= --valor;
}

int Cliente::getId(int valor)
{
    return idCliente = ++valor;
}

void Cliente::actualizar()
{
    int indice;
    Cliente cliente;
//    clientes[indice]= newCliente;
    cout <<"Dijite el numero del cliente a actualizar: ";
    cin>>indice;
    if (indice> 0 && indice<= clientes.size())
    {
        cliente.setInfo();
        clientes[indice-1]= cliente;
        cout<<"Cliente actualizado."<<endl;
    }
    else
    {
        cout<<"ID invalido, no se pudo actulizar el cliente."<<endl;
    }
}

void Cliente::borrar()
{
    int indice;
    cout<<"Que contacto va a eliminar: ";
    cin>>indice;
    if (indice>0 && indice<=clientes.size())
    {
        clientes.erase(clientes.begin()+ indice-1);
        cout<<"Contacto eliminado con exito"<<endl;
    }
    else{
        cout <<"ID invalido, no se pudo actulizar el cliente."<<endl;
    }

}

void Cliente::setTipoCliente()
{
    cout<<"Dijite el tipo de cliente ('Frecuente', 'Ocasional', 'VIP'): ";
    fflush(stdin);
    getline(cin,tipoCliente);
};

string Cliente::getTipoCliente()
{
    return tipoCliente;
};

void Cliente::setInfo()
{
    setNombre();
    setFechaNacimiento();
    setDocumento();
    setTipoCliente();
}
void Cliente::getInfo()
{
    cout<< "Nombre: "<<getNombre()<<"| ";
    cout<< "Fecha de nacimiento: "<<getFechaNacimiento()<<"| ";
    cout<< "Documento: "<< getDocumento()<< "| ";
    cout<< "Tipo de cliente: "<< getTipoCliente() << endl;
}

void Cliente::menuClase()
{
    int opc;
    do
    {
        cout<<"   * * * Menu * * * "<<endl;
        cout<<"1. Crear Cliente"<<endl;
        cout<<"2. Ver Clientes"<<endl;
        cout<<"3. Actualizar Clientes"<<endl;
        cout<<"4. Eliminar Clientes"<<endl;
        cout<<"0. Para salir"<<endl;
        cout<<"Ingrese su eleccion: ";
        cin>>opc;
        switch(opc)
        {
        case 1:
        {
            system("cls"); //limpiar la pantalla de la consola

            cout<<"Estas en Crear Cliente"<<endl;
            agregar();
            break;
        }
        case 2:
        {
            system("cls"); //limpiar la pantalla de la consola
            cout<<"Estas en Ver Clientes"<<endl;
            mostrar();
            break;
        }
        case 3:
        {
            system("cls"); //limpiar la pantalla de la consola
            cout<<"Estas en Actualizar Clientes"<<endl;
            mostrar();
            actualizar();
            break;
        }
        case 4:
        {
            system("cls"); //limpiar la pantalla de la consola
            cout<<"Estas en Eliminar Cliente"<<endl;
            mostrar();
            borrar();
            break;
        }
        case 0:
            system("cls"); //limpiar la pantalla de la consola
            cout<<"saliendo menu cliente..."<<endl;
            break;
        default:
            cout<<"Presionaste mal"<<endl;
        }
    }
    while(opc!=0);
}
