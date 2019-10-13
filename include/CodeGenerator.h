#pragma once
#include "header.h"
#include "SymbolTable.h"

class CodeGenerator
{
private:
    const SymbolTable &symbols;
    int last_variable {16}; 
    std::fstream &output;
public:
    CodeGenerator(const SymbolTable &, std::fstream &);
    void generate(INSTRUCTION &);
    ~CodeGenerator();
};