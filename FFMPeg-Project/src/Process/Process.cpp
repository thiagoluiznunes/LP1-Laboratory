#include "Process.h"

//https://ffmpeg.org/ffmpeg.html
//https://ffmpeg.org/doxygen/3.1/demuxing_decoding_8c-example.html#a30

Process::Process(const std::string& input) : formatContext(nullptr) {
    if (avformat_open_input(&formatContext, input.c_str(), nullptr, nullptr) != 0) {
        //lança execessão
        std::cerr << "Não abriu a entrada" << std::endl;
    }
    // Print detailed information about the input or output format, such as duration,
    //bitrate, streams, container, programs, metadata, side data, codec and time base.
    av_dump_format(formatContext, 0, input.c_str(), false);

    /* initialize packet, set data to NULL, let the demuxer fill it */
    av_init_packet(&pkt);
    pkt.data = NULL;
    pkt.size = 0;
    //Função retornará um quadro(FRAME) para cada chamada
    while(av_read_frame(formatContext, &pkt) >= 0){
      if(pkt.stream_index == video_stream_idx){
        //Alloc memory to frame
        frame = av_frame_alloc();

        avcodec_decode_video2(formatContext, frame, &frameFinished, &pkt);
      }
    }
    //After you have finished reading the file.
    avformat_close_input()
}

Process::~Process() {

}
