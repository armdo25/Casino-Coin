/*
   La clase Administrador representa a un usuario con privilegios especiales en el sistema de apuestas deportivas.
   A diferencia de un Jugador, el Administrador no tiene saldo ni puede realizar apuestas, pero tiene la capacidad de visualizar el historial general de apuestas realizadas por todos los usuarios en el sistema.
   Esta clase hereda de Usuario y sobrescribe el método virtual verHistorial() para mostrar toda la información de las apuestas en lugar de solo las apuestas de un jugador específico.
*/  
#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include "Usuario.hpp"

//Declaro la clase Administrador como clase hija de Usuario
class Administrador : public Usuario {
public:
    //Constructor de Administrador que ecibe solamente idUsuario y nombre porque el administrador no maneja saldo
    Administrador(int idUsuario, string nombre);

    //Se sobrescribe el metodo abstracto verHistorial() heredado de Usuario que sirve para mostrar el historial general de apuestas
    void verHistorial(vector<Apuesta>& apuestas) override;
};

#endif
