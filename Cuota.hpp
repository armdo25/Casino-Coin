/*
    La clase Cuota representa las cuotas de apuesta de un evento deportivo. Cada evento tiene una cuota para el equipo local, una cuota para el empate y una cuota para el equipo visitante.
    La clase incluye un método para calcular la ganancia potencial de una apuesta dependiendo del monto apostado y la selección del jugador, así como un método para mostrar las cuotas en consola. 
*/  

#ifndef CUOTA_HPP
#define CUOTA_HPP

#include <iostream>
#include <string>

using namespace std;


class Cuota {
private:
    double cuotaLocal;
    double cuotaEmpate;
    double cuotaVisitante;

public:
    Cuota(double cuotaLocal, double cuotaEmpate, double cuotaVisitante);
    double calcularGanancia(double monto, string seleccion);
    void mostrarCuotas();
};

#endif
