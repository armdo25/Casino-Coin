#ifndef EVENTO_DEPORTIVO_HPP
#define EVENTO_DEPORTIVO_HPP

#include <iostream>
#include <string>
#include "Cuota.hpp"

using namespace std;

class EventoDeportivo {
private:
    int idEvento;
    string deporte;
    string equipoLocal;
    string equipoVisitante;
    string fecha;
    string resultado;
    string estado;
    Cuota cuota;

public:
    EventoDeportivo(int idEvento, string deporte, string equipoLocal, string equipoVisitante, string fecha, Cuota cuota);

    int getIdEvento();
    string getEquipoLocal();
    string getEquipoVisitante();
    Cuota getCuota();

    void mostrarEvento();
    void actualizarResultado(string resultado);
    void cerrarEvento();
};

#endif
