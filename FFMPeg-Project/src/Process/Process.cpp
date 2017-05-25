#include "Process.h"
//https://ffmpeg.org/ffmpeg.html
//https://ffmpeg.org/doxygen/3.1/demuxing_decoding_8c-example.html#a30

Process::Process(const std::string& videoFileName) : formatContext(nullptr) {
    videoFileName = videoFileName;
    av_register_all(); //Register muxers/demuxers
    av_log_set_level(AV_LOG_INFO); //Set log level (What FFMPEG prints on screen)
}

Process::~Process() {
}

void Process::openFile(const std::string& input) throw(ProcessError) {
    /* open input file, and allocate format context */

    std::cout << "Opening: " << input << std::endl;
    if (avformat_open_input(&formatContext, input.c_str(), nullptr, nullptr) < 0) {
        throw ProcessError("Could not open source file");
    }

    // retrieve stream information
    if(avformat_find_stream_info(formatContext, nullptr) < 0){
        throw ProcessError("Could not find stream information");
    }

    if(open_codec_context(&video_stream_idx, &videodecodeCtx, formatContext, AVMEDIA_TYPE_VIDEO) >= 0) {
        /*Receiving the ID of the best stream video of the input coming from method  ---- video_stream_idx its changed */
        video_stream = formatContext->streams[video_stream_idx];

        //Creating video file to write to it
        video_dst_file = std::fopen(videoFileName, "wb");
        if (!video_dst_file) {
            ret = 1;
            throw ProcessError("Could not open destination file " + video_dst_filename);
        }

        /* allocate image where the decoded image will be put */
        width = videodecodeCtx->width;
        height = videodecodeCtx->height;
        pix_fmt = videodecodeCtx->pix_fmt;
        ret = av_image_alloc(video_dst_data, video_dst_linesize,
                             width, height, pix_fmt, 1);
        if (ret < 0) {
            throw ProcessError("Could not allocate raw video buffer");
        }
        /*Size in bytes required for the image buffer*/
        video_dst_bufsize = ret;
    }

    //Paste stream information on the screen
    av_dump_format(formatContext, 0, input.c_str(), 0);
}
