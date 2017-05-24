#include <iostream>
#include <string>

#include "Process.h"

int main(const int argc, const char** argv) {
    std::cout << "READING FROM: " << argv[1] << std::endl;

    Process process; //Creates a new process
    try {
        process.openFile(std::string(argv[1]));
    } catch(ProcessError& err) {
        std::cerr << "Error - what(): " << err.what() << std::endl;
    }
    return 0;
}
