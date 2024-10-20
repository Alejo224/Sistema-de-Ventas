#include "Persona.h"
#include <iostream>

Persona::Persona()
{
    //ctor
}

void Persona::setNombre()
{
    fflush(stdin);
    cout<<"cual es el nombre: ";
    getline(cin,nombre);
}

string Persona::getNombre()
{
    return nombre;
}

void Persona::setFechaNacimiento()
{
    fflush(stdin);
    cout<<"cual es tu fecha de nacimiento: ";
    getline(cin,fechaNacimiento);
}

string Persona::getFechaNacimiento()
{
    return fechaNacimiento;
}

void Persona::setDocumento()
{
    cout<<"Ingrese el numero de documento: ";
    cin>> documento;
}

int Persona::getDocumento()
{
    return documento;
}


void Persona::setInfo()
{
    setNombre();
    setFechaNacimiento();
    setDocumento();
}

void Persona::getInfo()
{
    cout<<"Nombre: "<<getNombre()<<endl;
    cout <<"Fecha de namiento: "<<getFechaNacimiento()<< endl;
    cout <<"Documento: "<< getDocumento()<< endl;
}


