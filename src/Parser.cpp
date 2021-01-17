#include "Parser.h"

Parser::Parser(list<Token> tokens) : tokens(tokens)
{
}

Node Parser::parse()
{
    StandartNode topLevelNode;
    topLevelNode.name = TOP_LEVEL;

    for (auto it = tokens.cbegin(); it != tokens.cend(); ++it)
    {
        Token currentToken = *it;
        
    }

    return topLevelNode;
}
