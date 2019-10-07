#include "Parser.h"

Parser::Parser(std::fstream &stream) : stream(stream)
{
}

void Parser::run()
{
    while (!stream.eof())
    {
        std::string line = readline();
        if (line == "")
            continue;
        INSTRUCTION instruction = command(line);
    }
}

std::string Parser::readline()
{
    std::string result;
    std::getline(stream, result);
    sanitize(result);
    return result;
}

INSTRUCTION Parser::command(std::string &line)
{
    INSTRUCTION inst;
    switch (line[0])
    {
    case '@':
        inst.type = INSTRUCTION_TYPE::A_TYPE;
        strcpy(inst.a_value, line.substr(1).c_str());
        return inst;
        break;
    case '(':
        inst.type = INSTRUCTION_TYPE::L_TYPE;
        strcpy(inst.label, line.substr(1, line.size() - 1).c_str());
        return inst;
        break;
    default:
        // char buff[line.size()];
        // strcpy(buff, line.c_str());
        // std::vector<std::string> tokens;
        // char *token = strtok(buff, "=;");
        // while(token != NULL){
        //     tokens.emplace_back(token);
        //     token = strtok(NULL, "=;");
        // }
        // DEBUG("///////");
        // DEBUG(line);
        // for(auto i : tokens)
        //     DEBUG(i);
        // DEBUG("///////");
        parse_command(line, inst);
        return inst;
        break;
    }
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

void Parser::parse_command(std::string &line, INSTRUCTION &inst)
{
    std::size_t pos = line.find(';');
    std::string temp;
    if (pos != std::string::npos)
    {
        strcpy(inst.jmp_value, line.substr(pos + 1).c_str());
        temp = line.substr(0, pos);
    }
    else
    {

        strcpy(inst.jmp_value, "---");
        inst.type = INSTRUCTION_TYPE::C_TYPE_ASSIGN;
        temp = line;
    }
    pos = temp.find('=');
    if (pos == std::string::npos)
    {
        strcpy(inst.cmp_value, temp.c_str());
        strcpy(inst.dest_value, "---");
        inst.type = INSTRUCTION_TYPE::C_TYPE_JMP_ONLY;
    }
    else
    {
        strcpy(inst.dest_value, temp.substr(0, pos).c_str());
        strcpy(inst.cmp_value, temp.substr(pos + 1).c_str());
        if (inst.type != INSTRUCTION_TYPE::C_TYPE_ASSIGN)
            inst.type = INSTRUCTION_TYPE::C_TYPE_COMPLETE;
    }
    DEBUG((int)inst.type);
    DEBUG(inst.dest_value);
    DEBUG(inst.cmp_value);
    DEBUG(inst.jmp_value);
    std::cout << " // " << std::endl;
}
Parser::~Parser()
{
}