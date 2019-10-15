#pragma once
#include "header.h"
#include "SymbolTable.h"

class CodeGenerator
{
private:
    SymbolTable &symbols;
    int last_variable {16}; 
    std::ostream &output;
public:
    CodeGenerator(SymbolTable &, std::ostream &);
    void generate(INSTRUCTION &);
    ~CodeGenerator();
};