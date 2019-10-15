#include "CodeGenerator.h"

CodeGenerator::CodeGenerator(SymbolTable &symbols, std::ostream &output) : symbols(symbols),
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
                sscanf(inst.a_value.c_str(), "%d", &x);
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
        if (inst.dest_value == "")
        {
            instruction += symbols.get_cmps(inst.cmp_value) + "000" + symbols.get_jmp(inst.jmp_value);
        }
        else if (inst.jmp_value == "")
        {
            instruction += symbols.get_cmps(inst.cmp_value) + symbols.get_dest(inst.dest_value) + "000";
        }
        else
        {
            instruction += symbols.get_cmps(inst.cmp_value) + symbols.get_dest(inst.dest_value) + symbols.get_jmp(inst.jmp_value);
        }
    }
    if (inst.type != INSTRUCTION_TYPE::L_TYPE)
        output << instruction << std::endl;
}

CodeGenerator::~CodeGenerator()
{
}
