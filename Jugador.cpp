#include "Jugador.hpp"

Jugador::Jugador(int idUsuario, string nombre, double saldo)
    : Usuario(idUsuario, nombre) {

    //Guardo el saldo recibido en el atributo propio de Jugador
    this->saldo = saldo;
}

double Jugador::getSaldo() {
    return saldo;
}

void Jugador::depositarSaldo(double monto) {
    if (monto > 0) {
        saldo = saldo + monto;
    }
}

bool Jugador::retirarSaldo(double monto) {
    if (monto > 0 && saldo >= monto) {
        saldo = saldo - monto;
        return true;
    }
    else {
        return false;
    }
}


Apuesta Jugador::realizarApuesta(int idApuesta, Evento_Deportivo evento, double monto, string seleccion) {
    double gananciaPotencial = evento.getCuota().calcularGanancia(monto, seleccion);

    if (retirarSaldo(monto)) {
        return Apuesta(idApuesta, idUsuario, evento.getIdEvento(), monto, seleccion, gananciaPotencial);
    }
    else {
        cout << "Saldo insuficiente para realizar la apuesta." << endl;
        return Apuesta(idApuesta, idUsuario, evento.getIdEvento(), 0, seleccion, 0);
    }
}

//Se sobrescribe el método abstracto de Usuario
void Jugador::verHistorial(vector<Apuesta>& apuestas) {
    cout << "Historial de apuestas del jugador " << nombre << ":" << endl;

    //Recorre todas las apuestas recibidas en el vector
    for (int i = 0; i < apuestas.size(); i++) {
        //Compara el idUsuario de la apuesta con el idUsuario del jugador actual
        if (apuestas[i].getIdUsuario() == idUsuario) {
            //Si coinciden, significa que la apuesta pertenece a este jugador
            apuestas[i].mostrarApuesta();

            //Imprime una línea para separar las apuestas y simular un boleto de apuesta
            cout << "------------------------" << endl;
        }
    }
}
