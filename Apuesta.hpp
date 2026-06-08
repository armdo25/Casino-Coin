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
    Apuesta(int idApuesta, int idUsuario, int idEvento, double monto, string seleccion, double gananciaPotencial);

    int getIdUsuario();
    int getIdEvento();

    double calcularGananciaPotencial(Cuota cuota);
    bool validarApuesta(double saldoUsuario, Evento_Deportivo evento);
    void resolverApuesta(string resultado);
    void mostrarApuesta();
};

#endif