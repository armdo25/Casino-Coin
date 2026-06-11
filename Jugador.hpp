/*
    Jugador es clase hija de Usuario. Esta clase maneja un saldo propio del jugador, y tiene métodos para depositar, retirar saldo y realizar apuestas sobre eventos deportivos.
    Además, sobrescribe el método virtual verHistorial() para mostrar solamente el historial de apuestas de ese jugador en particular.
*/  
#ifndef JUGADOR_HPP
#define JUGADOR_HPP


#include "Usuario.hpp"
#include "Evento_Deportivo.hpp"
#include "Apuesta.hpp"

//Declaro la clase Jugador como clase hija de Usuario
class Jugador : public Usuario {
private:
    double saldo;

public:
    Jugador(int idUsuario, string nombre, double saldo);
    double getSaldo();
    void depositarSaldo(double monto);

    //Regresa true si el retiro fue posible y false si no había saldo suficiente
    bool retirarSaldo(double monto);
    Apuesta realizarApuesta(int idApuesta, Evento_Deportivo evento, double monto, string seleccion);

    //Se sobrescribe el método abstracto heredado de Usuario donde se muestra solamente el historial de apuestas de ese jugador
    void verHistorial(vector<Apuesta>& apuestas) override;
};

#endif
