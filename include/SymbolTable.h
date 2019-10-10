#pragma once
#include "header.h"

class SymbolTable
{
private:
    std::fstream &stream;
    std::map<std::string, std::string> symbols;
public:
    SymbolTable(std::fstream &);
    void look_for_lables();
    std::string has_label(const std::string &);
    void print_table();
    ~SymbolTable();
};