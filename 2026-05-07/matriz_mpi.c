#include <mpi.h>
#include <stdio.h>

#define FILAS 7
#define COLUMNAS 3

// Delgado Lucero Cristian Isaac
// Este codigo es para enviar las operaciones de la practica 05 :D

int main(int argc, char **argv) {
    int pid, procesos, origen, destino, datos;
    int matriz[FILAS][COLUMNAS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {9, 6, 3},
        {-6, -9, -12},
        {5, 10, 15},
        {7, 14, 21}
    };
    
    int fila[COLUMNAS];
    int i;
    MPI_Status estatus;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    MPI_Comm_size(MPI_COMM_WORLD, &procesos);
    
    // Todo lo que va despues de aqui se va para todos los procesadores de mi compu
    // Mi computadora tiene 10 nucleos, entonces alcanza para hacer todo de una

    // Inicializo esto como el codigo del profe
    for(i = 0; i < COLUMNAS; i++)
        fila[i] = 0;
    
    // El proceso maestro es el 0. 
    // Enviaremos cada fila a los procesos del 1 al 7
    if(pid == 0) {
        destino = 1;
        MPI_Send(&matriz[0][0], COLUMNAS, MPI_INT, destino, 0, MPI_COMM_WORLD);
        printf("Proceso 0 envió fila 0 al proceso %d\n", destino);
        
        destino = 2;
        MPI_Send(&matriz[1][0], COLUMNAS, MPI_INT, destino, 0, MPI_COMM_WORLD);
        printf("Proceso 0 envió fila 1 al proceso %d\n", destino);
        
        destino = 3;
        MPI_Send(&matriz[2][0], COLUMNAS, MPI_INT, destino, 0, MPI_COMM_WORLD);
        printf("Proceso 0 envió fila 2 al proceso %d\n", destino);
        
        destino = 4;
        MPI_Send(&matriz[3][0], COLUMNAS, MPI_INT, destino, 0, MPI_COMM_WORLD);
        printf("Proceso 0 envió fila 3 al proceso %d\n", destino);
        
        destino = 5;
        MPI_Send(&matriz[4][0], COLUMNAS, MPI_INT, destino, 0, MPI_COMM_WORLD);
        printf("Proceso 0 envió fila 4 al proceso %d\n", destino);
        
        destino = 6;
        MPI_Send(&matriz[5][0], COLUMNAS, MPI_INT, destino, 0, MPI_COMM_WORLD);
        printf("Proceso 0 envió fila 5 al proceso %d\n", destino);
        
        destino = 7;
        MPI_Send(&matriz[6][0], COLUMNAS, MPI_INT, destino, 0, MPI_COMM_WORLD);
        printf("Proceso 0 envió fila 6 al proceso %d\n", destino);
    }
    else if(pid == 1) {
        // Aqui imite lo que habia en el codigo de MPI-Arreglos.c que vimos en clase.
        origen = 0;
        MPI_Recv(&fila[0], COLUMNAS, MPI_INT, origen, 0, MPI_COMM_WORLD, &estatus);
        
        int a = fila[0];
        int b = fila[1];
        int c = fila[2];
        
        printf("\n========================================\n");
        printf("Proceso %d recibió la fila: [%d, %d, %d]\n", pid, a, b, c);
        printf("========================================\n");
        
        printf("1) a + b + c = %d + %d + %d = %d\n", a, b, c, a + b + c);
        printf("2) a - b + c = %d - %d + %d = %d\n", a, b, c, a - b + c);
        printf("3) a * b * c = %d * %d * %d = %d\n", a, b, c, a * b * c);
        printf("4) a * (b + c) = %d * (%d + %d) = %d\n", a, b, c, a * (b + c));
        printf("5) a * b - b * c = (%d * %d) - (%d * %d) = %d\n", a, b, b, c, (a * b) - (b * c));
        printf("6) c * (a + b)^2 = %d * (%d + %d)^2 = %d\n", c, a, b, c * ((a + b) * (a + b)));
        printf("7) a^2 - b^2 + c^3 = (%d^2) - (%d^2) + (%d^3) = %d\n", a, b, c, (a*a) - (b*b) + (c*c*c));
        printf("----------------------------------------\n\n");
    }
    else if(pid == 2) {
        origen = 0;
        MPI_Recv(&fila[0], COLUMNAS, MPI_INT, origen, 0, MPI_COMM_WORLD, &estatus);
        
        int a = fila[0];
        int b = fila[1];
        int c = fila[2];
        
        printf("\n========================================\n");
        printf("Proceso %d recibió la fila: [%d, %d, %d]\n", pid, a, b, c);
        printf("========================================\n");
        
        printf("1) a + b + c = %d + %d + %d = %d\n", a, b, c, a + b + c);
        printf("2) a - b + c = %d - %d + %d = %d\n", a, b, c, a - b + c);
        printf("3) a * b * c = %d * %d * %d = %d\n", a, b, c, a * b * c);
        printf("4) a * (b + c) = %d * (%d + %d) = %d\n", a, b, c, a * (b + c));
        printf("5) a * b - b * c = (%d * %d) - (%d * %d) = %d\n", a, b, b, c, (a * b) - (b * c));
        printf("6) c * (a + b)^2 = %d * (%d + %d)^2 = %d\n", c, a, b, c * ((a + b) * (a + b)));
        printf("7) a^2 - b^2 + c^3 = (%d^2) - (%d^2) + (%d^3) = %d\n", a, b, c, (a*a) - (b*b) + (c*c*c));
        printf("----------------------------------------\n\n");
    }
    else if(pid == 3) {
        origen = 0;
        MPI_Recv(&fila[0], COLUMNAS, MPI_INT, origen, 0, MPI_COMM_WORLD, &estatus);
        
        int a = fila[0];
        int b = fila[1];
        int c = fila[2];
        
        printf("\n========================================\n");
        printf("Proceso %d recibió la fila: [%d, %d, %d]\n", pid, a, b, c);
        printf("========================================\n");
        
        printf("1) a + b + c = %d + %d + %d = %d\n", a, b, c, a + b + c);
        printf("2) a - b + c = %d - %d + %d = %d\n", a, b, c, a - b + c);
        printf("3) a * b * c = %d * %d * %d = %d\n", a, b, c, a * b * c);
        printf("4) a * (b + c) = %d * (%d + %d) = %d\n", a, b, c, a * (b + c));
        printf("5) a * b - b * c = (%d * %d) - (%d * %d) = %d\n", a, b, b, c, (a * b) - (b * c));
        printf("6) c * (a + b)^2 = %d * (%d + %d)^2 = %d\n", c, a, b, c * ((a + b) * (a + b)));
        printf("7) a^2 - b^2 + c^3 = (%d^2) - (%d^2) + (%d^3) = %d\n", a, b, c, (a*a) - (b*b) + (c*c*c));
        printf("----------------------------------------\n\n");
    }
    else if(pid == 4) {
        origen = 0;
        MPI_Recv(&fila[0], COLUMNAS, MPI_INT, origen, 0, MPI_COMM_WORLD, &estatus);
        
        int a = fila[0];
        int b = fila[1];
        int c = fila[2];
        
        printf("\n========================================\n");
        printf("Proceso %d recibió la fila: [%d, %d, %d]\n", pid, a, b, c);
        printf("========================================\n");
        
        printf("1) a + b + c = %d + %d + %d = %d\n", a, b, c, a + b + c);
        printf("2) a - b + c = %d - %d + %d = %d\n", a, b, c, a - b + c);
        printf("3) a * b * c = %d * %d * %d = %d\n", a, b, c, a * b * c);
        printf("4) a * (b + c) = %d * (%d + %d) = %d\n", a, b, c, a * (b + c));
        printf("5) a * b - b * c = (%d * %d) - (%d * %d) = %d\n", a, b, b, c, (a * b) - (b * c));
        printf("6) c * (a + b)^2 = %d * (%d + %d)^2 = %d\n", c, a, b, c * ((a + b) * (a + b)));
        printf("7) a^2 - b^2 + c^3 = (%d^2) - (%d^2) + (%d^3) = %d\n", a, b, c, (a*a) - (b*b) + (c*c*c));
        printf("----------------------------------------\n\n");
    }
    else if(pid == 5) {
        origen = 0;
        MPI_Recv(&fila[0], COLUMNAS, MPI_INT, origen, 0, MPI_COMM_WORLD, &estatus);
        
        int a = fila[0];
        int b = fila[1];
        int c = fila[2];
        
        printf("\n========================================\n");
        printf("Proceso %d recibió la fila: [%d, %d, %d]\n", pid, a, b, c);
        printf("========================================\n");
        
        printf("1) a + b + c = %d + %d + %d = %d\n", a, b, c, a + b + c);
        printf("2) a - b + c = %d - %d + %d = %d\n", a, b, c, a - b + c);
        printf("3) a * b * c = %d * %d * %d = %d\n", a, b, c, a * b * c);
        printf("4) a * (b + c) = %d * (%d + %d) = %d\n", a, b, c, a * (b + c));
        printf("5) a * b - b * c = (%d * %d) - (%d * %d) = %d\n", a, b, b, c, (a * b) - (b * c));
        printf("6) c * (a + b)^2 = %d * (%d + %d)^2 = %d\n", c, a, b, c * ((a + b) * (a + b)));
        printf("7) a^2 - b^2 + c^3 = (%d^2) - (%d^2) + (%d^3) = %d\n", a, b, c, (a*a) - (b*b) + (c*c*c));
        printf("----------------------------------------\n\n");
    }
    else if(pid == 6) {
        origen = 0;
        MPI_Recv(&fila[0], COLUMNAS, MPI_INT, origen, 0, MPI_COMM_WORLD, &estatus);
        
        int a = fila[0];
        int b = fila[1];
        int c = fila[2];
        
        printf("\n========================================\n");
        printf("Proceso %d recibió la fila: [%d, %d, %d]\n", pid, a, b, c);
        printf("========================================\n");
        
        printf("1) a + b + c = %d + %d + %d = %d\n", a, b, c, a + b + c);
        printf("2) a - b + c = %d - %d + %d = %d\n", a, b, c, a - b + c);
        printf("3) a * b * c = %d * %d * %d = %d\n", a, b, c, a * b * c);
        printf("4) a * (b + c) = %d * (%d + %d) = %d\n", a, b, c, a * (b + c));
        printf("5) a * b - b * c = (%d * %d) - (%d * %d) = %d\n", a, b, b, c, (a * b) - (b * c));
        printf("6) c * (a + b)^2 = %d * (%d + %d)^2 = %d\n", c, a, b, c * ((a + b) * (a + b)));
        printf("7) a^2 - b^2 + c^3 = (%d^2) - (%d^2) + (%d^3) = %d\n", a, b, c, (a*a) - (b*b) + (c*c*c));
        printf("----------------------------------------\n\n");
    }
    else if(pid == 7) {
        origen = 0;
        MPI_Recv(&fila[0], COLUMNAS, MPI_INT, origen, 0, MPI_COMM_WORLD, &estatus);
        
        int a = fila[0];
        int b = fila[1];
        int c = fila[2];
        
        printf("\n========================================\n");
        printf("Proceso %d recibió la fila: [%d, %d, %d]\n", pid, a, b, c);
        printf("========================================\n");
        
        printf("1) a + b + c = %d + %d + %d = %d\n", a, b, c, a + b + c);
        printf("2) a - b + c = %d - %d + %d = %d\n", a, b, c, a - b + c);
        printf("3) a * b * c = %d * %d * %d = %d\n", a, b, c, a * b * c);
        printf("4) a * (b + c) = %d * (%d + %d) = %d\n", a, b, c, a * (b + c));
        printf("5) a * b - b * c = (%d * %d) - (%d * %d) = %d\n", a, b, b, c, (a * b) - (b * c));
        printf("6) c * (a + b)^2 = %d * (%d + %d)^2 = %d\n", c, a, b, c * ((a + b) * (a + b)));
        printf("7) a^2 - b^2 + c^3 = (%d^2) - (%d^2) + (%d^3) = %d\n", a, b, c, (a*a) - (b*b) + (c*c*c));
        printf("----------------------------------------\n\n");
    }
    
    MPI_Finalize();
    return 0;
}