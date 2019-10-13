#include "CodeGenerator.h"

CodeGenerator::CodeGenerator(SymbolTable &symbols, std::fstream &output) : symbols(symbols),
                                                                                 output(output)
{
}

void CodeGenerator::generate(INSTRUCTION &inst)
{
    std::string instruction;
    int x;
    if (inst.type == INSTRUCTION_TYPE::A_TYPE)
    {
        if (!symbols.has_label(inst.a_value))
        {
            if (is_digits(inst.a_value))
                sscanf(inst.a_value, "%d", &x);
            else
            {
                x = last_variable++;
                symbols.add_label(inst.a_value, x);
            }
        }
        else
        {
            sscanf(symbols.get_label(inst.a_value).c_str(), "%d", &x);
        }
        instruction += binary(x);
    }
    else
    {
        instruction = "111";
        if (inst.type == INSTRUCTION_TYPE::C_TYPE_JMP_ONLY)
        {
            instruction += symbols.get_cmps(inst.cmp_value) + "000" + symbols.get_jmp(inst.jmp_value);
        }
        else if (inst.type == INSTRUCTION_TYPE::C_TYPE_ASSIGN)
        {
            instruction += symbols.get_cmps(inst.cmp_value) + symbols.get_dest(inst.dest_value) + "000";
        }
        else if (inst.type == INSTRUCTION_TYPE::C_TYPE_COMPLETE)
        {
            instruction += symbols.get_cmps(inst.cmp_value) + symbols.get_dest(inst.dest_value) + symbols.get_jmp(inst.jmp_value);
        }
    }
    if (inst.type != INSTRUCTION_TYPE::L_TYPE)
        std::cout << instruction << std::endl;
}

CodeGenerator::~CodeGenerator()
{
}
