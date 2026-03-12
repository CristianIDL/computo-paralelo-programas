%%PID%%

# Qué es PID

> PID son siglas de Process ID.


De esta forma 

_UN compañero preguntó si se podría hacer en C++, el profesor dijo que técnicamente sería posible pero que_

# getpid()

> Es una llamada al sistema que le pide el identificador. 

`getpid()` no requiere un parámetro por que al momento de hacer una interrupción al sistema desde el Proceso A

## Por qué primero muestra al Padre y luego al Hijo?

> Esto tiene algo que ver con el [[Kernel]], este le dice que ejeccute al padre primero. Es como ir con un gurú en tlatemalco o así. Usando un algoritmo interno verificador. La elección depende de las circunstancias alrededor del proceso.

_El profesor comenta que no va a adentrarse porque laa clase no es de [[Sistemas Operativos]]_


# getppid()

> `Get Parent Rroces Identification`

_A un compañero y a mi nos salió mal uno de los padres, a lo que el profesor muy serio comentó:_

> "A veces `gcc` está loco."

Tras un rato de meditar el profe llegó a una conclusión.

> Seguramente en algún momento les llegue a pasar a todos. Usando `sleep();`

El padre tiene su padre, pero [[Linux]] es un sistema muy jerárquico y parternalista. EL 8 de marzo deberían haber estado todas en contra de Linux, no hay procesos Madre.

Lo que pasaba era que el padre se muere, dejando huérfano al hijo por un instante, por lo que otro padre lo adopta.

## Revisar los procesos

Al ejecutar el código de `Hijos1.c`, e inmediatamente poner `ps -fea` se puede ver la lista de procesos, la cual mostrará los procesos que hemos generado.

```
cristia+    9348    7527  0 17:38 pts/1    00:00:00 ./Hijos1
cristia+    9349    9348  0 17:38 pts/1    00:00:00 ./Hijos1
```