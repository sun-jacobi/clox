
#ifndef SCANNER_H
#define SCANNER_H
#include <token.h>
#include <vector>
#include <string>
//--------
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
    void commentOut();
    std::string consumeStr(); 
    bool isAtEnd();
    bool match(char);
public: 
    Scanner(std::string);

    void addToken(TokenType);
    void addToken(TokenType, std::string);

    std::vector<Token*> scanTokens();
   
}; 


#endif