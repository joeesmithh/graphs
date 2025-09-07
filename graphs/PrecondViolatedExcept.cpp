	/** @file PrecondViolatedExcept.cpp */
#include "PrecondViolatedExcept.h"

PrecondViolatedExcept::PrecondViolatedExcept (const std::string& message)
	: std::logic_error ("PrecondViolatedExcept: " + message)
{} // end constructor