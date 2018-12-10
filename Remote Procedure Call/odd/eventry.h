/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _EVENTRY_H_RPCGEN
#define _EVENTRY_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct intpair {
	int a;
};
typedef struct intpair intpair;

#define evenp_PROG 0x23451111
#define evenp_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define evenp 1
extern  int * evenp_1(intpair *, CLIENT *);
extern  int * evenp_1_svc(intpair *, struct svc_req *);
extern int evenp_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define evenp 1
extern  int * evenp_1();
extern  int * evenp_1_svc();
extern int evenp_prog_1_freeresult ();
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

#endif /* !_EVENTRY_H_RPCGEN */
