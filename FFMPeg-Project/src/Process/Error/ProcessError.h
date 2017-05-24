#ifndef ERROR_PROCESS_ERROR_H
#define ERROR_PROCESS_ERROR_H

// C++ Headers
//---------------------------------------------------------------------------------------------
#include <stdexcept> // Standard exception.
#include <exception> // C++ exception.
#include <string>	 // C++ string.
//---------------------------------------------------------------------------------------------

class ProcessError : public std::runtime_error{
public:
	/**
	 * @brief Default constructor.
	 */
	ProcessError();
	/**
	 * @brief Custom constructor.
	 *
	 * @param msg The message to be thrown with the error.
	 */
	ProcessError(const std::string& msg);
};

#endif //define ERROR_PROCESS_ERROR_H
