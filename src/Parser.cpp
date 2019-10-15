#include "Parser.h"

Parser::Parser(std::fstream &stream) : stream(stream)
{
    stream.clear();
    stream.seekg(0, std::ios::beg);
}

bool Parser::has_commands()
{
    return !stream.eof();
}

std::string Parser::readline()
{
    std::string result;
    std::getline(stream, result);
    sanitize(result);
    return result;
}

INSTRUCTION Parser::command()
{
    std::string line = readline();
    if (line == "")
        return {.type = INSTRUCTION_TYPE::INVALID};

    INSTRUCTION inst;

    switch (line[0])
    {
    case '@':
        inst.type = INSTRUCTION_TYPE::A_TYPE;
        inst.a_value = line.substr(1);
        break;
    case '(':
        inst.type = INSTRUCTION_TYPE::L_TYPE;
        inst.label = line.substr(1, line.size() - 2);
        break;
    default:
        inst.type = INSTRUCTION_TYPE::C_TYPE;
        parse_C_command(line, inst);
        break;
    }

    return inst;
}

/*
    Strips comments, whitespaces and newlines from the lineP
*/
void Parser::sanitize(std::string &line)
{
    std::size_t size = line.size();
    std::size_t pos = line.find_first_of("//");
    if (pos != std::string::npos)
    {
        line.erase(pos, size);
    }
    pos = line.find_first_of('\r');
    if (pos != std::string::npos)
    {
        line.erase(pos, size);
    }
    pos = line.find_first_not_of(" \r\t\n");
    if (pos != std::string::npos)
    {
        line.erase(0, pos);
    }
    pos = line.find_last_not_of(" \r\t\n");
    if (pos != std::string::npos)
    {
        line.erase(pos + 1, size);
    }
}

void Parser::parse_C_command(std::string &line, INSTRUCTION &inst)
{
    std::size_t eq_pos = line.find('=');
    std::size_t semi_pos = line.find(";");

    if (eq_pos != std::string::npos)
    {
        inst.dest_value = line.substr(0, eq_pos);
        if (semi_pos != std::string::npos)
        {
            inst.cmp_value = line.substr(eq_pos+1, semi_pos - eq_pos - 1);
            inst.jmp_value = line.substr(semi_pos+1);
        }else{
            inst.cmp_value = line.substr(eq_pos+1);
        }
    }else{
        inst.cmp_value = line.substr(0, semi_pos);
        inst.jmp_value = line.substr(semi_pos + 1);
    }
    // std::cout << "DEST: " << inst.dest_value << " -- CMP: " << inst.cmp_value << " -- JMP: " << inst.jmp_value << std::endl;
}

Parser::~Parser()
{
}