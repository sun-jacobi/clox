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


Scanner::Scanner(std::string code) :code(code), tokens(0) {
    keywords["and"] =  TokenType::AND; 
    keywords["or"] =  TokenType::OR; 
    
    
    keywords["else"] =  TokenType::ELSE;
    keywords["func"] =  TokenType::FUN; 
    keywords["for"] =  TokenType::FOR; 
    keywords["while"] =  TokenType::WHILE; 
    keywords["if"] =  TokenType::IF; 
    keywords["nil"] =  TokenType::NIL; 
    
    keywords["return"] =  TokenType::RETURN; 
    keywords["true"] =  TokenType::TRUE; 
    keywords["false"] =  TokenType::FALSE; 
    keywords["var"] =  TokenType::VAR; 

    keywords["class"] =  TokenType::CLASS;
    keywords["super"] =  TokenType::SUPER;
    keywords["this"] =  TokenType::THIS;
    keywords["print"] =  TokenType::PRINT;
    
}

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
                addToken(TokenType::Integer, comsumeInt(c)); 
                break;// current only support integer
            }
            if (isAlpha(c)) {
                auto word = consumeWord(c);
                if (keywords.find(word) != keywords.end()) addToken(keywords[word]);
                else addToken(TokenType::Ident, word);
                break;
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


bool Scanner::isAlpha(char c) {
    return ((c >= 'a' && c <= 'z') 
            || (c >= 'A' && c <= 'Z') 
            || c == '_');
}

bool Scanner::isAlphaDigit(char c) {
    return isalpha(c) || isDigit(c);
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



std::string Scanner::consumeWord(char c) {
    std::string word = "";
    word.push_back(c);
    while(!isAtEnd() && isAlphaDigit(peek())) {
        word.push_back(pop());
    }
    return word;
}

int  Scanner::comsumeInt(char c) {
    std::string str = "";
    str.push_back(c);
    while(!isAtEnd() && isdigit(peek())) {
        str.push_back(pop());
    }
    
    return std::stoi(str);
}






