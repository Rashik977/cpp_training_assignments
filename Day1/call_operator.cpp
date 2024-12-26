#include <iostream>
#include <string>

class Greeting
{
private:
    std::string name;
    int times;

public:
    Greeting(const std::string &name, int times) : name(name), times(times) {}

    // Overload call operator
    void operator()() const
    {
        for (int i = 0; i < times; ++i)
        {
            std::cout << "Hello, " << name << "!" << std::endl;
        }
    }
    ~Greeting() {}
};

int main()
{

    Greeting greet("Rashik", 3);

    // Invoking the call operator
    greet();

    return 0;
}
