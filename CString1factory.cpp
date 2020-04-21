#include "CString.hpp"
#include "CString1.hpp"
#include "factory.hpp"
#include "CString1factory.hpp"

CString* CString1factory::createString(Line line)
{ 
    return new CString1(line); 
}