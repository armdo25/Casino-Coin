#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include "Usuario.hpp"

class Administrador : public Usuario {
public:
    Administrador(int idUsuario, string nombre, double saldo);

    void verHistorial(vector<Apuesta>& apuestas) override;
};

#endif