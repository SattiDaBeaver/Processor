#ifndef INPUT_ERROR_H
#define INPUT_ERROR_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

bool argument_length_error(int argc);
bool file_not_found(ifstream& inFile);
bool incorrect_extension(char* file_name);

#endif