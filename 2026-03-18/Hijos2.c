#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

    int pid1, pid2;
    // Ustedes deben poner el fork cuando se necesita el proceso
    pid1 = fork();

    if(pid1 == -1){
        perror("Error en fork");
        exit(-1);
    }

    if(pid1 == 0){
        printf("Hola soy el proceso Hijo1 y mi pid es %d\n\n", getpid());
        printf("\nMi padre es %d\n\n", getppid());
        sleep(5);
        exit(0);
    } else {
        printf("Hola soy el proceso padre y mi pid es %d\n\n", getpid());  
        sleep(5);
    }

    // HIjo2

    pid2 = fork();

    if(pid2 == -1){
        perror("Error en fork");
        exit(-1);
    } if(pid2 == 0){
        printf("Hola soy el proceso Hijo2 y mi pid es %d\n\n", getpid());
        printf("\nMi padre es %d\n\n", getppid());
        sleep(5);
        exit(0);
    } 
    return 0;

}
