#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mpi.h"
int main( int argc, char **argv )
{
	MPI_Comm server;
	MPI_Status status;
	char port_name[MPI_MAX_PORT_NAME],str[50]="",str1[50]="",ch,ch1;
	int i, j,tag,again;
	if (argc < 2) {
		fprintf(stderr, "server port name required.\n");
		exit(EXIT_FAILURE);
	}
	MPI_Init(&argc, &argv);
	strcpy(port_name, argv[1]);
	MPI_Comm_connect(port_name, MPI_INFO_NULL, 0, MPI_COMM_WORLD, &server);
	// accept input string
	printf("\nEnter the string :\n");
	scanf("%s",str);
	//send string to server (character by character)
	for (i = 0; i < strlen(str); i++) {
		if(str[i]!='\0')
			ch=str[i];
		tag=2;
	MPI_Send(&ch, 1, MPI_CHAR, 0, tag, server);
	}
	printf("\nEnter Second  string :\n");
	scanf("%s",str1);
	for (j = 0; j < strlen(str1); j++) {
		if(str1[j]!='\0')
			ch1=str1[j];
		tag=2;
	MPI_Send(&ch1, 1, MPI_CHAR, 0, tag, server);

	}// done sending string to the server
	MPI_Send(&i, 0, MPI_INT, 0, 1, server);
	MPI_Send(&j, 0, MPI_INT, 0, 1, server);

	// Receive the reversed string from server and display it
	i=0;
	again=1;
	while (again) {
	MPI_Recv(&ch, 1, MPI_CHAR, MPI_ANY_SOURCE, MPI_ANY_TAG, server, &status);
	switch (status.MPI_TAG) {
	case 2:
		str[i]=ch;
		i++;
	break;
	case 1: again=0;
	break;
	}
	}
	printf("\nConcatination OF string is : %s\n\n",str);
	MPI_Comm_disconnect(&server);
	MPI_Finalize();
	return 0;
}
