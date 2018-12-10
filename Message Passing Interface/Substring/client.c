#include<stdio.h>
#include<string.h>
#include"mpi.h"

int main(int argc , char **argv)
{
   MPI_Comm server;
   MPI_Status status;
   char port_name[MPI_MAX_PORT_NAME] , string1[20] , result[40];
   int startIndex, endIndex;
   MPI_Init(&argc,&argv);
   strcpy(port_name,argv[1]);
   MPI_Comm_connect(port_name,MPI_INFO_NULL , 0 , MPI_COMM_WORLD , &server);
   printf("Enter first string :\n");
   scanf("%s" , string1);
   printf("Enter start index :\n");
   scanf("%d" , &startIndex);
   printf("Enter end index :\n");
   scanf("%d" , &endIndex);
  
   MPI_Send(&string1 , 20 , MPI_CHAR , 0 , 1 , server);
   MPI_Send(&startIndex , 1 , MPI_INT , 0 , 1 , server);
   MPI_Send(&endIndex , 1 , MPI_INT , 0 , 1 , server);
   MPI_Recv(&result , 40 , MPI_CHAR , MPI_ANY_SOURCE , MPI_ANY_TAG , server,&status);
   printf("The substring is : %s\n",result);
  
   MPI_Comm_disconnect(&server);
    MPI_Finalize();
}
