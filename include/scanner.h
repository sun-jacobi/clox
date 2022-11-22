
#ifndef SCANNER_H
#define SCANNER_H
#include <token.h>
#include <vector>

class Scanner {
private:
    std::string code; 
    std::vector<Token*> tokens;
    int curr = 0;
    int start = 0; 
    int line = 1; 
public: 
    Scanner(std::string code):code(code), tokens(0){}


    void addToken(TokenType ty) {
        auto token = new Token(ty, line);
        tokens.push_back(token);
    }

    std::vector<Token*> scanTokens(){ 
       while (!isAtEnd()) {
            char c = pop();
            switch (c) { 
            case '(' : addToken(TokenType::OpenParen); break;
            case ')' : addToken(TokenType::CloseParen); break;
            case '{' : addToken(TokenType::OpenCur); break;
            case '}' : addToken(TokenType::CloseCur); break;
            case ';' : addToken(TokenType::SemiCol); break;
            case ',' : addToken(TokenType::Comma); break;
            case '*' : addToken(TokenType::Star); break;
            case '+' : addToken(TokenType::Add); break;
            default:
                break;
            }
       } 
       return tokens;
    } 

    char peek() {
        return code[curr];
    }
    char pop() {
       return code[curr++];
    }

    bool isAtEnd() {
        return curr >= code.length();
    } 
}; 


#endif