/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "operation.h"

bool_t
xdr_intpair (XDR *xdrs, intpair *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->a))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->b))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->ch))
		 return FALSE;
	return TRUE;
}
