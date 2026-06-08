#include "Administrador.hpp"

Administrador::Administrador(int idUsuario, string nombre, double saldo)
    : Usuario(idUsuario, nombre, saldo) {
}

void Administrador::verHistorial(vector<Apuesta>& apuestas) {
    cout << "Historial general de apuestas:" << endl;

    for (int i = 0; i < apuestas.size(); i++) {
        apuestas[i].mostrarApuesta();
        cout << "------------------------" << endl;
    }
}