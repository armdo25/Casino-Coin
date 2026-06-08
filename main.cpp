#include "Sistema_Apuestas.hpp"
#include "Jugador.hpp"
#include "Administrador.hpp"

int main() {
    Sistema_Apuestas sistema;

    Jugador* jugador1 = new Jugador(1, "Luis Alberto Iniestra Reyes", 6500);
    Jugador* jugador2 = new Jugador(3, "Alejandro Sarrelangue González", 8500);

    Administrador* admin1 = new Administrador(2, "Administrador Turno2 Erick Muñoz", 0);

    sistema.registrarUsuario(jugador1);
    sistema.registrarUsuario(jugador2);
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

    Cuota cuota2(1.75, 3.10, 4.60);

    Evento_Deportivo evento2(
        2,
        "Fútbol",
        "México",
        "Sudáfrica",
        "11/07/26",
        cuota2
    );

    sistema.agregarEvento(evento2);

    vector<Apuesta> historialGeneral;

    Evento_Deportivo* eventoEncontrado = sistema.buscarEvento(1);

    if (eventoEncontrado != nullptr) {
        Apuesta apuesta1 = jugador1->realizarApuesta(
            579,
            *eventoEncontrado,
            1500,
            "local"
        );

        sistema.procesarApuesta(apuesta1);
        historialGeneral.push_back(apuesta1);

        Apuesta apuesta2 = jugador2->realizarApuesta(
            580,
            *eventoEncontrado,
            1200,
            "visitante"
        );

        //revisar este doble proceso de apuesta, ya que se procesa en el main y también en el realizarApuesta, revisar si es necesario o eliminarlo
        sistema.procesarApuesta(apuesta2);
        historialGeneral.push_back(apuesta2);
    }

    Evento_Deportivo* eventoEncontrado2 = sistema.buscarEvento(2);

    if (eventoEncontrado2 != nullptr) {
        Apuesta apuesta3 = jugador2->realizarApuesta(
            581,
            *eventoEncontrado2,
            2000,
            "local"
        );

        sistema.procesarApuesta(apuesta3);
        historialGeneral.push_back(apuesta3);
    }

    cout << endl;
    jugador1->verHistorial(historialGeneral);

    cout << endl;
    jugador2->verHistorial(historialGeneral);

    cout << endl;
    admin1->verHistorial(historialGeneral);

    delete jugador1;
    delete jugador2;
    delete admin1;

    return 0;
}
