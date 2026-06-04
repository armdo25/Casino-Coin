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
