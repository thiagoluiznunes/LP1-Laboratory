#include "Process.h"
//https://ffmpeg.org/ffmpeg.html
//https://ffmpeg.org/doxygen/3.1/demuxing_decoding_8c-example.html#a30

Process::Process() : formatContext(nullptr) {
    av_register_all(); //Register muxers/demuxers
    av_log_set_level(AV_LOG_INFO); //Set log level (What FFMPEG prints on screen)
}

Process::~Process() {
}

void Process::openFile(const std::string& type , const std::string& input) throw(ProcessError) {
    /* open input file, and allocate format context */

    std::cout << "OPENING: " << input << std::endl;
    std::cout << "" << '\n';
    if (avformat_open_input(&formatContext, input.c_str(), nullptr, nullptr) < 0) {
        throw ProcessError("Could not open source file");
    }

    // retrieve stream information
    if(avformat_find_stream_info(formatContext, nullptr) < 0){
        throw ProcessError("Could not find stream information");
    }

    /*OPEN CODEC CONTEXT VIDEO*/
    if(type.compare("video") == 0){

      std::cout << "*****************VIDEO*****************" << '\n';

      std::string videoOutput = "myVideoFile";
      if(open_codec_context(&video_stream_idx, &videodecodeCtx, formatContext, AVMEDIA_TYPE_VIDEO, &refcount) >= 0) {
        /*Receiving the ID of the best stream video of the input coming from method  ---- video_stream_idx its changed */
        video_stream = formatContext->streams[video_stream_idx];

        //Creating video file to write to it
        video_dst_file = std::fopen(videoOutput.c_str(), "wb");
        if (!video_dst_file) {
          ret = 1;
          throw ProcessError("Could not open destination file " + input);
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

        /*Chech video stream*/
        if (!video_stream) {
          ret = 1;
          throw ProcessError("Could not find video stream in the input, aborting");
        }

        /*Allocate an AVFrame and set its fields to default values. The resulting struct must be freed using av_frame_free().*/
        frame = av_frame_alloc();
        if (!frame) {
          ret = AVERROR(ENOMEM);
          throw ProcessError("Could not allocate frame");
        }

        /* initialize packet, set data to NULL, let the demuxer fill it */
        av_init_packet(&pkt);
        pkt.data = NULL;
        pkt.size = 0;
        if (video_stream){
          std::cout << "Demuxing video from file: " + input + '\n' +"Into: " + videoOutput << '\n';
          std::cout << "" << '\n';
        }
      }
      avcodec_free_context(&videodecodeCtx);
    }

    /*OPEN CODEC CONTEXT AUDIO*/
    if(type.compare("audio") == 0) {

      std::cout << "*****************AUDIO*****************" << '\n';

      std::string audioOutput = "myAudioFile";
      if (open_codec_context(&audio_stream_idx, &audiodecodeCtx, formatContext, AVMEDIA_TYPE_AUDIO, &refcount) >= 0) {
        audio_stream = formatContext->streams[audio_stream_idx];
        audio_dst_file = fopen("meyAudio", "wb");
        if (!audio_dst_file) {
            ret = 1;
            throw ProcessError("Could not open destination file " + input);
        }
        /*Check audio stream*/
        if (!audio_stream) {
          ret = 1;
          throw ProcessError("Could not find audio stream in the input, aborting");
        }

        /* initialize packet, set data to NULL, let the demuxer fill it */
        av_init_packet(&pkt);
        pkt.data = NULL;
        pkt.size = 0;

        if (audio_stream){
          std::cout << "Demuxing audio from file: " + input + '\n' + "Into: " + audioOutput << '\n';
          std::cout << "" << '\n';
        }

        /*Allocate an AVFrame and set its fields to default values. The resulting struct must be freed using av_frame_free().*/
        frame = av_frame_alloc();
        if (!frame) {
          ret = AVERROR(ENOMEM);
          throw ProcessError("Could not allocate frame");
        }
      }
      avcodec_free_context(&audiodecodeCtx); //ABORTED (CORE DUMPED)
    }

    // Paste stream information on the screen
    //av_dump_format(formatContext, 0, input.c_str(), 0);

    avformat_close_input(&formatContext);
    if (video_dst_file){fclose(video_dst_file);}
    if (audio_dst_file){fclose(audio_dst_file);}

    // av_frame_free(&frame);     //SEGMENT FAULT
    av_free(video_dst_data[0]);
}
