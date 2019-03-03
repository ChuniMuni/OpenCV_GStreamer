/*
* Sender.cpp: Sender for OpenCV_GStreamer example
*
* Copyright (C) 2019 Simon D. Levy
*
* MIT License
*/

#include "pch.h"

#include <opencv2/opencv.hpp>
using namespace cv;

#include <iostream>
using namespace std;

int main()
{
    VideoCapture cap(0);
	
    if (!cap.isOpened()) {
        cerr <<"VideoCapture not opened"<<endl;
        exit(-1);
    }

	VideoWriter writer("appsrc ! videoconvert ! video/x-raw,format=YUY2,width=640,height=480,framerate=30/1 ! jpegenc ! rtpjpegpay ! udpsink host=127.0.0.1 port=5000", 
            0, 30, Size(640, 480), true);


	
    if (!writer.isOpened()) {
        cerr <<"VideoWriter not opened"<<endl;
        exit(-1);
    }

    while (true) {

        Mat frame;

        cap.read(frame);

        writer.write(frame);

        imshow("sender", frame);

        if (waitKey(1) == 27) {
            break;
        }
    }

    return 0;
}


