#include "Empleado.h"
#include <iostream>
using namespace std;

Empleado::Empleado()
{
    //ctor
}

void Empleado::agregar()
{
    cout<<"polimorfismo en agregar  "<<endl;
    Empleado objEmpleado;
    objEmpleado.setInfo();
    empleados.push_back(objEmpleado);
    cout<<"Cliente creado con exito"<<endl;
}
void Empleado::mostrar()
{
    cout<<"\t\t*****EMPLEADOS REGISTRADOS*****"<<endl;
    //validacion de empleados registrados
    if (empleados.size()==NULL){cout<<"No se encuentran productos registrados"<<endl;}

    for(int i=0; i<empleados.size(); i++)
    {
        cout<<"Id:"<<i + 1<<endl;
        empleados[i].getInfo();
    }
    cout<<"-----------------------------------------------------------------------------"<<endl;
}


void Empleado::actualizar()
{
    Empleado empleado;
    int indice;
    cout<<"Cual es el Empleado a actualizar: ";
    cin>>indice;
    if (indice > 0 && indice<= empleados.size()){
    empleado.setInfo();
    empleados[indice -1]=empleado;
    }
    else
    {
        cout<<"ID invalido, no se pudo actulizar el empleado."<<endl;
    }

}

void Empleado::borrar()
{
    int indice;
    cout<<"Que contacto va a eliminar: ";
    cin>>indice;
    empleados.erase(empleados.begin()+indice-1);
    cout<<"Contacto eliminado con exito"<<endl;
}

void Empleado::setCorreo()
{
    cout<<"Digite el correo del empleado: ";
    fflush(stdin);
    getline(cin,correo);


};
string Empleado::getCorreo()
{
    return correo;
};

void Empleado::setPuestoEmpleado()
{
    cout<<"Digite el puesto del empleado: ";
    fflush(stdin);
    getline(cin,puestoEmpleado);
};

string Empleado::getPuestoEmpleado()
{
    return puestoEmpleado;
};


void Empleado::setInfo()
{
    setNombre();
    setFechaNacimiento();
    setDocumento();
    setCorreo();
    setPuestoEmpleado();
}
void Empleado::getInfo()
{
    cout<< "Nombre: "<<getNombre()<<"| ";
    cout<< "Fecha de namiento: "<<getFechaNacimiento()<<"| ";
    cout<< "Documento: "<< getDocumento()<< "| ";
    cout<< "Correo:" <<getCorreo() << "| ";
    cout<< "Puesto del empleado: " << getPuestoEmpleado() << endl;
}

void Empleado::menuClase()
{
    int opc;
    do
    {
        cout<<"   * * * Menu * * * "<<endl;
        cout<<"1. Crear Empleado"<<endl;
        cout<<"2. Ver Empleado"<<endl;
        cout<<"3. Actualizar Empleado"<<endl;
        cout<<"4. Eliminar Empleados"<<endl;
        cout<<"0. Para salir"<<endl;
        cout<<"Ingrese su eleccion: ";
        cin>>opc;
        switch(opc)
        {
        case 1:
        {
            system("cls"); //limpiar la pantalla de la consola
            cout<<"Estas en Crear Empleado"<<endl;
            agregar();
            break;
        }
        case 2:
        {
            system("cls"); //limpiar la pantalla de la consola
            cout<<"Estas en Ver Empleado"<<endl;
            mostrar();
            break;
        }
        case 3:
        {
            system("cls"); //limpiar la pantalla de la consola
            cout<<"Estas en Actualizar Empleado"<<endl;
            mostrar();
            actualizar();
            break;
        }
        case 4:
        {
            system("cls"); //limpiar la pantalla de la consola
            cout<<"Estas en Eliminar Empleado"<<endl;
            mostrar();
            borrar();
            break;
        }
        case 0:
            system("cls"); //limpiar la pantalla de la consola
            cout<<"Adios Empleado..."<<endl;
            break;
        default:
            cout<<"Presionaste mal"<<endl;
        }
    }
    while(opc!=0);
}
