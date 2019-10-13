#pragma once
#include "header.h"
#include "SymbolTable.h"

class CodeGenerator
{
private:
    SymbolTable &symbols;
    int last_variable {16}; 
    std::fstream &output;
public:
    CodeGenerator(SymbolTable &, std::fstream &);
    void generate(INSTRUCTION &);
    ~CodeGenerator();
};