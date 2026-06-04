#include "Evento_Deportivo.hpp"

Evento_Deportivo::Evento_Deportivo(int idEvento, string deporte, string equipoLocal, string equipoVisitante, string fecha, Cuota cuota) 
    : cuota(cuota) {
    this->idEvento = idEvento;
    this->deporte = deporte;
    this->equipoLocal = equipoLocal;
    this->equipoVisitante = equipoVisitante;
    this->fecha = fecha;
    this->resultado = "Pendiente";
    this->estado = "Abierto";
}

int Evento_Deportivo::getIdEvento() {
    return idEvento;
}

string Evento_Deportivo::getEquipoLocal() {
    return equipoLocal;
}

string Evento_Deportivo::getEquipoVisitante() {
    return equipoVisitante;
}

Cuota Evento_Deportivo::getCuota() {
    return cuota;
}

void Evento_Deportivo::mostrarEvento() {
    cout << "ID evento: " << idEvento << endl;
    cout << "Deporte: " << deporte << endl;
    cout << "Local: " << equipoLocal << endl;
    cout << "Visitante: " << equipoVisitante << endl;
    cout << "Fecha: " << fecha << endl;
    cout << "Resultado: " << resultado << endl;
    cout << "Estado: " << estado << endl;
    cuota.mostrarCuotas();
}

void Evento_Deportivo::actualizarResultado(string resultado) {
    this->resultado = resultado;
}

void Evento_Deportivo::cerrarEvento() {
    estado = "Cerrado";
}
