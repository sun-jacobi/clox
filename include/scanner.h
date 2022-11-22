
#ifndef SCANNER_H
#define SCANNER_H
#include <token.h>
#include <vector>
#include <error.h>


class Scanner {
private:
    std::string code; 
    std::vector<Token*> tokens;
    int curr = 0;
    int start = 0; 
    int line = 1; 

    char peek();

    char pop();

    bool isAtEnd();
public: 
    Scanner(std::string code);

    void addToken(TokenType ty);

    std::vector<Token*> scanTokens();
   
}; 


#endif