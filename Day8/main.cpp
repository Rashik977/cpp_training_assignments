#include <iostream>
#include "logger.h"
#include "let.h"

int main()
{

    Let a = 10;
    Let b = 20;

    Let two = "there";
    Let one = "Hello0000";

    Let three = two - one;

    ConsoleLogger logger;

    LoggingDecorator loggingLet1(a, logger);
    LoggingDecorator loggingLet2(b, logger);

    LoggingDecorator result = loggingLet1 - loggingLet2;
    std::cout << result << std::endl;
    return 0;
}