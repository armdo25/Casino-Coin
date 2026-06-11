#include "Sistema_Apuestas.hpp"
#include "Jugador.hpp"
#include "Administrador.hpp"
#include "Cuota.hpp"


Sistema_Apuestas::Sistema_Apuestas() {
}
Sistema_Apuestas::~Sistema_Apuestas() {
    for (int i = 0; i < usuarios.size(); i++) {
        delete usuarios[i];
    }
}
void Sistema_Apuestas::registrarUsuario(Usuario* usuario) {
    usuarios.push_back(usuario);
}

void Sistema_Apuestas::agregarEvento(Evento_Deportivo evento) {
    eventos.push_back(evento);
}

Evento_Deportivo* Sistema_Apuestas::buscarEvento(int idEvento) {
    for (int i = 0; i < eventos.size(); i++) {
        if (eventos[i].getIdEvento() == idEvento) {
            return &eventos[i];
        }
    }

    return nullptr;
}

Evento_Deportivo* Sistema_Apuestas::buscarEvento(string equipoLocal, string equipoVisitante) {
    for (int i = 0; i < eventos.size(); i++) {
        if (eventos[i].getEquipoLocal() == equipoLocal &&
            eventos[i].getEquipoVisitante() == equipoVisitante) {
            return &eventos[i];
        }
    }

    return nullptr;
}

void Sistema_Apuestas::procesarApuesta(Apuesta apuesta) {
    apuestas.push_back(apuesta);
}

vector<Apuesta>& Sistema_Apuestas::getApuestas() {
    return apuestas;
}

