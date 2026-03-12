#include <stdio.h>

// Esta función es para las entradas su salidas estándar. C
// Con esta podemos usar el teclado y pantalla

#include <stdlib.h>

int main(){
  pid_t pid;
  // pid_t es un tipo de dato entero.
  // es una re definición de int. Pero son lo mismo, solo para Linuxeros de corazón.
  printf("\n\tHola, soy el proceso padre\n\n");

  /* 
    # ¿Qué es un printf()?
    Vas a usar algo en la pantalla. Es una [[Llamada al Sistema]].
    Decir que es una función puede estar medio equis, pero la respuesta correcta es esa
  */

  pid = fork();
  /*
    > Fork significa "bifurcación".
    Esto es una llamada al sistema. Llama  la RAM y crea un espacio nuevo conocido como proceso hijo.
    Entonces el proceso A se convierte en proceso padre
  */

  if(pid == -1){
    // Quien programó Fork, estableció que "-1" es error.
    perror("Error en fork");
    exit(-1);
  }
  
  // # IF MÁGICO
  // Es un if mágico debido a que ambos bloques se usan.
  
  if(pid == 0){
    printf("Hola soy el hijo");
  } else {
    // Este código de acá abajo es del padre. Él nunca ejecutará el del hijo.
    printf("Hola soy el padre");  
  }
  
  return 0;

 
  /*
    Yo creo que el sistema operativo se creó a imagen y semejanza del ser humano.
  */

}
