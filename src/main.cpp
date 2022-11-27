#include <iostream>
#include <string>
#include <vector> 
#include <token.h>
#include <scanner.h>

using namespace std;

class Lox {
public:
    static void runFile(string script) {
        cout << script << endl;
    }

    static void runLine(string code) {
        Scanner scanner(code); 
        auto tokens = scanner.scanTokens(); 
        cout << code << endl;
        for (auto token : tokens) {
            cout << "type " << token->type()  <<  endl;
            cout << "literal " << token->literal() << endl;
            cout << "value " << token->value() << endl;
        }
    }
    static void repl() {
        while(true) {
        cout << ">>";
        string code; 
        getline(cin, code);
        runLine(code);
        }
    };
};


int main(int argc, char** argv) {
    if (argc > 2) {
        cout << "Usage: clox [script]";
    } else if (argc == 2) {
        string script  = argv[1];
        Lox::runFile(script);
    } else {
        Lox::repl();
    }
}