void Sistema_Apuestas::mostrarMenu() {
    int opcionPrincipal = 0;

    while (opcionPrincipal != 3) {
        cout << endl;
        cout << "===== CASINO COIN =====" << endl;
        cout << "1. Registrar / ingresar usuario" << endl;
        cout << "2. Buscar evento" << endl;
        cout << "3. Salir" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcionPrincipal;

        if (opcionPrincipal == 1) {
            int tipoUsuario;
            int idUsuario;

            cout << endl;
            cout << "Tipo de usuario:" << endl;
            cout << "1. Jugador" << endl;
            cout << "2. Administrador" << endl;
            cout << "Selecciona una opcion: ";
            cin >> tipoUsuario;

            cout << "Ingresa el ID del usuario: ";
            cin >> idUsuario;

            Usuario* usuarioEncontrado = nullptr;

            //Busco si el usuario ya existe dentro del sistema.
            for (int i = 0; i < usuarios.size(); i++) {
                if (usuarios[i]->getIdUsuario() == idUsuario) {
                    usuarioEncontrado = usuarios[i];
                }
            }

            if (tipoUsuario == 1) {
                Jugador* jugadorActivo = nullptr;

                if (usuarioEncontrado != nullptr) {
                    jugadorActivo = static_cast<Jugador*>(usuarioEncontrado);
                }
                else {
                    string nombre;
                    double saldo;

                    cout << "Nombre del jugador sin espacios: ";
                    cin >> nombre;

                    cout << "Saldo inicial: ";
                    cin >> saldo;

                    jugadorActivo = new Jugador(idUsuario, nombre, saldo);
                    registrarUsuario(jugadorActivo);

                    cout << "Jugador registrado correctamente." << endl;
                }

                int opcionJugador = 0;

                while (opcionJugador != 3) {
                    cout << endl;
                    cout << "===== MENU JUGADOR =====" << endl;
                    cout << "1. Realizar apuesta" << endl;
                    cout << "2. Ver historial personal" << endl;
                    cout << "3. Regresar al menu principal" << endl;
                    cout << "Selecciona una opcion: ";
                    cin >> opcionJugador;

                    if (opcionJugador == 1) {
                        int idEvento;
                        int idApuesta;
                        double monto;
                        string seleccion;

                        cout << "ID del evento: ";
                        cin >> idEvento;

                        Evento_Deportivo* eventoEncontrado = buscarEvento(idEvento);

                        if (eventoEncontrado != nullptr) {
                            cout << "ID de la apuesta: ";
                            cin >> idApuesta;

                            cout << "Monto a apostar: ";
                            cin >> monto;

                            cout << "Seleccion local / empate / visitante: ";
                            cin >> seleccion;

                            Apuesta nuevaApuesta = jugadorActivo->realizarApuesta(
                                idApuesta,
                                *eventoEncontrado,
                                monto,
                                seleccion
                            );

                            procesarApuesta(nuevaApuesta);

                            cout << "Apuesta registrada correctamente." << endl;
                        }
                        else {
                            cout << "No se encontro el evento." << endl;
                        }
                    }
                    else if (opcionJugador == 2) {
                        jugadorActivo->verHistorial(getApuestas());
                    }
                    else if (opcionJugador == 3) {
                        cout << "Regresando al menu principal..." << endl;
                    }
                    else {
                        cout << "Opcion no valida." << endl;
                    }
                }
            }
            else if (tipoUsuario == 2) {
                Administrador* adminActivo = nullptr;

                if (usuarioEncontrado != nullptr) {
                    adminActivo = static_cast<Administrador*>(usuarioEncontrado);
                }
                else {
                    string nombre;

                    cout << "Nombre del administrador sin espacios: ";
                    cin >> nombre;

                    adminActivo = new Administrador(idUsuario, nombre);
                    registrarUsuario(adminActivo);

                    cout << "Administrador registrado correctamente." << endl;
                }

                int opcionAdmin = 0;

                while (opcionAdmin != 3) {
                    cout << endl;
                    cout << "===== MENU ADMINISTRADOR =====" << endl;
                    cout << "1. Agregar evento" << endl;
                    cout << "2. Ver historial general" << endl;
                    cout << "3. Regresar al menu principal" << endl;
                    cout << "Selecciona una opcion: ";
                    cin >> opcionAdmin;

                    if (opcionAdmin == 1) {
                        int idEvento;
                        string deporte;
                        string equipoLocal;
                        string equipoVisitante;
                        string fecha;
                        double cuotaLocal;
                        double cuotaEmpate;
                        double cuotaVisitante;

                        cout << "ID del evento: ";
                        cin >> idEvento;

                        cout << "Deporte sin espacios: ";
                        cin >> deporte;

                        cout << "Equipo local sin espacios: ";
                        cin >> equipoLocal;

                        cout << "Equipo visitante sin espacios: ";
                        cin >> equipoVisitante;

                        cout << "Fecha sin espacios: ";
                        cin >> fecha;

                        cout << "Cuota local: ";
                        cin >> cuotaLocal;

                        cout << "Cuota empate: ";
                        cin >> cuotaEmpate;

                        cout << "Cuota visitante: ";
                        cin >> cuotaVisitante;

                        Cuota nuevaCuota(cuotaLocal, cuotaEmpate, cuotaVisitante);

                        Evento_Deportivo nuevoEvento(
                            idEvento,
                            deporte,
                            equipoLocal,
                            equipoVisitante,
                            fecha,
                            nuevaCuota
                        );

                        agregarEvento(nuevoEvento);

                        cout << "Evento agregado correctamente." << endl;
                    }
                    else if (opcionAdmin == 2) {
                        adminActivo->verHistorial(getApuestas());
                    }
                    else if (opcionAdmin == 3) {
                        cout << "Regresando al menu principal..." << endl;
                    }
                    else {
                        cout << "Opcion no valida." << endl;
                    }
                }
            }
            else {
                cout << "Tipo de usuario no valido." << endl;
            }
        }
        else if (opcionPrincipal == 2) {
            int tipoBusqueda;

            cout << endl;
            cout << "Buscar evento por:" << endl;
            cout << "1. ID" << endl;
            cout << "2. Equipos" << endl;
            cout << "Selecciona una opcion: ";
            cin >> tipoBusqueda;

            if (tipoBusqueda == 1) {
                int idEvento;

                cout << "ID del evento: ";
                cin >> idEvento;

                Evento_Deportivo* evento = buscarEvento(idEvento);

                if (evento != nullptr) {
                    evento->mostrarEvento();
                }
                else {
                    cout << "No se encontro el evento." << endl;
                }
            }
            else if (tipoBusqueda == 2) {
                string equipoLocal;
                string equipoVisitante;

                cout << "Equipo local sin espacios: ";
                cin >> equipoLocal;

                cout << "Equipo visitante sin espacios: ";
                cin >> equipoVisitante;

                Evento_Deportivo* evento = buscarEvento(equipoLocal, equipoVisitante);

                if (evento != nullptr) {
                    evento->mostrarEvento();
                }
                else {
                    cout << "No se encontro el evento." << endl;
                }
            }
            else {
                cout << "Opcion no valida." << endl;
            }
        }
        else if (opcionPrincipal == 3) {
            cout << "Saliendo de Casino Coin..." << endl;
        }
        else {
            cout << "Opcion no valida." << endl;
        }
    }
}
