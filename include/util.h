#pragma once
#include "header.h"

#define DEBUG(x) std::cout << #x << ": " << x << std::endl;

enum class INSTRUCTION_TYPE
{
    A_TYPE,      // ( 0 )
    C_TYPE,
    L_TYPE,       // ( 4 )
    INVALID
};

struct INSTRUCTION
{
    INSTRUCTION_TYPE type = INSTRUCTION_TYPE::INVALID;
    std::string a_value = "";
    std::string dest_value = "";
    std::string cmp_value = "";
    std::string jmp_value = "";
    std::string label = "";
};

void error(const std::string &);

void handle_arguments(int, char **, std::string &, std::string &);

std::string binary(int);

bool is_digits(const std::string &);