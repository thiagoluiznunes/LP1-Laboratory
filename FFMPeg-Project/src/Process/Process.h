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
    #include <libavutil/imgutils.h>
}

#define AV_OUTPUT_FORMAT "mpegts"
#define AUDIO_OUTPUT_CODEC "ac3"

class Process {
private:
    AVFormatContext* formatContext;
    AVFormatContext* outputFormatContext;
    AVCodecContext* videodecodeCtx;
    AVCodecContext* audiodecodeCtx;
    AVStream* outStream;
    AVStream* video_stream;
    AVStream* audio_stream;
    AVFrame *frame;
    AVFrame *frameBuffer;
    AVPacket pkt;
    AVPacket pktOutput;

    int video_stream_idx = -1;
    int audio_stream_idx = -1;
    int frameFinished = 1;
    int ret = 0, got_frame;
    int refcount = 0;
    int video_frame_count = 0;
    int audio_frame_count = 0;

    uint8_t *video_dst_data[4] = {NULL};
    int      video_dst_linesize[4];
    int width, height;
    enum AVPixelFormat pix_fmt;
    int video_dst_bufsize;

    FILE *video_dst_file = NULL;
    FILE *audio_dst_file = NULL;

public:
    Process();
    ~Process();

    void openFile(const std::string& type, const std::string& input) throw(ProcessError);

    Process(const Process&)            = delete; // We don't need the copy constructor as this is a singleton.
    Process& operator=(const Process&) = delete; // Copy assignment is not needed also.
};

#endif //defined as PROCESS_PROCESS_H
