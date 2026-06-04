#include "Sistema_Apuestas.hpp"
#include "Jugador.hpp"
#include "Administrador.hpp"

int main() {
    Sistema_Apuestas sistema;

    Jugador* jugador1 = new Jugador(1, "Luis Alberto Iniestra Reyes", 6500);
    Administrador* admin1 = new Administrador(2, "Administrador Turno2 Erick Muñoz", 0);

    sistema.registrarUsuario(jugador1);
    sistema.registrarUsuario(admin1);

    Cuota cuota1(1.89, 4.2, 2.47);

    Evento_Deportivo evento1(
        1,
        "Fútbol",
        "Pumas",
        "Cruz Azul",
        "24/05/2026",
        cuota1
    );

    sistema.agregarEvento(evento1);

    Evento_Deportivo* eventoEncontrado = sistema.buscarEvento(1);

    vector<Apuesta> historialGeneral;

    if (eventoEncontrado != nullptr) {
        Apuesta apuesta1 = jugador1->realizarApuesta(
            579,
            *eventoEncontrado,
            1500,
            "local"
        );

        sistema.procesarApuesta(apuesta1);
        historialGeneral.push_back(apuesta1);
    }

    cout << endl;
    jugador1->verHistorial(historialGeneral);

    cout << endl;
    admin1->verHistorial(historialGeneral);

    delete jugador1;
    delete admin1;

    return 0;
}
