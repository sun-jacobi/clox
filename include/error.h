#ifndef LOX_ERR_H
#define LOX_ERR_H

#include <string>
class Logger {
public: 
    static void report(int line, std::string message);
};

#endif