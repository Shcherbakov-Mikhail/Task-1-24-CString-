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
    
        CString() : len(0), str("null"){ }
        CString(string str) : len(static_cast<int>(str.length())), str(str){ }
        virtual ~CString(){}
        void operator=(string second)
        {
            str = second;
            len = static_cast<int>(str.length());
        }
        void operator=(const CString* second)
        {
            str = second->str;
            len = second->len;
        }
        string get_string()
        {
            return(str);
        }
        virtual int output(const char *FileName = NULL) = 0;
        virtual void set_fname(string FileName = NULL) = 0;
        static CString* createString(Line line);
};

class CString0 : public CString
{
    private:
        string fname = "";
    public:
        CString0() : CString(""){}
        CString0(string text) : CString(text){}
        void set_fname(string FileName)
        {
            fname = FileName;
        } 
        virtual int output(const char *FileName)
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
};

CString0 operator+(const CString& first,const CString& second)
{
    CString0 res;
    res.len = first.len + second.len;
    res.str = first.str + second.str;
    return res;
}

class CString1 : public CString
{
    private:
        string fname = "";
    public:
        CString1() : CString(""){}
        CString1(string text) : CString(text){}
        void set_fname(string FileName)
        {
            fname = FileName;
        }
        virtual int output(const char *FileName)
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
                file << arr[i] << endl;
            }
            return 0;
        }
};

CString* CString::createString(Line line)
{
    CString *p;
    switch(line.I)
    {
        case 0:
            p = new CString0(line.Data);
            p->set_fname(line.Name);
            break;
        case 1:
            p = new CString1(line.Data);
            p->set_fname(line.Name);
            break;
        default:
            assert(false);
    }
    return p;
}

void Test0()
{
    vector<CString*> factory;
    
    // Creating classes from file and filling them with data
    ifstream file;
    Line line;
    int p = 0;
    string stroka;
    file.open("/Users/shcherbakovmikhail/Desktop/data.txt");
    
    while(getline(file,stroka))
    {
          if(stroka[0] == '0')
          {
            line.I = 0;
          }
          else
          {
            line.I = 1;
          }
          
          for (int i = 2; i < stroka.length(); i++)
          {
            if (stroka[i] == ' ')
            {
                p = i + 1;
                break;
            }
            line.Name += stroka[i];
          }
          
          for (int i = p; i < stroka.length(); i++)
          {
            line.Data += stroka[i];
          }
          
          factory.push_back(CString::createString(line));
          
          p = 0;
          line.Data = "";
          line.Name = "";
    }
    file.close();
    
    // Outputting data
    for (int i = 0; i < factory.size(); i++)
    {
        factory[i]->output();
    }
}



void Test1()
{
    CString1 a("Hello, ");
    CString0 b("world!");
    CString0 c;
    
    c = a + b;
    if (c.get_string() == "Hello, world!")
    {
        cout << "TEST1: OK!" << endl;
    }
    else
    {
        cout << "TEST1: FAILED!" << endl;
    }
}

void Test2()
{
    CString0 c;
    string d = "Goodbye, world!";
    
    c = d;
    
    if (c.get_string() == "Goodbye, world!")
    {
        cout << "TEST2: OK!" << endl;
    }
    else
    {
        cout << "TEST2: FAILED!" << endl;
    }
}

int main()
{
    Test0();
    Test1();
    Test2();
    return 0;
}

