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

    av_dump_format(formatContext, 0, input.c_str(), 0);

    /*OPEN CODEC CONTEXT VIDEO*/
    if(type.compare("video") == 0){

        std::cout << "*****************VIDEO*****************" << '\n';

        std::string videoOutput = "myVideoFile";
        if(open_codec_context(&video_stream_idx, &videodecodeCtx, formatContext, AVMEDIA_TYPE_VIDEO, &refcount) >= 0) {
            /*Receiving the ID of the best stream video of the input coming from method  ---- video_stream_idx its changed */
            video_stream = formatContext->streams[video_stream_idx];

            /*Chech video stream*/
            if (!video_stream) {
              ret = 1;
              throw ProcessError("Could not find video stream in the input, aborting");
            }

            if (video_stream){
              std::cout << "Demuxing video from file: " + input + '\n' +"Into: " + videoOutput << '\n';
              std::cout << "" << '\n';
            }
            //Initialize Output
            if (avformat_alloc_output_context2(&formatContext, NULL, AV_OUTPUT_FORMAT, videoOutput.c_str()) < 0) {
              throw ProcessError("Could not create output context");
        		}
            outStream = avformat_new_stream(formatContext, nullptr);
            if(outStream == nullptr){
              throw ProcessError("Could not create output stream");
            }
            //Open output context
        		if (avio_open (&formatContext->pb, videoOutput.c_str(), AVIO_FLAG_WRITE)) {
              throw ProcessError("AVIO_OPEN failed: " + videoOutput);
        		}
            /* Read frames from the file */
            while (av_read_frame(formatContext, &pkt) >= 0) {
               if (pkt.stream_index == video_stream_idx) {

                 av_packet_ref(&pktOutput, &pkt);
                 pktOutput.stream_index = video_stream_idx;

                 if(av_write_frame (formatContext, &pktOutput) < 0) {
                   std::cout << "Unable to write to output stream.." << '\n';
                 }
               }
            }

            avcodec_free_context(&videodecodeCtx);
        }
    }

    /*OPEN CODEC CONTEXT AUDIO*/
    if(type.compare("audio") == 0) {

      std::cout << "*****************AUDIO*****************" << '\n';

      std::string audioOutput = "myAudioFile";
      if (open_codec_context(&audio_stream_idx, &audiodecodeCtx, formatContext, AVMEDIA_TYPE_AUDIO, &refcount) >= 0) {
        audio_stream = formatContext->streams[audio_stream_idx];
        /*Check audio stream*/
        if (!audio_stream) {
          ret = 1;
          throw ProcessError("Could not find audio stream in the input, aborting");
        }

        if (audio_stream){
          std::cout << "Demuxing audio from file: " + input + '\n' + "Into: " + audioOutput << '\n';
          std::cout << "" << '\n';
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
