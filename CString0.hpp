class CString0 : public CString
{
    public:
        CString0();
        CString0(string text);
        CString0(Line line);
        CString0(const char* second);
        CString0& operator=(const char* second);
        void output(const char *FileName = NULL);
};