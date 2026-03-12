#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

  int pid;
  pid = fork();
 
  if(pid == -1){
    perror("Error en fork");
    exit(-1);
  }
  
  if(pid == 0){
    printf("Hola soy el proceso hijo y mi pid es %d\n\n", getpid());
    printf("\nMi padre es %d\n\n", getppid());
    sleep(5);
  } else {
    printf("Hola soy el proceso padre y mi pid es %d\n\n", getpid());  
    sleep(5);
  }
  
  return 0;

}
