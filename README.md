# Casino-Coin

Casino Coin es un porgrama diseñado totalmente en C++ que busca emular el fervor de las apuestas deportivas a partir de su propio sistema de apuestas. El usuario se registra y puede apostar en distintos eventos a partir de las cuotas que más le convengan. Se busca que el usuario obtenga la experiencia completa de un casino online, por lo que el programa está diseñado para que pueda estructurar apuestas derechas, parlays y/o hasta ambas. El registro de las apuestas permite tener un seguimiento eficaz y dinámico.


# Funcionalidad

<img width="1126" height="710" alt="image" src="https://github.com/user-attachments/assets/2663c548-ff56-463c-8557-bde2c74cecc0" />

El sistema es simple, ya que está compuesto de 7 clases que tienen relaciones claras entre sí. Básicamente, el programa gestiona las apuestas relizadas por usuarios a partir de la clase  SistemaApuestas. Desde ahí se gestiona el menú principal, los vectores o listas recolectados de los usuarios, los eventos deportivos y de las apuestas, entre otras cosas. La clase EventoDeportivo gestiona los eventos deportivos y sus momios, por lo cual se creó otra clase llamada Cuota la cual se integra para facilitar la exposición y manejo de cuotas por cada evento (de ahí que sea una relación de composición).

Por otro lado, la clase Apuesta gestiona la apuesta que el usuario tipo Jugador desee hacer. Ahí se calcula su ganancia potencial, la selección que se desee, el estado de la apuesta,etc. Un punto clave a tener aquí es que se agregó un atributo que antes no se tenía contemplado hasta hace poco, el cual es el atributo idUsuario. Debido a que la clase Usuario se define como una clase abstracta para denegar u otrogar permisos, los cuales se bifurcan en aquellos correspondientes al Jugador y Administrador, el idUsuario integrado en la clase Apuesta agiliza la corroboración del tipo de usuario mediante el ID, de tal manera que el Administrador puede visualizar el historial total de apuestas de uno o más usuarios, mientras que el Jugador sólo puede visualizar el suyo.



# Consideraciones

- Algunos eventos deportivos no pueden terminar en empate, debido a la naturaleza del deporte como el básquetbol en la NBA o Hockey en la NHL, por lo que el sistema podría encontrar dificultades para mostrar las cuotas de manera correcta en el sentido que en atributos de una clase de considera el estado del evento como empate

- El sistema podría hacer un doble registro a partir del ID de usuario si no se especifica un ID único para cada uno.

- El sistema podría no tener límites de apuesta máxima o mínima, lo cual para eventos reales es algo importante a considerar, ya que podría poner en apuros la economía del casino online al ofrecer promociones "seguras" para usuarios sin límite de saldo


