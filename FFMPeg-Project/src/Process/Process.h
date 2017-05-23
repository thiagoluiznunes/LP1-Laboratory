#ifndef PROCESS_PROCESS_H
#define PROCESS_PROCESS_H

#include <string>
#include <iostream>

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
    AVCodecContext  *videodecodeCtx = nullptr, *audiodecodeCtx = nullptr;
    AVStream *video_stream = nullptr, *audio_stream = nullptr;
    AVFrame *frame = nullptr;
    AVPacket pkt;

    int video_stream_idx = -1;
    int frameFinished = 1;

public:
    Process(const std::string& input);
    ~Process();

    Process(const Process&)            = delete; // We don't need the copy constructor as this is a singleton.
    Process& operator=(const Process&) = delete; // Copy assignment is not needed also.
};

#endif //defined as PROCESS_PROCESS_H
