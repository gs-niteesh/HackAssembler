#include "util.h"

void error(const std::string &err){
    std::cerr << err << std::endl;
    exit(0);
}

void handle_arguments(int argc, char **argv, std::string &source, std::string &output)
{
    if (argc < 2 or argc > 3)
    {
        error("Usage: asm ASM_FILE_NAME.asm (optional) OUTPUT_FILE_NAME\n");
        exit(1);
    }

    source = argv[1];

    if (argc == 3)
        output = argv[2];
    else
        output = source.substr(0, source.find_last_of('.'));
    output += ".hack";
}