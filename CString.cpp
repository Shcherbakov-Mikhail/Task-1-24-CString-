#include "CString.hpp"
#include "CString0.hpp"
#include "CString1.hpp"


CString::CString(): len(0), str(""), fname(""){ }
CString::CString(string str): len(static_cast<int>(str.length())), str(str), fname(""){ }
CString::CString(Line line): line(line), fname(line.Name){}
CString::CString(const CString& second): len(second.len), str(second.str), fname(second.fname) {}
CString::~CString(){}
CString& CString::operator=(const CString& second)
{
    str = second.str;
    len = second.len;
    return *this;
}     