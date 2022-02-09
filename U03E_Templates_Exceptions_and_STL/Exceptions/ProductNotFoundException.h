#ifndef _PRODUCT_NOT_FOUND_EXCEPTION_H
#define _PRODUCT_NOT_FOUND_EXCEPTION_H

#include <stdexcept>
using namespace std;

class ProductNotFoundException : public runtime_error
{
public:
    ProductNotFoundException(string errorMessage) : runtime_error(errorMessage.c_str()) { /* nothing else to do */ }
};

#endif
