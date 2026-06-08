#include "Cuota.hpp"

Cuota::Cuota(double cuotaLocal, double cuotaEmpate, double cuotaVisitante) {
    this->cuotaLocal = cuotaLocal;
    this->cuotaEmpate = cuotaEmpate;
    this->cuotaVisitante = cuotaVisitante;
}

double Cuota::calcularGanancia(double monto, string seleccion) {
    if (seleccion == "local" || seleccion == "Local") {
        return monto * cuotaLocal;
    }
    else if (seleccion == "empate" || seleccion == "Empate") {
        return monto * cuotaEmpate;
    }
    else if (seleccion == "visitante" || seleccion == "Visitante") {
        return monto * cuotaVisitante;
    }
    else {
        return 0;
    }
}

void Cuota::mostrarCuotas() {
    cout << "Cuota local: " << cuotaLocal << endl;
    cout << "Cuota empate: " << cuotaEmpate << endl;
    cout << "Cuota visitante: " << cuotaVisitante << endl;
}
