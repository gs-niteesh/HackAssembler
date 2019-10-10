#pragma once
#include "header.h"

class CodeGenerator
{
private:
    const SymbolTable labels; 
    std::fstream output;
public:
    CodeGenerator(const SymbolTable &, std::fstream &);
    ~CodeGenerator();
};