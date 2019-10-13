#pragma once
#include "header.h"
#include "SymbolTable.h"

class CodeGenerator
{
private:
    const SymbolTable &symbols; 
    std::fstream &output;
public:
    CodeGenerator(const SymbolTable &, std::fstream &);
    void generate(INSTRUCTION &);
    ~CodeGenerator();
};