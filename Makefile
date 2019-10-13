CC = g++
CFLAGS = -Iinclude/

assembler: src/Assembler.cpp src/Parser.cpp src/CodeGenerator.cpp src/SymbolTable.cpp src/util.cpp
	$(CC) -o HackAssembler src/Assembler.cpp src/Parser.cpp src/CodeGenerator.cpp \
			 src/SymbolTable.cpp src/util.cpp $(CFLAGS)
