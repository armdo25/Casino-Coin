#include "Usuario.hpp"

Usuario::Usuario(int idUsuario, string nombre, double saldo) {
    this->idUsuario = idUsuario;
    this->nombre = nombre;
    this->saldo = saldo;
}

Usuario::~Usuario() {
}

int Usuario::getIdUsuario() {
    return idUsuario;
}

string Usuario::getNombre() {
    return nombre;
}

double Usuario::getSaldo() {
    return saldo;
}

void Usuario::depositarSaldo(double monto) {
    if (monto > 0) {
        saldo = saldo + monto;
    }
}

bool Usuario::retirarSaldo(double monto) {
    if (monto > 0 && saldo >= monto) {
        saldo = saldo - monto;
        return true;
    }
    else {
        return false;
    }
}
