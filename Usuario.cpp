#include "Usuario.hpp"

Usuario::Usuario(int idUsuario, string nombre) {
    //Uso this para diferenciar el atributo idUsuario del parametro idUsuario
    this->idUsuario = idUsuario;
    this->nombre = nombre;
}

//Destructor de Usuario
//Se deja vacio porque Usuario no reserva memoria directamente pero debe ser virtual para que los objetos hijos se destruyan correctamente
Usuario::~Usuario() {
}

int Usuario::getIdUsuario() {
    return idUsuario;
}

string Usuario::getNombre() {
    return nombre;
}
