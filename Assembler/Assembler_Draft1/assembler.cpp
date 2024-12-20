#include <fstream>
#include <iostream>
#include <string>

#include "input_error.h"
#include "default.h"
#include "syntax_error.h"

using namespace std;

int main(int argc, char* argv[]){
    // argc: number of arguments including "./assembler"
    // argv[]: array of the arguments in c-string format. 

    // run "./assembler <file_name.txt>" in the command line

    int line = 1;

    partition();

    if (argument_length_error(argc)) return -1;
    if (incorrect_extension(argv[1])) return -1;

    ifstream inFile(argv[1]);

    if (file_not_found(inFile)) {
        inFile.close();
        return -1;
    }

    ofstream outFile("output.txt");

    // Unga code goes here

    while (!inFile.eof()){
        if (!parse_line(inFile, outFile, line)){
            inFile.close();
            outFile.close();
            remove("output.txt");
            return -1;
        }
        line++;
    }
    
    // Unga code ends here

    inFile.close();
    outFile.close();

    partition();

    return 0;
}





