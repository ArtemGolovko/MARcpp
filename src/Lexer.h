#include <iostream>
#include <string>
#include <list>
#include "Token.h"

using namespace std;


#ifndef LEXER_H
#define LEXER_H

class Lexer
{
private:
    string input;
    int position = 0;
    char char_ = 0;

    char read();
    Token readNumber();
    Token readIndentifier();
    Token readString(char startChar);
    bool isLetter(char char_);
    bool isDigit(char char_);
public:
    Lexer(string code);
    list<Token> tokenize();
};

#endif
