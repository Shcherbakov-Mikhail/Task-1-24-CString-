#include "CString.hpp"
#include "CString0.hpp"
#include "CString1.hpp"

CString1::CString1(): CString(""){}

CString1::CString1(string text): CString(text){}

CString1::CString1(Line line): CString(line){}

CString1::CString1(const char* second)
{
    string tmp(second);
    str = tmp;
    len = static_cast<int>(tmp.length());
}

CString1& CString1::operator=(const char* second)
{
    string tmp(second);
    str = tmp;
    len = static_cast<int>(str.length());
    return *this;
}

void CString1::output(const char *FileName = NULL)
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
        file << arr[i] << endl;
    }
}