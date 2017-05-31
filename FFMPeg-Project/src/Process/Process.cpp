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
  	streamIndex =  av_find_best_stream(inputformatContext, AVMEDIA_TYPE_VIDEO, -1, -1, &inputEncoder, 0);
  	inputCodecCtx = inputformatContext->streams[streamIndex]->codec;

    av_dump_format(inputformatContext, 0, input.c_str(), 0);
    std::cout << "" << '\n';

    /*OPEN CODEC CONTEXT VIDEO*/
    if(type.compare("video") == 0){

        std::cout << "___________________________VIDEO__________________________" << '\n';
        std::cout << "" << '\n';
        std::cout << "" << '\n';

        std::string videoOutput = "myVideoFile";
        if (avcodec_open2 (inputCodecCtx, inputEncoder, nullptr) < 0) {
          throw ProcessError("Could not open input codec");
        }
        //Allocate an AVFormatContext for an output format.
        if (avformat_alloc_output_context2(&outputFormatContext, nullptr, AV_OUTPUT_FORMAT, videoOutput.c_str()) < 0) {
          throw ProcessError("Could not create output context");
        }
        fmt = outputFormatContext->oformat;
        //Finde the encoder
        outputEncoder = avcodec_find_encoder(fmt->video_codec);
        //Add a new stream to a media file.
        outStream = avformat_new_stream (outputFormatContext, nullptr);
    		if (outStream == nullptr) {
          throw ProcessError("Could not create output stream");
    		}
        outStream->id = outputFormatContext->nb_streams-1;
        //Fill the parameters struct based on the values from the supplied codec context
        //Copy the stream parameters to the muxer
        if (avcodec_parameters_from_context(outStream->codecpar, inputCodecCtx) < 0) {
          throw ProcessError("Could not allocated fields in par");
        }
        //Open output context
    		if (avio_open (&outputFormatContext->pb, videoOutput.c_str(), AVIO_FLAG_WRITE)) {
          throw ProcessError("AVIO_OPEN failed");
    		}
        //Allocate the stream private data and initialize the code
        // if(avformat_init_output(outputFormatContext, nullptr) < 0){
        //   throw ProcessError("Init output failed");
        // }
        //Write format context header
    		// if (avformat_write_header (outputFormatContext, nullptr) < 0) {
        //   throw ProcessError("Fail to write outstream header");
    		// }


        std::cout << "__________________________ENCODER__________________________" << '\n';
        std::cout << "INPUT" << '\n';
        std::cout << "id: " + std::to_string(inputEncoder->id) << '\n';
        std::cout << "name: " << inputEncoder->name << '\n';
        std::cout << "long name: " << inputEncoder->long_name << '\n';
        std::cout << "type: " + std::to_string(inputEncoder->type) << '\n';
        std::cout << "" << '\n';

        std::cout << "OUTPUT" << '\n';
        std::cout << "id: " + std::to_string(outputEncoder->id) << '\n';
        std::cout << "name:: " << outputEncoder->name << '\n';
        std::cout << "long name: " << outputEncoder->long_name << '\n';
        std::cout << "type: " + std::to_string(outputEncoder->type) << '\n';
        std::cout << "" << '\n';

        std::cout << "_______________________AVFORMATCONTEXT_______________________" << '\n';
        std::cout << "INPUT" << '\n';
        std::cout << "video codec id: " + std::to_string(inputformatContext->video_codec_id) << '\n';
        std::cout << "audio codec id: " + std::to_string(inputformatContext->audio_codec_id) << '\n';
        std::cout << "" << '\n';

        std::cout << "OUTPUT" << '\n';
        std::cout << "video codec id: " + std::to_string(outputFormatContext->video_codec_id) << '\n';
        std::cout << "audio codec id: " + std::to_string(outputFormatContext->audio_codec_id) << '\n';



        std::cout << "" << '\n';
        std::cout << "" << '\n';
    }
}
