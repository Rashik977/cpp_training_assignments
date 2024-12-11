#include <iostream>

// Define the class
class CallOperator {
private:
    int a, b;  // Data members to hold values

public:
    // Constructor with parameters identical to the call operator
    CallOperator(int x, int y) : a(x), b(y) {
        std::cout << "Constructor called with values a = " << a << " and b = " << b << std::endl;
    }

    // Overload the call operator
    void operator()() {
        std::cout << "Call operator invoked!" << std::endl;
        std::cout << "a + b = " << a + b << std::endl;
    }
};

int main() {
    // Create an object of CallOperator and invoke the constructor
    CallOperator obj(10, 20);

    // Use the call operator by treating the object as a function
    obj();  // Calls operator()

    return 0;
}
