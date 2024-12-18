
#include <iostream>
#include <string.h>

enum class LetType
{
    Char,
    Int,
    Double
};
class Let
{
public:
    Let(const char *str)
    {
        type = LetType::Char;
        m_str = new char[strlen(str) + 1];
        for (int i = 0; i < strlen(str); i++)
        {
            m_str[i] = str[i];
        }
    };

    Let(int i)
    {
        type = LetType::Int;
        m_i = i;
    };

    Let(double d)
    {
        type = LetType::Double;
        m_d = d;
    };

    Let &operator+(int num)
    {
        m_i += num;
        return *this;
    };

    Let &operator+=(int num)
    {
        m_i += num;
        return *this;
    }

    Let &operator+(const char *newStr)
    {
        if (type == LetType::Char)
        {
            int length = strlen(m_str) + strlen(newStr) + 1;
            char *temp = new char(length);
            strcpy(temp, m_str);
            strcat(temp, newStr);

            delete[] m_str;
            m_str = temp;
        }
        return *this;
    };

    Let &operator+(double num)
    {
        m_d += num;
        return *this;
    };

    Let &operator+=(double num)
    {
        m_d += num;
        return *this;
    }

    ~Let()
    {
        if (type == LetType::Char)
        {
            delete[] m_str;
        }
    };

    friend std::ostream &operator<<(std::ostream &os, const Let &let);

private:
    LetType type;
    char *m_str;
    int m_i = 0;
    double m_d = 0.0;
};

std::ostream &operator<<(std::ostream &os, const Let &let)
{
    if (let.type == LetType::Int)
    {
        os << let.m_i;
    }
    else if (let.type == LetType::Double)
    {
        os << let.m_d;
    }
    else
    {
        os << let.m_str;
    }
    return os;
};

int main()
{

    Let a = 1;
    Let d = 35.5;
    Let s = "hello";

    s = s + " there";

    a += 5;
    d += 5.5;

    std::cout << s << std::endl;
    std::cout << d << std::endl;
    std::cout << a << std::endl;
};
