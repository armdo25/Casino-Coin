/*
    La clase Sistema_Apuestas es el núcleo del proyecto, ya que es la encargada de gestionar los usuarios, eventos deportivos y apuestas. 
    En este archivo se definen los métodos para registrar usuarios, agregar eventos, buscar eventos, procesar apuestas y mostrar el menú interactivo. 
    El sistema utiliza vectores para almacenar la información de manera dinámica y aprovecha el polimorfismo para manejar tanto jugadores como administradores a través de apuntadores a la clase abstracta Usuario. 
*/  


#ifndef SISTEMA_APUESTAS_HPP
#define SISTEMA_APUESTAS_HPP

#include <iostream>

//Incluyo vector porque el sistema guarda listas de usuarios, eventos y apuestas
#include <vector>
#include <string>

//Incluyo Usuario porque el sistema guarda usuarios mediante apuntadores a la clase abstracta
#include "Usuario.hpp"
#include "Evento_Deportivo.hpp"
#include "Apuesta.hpp"

using namespace std;

class Sistema_Apuestas {
private:
    //Vector de apuntadores a Usuario
    //Se usa Usuario* porque Usuario es abstracta y aquí se pueden guardar Jugador y Administrador
    vector<Usuario*> usuarios;

    //Vector donde se guardan todos los eventos deportivos registrados en el sistema
    vector<Evento_Deportivo> eventos;

    //Vector donde se guarda el historial general de apuestas del sistema
    vector<Apuesta> apuestas;

public:
    Sistema_Apuestas();
    ~Sistema_Apuestas();

    //Registra un usuario dentro del vector de usuarios
    //Puede recibir un Jugador* o Administrador* gracias al polimorfismo
    void registrarUsuario(Usuario* usuario);


    void agregarEvento(Evento_Deportivo evento);

    //El método buscarEvento está sobrecargado para permitir buscar por ID o por equipos
    Evento_Deportivo* buscarEvento(int idEvento);
    Evento_Deportivo* buscarEvento(string equipoLocal, string equipoVisitante);


    void procesarApuesta(Apuesta apuesta);

    //Regresa el vector de apuestas del sistema por referencia lo cual permite pasarlo a verHistorial() sin crear otro vector duplicado
    vector<Apuesta>& getApuestas();

    void mostrarMenu();
};

#endif
