#include "Process.h"

//https://ffmpeg.org/ffmpeg.html
//https://ffmpeg.org/doxygen/3.1/demuxing_decoding_8c-example.html#a30

Process::Process() : formatContext(nullptr) {
    av_register_all(); //Register muxers/demuxers
    av_log_set_level(AV_LOG_INFO); //Set log level (What FFMPEG prints on screen)
}

Process::~Process() {
}

void Process::openFile(const std::string& input) {
    /* open input file, and allocate format context */
    std::cout << "Opening: " << input << std::endl;
    if (avformat_open_input(&formatContext, input.c_str(), nullptr, nullptr) < 0) {
        std::cerr << "Could not open source file" << std::endl;
    }

    // retrieve stream information
    if(avformat_find_stream_info(formatContext, nullptr) < 0){
      std::cerr << "Could not find stream information" << std::endl;
    }

    //Paste stream information on the screen
    av_dump_format(formatContext, 0, input.c_str(), 0);
}
