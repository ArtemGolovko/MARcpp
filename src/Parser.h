#include <iostream>
#include <vector>
#include <string>
#include "Token.h"
#include "Node.h"

#ifndef PARSER_H
#define PARSER_H

class Parser
{
public:
    Parser(vector<Token> tokens);
    Node parse();
private:
    vector<Token> tokens;
};

#endif
