#include <iostream>
#include <stdexcept>
#include <exception>

using namespace std;

#ifndef CMDERROR_CPP
#define CMDERROR_CPP

class CmdError : public runtime_error
{
	public:
		CmdError(char *msg):runtime_error(msg){}
};

#endif
