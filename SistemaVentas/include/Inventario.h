#ifndef INVENTARIO_H
#define INVENTARIO_H
#include<vector>
#include "Producto.h"
#include "Menu.h"


class Inventario:public Menu{
public:
    Inventario();
    Producto producto;

    void agregar()override;
    void borrar()override;
    void actualizar()override;
    void mostrar()override;
    void menuClase()override;


};
extern vector<Producto> productos;
#endif // INVENTARIO_H
