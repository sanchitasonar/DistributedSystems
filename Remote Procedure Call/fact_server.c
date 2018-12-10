#include "fact.h"
int *
fact_1_svc(intpair *argp, struct svc_req *rqstp)
{
static int result,n,fact;
int i;
n=argp->a;
// factorial logic
fact = 1;
printf("\n Received : n= %d \n",n);
for (i=n;i>0;i--)
{
fact=fact * i;
}
result=fact;
return &result;
}




/*
OUTPUT:-
info17@info17-HP-280-G2-MT:~/Desktop/exp2$ sudo ./fact_server

 Received : n=4 

 Received : n=7 
*/
