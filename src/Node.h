#include <iostream>
#include <vector>

#ifndef NODE_H
#define NODE_H

enum NodeName
{
    TOP_LEVEL,
};

struct Node
{
    NodeName name;
    Node *parent;
};

struct StandartNode : Node
{
    bool _final;
    vector<Node*> childern;
};


#endif