#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include "Menu.h"

using namespace std;

class Persona: public Menu{
    public:
        Persona();

        string nombre;
        string fechaNacimiento;
        int documento;

        string getNombre();
        string getFechaNacimiento();
        int getDocumento();

        void setDocumento();
        void setNombre();
        void setFechaNacimiento();

        virtual void getInfo();
        virtual void setInfo();
};

#endif // PERSONA_H
