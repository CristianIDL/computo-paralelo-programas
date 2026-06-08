#include<stdio.h>
#include<cuda_runtime.h>
#include<device_launch_parameters.h>

#define Tam 3

__global__ void SumaMatriz(int *A, int *B, int *C, int tam)
{
   printf("\nRealizando trabajo en el hilo (%d, %d)",threadIdx.x,threadIdx.y);
   int n=threadIdx.x;
   int m=threadIdx.y;
   C[n+m*tam]=A[n+m*tam]+B[n+m*tam];
}

int main()
{
   int i,j;
   int A[Tam][Tam]={{0,1,2},{3,4,5},{6,7,8}};
   int B[Tam][Tam]={{0,1,2},{3,4,5},{6,7,8}};
   int C[Tam][Tam]={{0,0,0},{0,0,0},{0,0,0}};
   int *devA, *devB, *devC;
   dim3 HilosPorBloque(Tam*Tam);
   dim3 BloquesPorGrid(1);

   printf("\nInicializando datos desde la CPU\n\n");

   for(i=0;i<Tam;i++)
   {
      for(j=0;j<Tam;j++)
      {
         printf("A[%d][%d]=%d\t",i,j,A[i][j]);
      }
      printf("\n");
   }
   printf("\n");
   for(i=0;i<Tam;i++)
   {
      for(j=0;j<Tam;j++)
      {
         printf("B[%d][%d]=%d\t",i,j,B[i][j]);
      }
      printf("\n");
   }
   printf("\n");
   for(i=0;i<Tam;i++)
   {
      for(j=0;j<Tam;j++)
      {
         printf("C[%d][%d]=%d\t",i,j,C[i][j]);
      }
      printf("\n");
   }

   cudaMalloc((void**)&devA,Tam*Tam*sizeof(int));
   cudaMalloc((void**)&devB,Tam*Tam*sizeof(int));
   cudaMalloc((void**)&devC,Tam*Tam*sizeof(int));

   printf("\nCopiando datos al dispositivo\n");

   cudaMemcpy(devA,A,Tam*Tam*sizeof(int),cudaMemcpyHostToDevice);
   cudaMemcpy(devB,B,Tam*Tam*sizeof(int),cudaMemcpyHostToDevice);
   cudaMemcpy(devC,C,Tam*Tam*sizeof(int),cudaMemcpyHostToDevice);

   printf("\nIniciando procesamiento paralelo al dispositivo\n");

   SumaMatriz<<<BloquesPorGrid,HilosPorBloque>>>(devA,devB,devC,Tam);

   cudaMemcpy(C,devC,Tam*Tam*sizeof(int),cudaMemcpyDeviceToHost);

   printf("\n\nMostrando datos generados desde la CPU\n\n");

   for(i=0;i<Tam;i++)
   {
      for(j=0;j<Tam;j++)
      {
         printf("C[%d][%d]=%d\t",i,j,C[i][j]);
      }
      printf("\n");
   }

   cudaFree(devA);
   cudaFree(devB);
   cudaFree(devC);

   cudaDeviceReset();

   return 0;
}