class CString1 : public CString
{
    public:
        CString1();
        CString1(string text);
        CString1(Line line);
        CString1(const char* second);
        CString1& operator=(const char* second);
        void output(const char *FileName = NULL);
        using CString::operator=;
        CString1(const CString& second);
};