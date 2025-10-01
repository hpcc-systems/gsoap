#include "soapH.h"
#include "gmt.nsmap"
int main()
{
  struct soap *soap = soap_new();
  SOAP_SOCKET m = soap_bind(soap, NULL, 8080, 1);
  if (soap_valid_socket(m))
  {
    while (true)
    {
      SOAP_SOCKET s = soap_accept(soap);
      if (!soap_valid_socket(s))
        break;
      soap_serve(soap);
      soap_destroy(soap);
      soap_end(soap);
    }
  }
  soap_print_fault(soap, stderr);
  soap_free(soap);
}
int t__gmt(struct soap *soap, time_t *t)
{
  *t = time(0);
  return SOAP_OK;
}
