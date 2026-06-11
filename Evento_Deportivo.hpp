/*
    La clase Evento_Deportivo representa un evento o partido deportivo sobre el cual los jugadores pueden realizar apuestas.
    Cada evento tiene un ID único, un tipo de deporte, nombres de los equipos local y visitante, una fecha, un resultado, un estado (abierto o cerrado) y una cuota asociada que determina las ganancias potenciales de las apuestas realizadas sobre ese evento.
    Esta clase incluye métodos para mostrar la información del evento, actualizar su resultado y cerrar el evento para que ya no acepte nuevas apuestas.
    Se relaciona con la clase Apuesta, ya que cada apuesta está vinculada a un evento deportivo específico, y con la clase Cuota, ya que cada evento tiene una cuota que se utiliza para calcular las ganancias potenciales de las apuestas.
*/  
#ifndef EVENTO_DEPORTIVO_HPP
#define EVENTO_DEPORTIVO_HPP

#include <iostream>
#include <string>
#include "Cuota.hpp"

using namespace std;

class Evento_Deportivo {
private:

    int idEvento;


    string deporte;
    string equipoLocal;
    string equipoVisitante;
    string fecha;

    //Resultado del evento que al inicio queda como Pendiente
    string resultado;

    //Estado del evento que puede estar Abierto o Cerrado
    string estado;

    //Objeto de tipo Cuota que representa las cuotas local, empate y visitante del evento
    Cuota cuota;

public:
    //Constructor de Evento_Deportivo que recibe los datos principales del evento y su cuota asociada
    Evento_Deportivo(int idEvento, string deporte, string equipoLocal, string equipoVisitante, string fecha, Cuota cuota);


    int getIdEvento();
    string getEquipoLocal();
    string getEquipoVisitante();
    Cuota getCuota();
    void mostrarEvento();

    //la diferencia de actualizarResultado y cerrarEvento es que actualizarResultado solo cambia el resultado del evento pero sigue permitiendo apostar, mientras que cerrarEvento cambia el estado a Cerrado para que ya no se puedan realizar apuestas sobre ese evento.
    void actualizarResultado(string resultado);
    void cerrarEvento();
};

#endif
