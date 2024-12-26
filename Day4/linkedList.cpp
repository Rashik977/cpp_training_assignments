#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node *next;
};

template <typename T>
class LinkedList
{
public:
    void insert(T data)
    {
        Node<T> *newNode = new Node<T>();
        newNode->data = data;
        if (head)
        {
            Node<T> *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        else
        {
            head = newNode;
        }
    }

    ~LinkedList()
    {
        Node<T> *temp = head;
        while (temp)
        {
            Node<T> *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

    template <typename U>
    friend std::ostream &operator<<(std::ostream &stream, const LinkedList<U> &ll);

private:
    Node<T> *head = nullptr;
};

template <typename T>
std::ostream &operator<<(std::ostream &stream, const LinkedList<T> &ll)
{
    Node<T> *temp = ll.head;
    while (temp)
    {
        stream << "[" << temp->data << "]";
        if (temp->next)
        {
            stream << " => ";
        }
        temp = temp->next;
    }
    return stream;
}

int main()
{
    LinkedList<int> ll;

    ll.insert(10);
    ll.insert(20);
    ll.insert(30);
    ll.insert(40);
    ll.insert(50);

    std::cout << ll << std::endl;

    return 0;
}