#ifndef __OPERATOR__
#define __OPERATOR__

class Number
{
private:
    static int m_count;

public:
    Number();

    ~Number();

    Number& operator++();
    Number operator++(int);
    
    int getCount() const;
};

#endif // __OPERATOR__