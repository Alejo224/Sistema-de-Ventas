#ifndef FACTURA_H
#define FACTURA_H

#include <iostream>
#include <vector>
using namespace std;

#include "Cliente.h"
#include "Empleado.h"
#include "Producto.h"
#include "Inventario.h"

class Factura
{
    public:
        Factura();

        // Estructura para productos seleccionados
    struct ProductosSeleccionados {
        string marca;
        int cantidad;
        double precio;
        string fechaVencimiento;
    };

    vector<ProductosSeleccionados> productosSeleccionados; // Mueve esto fuera de la clase


        //atributos
        int idFactura;
        int idCliente;
        int idEmpleado;
        int idProducto;
        string fechaFactura;
        double totalFactura = 0.0;
        int cantidadVendida;

        void MostrarProductosSeleccionados();

        //setters
        void setIdCliente();
        void setIdEmpleado();
        void setIdProducto();
        void setFechaFactura();
        void setTotalFactura();
        void  setCantidadVendida();
        void setInfo();
        void getInfo();

        //getters
        int getIdFactura();
        int  getIdCliente();
        int getIdEmpleado();
        int getIdProducto();
        string getFechaFactura();
        double getTotalFactura();
        int  getCantidadVendida();
};

#endif // FACTURA_H
