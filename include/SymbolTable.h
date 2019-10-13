#pragma once
#include "header.h"
#include "util.h"

class SymbolTable
{
private:
    std::fstream &stream;
    static std::map<std::string, std::string> labels;
    static std::map<std::string, std::string> compare;
    static std::map<std::string, std::string> destinations;
    static std::map<std::string, std::string> jump;
public:
    SymbolTable(std::fstream &);
    void look_for_lables() const;
    bool has_label(const std::string &) const;
    void add_label(const std::string &, int x);
    const std::string get_label(const std::string &) const;
    const std::string get_cmps(const std::string &) const;
    const std::string get_jmp(const std::string &) const;
    const std::string get_dest(const std::string &) const;
    void print_table() const;
    ~SymbolTable();
};