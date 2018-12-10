#include "fact.h"
void
fact_prog_1(char *host,int a,int i)
{
CLIENT *clnt;
int *result_1;
intpair fact_1_arg;



clnt = clnt_create (host, FACT_PROG, FACT_VERS, "udp");
if (clnt == NULL) {
clnt_pcreateerror (host);
exit (1);
}
//endif /* DEBUG */
fact_1_arg.a=a;
fact_1_arg.i=i;
result_1 = fact_1(&fact_1_arg, clnt);
if (result_1 == (int *) NULL) {
clnt_perror (clnt, "call failed");
}
else
{

	

		
		printf("%d\n",*result_1);
	
}
//ifndefDEBUG
clnt_destroy (clnt);
//endif /* DEBUG */
}
int
main (int argc, char *argv[])
{
char *host;
int a,ch,i;
if (argc < 2) {
printf ("usage: %s server_host\n", argv[0]);
exit (1);
}
host = argv[1];
do
{
	system("clear");
	printf("\nEnter a no:: ");
	scanf("%d",&a);
	printf("\nTable of %d is :\n",a);
	for(i=1;i<=10;i++)
	{
		fact_prog_1 (host,a,i);
	}

	printf("\nTry again : (1/0) :: ");	
	scanf("%d",&ch);
} while(ch==1);
exit (0);
}
