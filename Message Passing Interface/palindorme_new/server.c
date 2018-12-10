#include <stdlib.h>
#include <stdio.h>
#include "mpi.h"
#include<string.h>
int main(int argc, char **argv)
{
	MPI_Comm client;	
	MPI_Status status;
	char port_name[MPI_MAX_PORT_NAME],str[50],str1[50],str2[50]="string is palindrome",str3[50]="string is not palindrome",ch,temp;
	int size, again, i,j,flag=0;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if (size != 1) {
	fprintf(stderr, "Server too big");
	exit(EXIT_FAILURE);
	}
	MPI_Open_port(MPI_INFO_NULL, port_name);
	printf("Server available at port: %s\n", port_name);
	i=0;
	while (1) {
	MPI_Comm_accept(port_name, MPI_INFO_NULL, 0, MPI_COMM_WORLD, &client);
	again = 1;
	while (again) {
	MPI_Recv(&ch, 1, MPI_CHAR, MPI_ANY_SOURCE, MPI_ANY_TAG, client, &status);
	switch (status.MPI_TAG) {
	case 0:
		MPI_Comm_free(&client);
		MPI_Close_port(port_name);
		MPI_Finalize();
	return 0;
	case 1:
		//printf("\nReceived String: %s\n",str);
		// reverse the string
		   
		strcpy(str1,str);// actual string is in str1
		i = 0;
		j = strlen(str) - 1;
		while (i < j) {
			temp = str[i];
			str[i] = str[j];
			str[j] = temp;
			i++;
			j--;
		}   
		           
	             // str contain reverse string
		for(i=0;i<strlen(str)-1 && str[i]!='\0';i++)       //calculating length of string
		{
			if(str[i]==str1[i])   // compairing char at each place in str,str1
			{
				printf("%c%c",str[i],str1[i]);
				flag=1;
				
				              // set 1  if string is equal
			}
			else
			{
				flag=0;
				break;
			}

		}	
		if(flag==1)
		{
			for (i = 0; i < strlen(str2)-1 && str2[i]!='\0'; i++) {
			ch=str2[i];
			MPI_Send(&ch, 1, MPI_CHAR, 0, 2, client);
			}
		}	
		else
		{
			for (i = 0; i < strlen(str3)-1 && str3[i]!='\0'; i++) {
			ch=str3[i];
			MPI_Send(&ch, 1, MPI_CHAR, 0, 2, client);
			}
			
		}
			
		//send tag=1 to indicate end of string
		MPI_Send(&ch, 1, MPI_CHAR, 0, 1, client);
		MPI_Comm_disconnect(&client);
		again = 0;
		strcpy(str,"");
		i=0;
	break;
	case 2:
		printf("Received character: %c\n", ch);
		str[i]=ch;
		i++;
		// add null character at the end of string
		str[i]='\0';
	break;
	default:
		/* Unexpected message type */
		MPI_Abort(MPI_COMM_WORLD, 1);
	}
	}
	}
}

