#include "CString.hpp"
#include "CString0.hpp"
#include "factory.hpp"
#include "CString0factory.hpp"

CString* CString0Factory::createString(Line line)
{ 
    return new CString0(line); 
}