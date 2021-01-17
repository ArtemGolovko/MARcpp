#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "Lexer.h"
#include "Parser.h"

using namespace std;


#ifndef REPL_H
#define REPL_H

class Repl
{
public:
    static int readFile(char* filename);
    static int start();
    static void parse(string code);
};

#endif
