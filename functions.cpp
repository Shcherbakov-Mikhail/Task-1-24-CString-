#include "CString.hpp"
#include "CString0.hpp"
#include "CString1.hpp"
#include "functions.hpp"

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
            break;
    }
    return p;
}

CString0 operator+(const CString& first,const CString& second)
{
    CString0 res;
    res.len = first.len + second.len;
    res.str = first.str + second.str;
    return res;
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
          
          for (int i = 2; i < static_cast<int>(stroka.length()); i++)
          {
            if (stroka[i] == ' ')
            {
                p = i + 1;
                break;
            }
            line.Name += stroka[i];
          }
          
          for (int i = p; i < static_cast<int>(stroka.length()); i++)
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
    for (int i = 0; i < static_cast<int>(factory.size()); i++)
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
