#include "Jugador.hpp"

Jugador::Jugador(int idUsuario, string nombre, double saldo)
    : Usuario(idUsuario, nombre, saldo) {
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

void Jugador::verHistorial(vector<Apuesta>& apuestas) {
    cout << "Historial de apuestas del jugador " << nombre << ":" << endl;

    for (int i = 0; i < apuestas.size(); i++) {
        if (apuestas[i].getIdUsuario() == idUsuario) {
            apuestas[i].mostrarApuesta();
            cout << "------------------------" << endl;
        }
    }
}