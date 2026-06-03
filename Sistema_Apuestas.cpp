#ifndef SISTEMA_APUESTAS_HPP
#define SISTEMA_APUESTAS_HPP

#include <iostream>
#include <vector>
#include <string>
#include "Usuario.hpp"
#include "EventoDeportivo.hpp"
#include "Apuesta.hpp"

using namespace std;

class SistemaApuestas {
private:
    vector<Usuario*> usuarios;
    vector<EventoDeportivo> eventos;
    vector<Apuesta> apuestas;

public:
    void registrarUsuario(Usuario* usuario);
    void agregarEvento(EventoDeportivo evento);

    EventoDeportivo* buscarEvento(int idEvento);
    EventoDeportivo* buscarEvento(string equipoLocal, string equipoVisitante);

    void procesarApuesta(Apuesta apuesta);
    void mostrarMenu();
};

#endif