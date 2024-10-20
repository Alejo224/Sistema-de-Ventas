#ifndef MENUFACTURA_H
#define MENUFACTURA_H

#include<vector>
#include "Factura.h"

class MenuFactura:public Menu{
public:
    MenuFactura();

    vector<Factura> facturas;

    void agregar()override;
    void borrar()override;
    void actualizar()override;
    void mostrar()override;
    void menuClase()override;

};

#endif // MENUFACTURA_H
