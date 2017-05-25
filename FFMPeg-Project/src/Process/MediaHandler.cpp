#include "MediaHandler.h"


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
