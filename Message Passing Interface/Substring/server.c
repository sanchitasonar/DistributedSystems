#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"mpi.h"

int main(int argc , char **argv)
{
   MPI_Comm client;
   MPI_Status status;
   int size;
   char port_name[MPI_MAX_PORT_NAME] , string1[20] , string2[20];
   int startIndex, endIndex, i=0, j=0,again;

   MPI_Init(&argc,&argv);

   MPI_Comm_size(MPI_COMM_WORLD , &size);

   if(size != 1)
   {

   fprintf(stderr,"Server too large");
   exit(EXIT_FAILURE);
   }

   MPI_Open_port(MPI_INFO_NULL,port_name);
   printf("Server is at port : %s\n ",port_name);
i=0;
while (1) {
   MPI_Comm_accept(port_name , MPI_INFO_NULL , 0 , MPI_COMM_WORLD , &client);
again = 1;
while (again) {
   MPI_Recv(&string1 , 20 , MPI_CHAR , MPI_ANY_SOURCE , MPI_ANY_TAG , client,&status);
   MPI_Recv(&startIndex , 1 , MPI_INT , MPI_ANY_SOURCE , MPI_ANY_TAG , client,&status);
   MPI_Recv(&endIndex , 1 , MPI_INT , MPI_ANY_SOURCE , MPI_ANY_TAG , client,&status);
switch (status.MPI_TAG) {case 0:
MPI_Comm_free(&client);
MPI_Close_port(port_name);
MPI_Finalize();
return 0;
case 1:
   printf("\nString 1 is : %s \n",string1);
   if(status.MPI_TAG == 1)
   {
    for(i=startIndex; i<endIndex; i++){
    	string2[j] = string1[i];
    	j++;
    }
    string2[j] = '\0';
    
    MPI_Send(&string2 , 40 , MPI_CHAR , 0 , 1 , client);
   }
   
   MPI_Comm_disconnect(&client);
   MPI_Finalize();
break;
}
}
}
}
