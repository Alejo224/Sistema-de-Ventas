#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <vector>
#include "Menu.h"
#include "Persona.h"

class Empleado:public Persona{
public:
    Empleado();

    //atributos
    string correo;
    string puestoEmpleado;

    //metodos
    void setCorreo();
    string getCorreo();

    void setPuestoEmpleado();
    string getPuestoEmpleado();

    //poilimorfismo
    void setInfo()override;
    void getInfo()override;

    void agregar()override;
    void borrar()override;
    void actualizar()override;
    void mostrar()override;
    void menuClase()override;
};

// Declarar el vector de Empleado como una variable externa
extern vector<Empleado> empleados;

#endif // EMPLEADO_H
