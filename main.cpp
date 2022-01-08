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

int blurAmount = 15;

// Trackbar callback function
static void onChange(int pos, void* userInput);

// Mouse callback
static void onMouse(int event, int x, int y, int, void* userInput);

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

    namedWindow("Blur");

    // Create window
    createTrackbar("Blur", "Blur", &blurAmount, 30, onChange, &frame);

    setMouseCallback("Blur", onMouse, &frame);
    onChange(blurAmount, &frame);
    waitKey(0);

    destroyAllWindows();
    return 0;
}

static void onChange(int pos, void* userInput) {
    if (pos <= 0) return;

    // Aux variable for result
    Mat imgBlur;

    // Get the pointer input image
    Mat* img = (Mat*)userInput;

    // Apply blur filter
    blur(*img, imgBlur, Size(pos, pos));

    // show the result
    imshow("Blur", imgBlur);
}

static void onMouse(int event, int x, int y, int, void* userInput) {
    if (event != EVENT_LBUTTONDOWN) {
        return;
    }

    // Get the pointer input image
    Mat* img = (Mat*)userInput;

    // Draw circle
    circle(*img, Point(x, y), 10, Scalar(0,255,0), 3);

    // Call onChange to get blurred image
    onChange(blurAmount, img);
}