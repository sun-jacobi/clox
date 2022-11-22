

#ifndef TOKEN_H
#define TOKEN_H

#include <string>


enum TokenType {
    Add, 
    Minus, 
    Star, 
    Slash, 
    Lt,
    Gt,
    Geq,
    Leq,
    NotEq,
    DoubleEq,
    Eq,
    OpenParen,  // (
    CloseParen, // )
    OpenCur,    // {
    CloseCur,   // }
    Comma,
    SemiCol, // ; 
    And, // &

    // Literals
    Ident, Str, Num,  
    // KEYWORLD
    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,
    // EOF 
    End, 
};

class Token {

private : 
    TokenType ty; 
    std::string lit = ""; 
    int val = 0; // when Token is a number 
    int line; 

public: 
    Token(TokenType ty, std::string lit, int line) : ty(ty), lit(lit), line(line) {}
    Token(TokenType ty, int line) : ty(ty),line(line) {}
    std::string type() {
        switch (ty) {
            case(TokenType::Add) : return "+";
            case(TokenType::Star) : return "*";
            default: return "";
        }
    }
};
#endif