#include <iostream>
#include <list>
#include <string>
#include "Token.h"
#include "Node.h"

#ifndef PARSER_H
#define PARSER_H

class Parser
{
public:
    Parser(list<Token> tokens);
    Node parse();
private:
    list<Token> tokens;
};

#endif
