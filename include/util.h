#pragma once
#include "header.h"

#define DEBUG(x) std::cout << #x << ": " << x << std::endl;

void error(const std::string &err);

void handle_arguments(int argc, char **argv, std::string &source, std::string &output);