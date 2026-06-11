/*
    Este es el archivo principal del proyecto de sistema de apuestas deportivas.
    Aquí se crean algunos datos de prueba para mostrar el funcionamiento del sistema
    y luego se inicia el menú interactivo para que el usuario pueda probarlo por sí mismo.
*/  

#include "Sistema_Apuestas.hpp"
#include "Jugador.hpp"
#include "Administrador.hpp"

int main() {
    //Creo el objeto principal del sistema de apuestas
    Sistema_Apuestas sistema;

    //Apuntadores para crear objetos de tipo Jugador y Administrador porque Usuario es una clase abstracta y se aprovecha el polimorfismo para registrar ambos tipos de usuarios dentro del sistema.
    Jugador* jugador1 = new Jugador(1, "Luis Alberto Iniestra Reyes", 6500);
    Jugador* jugador2 = new Jugador(3, "Alejandro Sarrelangue Gonzalez", 8500);

    //El administrador ya no recibe saldo porque el saldo pertenece solamente a Jugador
    Administrador* admin1 = new Administrador(2, "Administrador Turno2 Erick Muñoz");

    sistema.registrarUsuario(jugador1);
    sistema.registrarUsuario(jugador2);
    sistema.registrarUsuario(admin1);

    Cuota cuota1(1.89, 4.2, 2.47);

    Evento_Deportivo evento1(
        1,
        "Futbol",
        "Pumas",
        "Cruz Azul",
        "24/05/2026",
        cuota1
    );

    sistema.agregarEvento(evento1);


    Cuota cuota2(1.75, 3.10, 4.60);

    Evento_Deportivo evento2(
        2,
        "Futbol",
        "Mexico",
        "Sudafrica",
        "11/07/26",
        cuota2
    );
  
    sistema.agregarEvento(evento2);

    Evento_Deportivo* eventoEncontrado = sistema.buscarEvento(1);

    //Verifico que el primer evento exista antes de apostar
    if (eventoEncontrado != nullptr) {
      
        Apuesta apuesta1 = jugador1->realizarApuesta(
            579,
            *eventoEncontrado,
            1500,
            "local"
        );

        sistema.procesarApuesta(apuesta1);

  
        Apuesta apuesta2 = jugador2->realizarApuesta(
            580,
            *eventoEncontrado,
            1200,
            "visitante"
        );

        //Guardo la segunda apuesta en el historial general del sistema
        sistema.procesarApuesta(apuesta2);
    }

    Evento_Deportivo* eventoEncontrado2 = sistema.buscarEvento(2);

    //Verifico que el segundo evento exista antes de apostar
    if (eventoEncontrado2 != nullptr) {
      
        Apuesta apuesta3 = jugador2->realizarApuesta(
            581,
            *eventoEncontrado2,
            2000,
            "local"
        );


        sistema.procesarApuesta(apuesta3);
    }

    cout << endl;
    cout << "Datos de prueba cargados correctamente." << endl;


    cout << "Puedes ingresar como:" << endl;
    cout << "Jugador Luis -> ID 1" << endl;
    cout << "Administrador -> ID 2" << endl;
    cout << "Jugador Alejandro -> ID 3" << endl;

  
    sistema.mostrarMenu();

    //No se usa delete aquí porque Sistema_Apuestas libera los usuarios en su destructor
    return 0;
}
