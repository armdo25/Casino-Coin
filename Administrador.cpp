#include "Administrador.hpp"

Administrador::Administrador(int idUsuario, string nombre)
    : Usuario(idUsuario, nombre) {
}

//Método sobrescrito de la clase Usuario
void Administrador::verHistorial(vector<Apuesta>& apuestas) {
    cout << "Historial general de apuestas:" << endl;

    //Recorre todas las apuestas recibidas en el vector
    for (int i = 0; i < apuestas.size(); i++) {
        //Muestra la informacion de cada apuesta
        apuestas[i].mostrarApuesta();

        //Imprime una linea para separar visualmente cada apuesta y que se vea como un boleto de apuesta
        cout << "------------------------" << endl;
    }
}
