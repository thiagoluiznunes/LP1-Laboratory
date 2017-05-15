#include "Process.h"

Process::Process(const std::string& input) : formatContext(nullptr) {
    if (avformat_open_input(&formatContext, input.c_str(), nullptr, nullptr) != 0) {
        //lança execessão
        std::cerr << "Não abriu a entrada" << std::endl;
    }

    av_dump_format(formatContext, 0, input.c_str(), false);
}

Process::~Process() {

}
