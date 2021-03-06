/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _OPERATION_H_RPCGEN
#define _OPERATION_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct intpair {
	int a;
	int b;
	int ch;
};
typedef struct intpair intpair;

#define FACT_PROG 0x23451111
#define FACT_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define FACT 1
extern  int * fact_1(intpair *, CLIENT *);
extern  int * fact_1_svc(intpair *, struct svc_req *);
extern int fact_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define FACT 1
extern  int * fact_1();
extern  int * fact_1_svc();
extern int fact_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_intpair (XDR *, intpair*);

#else /* K&R C */
extern bool_t xdr_intpair ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_OPERATION_H_RPCGEN */
