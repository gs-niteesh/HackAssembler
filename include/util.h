#pragma once
#include "header.h"

#define DEBUG(x) std::cout << #x << ": " << x << std::endl;

enum class INSTRUCTION_TYPE
{
    A_TYPE,      // ( 0 )
    C_TYPE_JMP_ONLY,  // ( 1 ) 0;JMP(DIRECT JUMP)
    C_TYPE_ASSIGN, // ( 2 ) D=D+A (STORING ONLY)
    C_TYPE_COMPLETE, // ( 3 ) COMPLETE C INSTRUCTION
    L_TYPE       // ( 4 )
};

struct INSTRUCTION
{
    INSTRUCTION_TYPE type;
    char a_value[16];
    char dest_value[16];
    char cmp_value[16];
    char jmp_value[16];
    char label[16];
};

void error(const std::string &err);

void handle_arguments(int argc, char **argv, std::string &source, std::string &output);