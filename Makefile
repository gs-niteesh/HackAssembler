CC = g++
CFLAGS = -Iinclude/

assembler: src/Assembler.cpp src/Parser.cpp src/CodeGenerator.cpp src/SymbolTable.cpp src/util.cpp
	$(CC) -o HackAssembler src/Assembler.cpp src/Parser.cpp src/CodeGenerator.cpp \
			 src/SymbolTable.cpp src/util.cpp $(CFLAGS)

test: tests/main_test.cpp src/Parser.cpp src/util.cpp src/CodeGenerator.cpp src/SymbolTable.cpp
	$(CC) -o TestAssembler tests/main_test.cpp src/Parser.cpp src/util.cpp src/CodeGenerator.cpp \
			 src/SymbolTable.cpp $(CFLAGS)
			 