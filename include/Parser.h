#pragma once
#include "header.h"

class Parser
{
private:
    std::fstream &stream;
public:
    Parser(std::fstream &);
    std::string readline();
    void run();
    ~Parser();
private:
    void sanitize(std::string &);
};