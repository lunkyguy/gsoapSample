/* soapcalcProxy.cpp
   Generated by gSOAP 2.8.79 for ..\..\samples\calc\calc.h

gSOAP XML Web services tools
Copyright (C) 2000-2018, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#include "soapcalcProxy.h"

calcProxy::calcProxy()
{	this->soap = soap_new();
	this->soap_own = true;
	calcProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

calcProxy::calcProxy(const calcProxy& rhs)
{	this->soap = rhs.soap;
	this->soap_own = false;
	this->soap_endpoint = rhs.soap_endpoint;
}

calcProxy::calcProxy(struct soap *_soap)
{	this->soap = _soap;
	this->soap_own = false;
	calcProxy_init(_soap->imode, _soap->omode);
}

calcProxy::calcProxy(struct soap *_soap, const char *soap_endpoint_url)
{	this->soap = _soap;
	this->soap_own = false;
	calcProxy_init(_soap->imode, _soap->omode);
	soap_endpoint = soap_endpoint_url;
}

calcProxy::calcProxy(const char *soap_endpoint_url)
{	this->soap = soap_new();
	this->soap_own = true;
	calcProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
	soap_endpoint = soap_endpoint_url;
}

calcProxy::calcProxy(soap_mode iomode)
{	this->soap = soap_new();
	this->soap_own = true;
	calcProxy_init(iomode, iomode);
}

calcProxy::calcProxy(const char *soap_endpoint_url, soap_mode iomode)
{	this->soap = soap_new();
	this->soap_own = true;
	calcProxy_init(iomode, iomode);
	soap_endpoint = soap_endpoint_url;
}

calcProxy::calcProxy(soap_mode imode, soap_mode omode)
{	this->soap = soap_new();
	this->soap_own = true;
	calcProxy_init(imode, omode);
}

calcProxy::~calcProxy()
{	if (this->soap_own)
	{	this->destroy();
		soap_free(this->soap);
	}
}

void calcProxy::calcProxy_init(soap_mode imode, soap_mode omode)
{	soap_imode(this->soap, imode);
	soap_omode(this->soap, omode);
	soap_endpoint = NULL;
	static const struct Namespace namespaces[] = {
        { "SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL },
        { "SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL },
        { "xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL },
        { "xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL },
        { "ns", "urn:calc", NULL, NULL },
        { NULL, NULL, NULL, NULL}
    };
	soap_set_namespaces(this->soap, namespaces);
}

calcProxy *calcProxy::copy()
{	calcProxy *dup = SOAP_NEW_UNMANAGED(calcProxy);
	if (dup)
	{	soap_done(dup->soap);
		soap_copy_context(dup->soap, this->soap);
	}
	return dup;
}

calcProxy& calcProxy::operator=(const calcProxy& rhs)
{	if (this->soap != rhs.soap)
	{	if (this->soap_own)
			soap_free(this->soap);
		this->soap = rhs.soap;
		this->soap_own = false;
		this->soap_endpoint = rhs.soap_endpoint;
	}
	return *this;
}

void calcProxy::destroy()
{	soap_destroy(this->soap);
	soap_end(this->soap);
}

void calcProxy::reset()
{	this->destroy();
	soap_done(this->soap);
	soap_initialize(this->soap);
	calcProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

void calcProxy::soap_noheader()
{	this->soap->header = NULL;
}

::SOAP_ENV__Header *calcProxy::soap_header()
{	return this->soap->header;
}

::SOAP_ENV__Fault *calcProxy::soap_fault()
{	return this->soap->fault;
}

const char *calcProxy::soap_fault_subcode()
{	return ::soap_fault_subcode(this->soap);
}

const char *calcProxy::soap_fault_string()
{	return ::soap_fault_string(this->soap);
}

const char *calcProxy::soap_fault_detail()
{	return ::soap_fault_detail(this->soap);
}

int calcProxy::soap_close_socket()
{	return ::soap_closesock(this->soap);
}

int calcProxy::soap_force_close_socket()
{	return ::soap_force_closesock(this->soap);
}

void calcProxy::soap_print_fault(FILE *fd)
{	::soap_print_fault(this->soap, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void calcProxy::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this->soap, os);
}
#endif

char *calcProxy::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this->soap, buf, len);
}
#endif

int calcProxy::send_add(const char *soap_endpoint_url, const char *soap_action, double a, double b)
{
	struct ns__add soap_tmp_ns__add;
	if (soap_endpoint_url != NULL)
		soap_endpoint = soap_endpoint_url;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://websrv.cs.fsu.edu/~engelen/calcserver.cgi";
	soap_tmp_ns__add.a = a;
	soap_tmp_ns__add.b = b;
	soap_begin(soap);
	soap->encodingStyle = ""; /* use SOAP encoding style */
	soap_serializeheader(soap);
	soap_serialize_ns__add(soap, &soap_tmp_ns__add);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__add(soap, &soap_tmp_ns__add, "ns:add", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__add(soap, &soap_tmp_ns__add, "ns:add", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

int calcProxy::recv_add(double *result)
{
	struct ns__addResponse *soap_tmp_ns__addResponse;
	if (!result)
		return soap_closesock(soap);
	soap_default_double(soap, result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__addResponse = soap_get_ns__addResponse(soap, NULL, "", NULL);
	if (!soap_tmp_ns__addResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (result && soap_tmp_ns__addResponse->result)
		*result = *soap_tmp_ns__addResponse->result;
	return soap_closesock(soap);
}

int calcProxy::send_sub(const char *soap_endpoint_url, const char *soap_action, double a, double b)
{
	struct ns__sub soap_tmp_ns__sub;
	if (soap_endpoint_url != NULL)
		soap_endpoint = soap_endpoint_url;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://websrv.cs.fsu.edu/~engelen/calcserver.cgi";
	soap_tmp_ns__sub.a = a;
	soap_tmp_ns__sub.b = b;
	soap_begin(soap);
	soap->encodingStyle = ""; /* use SOAP encoding style */
	soap_serializeheader(soap);
	soap_serialize_ns__sub(soap, &soap_tmp_ns__sub);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__sub(soap, &soap_tmp_ns__sub, "ns:sub", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__sub(soap, &soap_tmp_ns__sub, "ns:sub", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

int calcProxy::recv_sub(double *result)
{
	struct ns__subResponse *soap_tmp_ns__subResponse;
	if (!result)
		return soap_closesock(soap);
	soap_default_double(soap, result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__subResponse = soap_get_ns__subResponse(soap, NULL, "", NULL);
	if (!soap_tmp_ns__subResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (result && soap_tmp_ns__subResponse->result)
		*result = *soap_tmp_ns__subResponse->result;
	return soap_closesock(soap);
}

int calcProxy::send_mul(const char *soap_endpoint_url, const char *soap_action, double a, double b)
{
	struct ns__mul soap_tmp_ns__mul;
	if (soap_endpoint_url != NULL)
		soap_endpoint = soap_endpoint_url;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://websrv.cs.fsu.edu/~engelen/calcserver.cgi";
	soap_tmp_ns__mul.a = a;
	soap_tmp_ns__mul.b = b;
	soap_begin(soap);
	soap->encodingStyle = ""; /* use SOAP encoding style */
	soap_serializeheader(soap);
	soap_serialize_ns__mul(soap, &soap_tmp_ns__mul);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__mul(soap, &soap_tmp_ns__mul, "ns:mul", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__mul(soap, &soap_tmp_ns__mul, "ns:mul", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

int calcProxy::recv_mul(double *result)
{
	struct ns__mulResponse *soap_tmp_ns__mulResponse;
	if (!result)
		return soap_closesock(soap);
	soap_default_double(soap, result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__mulResponse = soap_get_ns__mulResponse(soap, NULL, "", NULL);
	if (!soap_tmp_ns__mulResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (result && soap_tmp_ns__mulResponse->result)
		*result = *soap_tmp_ns__mulResponse->result;
	return soap_closesock(soap);
}

int calcProxy::send_div(const char *soap_endpoint_url, const char *soap_action, double a, double b)
{
	struct ns__div soap_tmp_ns__div;
	if (soap_endpoint_url != NULL)
		soap_endpoint = soap_endpoint_url;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://websrv.cs.fsu.edu/~engelen/calcserver.cgi";
	soap_tmp_ns__div.a = a;
	soap_tmp_ns__div.b = b;
	soap_begin(soap);
	soap->encodingStyle = ""; /* use SOAP encoding style */
	soap_serializeheader(soap);
	soap_serialize_ns__div(soap, &soap_tmp_ns__div);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__div(soap, &soap_tmp_ns__div, "ns:div", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__div(soap, &soap_tmp_ns__div, "ns:div", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

int calcProxy::recv_div(double *result)
{
	struct ns__divResponse *soap_tmp_ns__divResponse;
	if (!result)
		return soap_closesock(soap);
	soap_default_double(soap, result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__divResponse = soap_get_ns__divResponse(soap, NULL, "", NULL);
	if (!soap_tmp_ns__divResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (result && soap_tmp_ns__divResponse->result)
		*result = *soap_tmp_ns__divResponse->result;
	return soap_closesock(soap);
}

int calcProxy::send_pow(const char *soap_endpoint_url, const char *soap_action, double a, double b)
{
	struct ns__pow soap_tmp_ns__pow;
	if (soap_endpoint_url != NULL)
		soap_endpoint = soap_endpoint_url;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://websrv.cs.fsu.edu/~engelen/calcserver.cgi";
	soap_tmp_ns__pow.a = a;
	soap_tmp_ns__pow.b = b;
	soap_begin(soap);
	soap->encodingStyle = ""; /* use SOAP encoding style */
	soap_serializeheader(soap);
	soap_serialize_ns__pow(soap, &soap_tmp_ns__pow);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__pow(soap, &soap_tmp_ns__pow, "ns:pow", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__pow(soap, &soap_tmp_ns__pow, "ns:pow", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

int calcProxy::recv_pow(double *result)
{
	struct ns__powResponse *soap_tmp_ns__powResponse;
	if (!result)
		return soap_closesock(soap);
	soap_default_double(soap, result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__powResponse = soap_get_ns__powResponse(soap, NULL, "", NULL);
	if (!soap_tmp_ns__powResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (result && soap_tmp_ns__powResponse->result)
		*result = *soap_tmp_ns__powResponse->result;
	return soap_closesock(soap);
}
/* End of client proxy code */
