#ifndef PROCESS_PROCESS_H
#define PROCESS_PROCESS_H

#include <string>
#include <iostream>

#include "ProcessError.h"
#include "OpenCodec.h"

extern "C" {
    #include <libavformat/avformat.h>
    #include <libavformat/avio.h>
    #include <libavcodec/avcodec.h>
    #include <libavutil/audio_fifo.h>
    #include <libavutil/avutil.h>
}

class Process {
private:
    AVFormatContext* formatContext;
    AVCodecContext* videodecodeCtx;
    AVCodecContext* audiodecodeCtx;
    AVStream* video_stream;
    AVStream* audio_stream;
    AVFrame *frame;
    AVFrame *frameBuffer;
    AVPacket pkt;

    int video_stream_idx = -1;
    int frameFinished = 1;
    int ret = 0, got_frame;
    int refcount = 0;

    uint8_t *video_dst_data[4] = {NULL};
    int      video_dst_linesize[4];
    int width, height;
    enum AVPixelFormat pix_fmt;
    int video_dst_bufsize;

    // std::string videoFileName = nullptr;
    // std::string audioFileName = nullptr;
    FILE *video_dst_file = NULL;

public:
    Process();
    ~Process();

    void openFile(const std::string& input) throw(ProcessError);

    Process(const Process&)            = delete; // We don't need the copy constructor as this is a singleton.
    Process& operator=(const Process&) = delete; // Copy assignment is not needed also.
};

#endif //defined as PROCESS_PROCESS_H
