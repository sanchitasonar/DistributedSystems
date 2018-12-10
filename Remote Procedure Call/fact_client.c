#include "fact.h"
void
fact_prog_1(char *host,int a)
{
CLIENT *clnt;
int *result_1;
intpair fact_1_arg;
#ifndef DEBUG
clnt = clnt_create (host, FACT_PROG, FACT_VERS, "udp");
if (clnt == NULL) {
clnt_pcreateerror (host);
exit (1);
}
#endif /* DEBUG */
fact_1_arg.a=a;
result_1 = fact_1(&fact_1_arg, clnt);
if (result_1 == (int *) NULL) {
clnt_perror (clnt, "call failed");
}
else
{
printf("Factorial=%d",*result_1);
}
#ifndef DEBUG
clnt_destroy (clnt);
#endif /* DEBUG */
}
int
main (int argc, char *argv[])
{
char *host;
int a,ch;
if (argc < 2) {
printf ("usage: %s server_host\n", argv[0]);
exit (1);
}
host = argv[1];do
{
system("clear");
printf("\nEnter a no:: ");
scanf("%d",&a);
fact_prog_1 (host,a);
printf("\nTry again : (1/0) :: ");
scanf("%d",&ch);
} while(ch==1);
exit (0);
}




/*
OUTPUT:-
root@info17-HP-280-G2-MT:/home/info17/Desktop/exp2# ./fact_client localhost

Enter a no:4
Factorial=24
Try again : (1/0) :: 1

*/
