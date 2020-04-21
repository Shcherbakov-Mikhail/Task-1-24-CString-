#include "CString.hpp"
#include "CString0.hpp"
#include "CString1.hpp"
#include "factory.hpp"
#include "CString0factory.hpp"
#include "CString1factory.hpp"
#include "functions.hpp"

CString0 operator+(const CString& first, const CString& second)
{
    CString0 res;
    res.len = first.len + second.len;
    res.str = first.str + second.str;
    return res;
}

void Test1()
{
    vector<CString*> v;
    CString0Factory* CString0_factory = new CString0Factory;
    CString1Factory* CString1_factory = new CString1Factory;

    ifstream file;
    Line line;
    int p = 0;
    string stroka;
    file.open("data.txt");
    //file.open(R"(полный путь к файлу)")
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
          
          if (line.I == 0)
          {
            v.push_back(CString0_factory->createString(line));
          }
          else if (line.I == 1)
          {
            v.push_back(CString1_factory->createString(line));
          }
          
          p = 0;
          line.Data = "";
          line.Name = "";
    }
    file.close();

    for(int i = 0; i < v.size(); i++)
    {
        v[i]->output();
    }

    cout << "TEST1: DONE. CHECK OUTPUT FILES" << endl;
}

void Test2()
{
    CString1 str = "abc";
    str.output("test.txt");
    
    cout << "TEST2: DONE. CHECK OUTPUT FILE" << endl;
}

void Test3()
{
    CString1 a("Hello, ");
    CString0 b("world!");
    CString0 c;
    
    c = a + b;

    if ((a + b).str == "Hello, world!")
    {
        cout << "TEST3: PASSED!" << endl;
    }
    else
    {
        cout << "TEST3: FAILED!" << endl;
    }
}

void Test4()
{
    CString0 c;
    string d = "Goodbye, world!";
    
    c = d;
    
    if (c.str == "Goodbye, world!")
    {
        cout << "TEST4: PASSED!" << endl;
    }
    else
    {
        cout << "TEST2: FAILED!" << endl;
    }
}