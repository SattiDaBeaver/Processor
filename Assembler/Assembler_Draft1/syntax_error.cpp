#include "syntax_error.h"

bool parse_line(ifstream& inFile, ofstream& outFile, int line){
    if (!get_instruction(inFile, outFile)){
        cout << "Error" << endl; // write a proper error message
    }



    return false; // change later
}

bool get_instruction(ifstream& inFile, ofstream& outFile){ // change arguments if needed
    
}

bool get_argument_1(string command, ifstream& inFile, ofstream& outFile){
    
}