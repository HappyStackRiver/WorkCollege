#ifndef _MEMORY_ALREADY_ALLOCATED_EXCEPTION_H
#define _MEMORY_ALREADY_ALLOCATED_EXCEPTION_H

#include <stdexcept>
using namespace std;

class MemoryAlreadyAllocatedException : public runtime_error
{
public:
    MemoryAlreadyAllocatedException(string errorMessage) : runtime_error(errorMessage.c_str()) { /* nothing else to do */ }
};

#endif
