#ifndef CASINO_COIN_HPP
#define CASINO_COIN_HPP

//incluimos las librerías de siempre mas vector para poder manejar listas de eventos, apuestas y usuarios
#include <iostream>
#include <string>
#include <vector>

using namespace std;


//clase cuota para manejar los momios
class Cuota {
private:
    double cuotaLocal;
    double cuotaEmpate;
    double cuotaVisitante;

public:
    Cuota(double cuotaLocal, double cuotaEmpate, double cuotaVisitante);

    double calcularGanancia(double monto, string seleccion);
    void mostrarCuotas();
};

//clase evento deportivo para crear y manejar los eventos
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


//clase apuesta para gestionar la apuesta deportiva, además de incluir el int idUsuario para relacionar la apuesta con el usuario que la realizó (importante para el método verHistorial y su override en las clases Usuario, Administrador y Jugador)
class Apuesta {
private:
    int idApuesta;
    int idUsuario;
    int idEvento;
    double monto;
    string seleccion;
    double gananciaPotencial;
    string estado;

public:
    Apuesta(int idApuesta, int idUsuario, int idEvento, double monto, string seleccion, double gananciaPotencial);

    int getIdUsuario();
    int getIdEvento();

    double calcularGananciaPotencial(Cuota cuota);
    bool validarApuesta(double saldoUsuario, EventoDeportivo evento);
    void resolverApuesta(string resultado);
    void mostrarApuesta();
};

//la clase Usuario es abstracta, ya que se busca que solo se puedan crear objetos de tipo Administrador o Jugador, y no de tipo Usuario directamente (evita fallas de seguridad). Esto se logra al declarar el método verHistorial como virtual puro (= 0)
class Usuario {
protected:
    int idUsuario;
    string nombre;
    double saldo;

public:
    Usuario(int idUsuario, string nombre, double saldo);
    virtual ~Usuario();

    int getIdUsuario();
    string getNombre();
    double getSaldo();

    void depositarSaldo(double monto);
    bool retirarSaldo(double monto);

    virtual void verHistorial(vector<Apuesta>& apuestas) = 0;
};


//la clase Administrador hereda de Usuario, donde desarrolla su propia implementación del método verHistorial, ya que puede ver el historial completo de todas las apuestas y/o usuarios
class Administrador : public Usuario {
public:
    Administrador(int idUsuario, string nombre, double saldo);

    void verHistorial(vector<Apuesta>& apuestas) override;
};

//la clase Jugador hereda de Usuario, donde desarrolla su propia implementación del método verHistorial, ya que solo puede ver el historial de sus propias apuestas (relacionadas por el idUsuario que es obligatorio incluir en la clase Apuesta para rastrearlas)
class Jugador : public Usuario {
public:
    Jugador(int idUsuario, string nombre, double saldo);

    Apuesta realizarApuesta(int idApuesta, EventoDeportivo evento, double monto, string seleccion);
    void verHistorial(vector<Apuesta>& apuestas) override;
};


//la clase SistemaApuestas es la encargada de gestionar todo, incluyendo el registro de usuarios, la creación de eventos deportivos, la gestión de apuestas y la interacción con los usuarios a través de un menú principal
class SistemaApuestas {
private:
    vector<Usuario*> usuarios;
    vector<EventoDeportivo> eventos;
    vector<Apuesta> apuestas;

public:
    void registrarUsuario(Usuario* usuario);
    void agregarEvento(EventoDeportivo evento);

    EventoDeportivo* buscarEvento(int idEvento);
    EventoDeportivo* buscarEvento(string equipoLocal, string equipoVisitante);

    void procesarApuesta(Apuesta apuesta);
    void mostrarMenu();
};

#endif
