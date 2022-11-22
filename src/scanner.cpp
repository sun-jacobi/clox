#include <scanner.h>


void Scanner::addToken(TokenType ty) {
    auto token = new Token(ty, line);
    tokens.push_back(token);
}

Scanner::Scanner(std::string code) :code(code), tokens(0) {}

std::vector<Token*> Scanner::scanTokens(){ 
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
            Logger::report(line, "unexpected character");
        }
    } 
    return tokens;
} 


char Scanner::peek() {
        return code[curr];
}

char Scanner::pop() {
    return code[curr++];
}

bool Scanner::isAtEnd() {
    return curr >= code.length();
} 




