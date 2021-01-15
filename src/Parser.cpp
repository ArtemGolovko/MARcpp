#include "Parser.h"

Parser::Parser(vector<Token> tokens)
{
    this->tokens = tokens;
}

Node Parser::parse()
{
    StandartNode topLevelNode;
    topLevelNode.name = TOP_LEVEL;

    for (int i = 0; i < this->tokens.size(); i++)
    {
        Token currentToken = this->tokens[i];
        
    }

    return topLevelNode;
}