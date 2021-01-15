#include "Repl.h"


void Repl::parse(string code) 
{
    Lexer lexer(code);
    vector<Token> tokens = lexer.tokenize();

    Parser parser(tokens);
    Node ast = parser.parse(); 

    cout << "Tokens:" << endl;
    for (const auto &token: tokens) {
        cout << "[" << token.type << "]";

        if (token.literal != "") {
            cout << ": \"" << token.literal << "\"";
        };

        cout << endl;
    }
}

int Repl::readFile(char* fileName)
{
    ifstream file(fileName, ios_base::in);
    if (!file) {
        cout << "File '" << fileName << "' cannot be open" << endl;
        return -1;
    } else {
        string code((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

        Repl::parse(code);
    }
    return 0;
}

int Repl::start()
{
    string code;

loop:
    cout << "> ";
    getline(cin, code);

    if (code == "") {
        return 0;
    }

    Repl::parse(code);
    goto loop;
}
