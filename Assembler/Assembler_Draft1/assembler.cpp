#include <fstream>
#include <iostream>
#include <string>

#include "input_error.h"
#include "default.h"

using namespace std;

int main(int argc, char* argv[]){
    // argc: number of arguments including "./main"
    // argv[]: array of the arguments in string format. 

    // run "./main <arg1> <arg2>" in the command line

    cout << endl;
    
    if (argument_length_error(argc)){
        return -1;
    }

    if (incorrect_extension(argv[1])){
        return -1;
    }

    ifstream inFile(argv[1]);

    if (file_not_found(inFile)){
        return -1;
    }

    cout << "Number of arguments: " << argc << endl;

    for (int i = 0; i < argc; i++){
        cout << "Argument " << i << " : " << argv[i] << endl;
    }

    inFile.close();

    return 0;
}





