#include "fact.h"
int *fact_1_svc(intpair *argp, struct svc_req *rqstp)
{
static int result,n,n1;

n=argp->a;
n1=argp->i;
printf("\n Received : n= %d \n",n);

printf("Received : i=%d\n",n1);
 
   
	result=n*n1;
	
        printf("%d\n", result);
	return &result;
   
    
}
