#ifndef MEDIA_HANDLER_H
#define MEDIA_HANDLER_H

#include <string>
#include <iostream>

extern "C" {
    #include <libavformat/avformat.h>
    #include <libavformat/avio.h>
    #include <libavcodec/avcodec.h>
    #include <libavutil/audio_fifo.h>
    #include <libavutil/avutil.h>
}

class MediaHandler {
private:
  AVFormatContext* formatContext;
  std:string input;

public:
    MediaHandler(const std:string& input);
    ~MediaHandler();

    void fetch();
    void showStreams();
    AVPacket* readPacket();

    MediaHandler(const MediaHandler&)            = delete; // We don't need the copy constructor as this is a singleton.
    MediaHandler& operator=(const MediaHandler&) = delete; // Copy assignment is not needed also.
};

MediaHandler::MediaHandler(const std:string& input) : formatContext(nullptr) {
    input = input;
}

MediaHandler::~MediaHandler() {
}

void MediaHandler::fetch() throw(ProcessError){
  /* open input file, and allocate format context */
  std::cout << "Opening: " << input << std::endl;
  if (avformat_open_input(&formatContext, input.c_str(), nullptr, nullptr) < 0) {
      throw ProcessError("Could not open source file");
  }

  // retrieve stream information
  if(avformat_find_stream_info(formatContext, nullptr) < 0){
      throw ProcessError("Could not find stream information");
  }
}

void MediaHandler::showStreams(){
  //Paste stream information on the screen
  av_dump_format(formatContext, 0, input.c_str(), 0);
}

AVPacket* MediaHandler::readPacket(){

}
#endif //defined as MediaHandler_MediaHandler_H
