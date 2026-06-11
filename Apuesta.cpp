#include "Apuesta.hpp"

Apuesta::Apuesta(int idApuesta, int idUsuario, int idEvento, double monto, string seleccion, double gananciaPotencial) {

    this->idApuesta = idApuesta;
    this->idUsuario = idUsuario;
    this->idEvento = idEvento;
    this->monto = monto;
    this->seleccion = seleccion;
    this->gananciaPotencial = gananciaPotencial;
    this->estado = "Pendiente";
}

int Apuesta::getIdUsuario() {
    return idUsuario;
}

int Apuesta::getIdEvento() {
    return idEvento;
}

double Apuesta::calcularGananciaPotencial(Cuota cuota) {
    return cuota.calcularGanancia(monto, seleccion);
}

bool Apuesta::validarApuesta(double saldoUsuario, Evento_Deportivo evento) {
    if (monto > 0 && saldoUsuario >= monto) {
        return true;
    }
    else {
        return false;
    }
}

void Apuesta::resolverApuesta(string resultado) {
    if (seleccion == resultado) {
        estado = "Ganada";
    }
    else {
        estado = "Perdida";
    }
}

void Apuesta::mostrarApuesta() {
    cout << "ID apuesta: " << idApuesta << endl;
    cout << "ID usuario: " << idUsuario << endl;
    cout << "ID evento: " << idEvento << endl;
    cout << "Monto: $" << monto << endl;
    cout << "Seleccion: " << seleccion << endl;
    cout << "Ganancia potencial: $" << gananciaPotencial << endl;
    cout << "Estado: " << estado << endl;
}