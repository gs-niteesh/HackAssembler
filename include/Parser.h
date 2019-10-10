#pragma once
#include "header.h"
#include "SymbolTable.h"
#include "util.h"

class Parser
{
private:
    std::fstream &stream;
public:
    Parser(std::fstream &);
    bool has_commands();
    INSTRUCTION command();
    ~Parser();
private:
    std::string readline();
    void sanitize(std::string &);
    void parse_command(std::string &, INSTRUCTION &);
};