#ifndef GSTREAM_H
#define GSTREAM_H

#include <gst/gst.h>
#include <gst/video/video.h>
#include <windows.h>
// #include <opencv2/highgui.hpp>
// #include <opencv2/imgcodecs.hpp>
// #include <opencv2/core.hpp>
// #include <opencv2/opencv.hpp>


typedef struct Elements {
  GstElementFactory *sourceFactory;
  GstElementFactory *filterFactory;
  GstElementFactory *convertFilterFactory;
  GstElementFactory *capsFilterFactory;
  GstElementFactory *sinkFactory;
  GstElement *pipeline;
  GstElement * source;
  GstElement *filter;
  GstElement *convertFilter;
  GstElement *capsFilter;
  GstElement *sink;
} elements;
static GstPadProbeReturn buffer_probe_callback (GstPad *pad, GstPadProbeInfo *info, gpointer user_data);
int gstream(int argc, char *argv[]);

#endif