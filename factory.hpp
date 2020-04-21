class Factory
{
    public:    
        virtual CString* createString(Line line) = 0;
        virtual ~Factory() {}
};