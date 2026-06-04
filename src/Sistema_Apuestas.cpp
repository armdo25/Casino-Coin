#include "Sistema_Apuestas.hpp"

void Sistema_Apuestas::registrarUsuario(Usuario* usuario) {
    usuarios.push_back(usuario);
}

void Sistema_Apuestas::agregarEvento(Evento_Deportivo evento) {
    eventos.push_back(evento);
}

Evento_Deportivo* Sistema_Apuestas::buscarEvento(int idEvento) {
    for (int i = 0; i < eventos.size(); i++) {
        if (eventos[i].getIdEvento() == idEvento) {
            return &eventos[i];
        }
    }

    return nullptr;
}

Evento_Deportivo* Sistema_Apuestas::buscarEvento(string equipoLocal, string equipoVisitante) {
    for (int i = 0; i < eventos.size(); i++) {
        if (eventos[i].getEquipoLocal() == equipoLocal && eventos[i].getEquipoVisitante() == equipoVisitante) {
            return &eventos[i];
        }
    }

    return nullptr;
}

void Sistema_Apuestas::procesarApuesta(Apuesta apuesta) {
    apuestas.push_back(apuesta);
}

void Sistema_Apuestas::mostrarMenu() {
    cout << "===== CASINO COIN =====" << endl;
    cout << "1. Registrar usuario" << endl;
    cout << "2. Agregar evento" << endl;
    cout << "3. Buscar evento" << endl;
    cout << "4. Realizar apuesta" << endl;
    cout << "5. Ver historial" << endl;
    cout << "6. Salir" << endl;
}
