class CString1 : public CString
{
    private:
        string fname = "";
    public:
        CString1();
        CString1(string text);
        void set_fname(string FileName);
        virtual int output(const char *FileName);
};