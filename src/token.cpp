#include <token.h>


Token::Token(TokenType ty, std::string lit, int line) : ty(ty), lit(lit), line(line) {}

Token::Token(TokenType ty, int line) : ty(ty),line(line) {}
    
std::string Token::type() {
    switch (ty) {
        case(TokenType::Add) : return "+";
        case(TokenType::Star) : return "*";
        default: return "";
    }
}