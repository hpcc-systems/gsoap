#include "soapH.h"
#include "r.nsmap"
int main() { int d; struct soap *soap = soap_new(); soap_call_r__roll(soap, "http://localhost:8080", "", d); printf("%d\n", d); soap_destroy(soap); soap_end(soap); soap_free(soap); return 0; }
