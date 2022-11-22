#ifndef LOX_ERR_H
#define LOX_ERR_H

#include <string>
#include <iostream>


class Logger {
public: 
    static void report(int line, std::string message) {
        std::cerr << "[" << line << "] Error: "; 
         std::cerr << message << std::endl;
    }
};


#endif