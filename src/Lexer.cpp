#include "Lexer.h"


Lexer::Lexer(string input) : input(input)
{
}

char Lexer::read() 
{
    if (position < input.length()) {
        char_ = input[position];
        position++;
    } else {
        char_ = 0;
    }
    return char_;
}

bool Lexer::isDigit(char char_) 
{
    return char_ >= '0' && char_ <= '9';
}

bool Lexer::isLetter(char char_) {
    return char_ >= 'A' && char_ <= 'Z' ||
        char_ >= 'a' && char_ <= 'z' ||
        char_ == '_';
}

Token Lexer::readNumber()
{
    Token token = {INT};
    int returnPosition = position;

loop:
    while (isDigit(char_))
    {
        token.literal += string(1, char_);
        returnPosition = position;
        read();
    }

    if (char_ == '.')
    {
        if (isDigit(read()) && token.type != FLOAT)
        {
            token.type = FLOAT;
            token.literal += ".";
            goto loop;
        }
        else
        {
            token.type = ILLEGAL;
        }
    }
    position = returnPosition;

    return token;
}

Token Lexer::readIndentifier()
{
    Token token = {IDENT};
    int returnPosition = position;

    while (isLetter(char_) || isDigit(char_))
    {
        token.literal += string(1, char_);
        returnPosition = position;
        read();
    }
    position = returnPosition;

    return token;
}

Token Lexer::readString(char startChar)
{
    Token token = {STRING};

    while (read() != startChar)
    {
        if (char_ == 0)
        {
            cout << "Unexcepted EOF" << endl;
            break;
        }
        token.literal += string(1, char_);
    }
    
    return token;
}

list<Token> Lexer::tokenize()
{
    list<Token> tokens;

    while (true)
    {
        switch (read())
        {
        case ' ':
        case '\n':
        case '\t':
        case '\v':
        case '\r':
            break;
        case '+':
            if (read() == '=')
            {
                tokens.push_back(Token{ADDa});
            }
            else
            {
                position--;
                tokens.push_back(Token{ADD});
            }
            break;
        case '-':
            if (read() == '=')
            {
                tokens.push_back(Token{SUBa});
            }
            else
            {
                position--;
                tokens.push_back(Token{SUB});
            }
            break;
        case '*':
            if (read() == '=')
            {
                tokens.push_back(Token{MULa});
            }
            else
            {
                position--;
                tokens.push_back(Token{MUL});
            }
            break;
        case '/':
            if (read() == '=')
            {
                tokens.push_back(Token{DIVa});
            }
            else
            {
                position--;
                tokens.push_back(Token{DIV});
            }
            break;
        case '%':
            if (read() == '=')
            {
                tokens.push_back(Token{MODa});
            }
            else
            {
                position--;
                tokens.push_back(Token{MOD});
            }
            break;
        case '^':
            if (read() == '=')
            {
                tokens.push_back(Token{POWa});
            }
            else
            {
                position--;
                tokens.push_back(Token{POW});
            }
            break;
        case '=':
            if (read() == '=')
            {
                tokens.push_back(Token{EQU});
            }
            else
            {
                position--;
                tokens.push_back(Token{ASS});
            }
            break;
        case '>':
            if (read() == '=')
            {
                tokens.push_back(Token{LARe});
            }
            else
            {
                position--;
                tokens.push_back(Token{LAR});
            }
            break;
        case '<':
            if (read() == '=')
            {
                tokens.push_back(Token{LESe});
            }
            else
            {
                position--;
                tokens.push_back(Token{LES});
            }
            break;
        case '!':
            if (read() == '=')
            {
                tokens.push_back(Token{NOTe});
            }
            else
            {
                position--;
                tokens.push_back(Token{NOT});
            }
            break;
        case '&':
            if (read() == '&')
            {
                tokens.push_back(Token{AND});
            }
            else
            {
                position--;
                // tokens.push_back(Token{BitAND});
            }
            break;
        case '|':
            if (read() == '|')
            {
                tokens.push_back(Token{OR});
            }
            else
            {
                position--;
                // tokens.push_back(Token{BitOR});
            }
            break;
        case '(':
            tokens.push_back(Token{LPAREN});
            break;
        case ')':
            tokens.push_back(Token{RPAREN});
            break;
        case '{':
            tokens.push_back(Token{LBRACE});
            break;
        case '}':
            tokens.push_back(Token{RBRACE});
            break;
        case ':':
            tokens.push_back(Token{COLON});
            break;
        case ';':
            tokens.push_back(Token{SEMICOLON});
            break;
        case ',':
        	tokens.push_back(Token{COMMA});
        	break;
        case '\'':
        case '"':
            tokens.push_back(readString(char_));
            break;
        case 0:
            return tokens;
        default:
            if (isLetter(char_))
            {
                tokens.push_back(readIndentifier());
            } 
            else if (isDigit(char_))
            {
                tokens.push_back(readNumber());
            }
        }
    }
}
