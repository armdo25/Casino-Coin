#ifndef JUGADOR_HPP
#define JUGADOR_HPP

#include "Usuario.hpp"
#include "Evento_Deportivo.hpp"
#include "Apuesta.hpp"

class Jugador : public Usuario {
public:
    Jugador(int idUsuario, string nombre, double saldo);

    Apuesta realizarApuesta(int idApuesta, EventoDeportivo evento, double monto, string seleccion);
    void verHistorial(vector<Apuesta>& apuestas) override;
};

#endif
