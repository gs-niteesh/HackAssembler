#pragma once
#include "header.h"
#include "util.h"

class Parser
{
private:
    std::fstream &stream;
public:
    Parser(std::fstream &);
    std::string readline();
    void run();
    INSTRUCTION command(std::string &);
    ~Parser();
private:
    void sanitize(std::string &);
    void parse_command(std::string &, INSTRUCTION &);
};