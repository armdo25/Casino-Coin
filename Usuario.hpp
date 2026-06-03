#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Apuesta.hpp"

using namespace std;

class Usuario {
protected:
    int idUsuario;
    string nombre;
    double saldo;

public:
    Usuario(int idUsuario, string nombre, double saldo);
    virtual ~Usuario();

    int getIdUsuario();
    string getNombre();
    double getSaldo();

    void depositarSaldo(double monto);
    bool retirarSaldo(double monto);

    virtual void verHistorial(vector<Apuesta>& apuestas) = 0;
};

#endif