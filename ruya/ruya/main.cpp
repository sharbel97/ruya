//
//  main.cpp
//  ruya
//
//  Created by sharbster on 1/2/22.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// OpenCV includes
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;


int main(int argc, const char * argv[]) {
    cout << "Hello, World!\n";
    
    const char* keys =
    {
        "{help h usage ? | | print this message}"
        "{@video | | Video file, if not defined try to use webcamera}"
    };
    
    
    CommandLineParser parser(argc, argv, keys);
    
    //If requires help show
    if (parser.has("help")) {
        parser.printMessage();
        return 0;
    }
    
    String videoFile= parser.get<String>(0);
    
    // Check if params are correctly parsed in his variables
    if (!parser.check()) {
    parser.printErrors();
    return 0;
    }
    
    // open the default camera
    VideoCapture cap;
    if(videoFile != "")
        cap.open(videoFile);
    else
        cap.open(0);
    
    if(!cap.isOpened()) // check if we succeeded
        return -1;
    
    namedWindow("Video",1);
    for(;;) {
        Mat frame;
        cap >> frame; // get a new frame from camera
        if(frame.data)
            imshow("Video", frame);
        if(waitKey(30) >= 0) break;
    }
    
    // Release the camera or video cap
    cap.release();
    return 0;
}
