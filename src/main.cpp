#include <iostream>
#include "Repl.h"

using namespace std;

int main(int argc, char **argv)
{
    if (argc > 1) {
        Repl::readFile(argv[1]);
        return 0;
    }

    Repl::start();

    return 0;
}