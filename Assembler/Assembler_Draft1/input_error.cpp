#include "input_error.h"
#include "default.h"

bool argument_length_error(int argc){ // Too many/few arguments : error = true
    if (argc < 2){
        cout << "No arguments entered." << endl;
        print_input_format();
        return true;
    }
    else if (argc > 2){
        cout << "Too many arguments entered." << endl;
        print_input_format();
        return true;
    }

    return false;    
}

bool file_not_found(ifstream& inFile){ // File name not found : error = true
    if (inFile.fail()){
        cout << "File name not found." << endl;
        print_input_format();
        return true;
    }
    return false;
}

bool incorrect_extension(char* file_name){ // Incorrect file extension (not .txt) : error = true
    stringstream ss(file_name);
    ss.ignore(1000, '.');

    string str;
    ss >> str;
    if (str != "txt" && str != ""){
        cout << "Input must be a .txt file" << endl;
        print_input_format();
        return true;
    }

    return false;
}