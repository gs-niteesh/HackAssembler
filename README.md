# Hack Assembler from NandTotetris

This is the Hack Assembler from the nand2tetris. It was written in standard C++. This is has it's own parser and doesn't use REGEX.
It does two passes, first time to get all labels and second time to generate machine code. Planning to release version 2 which does this in single pass.
Tried my best to make it as modular as possible and maybe soon will be updating with a more structured and modern c++ version.

The commits are bit messy and the code is not commented.
So if you are reading the code good luck with it ;

## TO COMPILE:
    g++ src/Assembler.cpp src/Parser.cpp src/SymbolTable.cpp src/util.cpp src/CodeGenerator.cpp -Iinclude/ -o HackAssmbler
## TO RUN (LINUX):
    ./HackAssembler FILE_NAME.asm OUTPUT_FILENAME(OPTIONAL)
Output file name will be same as input file name if ommited.

Suggestions are always welcomed :)
