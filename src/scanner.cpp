#include <scanner.h>


void Scanner::addToken(TokenType ty) {
    auto token = new Token(ty, line);
    tokens.push_back(token);
}

void Scanner::addToken(TokenType ty, std::string lit) {
    auto token = new Token(ty, lit, line);
    tokens.push_back(token);
}


void Scanner::addToken(TokenType ty, int val) {
    auto token = new Token(ty, val, line);
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
            if (isDigit(c)) {
                addToken(TokenType::Integer, comsumeInt(c)); // current only support integer
            }
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




// read the current token but not advance
char Scanner::peek() {
    if (isAtEnd()) return '\0';
    return code[curr];
}

// read the current token but advance
char Scanner::pop() {
    return code[curr++];
}

bool Scanner::isAtEnd() {
    return curr >= code.length();
} 

bool Scanner::isDigit(char c) {
    return (c >= '0' && c <= '9');
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

int  Scanner::comsumeInt(char c) {
    std::string str = "";
    str.push_back(c);
    while(!isAtEnd() && isdigit(peek())) {
        str.push_back(pop());
    }
    
    return std::stoi(str);
}






