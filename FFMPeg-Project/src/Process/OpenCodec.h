#ifndef PROCESS_OPEN_CODEC_H
#define PROCESS_OPEN_CODEC_H

#include "Process.h"
#include "ProcessError.h"

static int open_codec_context(int *stream_idx, AVCodecContext **videodecodeCtx, AVFormatContext *formatContext, enum AVMediaType type) {

    int ret, stream_index;
    AVStream *st;
    AVCodec *dec = NULL;
    AVDictionary *opts = NULL;

    ret = av_find_best_stream(formatContext, type, -1, -1, NULL, 0);

    std::string descMediaType = av_get_media_type_string(type);

    if (ret < 0) {
      throw ProcessError("Could not find " + descMediaType + " stream");
    }
    else {
        stream_index = ret;
        st = formatContext->streams[stream_index];

        /* find decoder for the stream */
        dec = avcodec_find_decoder(st->codecpar->codec_id);
        if (!dec) {
          throw ProcessError("Failed to find " + descMediaType + " codec");
        }

        /* Allocate a codec context for the decoder */
        *videodecodeCtx = avcodec_alloc_context3(dec);
        if (!*videodecodeCtx) {
          throw ProcessError("Failed to allocate " + descMediaType + " codec context");

        }

        /* Copy codec parameters from input stream to output codec context */
        if ((ret = avcodec_parameters_to_context(*videodecodeCtx, st->codecpar)) < 0) {
          throw ProcessError("Failed to copy " + descMediaType + " codec parameters to decoder context");
        }

        /* Init the decoders, with or without reference counting */
        av_dict_set(&opts, "refcounted_frames", refcount ? "1" : "0", 0);
        if ((ret = avcodec_open2(*videodecodeCtx, dec, &opts)) < 0) {
          throw ProcessError("Failed to open " + descMediaType + " codec");
        }
        *stream_idx = stream_index;
    }
    return 0;
}

#endif
