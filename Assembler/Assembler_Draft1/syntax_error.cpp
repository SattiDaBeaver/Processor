#include "syntax_error.h"

bool parse_line(ifstream& inFile, ofstream& outFile, int line){
    string command;
    int num_args;

    if (!get_instruction(inFile, outFile, command, num_args)){
        cout << "Error" << endl; // write a proper error message
    }

    for (int i = 0; i < num_args; i++){
        if (!get_argument(i, command, inFile, outFile)){
            cout << "Error" << endl; // write a proper error message
        }
    }



    return false; // change later
}

bool get_instruction(ifstream& inFile, ofstream& outFile, string& command, int num_args){ // change arguments if needed
    
}

bool get_argument(int arg_num, string command, ifstream& inFile, ofstream& outFile){

}