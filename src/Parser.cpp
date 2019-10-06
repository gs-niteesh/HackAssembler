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
        DEBUG(line);
    }
}

std::string Parser::readline()
{
    std::string result;
    std::getline(stream, result);
    sanitize(result);
    return result;
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

Parser::~Parser()
{
}