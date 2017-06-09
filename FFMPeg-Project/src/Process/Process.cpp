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
    /* Open input file, and allocate format context */

    std::cout << "OPENING: " << input << std::endl;
    std::cout << "" << '\n';
    if (avformat_open_input(&inputformatContext, input.c_str(), nullptr, nullptr) < 0) {
        throw ProcessError("Could not open source file");
    }

    // Retrieve stream information
    if(avformat_find_stream_info(inputformatContext, nullptr) < 0){
        throw ProcessError("Could not find stream information");
    }
    av_dump_format(inputformatContext, 0, input.c_str(), 0);
    std::cout << "" << '\n';

    /*OPEN CODEC CONTEXT VIDEO*/
    if(type.compare("video") == 0){

        std::cout << "___________________________VIDEO__________________________" << '\n';
        std::cout << "" << '\n';
        std::cout << "" << '\n';

        std::string outFile = "videoFile";
        /*********************************************************************************************************************/
        if (open_codec_context(&streamIndex, &inputCodecCtx, inputformatContext, AVMEDIA_TYPE_VIDEO, &refcount) >= 0) {
            inStream = inputformatContext->streams[streamIndex];
            video_dst_file = fopen(outFile.c_str(), "ws");
            if (!video_dst_file) {
              throw ProcessError("Could not open destination file");
            }
        }
        std::cout << "OI" << '\n';
        if(avformat_alloc_output_context2(&outputFormatContext, outFmt, nullptr, nullptr) < 0) {
          throw ProcessError("Could not allocate an AVFormatContext for an output format");
        }
        outFmt = outputFormatContext->oformat;
        if (!outFmt) {
          throw ProcessError("Couldn't create output format context");
        }
        //Find Encoder
        outputEncoder = avcodec_find_encoder(outFmt->video_codec);
        if(!(&outputEncoder)){
          throw ProcessError("Could not find encoder");
        }
        //Add new stream to AVFormatContext
        outStream = avformat_new_stream(outputFormatContext, nullptr);
        if(!outStream){
          throw ProcessError("Could not allocate stream");
        }
        //Allocate an AVCodecContext and set its fields to default values.
        outputCodecCtx = avcodec_alloc_context3(outputEncoder);
        if(!outputCodecCtx){
          throw ProcessError("Could not alloc an encoding context");
        }

        outputCodecCtx->codec_id = outFmt->video_codec;
        //Copy the contents of src(inStream) to dst(outStream)
        if(avcodec_parameters_copy(outStream->codecpar, inStream->codecpar) < 0){
          throw ProcessError("Could not copy the contents parameters");
        }
        /* Copy codec parameters from input stream to output codec context */
        if (avcodec_parameters_to_context(outputCodecCtx, inStream->codecpar) < 0) {
          throw ProcessError("Failed to copy codec parameters to decoder context");
        }
        /*
        std::cout << "CODEC TYPE: " + outStream->codecpar->codec_type << '\n';
        std::cout << "CODEC ID :"  + outStream->codecpar->codec_id << '\n';
        std::cout << "CODECT TAG: "  + outStream->codecpar->codec_tag << '\n';
        std::cout << "BIT RATE: "  + outStream->codecpar->bit_rate << '\n';
        std::cout << "WIDTH: "  + outStream->codecpar->width << '\n';
        std::cout << "HEIGHT: "  + outStream->codecpar->height << '\n';
        std::cout << "FRAME SIZE: "  + outStream->codecpar->frame_size << '\n';
        */
    }
}
