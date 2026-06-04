#ifndef SISTEMA_APUESTAS_HPP
#define SISTEMA_APUESTAS_HPP

#include <iostream>
#include <vector>
#include <string>
#include "Usuario.hpp"
#include "Evento_Deportivo.hpp"
#include "Apuesta.hpp"

using namespace std;

class Sistema_Apuestas {
private:
    vector<Usuario*> usuarios;
    vector<Evento_Deportivo> eventos;
    vector<Apuesta> apuestas;

public:
    void registrarUsuario(Usuario* usuario);
    void agregarEvento(Evento_Deportivo evento);

    Evento_Deportivo* buscarEvento(int idEvento);
    Evento_Deportivo* buscarEvento(string equipoLocal, string equipoVisitante);

    void procesarApuesta(Apuesta apuesta);
    void mostrarMenu();
};

#endif