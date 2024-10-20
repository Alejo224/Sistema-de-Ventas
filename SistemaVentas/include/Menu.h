#ifndef MENU_H
#define MENU_H
#include<vector>
//#include "Persona.h"
#include <iostream>


class Menu
{
    public:
        Menu();
        virtual void agregar();
        virtual void borrar();
        virtual void actualizar();
        virtual void mostrar();
        virtual void menuClase();

};

#endif // MENU_H
