#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void mostrar_hijos(int pid, int n_hijo);


int main(){

    int pid1, pid2;
    // Ustedes deben poner el fork cuando se necesita el proceso
    pid1 = fork();

    /*
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
    */

    mostrar_hijos(pid1,1);

    // HIjo2

    pid2 = fork();

    if(pid2 == -1){
        perror("Error en fork");
        exit(-1);
    } if(pid2 == 0){

        int pid3;

        printf("Hola soy el proceso Hijo2 y mi pid es %d\n\n", getpid());
        printf("\nMi padre es %d\n\n", getppid());
        
        pid3 = fork();
        
        if(pid3 == -1){
            perror("Error en fork");
            exit(-1);
        }
        
        if(pid3 == 0){
            printf("Hola soy el proceso Hijo3 y mi pid es %d\n\n", getpid());
            printf("\nMi padre es %d\n\n", getppid());
            sleep(5);
            exit(0);
        }

        sleep(5);
        exit(0);
    } 

    sleep(5);

    return 0;

}

void mostrar_hijos(int pid, int n_hijo){
    if(pid == -1){
        perror("Error en fork");
        exit(-1);
    }

    if(pid == 0){
        printf("Hola soy el proceso Hijo%d y mi pid es %d\n\n", n_hijo, getpid());
        printf("\nMi padre es %d\n\n", getppid());
        sleep(5);
        exit(0);
    } else {
        printf("Hola soy el proceso padre y mi pid es %d\n\n", getpid());  
        sleep(5);
    }
}
