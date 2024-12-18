#include <iostream>
#include <string.h>
#include <memory>

enum class DATATYPE
{
    DOUBLE,
    STRING,
    BOOLEN,
    INTEGER
};

class Variant
{
public:
    Variant(int intVar) : m_intVar(intVar), m_type(DATATYPE::INTEGER) {}
    Variant(bool boolVar) : m_boolVar(boolVar), m_type(DATATYPE::BOOLEN) {}
    Variant(double doubleVar) : m_doubleVar(doubleVar), m_type(DATATYPE::DOUBLE) {}

    Variant(const char *str) : m_type(DATATYPE::STRING)
    {
        m_strPtr = new char[strlen(str) + 1];
        strcpy(m_strPtr, str);
    }

    Variant(const Variant &v)
    {
        m_type = v.m_type;
        m_intVar = v.m_intVar;
        m_boolVar = v.m_boolVar;
        m_doubleVar = v.m_doubleVar;
        if (v.m_type == DATATYPE::STRING && v.m_strPtr)
        {
            m_strPtr = new char[strlen(v.m_strPtr)];
            strcpy(m_strPtr, v.m_strPtr);
        }
    }

    ~Variant()
    {
        if (m_strPtr != nullptr)
        {
            delete[] m_strPtr;
        }
    }

    int getIntVar() const { return m_intVar; }
    DATATYPE getType() const { return m_type; }
    bool getBoolVar() const { return m_boolVar; }
    const char *getStrPtr() const { return m_strPtr; }
    double getDoubleVar() const { return m_doubleVar; }

private:
    int m_intVar;
    bool m_boolVar;
    DATATYPE m_type;
    double m_doubleVar;
    char *m_strPtr = nullptr;
};

class Node
{
public:
    Variant v;
    Node *next;
    Node(const Variant v) : v(v), next(nullptr) {}
};

class VariantList
{
public:
    void insert(Variant v)
    {
        Node *node = new Node(v);
        if (head)
        {
            Node *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = node;
        }
        else
        {
            head = node;
        }
    }

    ~VariantList()
    {
        Node *temp = head;
        while (temp)
        {
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

    friend std::ostream &operator<<(std::ostream &stream, const VariantList &vl);

private:
    Node *head = nullptr;
};

std::ostream &operator<<(std::ostream &stream, const VariantList &vl)
{
    Node *temp = vl.head;
    while (temp)
    {
        switch (temp->v.getType())
        {
        case DATATYPE::INTEGER:
            stream << temp->v.getIntVar();
            break;
        case DATATYPE::DOUBLE:
            stream << temp->v.getDoubleVar();
            break;
        case DATATYPE::STRING:
            stream << temp->v.getStrPtr();
            break;
        case DATATYPE::BOOLEN:
            stream << temp->v.getBoolVar();
            break;
        }
        if (temp->next)
        {
            stream << " ===> ";
        }
        temp = temp->next;
    }
    return stream;
}

int main()
{
    std::shared_ptr<VariantList> vl = std::make_shared<VariantList>();
    auto vl2 = vl;

    vl->insert(10);
    vl->insert("Hello");
    vl->insert(false);
    vl->insert(10.25);
    vl->insert(121);

    vl2->insert(420);

    std::cout << *vl << std::endl;
    return 0;
}