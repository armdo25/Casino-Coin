/*
    Usuario es la clase base abstracta que representa a un usuario del sistema de apuestas, y mediante sobreescritura del metodo virtual verHistorial() permite
    que Jugador visualice solamente su historial personal de apuestas, mientras que el Administrador 
    puede visualizar el historial general de apuestas del sistema.
*/  

#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <iostream>
#include <string>

//Incluyo vector porque el metodo verHistorial recibe un vector de apuestas
#include <vector>
#include "Apuesta.hpp"

using namespace std;


class Usuario {
protected:
    //Se deja protected para que las clases hijas puedan acceder a este dato
    int idUsuario;
    string nombre;

public:

    Usuario(int idUsuario, string nombre);

    //Destructor virtual
    //Es importante porque usamos apuntadores de tipo Usuario*
    virtual ~Usuario();


    int getIdUsuario();
    string getNombre();

    //Metodo virtual pdonde Jugador y Administrador deben implementar su propia version de verHistorial
    virtual void verHistorial(vector<Apuesta>& apuestas) = 0;
};

#endif
