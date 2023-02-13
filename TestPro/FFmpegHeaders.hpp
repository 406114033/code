//
// Created by copewang on 2020/7/15.
//

#pragma once

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavutil/imgutils.h>
#include <libavutil/display.h> // av_display_rotation_get
#include <libavutil/pixdesc.h>
#include <libavutil/pixfmt.h> // AVPixelFormat
#include <libavutil/samplefmt.h> // AVSampleFormat
#include <libavutil/channel_layout.h> // channel layout
#include <libavutil/rational.h>
#include <libswresample/swresample.h>
#include <libavdevice/avdevice.h>
#include <libavcodec/avfft.h>
#include <libavutil/avstring.h>
#include <libavfilter/avfilter.h>
#include <libavutil/audio_fifo.h>// for AVAudioFifo
#include <libavutil/time.h>// for av_gettime_relative ,MediaInfo--Estimate
#include <libavutil/parseutils.h>// av_parse_video_rate
#include <libavutil/intreadwrite.h>// AV_RL32
#include <libavutil/error.h>

#if LIBAVFORMAT_VERSION_INT >= AV_VERSION_INT(58, 76, 100)
#include <libavcodec/codec_desc.h>// avcodec_descriptor_get_by_name
#endif
}
