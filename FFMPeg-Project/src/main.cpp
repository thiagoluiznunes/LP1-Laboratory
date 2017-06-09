#include <iostream>
#include <string>

#include "MyProcess.h"
#include "Process.h"

/*
Alterar canais com ffmpeg com videos de verdade
*/

int main(const int argc, const char** argv) {
    std::cout << "" << '\n';
    std::cout << "READING FROM: " << argv[1] << std::endl;
    std::cout << "" << '\n';

    //Process process; //Creates a new process
    MyProcess process;
    try {
        process.openFile("video", std::string(argv[1]));
        // process.openFile("audio", std::string(argv[1]));

    } catch(ProcessError& err) {
        std::cerr << "Error - what(): " << err.what() << std::endl;
    }
    return 0;
}
