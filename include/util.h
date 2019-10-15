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
    INSTRUCTION_TYPE type;
    char a_value[36];
    char dest_value[36];
    char cmp_value[36];
    char jmp_value[36];
    char label[36];
};

void error(const std::string &);

void handle_arguments(int, char **, std::string &, std::string &);

std::string binary(int);

bool is_digits(const std::string &);