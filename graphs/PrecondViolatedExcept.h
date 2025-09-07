/** @file PrecondViolatedExcept.h */
#ifndef PRECOND_VIOLATED_EXCEPT_H_
#define PRECOND_VIOLATED_EXCEPT_H_
#include <stdexcept>
#include <string>

class PrecondViolatedExcept: public std::logic_error
{
public:
	PrecondViolatedExcept (const std::string& message = "");
}; // end PrecondViolatedExcept
#endif // PRECOND_VIOLATED_EXCEPT_H_