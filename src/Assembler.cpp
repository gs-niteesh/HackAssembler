#include "Parser.h"

int main(int argc, char **argv)
{
    std::string source, output;
    handle_arguments(argc, argv, source, output);

    std::fstream stream(source, std::ios::in);
    if (not stream)
        error("Assembler: Error opening file");

    Parser parser(stream);
    parser.run();
}