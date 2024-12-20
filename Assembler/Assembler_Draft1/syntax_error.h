#ifndef SYNTAX_ERROR_H
#define SYNTAX_ERROR_H

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

// Parse Line
bool parse_line(ifstream& inFile, ofstream& outFile, int line);

// Get arguments
bool get_instruction(ifstream& inFile, ofstream& outFile); // change arguments if needed
bool get_argument_1(string command, ifstream& inFile, ofstream& outFile);

#endif