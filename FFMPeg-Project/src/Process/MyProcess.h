#ifndef PROCESS_MYPROCESS_H
#define PROCESS_MYPROCESS_H

#include <string>
#include <iostream>

#include "ProcessError.h"

extern "C" {
    #include <libavformat/avformat.h>
    #include <libavformat/avio.h>
    #include <libavcodec/avcodec.h>
    #include <libavutil/audio_fifo.h>
    #include <libavutil/avutil.h>
    #include <libavutil/imgutils.h>
}

#define AV_OUTPUT_FORMAT "mp4"
#define AUDIO_OUTPUT_CODEC "ac3"

class MyProcess {
private:
  AVFormatContext *inputformatContext = nullptr;
  AVCodecContext *inputCodecCtx;
  AVCodec *inputEncoder;
  AVStream *inStream;
  int streamIndex = -1;

  AVFormatContext *outputFormatContext = nullptr;
  AVOutputFormat *outFmt;
  AVCodecContext *outputCodecCtx;
  AVCodecParameters *outputParameters;
  AVCodec *outputEncoder;
  AVStream *outStream;

public:
    MyProcess();
    ~MyProcess();

    void openFile(const std::string& type, const std::string& input) throw(ProcessError);

    MyProcess(const MyProcess&)            = delete; // We don't need the copy constructor as this is a singleton.
    MyProcess& operator=(const MyProcess&) = delete; // Copy assignment is not needed also.
};

#endif //defined as PROCESS_PROCESS_H
