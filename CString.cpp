#include "CString.hpp"
#include "CString0.hpp"
#include "CString1.hpp"


CString::CString() : len(0), str("null"){ }
CString::CString(string str) : len(static_cast<int>(str.length())), str(str){ }
CString::~CString(){}
 void CString::operator=(string second)
{
    str = second;
    len = static_cast<int>(str.length());
}
void CString::operator=(const CString* second)
{
    str = second->str;
    len = second->len;
}        
 string CString::get_string()
{
     return(str);
}      