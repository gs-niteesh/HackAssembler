#include "Parser.h"
#include "SymbolTable.h"
#include "CodeGenerator.h"

int main(int argc, char **argv)
{
    std::string source, output;
    handle_arguments(argc, argv, source, output);

    std::fstream stream(source, std::ios::in);
    if (not stream)
        error("Assembler: Error opening file");

    std::fstream out_stream(output, std::ios::out | std::ios::trunc);
    if (not out_stream)
        error("Assembler: Error creating output file");
        
    SymbolTable sym(stream);
    sym.look_for_lables();

    Parser parser(stream);
    CodeGenerator cgen(sym, out_stream);
   
    while(parser.has_commands()){
        INSTRUCTION inst = parser.command();
        if (inst.type == INSTRUCTION_TYPE::INVALID) continue;
        cgen.generate(inst);
    }
}