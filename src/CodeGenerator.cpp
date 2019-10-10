#include "CodeGenerator.h"
#include "SymbolTable.h"

CodeGenerator::CodeGenerator(const SymbolTable &labels, std::fstream &output) : labels(labels), output(output)
{
}

CodeGenerator::~CodeGenerator()
{
}
