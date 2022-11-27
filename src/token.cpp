#include <token.h>


Token::Token(TokenType ty, std::string lit, int line) : ty(ty), lit(lit), line(line) {}

Token::Token(TokenType ty, int line) : ty(ty),line(line) {}


Token::Token(TokenType ty , int value, int line) : ty(ty), val(value), line(line) {}
    
std::string Token::type() {
    switch (ty) {
        case(TokenType::Add) : return "+";
        case(TokenType::Star) : return "*";
        case(TokenType::DoubleEq) : return "==";
        case(TokenType::Eq) : return "=";
        case(TokenType::Str) : return "string";
        case(TokenType::Integer) : return "integer";
        case(TokenType::OR) : return "or";
        case(TokenType::Ident) : return "variable";
        default: return "";
    }
    
}


std::string Token::literal() {
    switch (ty) {
        case(TokenType::Ident) : 
        case(TokenType::Str) : return lit;    
        default: return "";
    }
}


int Token::value() {
    return val;
}

