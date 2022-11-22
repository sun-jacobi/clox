#include <error.h>
#include <iostream>


void Logger::report(int line, std::string message) {
    std::cerr << "[" << line << "] Error: "; 
    std::cerr << message << std::endl;
}


 