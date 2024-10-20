#ifndef PRODUCTO_H
#define PRODUCTO_H
#include<iostream>
using namespace std;

class Producto{
    public:
        Producto();
        //atributos
        string marca;
        int cantidad;
        double precio;
        string fechaVencimiento;

        //metodos
        void setMarca();
        void setCantidad();
        void setCantidad(int nuevaCantidad); //sobrecarga para poder actualizar la cantidad del producto
        void setprecio();
        void setFechaVencimiento();

        void descontarProducto(int);

        string  getMarca();
        int getCantidad();
        double getPrecio();
        string getFechaVencimiento();

        void getInfo();
        void setInfo();

};

#endif // PRODUCTO_H
