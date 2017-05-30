#include "Process.h"
//https://ffmpeg.org/ffmpeg.html
//https://ffmpeg.org/doxygen/3.1/demuxing_decoding_8c-example.html#a30

Process::Process() : inputformatContext(nullptr) {
    av_register_all(); //Register muxers/demuxers
    avcodec_register_all();
    av_log_set_level(AV_LOG_INFO); //Set log level (What FFMPEG prints on screen)
}

Process::~Process() {
}

void Process::openFile(const std::string& type , const std::string& input) throw(ProcessError) {
    /* open input file, and allocate format context */

    std::cout << "OPENING: " << input << std::endl;
    std::cout << "" << '\n';
    if (avformat_open_input(&inputformatContext, input.c_str(), nullptr, nullptr) < 0) {
        throw ProcessError("Could not open source file");
    }

    // retrieve stream information
    if(avformat_find_stream_info(inputformatContext, nullptr) < 0){
        throw ProcessError("Could not find stream information");
    }
  	streamIndex =  av_find_best_stream(inputformatContext, AVMEDIA_TYPE_VIDEO, -1, -1, &inputEncoder, 0);
  	inputCodecCtx = inputformatContext->streams[streamIndex]->codec;

    av_dump_format(inputformatContext, 0, input.c_str(), 0);
    std::cout << "" << '\n';

    /*OPEN CODEC CONTEXT VIDEO*/
    if(type.compare("video") == 0){

        std::cout << "*****************VIDEO*****************" << '\n';

        std::string videoOutput = "myVideoFile";
        if (avcodec_open2 (inputCodecCtx, inputEncoder, nullptr) < 0) {
          throw ProcessError("Could not open input codec");
        }
        /**/
        if (avformat_alloc_output_context2(&outputFormatContext, nullptr, AV_OUTPUT_FORMAT, videoOutput.c_str()) < 0) {
          throw ProcessError("Could not create output context");
        }
        outStream = avformat_new_stream (outputFormatContext, nullptr);
    		if (outStream == nullptr) {
          throw ProcessError("Could not create output stream");
    		}

        if (avcodec_parameters_from_context(outputParameters, inputCodecCtx) < 0) {
          throw ProcessError("Could not allocated fields in par");
        }





    }
}
