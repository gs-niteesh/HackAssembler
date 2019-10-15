#include "CodeGenerator.h"
#include "Parser.h"
#include "SymbolTable.h"
#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::fstream;
using std::string;
using std::stringstream;

int main(int argc, char **argv)
{

    string input, testin;
    handle_arguments(argc, argv, input, testin);

    fstream instream(input, std::ios::in);
    fstream output("test_output.hack", std::ios::out | std::ios::trunc);
    fstream teststream(testin, std::ios::in);

    SymbolTable table(instream);
    table.look_for_lables();
    Parser p(instream);
    CodeGenerator cgen(table, output);

    while (p.has_commands())
    {
        INSTRUCTION isnt = p.command();
        if (isnt.type == INSTRUCTION_TYPE::INVALID)
            continue;
        cgen.generate(isnt);
    }
    bool failed = failed;
    output.close();
    output.open("test_output.hack", std::ios::in);
    while (teststream and output)
    {
        string one, two;
        output >> one;
        teststream >> two;
        if (two != one)
        {
            std::cout << "TEST FAILED: (expected) " << two << " (output)" << one << endl;
            failed = true;
        }
    }
    if(!failed)
        std::cout << "Passed all" << std::endl;

    return 0;
}
