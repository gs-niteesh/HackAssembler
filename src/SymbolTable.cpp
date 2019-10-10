#include "SymbolTable.h"

SymbolTable::SymbolTable(std::fstream &stream) : stream(stream)
{
    stream.seekg(0);
    symbols.insert({"R0", "0"});
    symbols.insert({"R1", "1"});
    symbols.insert({"R2", "2"});
    symbols.insert({"R3", "3"});
    symbols.insert({"R4", "4"});
    symbols.insert({"R5", "5"});
    symbols.insert({"R6", "6"});
    symbols.insert({"R7", "7"});
    symbols.insert({"R8", "8"});
    symbols.insert({"R9", "9"});
    symbols.insert({"R10", "10"});
    symbols.insert({"R11", "11"});
    symbols.insert({"R12", "12"});
    symbols.insert({"R13", "13"});
    symbols.insert({"R14", "14"});
    symbols.insert({"R15", "15"});
    symbols.insert({"SP", "0"});
    symbols.insert({"LCL", "1"});
    symbols.insert({"ARG", "2"});
    symbols.insert({"THIS", "3"});
    symbols.insert({"THAT", "4"});
    symbols.insert({"SCREEN", "16384"});
    symbols.insert({"KBD", "24576"});
}

void SymbolTable::look_for_lables()
{
    auto s = stream.tellg();
    stream.seekg(0);
    int line_no = 0;
    while (!stream.eof())
    {
        std::string line;
        std::getline(stream, line);
        if (line[0] == '(')
        {
            auto label = line.substr(1, line.size() - 3);
            symbols.insert({label, std::to_string(line_no + 1)});
            // DEBUG(label << " -- " << std::to_string(line_no+1));
        }
        line_no++;
    }
}

std::string SymbolTable::has_label(const std::string &label)
{
    auto loc = symbols.find(label);
    if (loc != symbols.end())
        return (*loc).second;
    return ""; 
}

void SymbolTable::print_table()
{
    for (auto i : symbols)
    {
        DEBUG(i.first << " - " << i.second);
    }
}

SymbolTable::~SymbolTable()
{
}