/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "fact.h"

int *
fact_1_svc(intpair *argp, struct svc_req *rqstp)
{
	static int  result,n,fact,i;
	n=argp->a;	
	fact=1;
	printf("\nReceived no. is=%d",n);
	for(i=n;i>0;i--)
	{
		fact=fact*i;	
	}
	result=fact;
	/*
	 * insert server code here
	 */

	return &result;
}
