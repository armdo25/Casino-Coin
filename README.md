# Casino-Coin

Casino Coin es un porgrama diseñado totalmente en C++ que busca emular el fervor de las apuestas deportivas a partir de su propio sistema de apuestas. El usuario se registra y puede apostar en distintos eventos a partir de las cuotas que más le convengan. Se busca que el usuario obtenga la experiencia completa de un casino online, por lo que el programa está diseñado para que pueda estructurar apuestas derechas, parlays y/o hasta ambas. El registro de las apuestas permite tener un seguimiento eficaz y dinámico.


# Funcionalidad

<img width="1581" height="988" alt="image" src="https://github.com/user-attachments/assets/9cb69445-bec1-4b9f-b0e0-f6a40c6e0369" />


# Descripción de clases y relaciones del sistema

El proyecto está compuesto por siete clases principales: Sistema_Apuestas, Usuario, Jugador, Administrador, Evento_Deportivo, Cuota y Apuesta. La idea fue mantener una estructura sencilla, pero que sí representara bien cómo funciona un casino de apuestas deportivas: hay usuarios, eventos disponibles, cuotas y apuestas registradas.

La clase Sistema_Apuestas funciona como el centro de control del programa. Desde ahí se registran usuarios, se agregan eventos, se buscan partidos y se guarda el historial general de apuestas. En el código se usan vectores como vector<Usuario*> usuarios, vector<Evento_Deportivo> eventos y vector<Apuesta> apuestas. Un vector es básicamente una lista dinámica, es decir, una estructura donde se pueden ir agregando elementos conforme el programa avanza. Se usaron vectores porque el sistema no trabaja con una sola apuesta o un solo evento, sino con varios usuarios, varios partidos y varias apuestas.

El vector usuarios usa apuntadores de tipo Usuario* porque Usuario es una clase abstracta. Esto significa que no se pueden crear objetos directos de tipo Usuario, ya que en el sistema un usuario real debe ser un Jugador o un Administrador. Gracias a los apuntadores, el sistema puede guardar jugadores y administradores dentro de una misma lista, aprovechando el polimorfismo.

La clase Usuario es la clase base abstracta del proyecto. Contiene los datos comunes que comparten los usuarios, como idUsuario y nombre. Se declaró como abstracta porque no tendría mucho sentido crear un usuario genérico dentro del casino. Para lograr esto se usa el método virtual puro verHistorial(vector<Apuesta>& apuestas) = 0, que obliga a las clases hijas a implementar su propia forma de mostrar historial.

La herencia aparece en las clases Jugador y Administrador, ya que ambas heredan de Usuario. En el código esto se representa con class Jugador : public Usuario y class Administrador : public Usuario. La clase Jugador agrega elementos propios como saldo, depositarSaldo(), retirarSaldo() y realizarApuesta(), porque solo el jugador puede manejar dinero y hacer apuestas. En cambio, Administrador no tiene saldo, pero sí puede consultar el historial general.

La sobreescritura se usa en el método verHistorial(). El método existe desde Usuario, pero cada clase hija lo desarrolla de forma distinta. En Jugador, el historial se filtra con el idUsuario, por lo que solo se muestran las apuestas de ese jugador. En Administrador, el método muestra todas las apuestas registradas. Así, el mismo método tiene comportamientos diferentes dependiendo del tipo de usuario que lo use.

La clase Apuesta representa una apuesta individual. Guarda datos como idApuesta, idUsuario, idEvento, monto, seleccion, gananciaPotencial y estado. El atributo idUsuario permite saber qué jugador hizo la apuesta, mientras que idEvento permite identificar sobre qué partido se apostó. Esto ayuda a que el historial pueda revisarse de forma personal para un jugador o de forma general para el administrador.

La clase Evento_Deportivo representa los partidos o eventos disponibles para apostar. Guarda información como deporte, equipo local, equipo visitante, fecha, resultado y estado. Además, tiene un atributo de tipo Cuota, lo que representa la relación entre el evento y sus momios. En otras palabras, cada evento tiene sus propias cuotas, y esas cuotas se usan para calcular la posible ganancia de una apuesta.

La clase Cuota guarda los momios del evento: cuota local, cuota empate y cuota visitante. Su método principal es calcularGanancia(), que recibe el monto apostado y la selección del jugador para calcular la ganancia potencial. Esto permite separar la lógica de los momios del resto del programa y evitar que Evento_Deportivo o Apuesta tengan demasiadas responsabilidades.

La sobrecarga se aplica en la clase Sistema_Apuestas con el método buscarEvento(). Hay dos versiones: una permite buscar un evento por idEvento, y la otra permite buscarlo por equipoLocal y equipoVisitante. Esto es útil porque a veces se conoce el ID del evento y otras veces es más natural buscarlo por el nombre de los equipos.

Cabe aclarar que el programa cuenta con un menú interactivo que permite al usuario navegar por las funciones principales del casino desde consola. Primero se muestra un menú general con opciones para ingresar o registrar un usuario, buscar eventos disponibles o salir del sistema. Al elegir la opción de usuario, el programa permite seleccionar si se trabajará como Jugador o como Administrador. Si se ingresa como jugador, se despliega un submenú para realizar apuestas o consultar el historial personal. Si se ingresa como administrador, se muestra un submenú para agregar nuevos eventos deportivos o revisar el historial general de apuestas. Además, en el main.cpp se cargaron valores de prueba, como jugadores, un administrador, eventos deportivos, cuotas y apuestas iniciales, con el objetivo de comprobar que el menú funcione correctamente desde el inicio. Gracias a estos datos precargados, se puede probar que el jugador visualice solo su historial, que el administrador consulte el historial general y que los eventos puedan buscarse por ID o por equipos.



# Consideraciones

- Algunos eventos deportivos no pueden terminar en empate, debido a la naturaleza del deporte como el básquetbol en la NBA o Hockey en la NHL, por lo que el sistema podría encontrar dificultades para mostrar las cuotas de manera correcta en el sentido que en atributos de una clase de considera el estado del evento como empate

- El sistema podría hacer un doble registro a partir del ID de usuario si no se especifica un ID único para cada uno.

- El sistema podría no tener límites de apuesta máxima o mínima, lo cual para eventos reales es algo importante a considerar, ya que podría poner en apuros la economía del casino online al ofrecer promociones "seguras" para usuarios sin límite de saldo


