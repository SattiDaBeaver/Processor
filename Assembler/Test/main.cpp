#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    // argc: number of arguments including "./main"
    // argv[]: array of the arguments in string format. 

    cout << "Number of arguments: " << argc << endl;
    
    for (int i = 0; i < argc; i++){
        cout << "Argument " << argc << " : " << argv[i] << endl;
    }

    return 0;
}