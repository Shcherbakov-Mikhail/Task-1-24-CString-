class CString0 : public CString
{
    private:
        string fname = "";
    public:
        void set_fname(string FileName);
        CString0();
        CString0(string text);
        virtual int output(const char *FileName);
};