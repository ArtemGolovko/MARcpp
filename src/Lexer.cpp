#include "Lexer.h"


Lexer::Lexer(string code) 
{
    this->input = code;
}

char Lexer::read() 
{
    if (this->position < this->input.length()) {
        this->char_ = input[this->position];
        this->position++;
    } else {
        this->char_ = 0;
    }
    return this->char_;
}

bool Lexer::isDigit(char char_) 
{
    return static_cast<int>(char_) >= static_cast<int>('0') && static_cast<int>(char_) <= static_cast<int>('9');
}

bool Lexer::isLetter(char char_) {
    return static_cast<int>(char_) >= static_cast<int>('A') && static_cast<int>(char_) <= static_cast<int>('Z') ||
        static_cast<int>(char_) >= static_cast<int>('a') && static_cast<int>(char_) <= static_cast<int>('z') ||
        char_ == '_';
}

Token Lexer::readNumber()
{
    Token token = {INT};
    int returnPosition = this->position;

loop:
    while (this->isDigit(this->char_))
    {
        token.literal += string(1, this->char_);
        returnPosition = this->position;
        this->read();
    }

    if (this->char_ == '.')
    {
        if (this->isDigit(this->read()) && token.type != FLOAT)
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
    this->position = returnPosition;

    return token;
}

Token Lexer::readIndentifier()
{
    Token token = {IDENT};
    int returnPosition = this->position;

    while (this->isLetter(this->char_) || this->isDigit(this->char_))
    {
        token.literal += string(1, this->char_);
        returnPosition = this->position;
        this->read();
    }
    this->position = returnPosition;

    return token;
}

Token Lexer::readString(char startChar)
{
    Token token = {STRING};

    while (this->read() != startChar)
    {
        if (this->char_ == 0)
        {
            cout << "Unexcepted EOF" << endl;
            break;
        }
        token.literal += string(1, this->char_);
    }
    
    return token;
}

vector<Token> Lexer::tokenize()
{
    vector<Token> tokens;

    while (true)
    {
        switch (this->read())
        {
        case ' ':
        case '\n':
        case '\t':
        case '\v':
        case '\r':
            break;
        case '+':
            if (this->read() == '=')
            {
                tokens.push_back(Token{ADDa});
            }
            else
            {
                this->position--;
                tokens.push_back(Token{ADD});
            }
            break;
        case '-':
            if (this->read() == '=')
            {
                tokens.push_back(Token{SUBa});
            }
            else
            {
                this->position--;
                tokens.push_back(Token{SUB});
            }
            break;
        case '*':
            if (this->read() == '=')
            {
                tokens.push_back(Token{MULa});
            }
            else
            {
                this->position--;
                tokens.push_back(Token{MUL});
            }
            break;
        case '/':
            if (this->read() == '=')
            {
                tokens.push_back(Token{DIVa});
            }
            else
            {
                this->position--;
                tokens.push_back(Token{DIV});
            }
            break;
        case '%':
            if (this->read() == '=')
            {
                tokens.push_back(Token{MODa});
            }
            else
            {
                this->position--;
                tokens.push_back(Token{MOD});
            }
            break;
        case '^':
            if (this->read() == '=')
            {
                tokens.push_back(Token{POWa});
            }
            else
            {
                this->position--;
                tokens.push_back(Token{POW});
            }
            break;
        case '=':
            if (this->read() == '=')
            {
                tokens.push_back(Token{EQU});
            }
            else
            {
                this->position--;
                tokens.push_back(Token{ASS});
            }
            break;
        case '>':
            if (this->read() == '=')
            {
                tokens.push_back(Token{LARe});
            }
            else
            {
                this->position--;
                tokens.push_back(Token{LAR});
            }
            break;
        case '<':
            if (this->read() == '=')
            {
                tokens.push_back(Token{LESe});
            }
            else
            {
                this->position--;
                tokens.push_back(Token{LES});
            }
            break;
        case '!':
            if (this->read() == '=')
            {
                tokens.push_back(Token{NOTe});
            }
            else
            {
                this->position--;
                tokens.push_back(Token{NOT});
            }
            break;
        case '&':
            if (this->read() == '&')
            {
                tokens.push_back(Token{AND});
            }
            else
            {
                this->position--;
                // tokens.push_back(Token{BitAND});
            }
            break;
        case '|':
            if (this->read() == '|')
            {
                tokens.push_back(Token{OR});
            }
            else
            {
                this->position--;
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
        case '?':
            tokens.push_back(Token{IF});
            break;
        case '\'':
        case '"':
            tokens.push_back(this->readString(this->char_));
            break;
        case 0:
            return tokens;
        default:
            if (this->isLetter(this->char_))
            {
                tokens.push_back(this->readIndentifier());
            } 
            else if (this->isDigit(this->char_))
            {
                tokens.push_back(this->readNumber());
            }
        }
    }
}