#ifndef OPENCVLIB_H
#define OPENCVLIB_H

#ifdef __cplusplus
#include <QCoreApplication> // For Qt Core
#include <QGuiApplication>   // For Qt Gui
#include <QWidget>           // For QWidget class (GUI applications)
#include <QLabel>            // For QLabel class (GUI applications)
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
extern "C" {
#endif

//function declaration in cpp
void objectDetection(gint width, gint height, guint8 *data);
void faceDetection();

#ifdef __cplusplus
}
#endif

#endif