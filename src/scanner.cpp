#include <scanner.h>


void Scanner::addToken(TokenType ty) {
    auto token = new Token(ty, line);
    tokens.push_back(token);
}

void Scanner::addToken(TokenType ty, std::string lit) {
    auto token = new Token(ty, lit, line);
    tokens.push_back(token);
}


Scanner::Scanner(std::string code) :code(code), tokens(0) {}

std::vector<Token*> Scanner::scanTokens(){ 
    while (!isAtEnd()) {
        char c = pop();
        switch (c) { 
        case ' ' : 
        case '\t' : 
        case '\r' : break;
        case '\n' : line++; break;
        case '(' : addToken(TokenType::OpenParen); break;
        case ')' : addToken(TokenType::CloseParen); break;
        case '{' : addToken(TokenType::OpenCur); break;
        case '}' : addToken(TokenType::CloseCur); break;
        case ';' : addToken(TokenType::SemiCol); break;
        case '.' : addToken(TokenType::Dot); break;
        case ',' : addToken(TokenType::Comma); break;
        case '*' : addToken(TokenType::Star); break;
        case '+' : addToken(TokenType::Add); break;
        case '!' : 
            if (match('=')) {
                addToken(TokenType::NotEq); 
            } else {
                addToken(TokenType::Excla);
            }
            break;
        case '=' : 
            if (match('=')) {
                addToken(TokenType::DoubleEq);
            } else {
                addToken(TokenType::Eq); 
            }
            break;
        case '<' : 
            if (match('=')) {
                addToken(TokenType::Leq);
            } else {
                addToken(TokenType::Lt); 
            }
            break;
        case '>' : 
            if (match('=')) {
                addToken(TokenType::Geq);
            } else {
                addToken(TokenType::Gt); 
            }
            break;
        case '/' : 
            if (match('/')) {
                commentOut();
            } else {
                addToken(TokenType::Slash);
            }
            break;
        case '"' :
            addToken(TokenType::Str, consumeStr());
            break;
        default:
            Logger::report(line, "unexpected character");
        }
    } 
    return tokens;
} 

bool Scanner::match(char expected) {
    if (isAtEnd()) {
        return false;
    } 
    if (peek() == expected) {
        pop(); 
        return true;
    } else {
        return false;
    }

}


char Scanner::peek() {
    if (isAtEnd()) return '\0';
    return code[curr];
}

char Scanner::pop() {
    return code[curr++];
}

bool Scanner::isAtEnd() {
    return curr >= code.length();
} 



void Scanner::commentOut() {
    while(!isAtEnd() && !match('\n')) {
        pop();
    }
}

std::string Scanner::consumeStr() {
    std::string str = "";
    while(!isAtEnd() && !match('"')) {
        str.push_back(pop());
    }
    return str;
}







