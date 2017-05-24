#include "ProcessError.h"

ProcessError::ProcessError() : runtime_error("Process error.") {}
ProcessError::ProcessError(const std::string& msg) : runtime_error(msg.c_str()) {}
