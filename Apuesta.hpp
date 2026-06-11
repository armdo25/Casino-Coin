/*
    La clase Apuesta representa una apuesta individual realizada por un usuario. Cada apuesta tiene un ID único, el ID del usuario que la realizó, el ID del evento deportivo relacionado, el monto apostado, 
    la selección del jugador (local, empate o visitante), la ganancia potencial calculada con base en la cuota del evento y el estado actual de la apuesta (Pendiente, Ganada o Perdida).
    La clase incluye métodos para calcular la ganancia potencial usando la cuota del evento, validar si la apuesta se puede realizar según el saldo del usuario y el estado del evento, resolver 
    la apuesta comparando la selección del usuario con el resultado real y mostrar en consola la información completa de la apuesta.
*/  

#ifndef APUESTA_HPP
#define APUESTA_HPP


#include <iostream>
#include <string>
#include "Cuota.hpp"
#include "Evento_Deportivo.hpp"

using namespace std;


class Apuesta {
private:
    int idApuesta;
    int idUsuario;
    int idEvento;
    double monto;
    string seleccion;
    double gananciaPotencial;
    string estado;

public:
    //Constructor de la clase Apuesta que recibe los datos necesarios para crear una apuesta
    Apuesta(int idApuesta, int idUsuario, int idEvento, double monto, string seleccion, double gananciaPotencial);

    //Regresa el ID del usuario que realizó la apuesta
    int getIdUsuario();

    //Regresa el ID del evento relacionado con la apuesta
    int getIdEvento();

    double calcularGananciaPotencial(Cuota cuota);

    //Valida si la apuesta se puede realizar según el saldo del usuario y el monto apostado
    bool validarApuesta(double saldoUsuario, Evento_Deportivo evento);

    //Resuelve la apuesta comparando la selección del usuario con el resultado real
    void resolverApuesta(string resultado);
    void mostrarApuesta();
};

#endif
