#ifndef SYNTAX_ERROR_H
#define SYNTAX_ERROR_H

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

bool parse_line(ifstream& inFile, ofstream& outFile, int line);

#endif