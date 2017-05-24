#include <iostream>
#include <string>

#include "Process.h"

int main(const int argc, const char** argv) {
    std::cout << "READING FROM: " << argv[1] << std::endl;
    
    Process process;

    process.openFile(std::string(argv[1]));
    return 0;
}
