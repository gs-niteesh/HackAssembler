#include "SymbolTable.h"

std::map<std::string, std::string> SymbolTable::labels = {
    {"R0", "0"},
    {"R1", "1"},
    {"R2", "2"},
    {"R3", "3"},
    {"R4", "4"},
    {"R5", "5"},
    {"R6", "6"},
    {"R7", "7"},
    {"R8", "8"},
    {"R9", "9"},
    {"R10", "10"},
    {"R11", "11"},
    {"R12", "12"},
    {"R13", "13"},
    {"R14", "14"},
    {"R15", "15"},
    {"SP", "0"},
    {"LCL", "1"},
    {"ARG", "2"},
    {"THIS", "3"},
    {"THAT", "4"},
    {"SCREEN", "16384"},
    {"KBD", "24576"}};

std::map<std::string, std::string> SymbolTable::compare = {
    {"0", "0101010"},
    {"1", "0111111"},
    {"-1", "0111010"},
    {"D", "0001100"},
    {"A", "0110000"},
    {"M", "1110000"},
    {"!D", "0001101"},
    {"!A", "0110001"},
    {"!M", "1110001"},
    {"-D", "0001111"},
    {"-A", "0110011"},
    {"D+1", "0011111"},
    {"A+1", "0110111"},
    {"M+1", "1110111"},
    {"D-1", "0001110"},
    {"A-1", "0110010"},
    {"M-1", "1110010"},
    {"D+A", "0000010"},
    {"D+M", "1000010"},
    {"D-A", "0010011"},
    {"D-M", "1010011"},
    {"A-D", "0000111"},
    {"M-D", "1000111"},
    {"D&A", "0000000"},
    {"D&M", "1000000"},
    {"D|A", "0010101"},
    {"D|M", "1010101"}};

std::map<std::string, std::string> SymbolTable::destinations = {
    //Dest: d1 d2 d3
    {"null", "000"},
    {"M", "001"},
    {"D", "010"},
    {"MD", "011"},
    {"A", "100"},
    {"AM", "101"},
    {"AD", "110"},
    {"AMD", "111"}};

std::map<std::string, std::string> SymbolTable::jump = {
    //JMP: j1 j2 j3
    {"null", "000"},
    {"JGT", "001"},
    {"JEQ", "010"},
    {"JGE", "011"},
    {"JLT", "100"},
    {"JNE", "101"},
    {"JLE", "110"},
    {"JMP", "111"}};

SymbolTable::SymbolTable(std::fstream &stream) : stream(stream)
{
    stream.seekg(0);
}

void SymbolTable::look_for_lables() const
{
    auto s = stream.tellg();
    stream.seekg(0);
    int line_no = 0;
    while (!stream.eof())
    {
        std::string line;
        std::getline(stream, line);

        if ((line[0] == '/' and line[1] == '/') or (line[0] == '\r' or line[0] == '\n') or line == "")
            continue;
        if (line[0] == '(')
        {
            auto label = line.substr(1, line.size() - 3);
            labels.insert({label, binary(line_no)});
        }
        (line_no++);
    }
}

bool SymbolTable::has_label(const std::string &label) const
{
    auto loc = labels.find(label);
    return loc != labels.end();
}

void SymbolTable::print_table() const
{
    for (auto i : labels)
    {
        DEBUG(i.first << " - " << i.second);
    }
}

const std::string SymbolTable::get_label(const std::string &sym) const
{
    return labels[sym];
}

const std::string SymbolTable::get_cmps(const std::string &sym) const
{
    return compare[sym];
}

const std::string SymbolTable::get_dest(const std::string &sym) const
{
    return destinations[sym];
}

const std::string SymbolTable::get_jmp(const std::string &sym) const
{
    return jump[sym];
}

SymbolTable::~SymbolTable()
{
}