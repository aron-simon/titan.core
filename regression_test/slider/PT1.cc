/******************************************************************************
 * Copyright (c) 2000-2018 Ericsson Telecom AB
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v2.0
 * which accompanies this distribution, and is available at
 * https://www.eclipse.org/org/documents/epl-2.0/EPL-2.0.html
 *
 * Contributors:
 *   Balasko, Jeno
 *   Lovassy, Arpad
 *   Raduly, Csaba
 *
 ******************************************************************************/
// This Test Port skeleton source file was generated by the
// TTCN-3 Compiler of the TTCN-3 Test Executor version 1.8.pre3 build 3
// for  (ecsardu@tcclab2) on Thu Apr 29 16:57:07 2010


// You may modify this file. Complete the body of empty functions and
// add your member functions here.

#include "PT1.hh"
#include "dual.hh"

#ifndef OLD_NAMES
namespace dual {
#endif

PT1_PROVIDER::PT1_PROVIDER(const char *par_port_name)
	: PORT(par_port_name)
{
  fprintf(stderr, "PT1(%s) constructed at %p\n", par_port_name, (void*)this);
}

PT1_PROVIDER::~PT1_PROVIDER()
{}

void PT1_PROVIDER::set_parameter(const char * /*parameter_name*/,
	const char * /*parameter_value*/)
{}

/*void PT1_PROVIDER::Handle_Fd_Event(int fd, boolean is_readable,
	boolean is_writable, boolean is_error) {}*/

void PT1_PROVIDER::Handle_Fd_Event_Error(int /*fd*/)
{}

void PT1_PROVIDER::Handle_Fd_Event_Writable(int /*fd*/)
{}

void PT1_PROVIDER::Handle_Fd_Event_Readable(int /*fd*/)
{}

/*void PT1_PROVIDER::Handle_Timeout(double time_since_last_call) {}*/

void PT1_PROVIDER::user_map(const char *system_port)
{
  fprintf(stderr, "PT1(%s) at %p mapped to %s\n", port_name, (void*)this, system_port);
}

void PT1_PROVIDER::user_unmap(const char *system_port)
{
  fprintf(stderr, "PT1(%s) at %p unmapped from %s\n", port_name, (void*)this, system_port);
}

void PT1_PROVIDER::user_start()
{
  fprintf(stderr, "PT1(%s) at %p started\n", port_name, (void*)this);
}

void PT1_PROVIDER::user_stop()
{
  fprintf(stderr, "PT1(%s) at %p stopped\n", port_name, (void*)this);
}

void PT1_PROVIDER::outgoing_send(const ControlRequest& send_par)
{
  if (send_par.text()[0] == CHARSTRING('C'))
  {
    ControlResponse r(CHARSTRING("CResp from PT1_PROVIDER"));
    incoming_message(r);
  }
  else {
    incoming_message(ErrorSignal(CHARSTRING("Not C")));
  }
}

void PT1_PROVIDER::outgoing_send(const OCTETSTRING& send_par)
{
  // got an octetstring, perhaps from enc__PDUType1 in encoders.cc
  incoming_message(send_par);
}

void PT1_PROVIDER::outgoing_send(const PDUType1& send_par)
{
  // Encode to octetstring and receive that.
  // This is highly silly since the outgoing mapping transformed an octetstring to this PDUType1
  incoming_message(OCTETSTRING(enc__PDUType1(send_par)));
}



// External functions defined in dual.ttcn
// Just squatting here in namespace dual.

// called from PT2::send.
// The output will soon end up in PT1_PROVIDER::outgoing_send(OCTETSTRING) in PT1.cc
OCTETSTRING enc__PDUType1(PDUType1 const& par)
{
  OCTETSTRING retval;
  //TTCN_Logger::log(TTCN_Logger::USER_UNQUALIFIED, "%s:", __FUNCTION__);
  TTCN_Logger::begin_event(TTCN_Logger::USER_UNQUALIFIED);
  TTCN_Logger::log_event("%s(", __FUNCTION__);
  par.log();
  TTCN_Logger::log_event_str(")");
  TTCN_Logger::end_event();

  TTCN_Buffer buf;
  par.encode(PDUType1_descr_, buf, TTCN_EncDec::CT_RAW);
  buf.get_string(retval);
  return retval;
}

// called from PT2::incoming_message
// This is prototype backtrack: return 0 for OK or 1 for NOT_MY_TYPE
INTEGER dec__PDUType1(OCTETSTRING const& stream, PDUType1& result)
{
  INTEGER retval(0);
  TTCN_Logger::log(TTCN_Logger::USER_UNQUALIFIED, "%s:", __FUNCTION__);
  {
    TTCN_Buffer buf(stream);
    result.decode(PDUType1_descr_, buf, TTCN_EncDec::CT_RAW);
  }
  return retval;
}
/*
OCTETSTRING enc__PDUType2(dual::PDUType1 const&)
{
  OCTETSTRING retval;
  return retval;
}

INTEGER dec__PDUType2(OCTETSTRING const&, dual::PDUType1&)
{
  INTEGER retval;
  return retval;
}
*/

INTEGER dec__slider(OCTETSTRING& /*stream*/, PDUType1& /*value*/)
{
  INTEGER retval(0); // 0k, 1=not, 2=ins
  return retval;
}

#ifndef OLD_NAMES
} // namespace
#endif
