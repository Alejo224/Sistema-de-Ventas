#ifndef CLIENTE_H
#define CLIENTE_H
#include "Persona.h"
#include "Menu.h"
#include<vector>

class Cliente: public Persona
{
public:
    Cliente();
    //atributos
    int idCliente = 1;
    string tipoCliente;

    //metodos
    int getId(int);
    int changeId(int);

    string getTipoCliente();
    void setTipoCliente();

    //polimorfismo Persona
    void setInfo()override;
    void getInfo()override;

    //polimorfismo Menu
    void agregar()override;
    void borrar()override;
    void actualizar()override;
    void mostrar()override;
    void menuClase()override;
};

// Declarar el vector de Empleado como una variable externa
extern vector<Cliente> clientes;

#endif // CLIENTE_H
