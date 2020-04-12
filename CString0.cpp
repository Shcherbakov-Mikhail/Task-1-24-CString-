#include "CString.hpp"
#include "CString0.hpp"
#include "CString1.hpp"

        //fname = "";
        CString0::CString0() : CString(""){}
        CString0::CString0(string text) : CString(text){}
        void  CString0::set_fname(string FileName)
        {
            fname = FileName;
        } 
        int  CString0::output(const char *FileName)
        {
            ofstream file(fname);
            vector<string> arr;
            string word = "";
            string str = CString::get_string();
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
            return 0;
        }