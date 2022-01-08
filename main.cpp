//
//  main.cpp
//  ruya
//
//  Created by Sharbel on 1/2/22.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


// OpenCV includes
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;

// int blurAmount = 15;

// // Trackbar callback function
// void onChange(int pos, void* userInput);

// // Mouse callback
// void onMouse(int event, int x, int y, int, void* userInput);

Mat frame;

// GLfloat num = 0.0;

int main(int argc, const char * argv[]) {
    cout << "Hello, World!\n";
    cout << getBuildInformation();


    // Read images
    frame = imread("../car.jpg");
    if (!frame.data) {
        cout << "Image is missing!" << endl;
        return -1;
    }

    // Create window
    imshow("img" ,frame);

    waitKey(0);

    destroyAllWindows();
    return 0;
}