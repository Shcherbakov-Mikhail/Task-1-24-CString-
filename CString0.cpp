#include "CString.hpp"
#include "CString0.hpp"
#include "CString1.hpp"

CString0::CString0(): CString(""){}

CString0::CString0(string text): CString(text){}

CString0::CString0(Line line): CString(line){}

CString0::CString0(const char* second)
{
    string tmp(second);
    str = tmp;
    len = static_cast<int>(tmp.length());
}

CString0& CString0::operator=(const char* second)
{
    string tmp(second);
    str = tmp;
    len = static_cast<int>(str.length());
    return *this;
}

void CString0::output(const char *FileName)
{
    isFabric = false;
    if (FileName == NULL)
    {
        isFabric = true;
        FileName = fname.c_str();
    }

    ofstream file(FileName);
    vector<string> arr;
    string word = "";
    string str;

    if (isFabric) {str = line.Data; }
    else {str = this->str; }

    for (int i = 0; i < static_cast<int>(str.length()); i++)
    {
        if (str[i] == ' ')
        {
            arr.push_back(word);
            word = "";
            continue;
        }
        if (i == (static_cast<int>(str.length())-1) && str[i] != ' ')
        {
            word += str[i];
            arr.push_back(word);
        }
        else
        {
            word += str[i];
        }
    }
    for (int i = 0; i < static_cast<int>(arr.size()); i++)
    {
        file << arr[i] << " ";
    }
}