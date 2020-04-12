#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

typedef struct Line
{
    int I;
    string Name;
    string Data;
}Line;

class CString{
    public:
        int len;
        string str;
        CString();
        CString(string str);
        virtual ~CString(); 
        void operator=(string second);
        void operator=(const CString* second);
        string get_string();
        virtual int output(const char *FileName = NULL) = 0;
        virtual void set_fname(string FileName = NULL) = 0;
        static CString* createString(Line line);
};