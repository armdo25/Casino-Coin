# Casino-Coin

Casino Coin es un porgrama diseñado totalmente en C++ que busca emular el fervor de las apuestas deportivas a partir de su propio sistema de apuestas. El usuario se registra y puede apostar en distintos eventos a partir de las cuotas que más le convengan. Se busca que el usuario obtenga la experiencia completa de un casino online, por lo que el programa está diseñado para que pueda estructurar apuestas derechas, parlays y/o hasta ambas. El registro de las apuestas permite tener un seguimiento eficaz y dinámico.


# Funcionalidad

El sistema es simple, ya que está compuesto de 5 clases que tienen relaciones claras entre sí. Básicamente, el programa gestiona las apuestas relizadas por usuarios a partir de la clase madre SistemaApuestas, la cual tiene como hija la clase Apuesta, ya que no se puede relizar sin la gestión pertinente del usuario en su registro o en su saldo. De igual manera, la clase Cuota es hija de la clase EventoDeportivo, por lo mismo que no puede existir un momio sobre un evento/mercado inexistente o clausurado.


# Consideraciones

- Algunos eventos deportivos no pueden terminar en empate, debido a la naturaleza del deporte como el básquetbol en la NBA o Hockey en la NHL, por lo que el sistema podría encontrar dificultades para mostrar las cuotas de manera correcta en el sentido que en atributos de una clase de considera el estado del evento como empate

- El sistema podría hacer un doble registro a partir del ID de usuario si no se especifica un ID único para cada uno

- El sistema podría no tener límites de apuesta máxima o mínima, lo cual para eventos reales es algo importante a considerar, ya que podría poner en apuros la economía del casino online al ofrecer promociones "seguras" para usuarios sin límite de saldo


