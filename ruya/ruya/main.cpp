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
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

// Create a variable to save the position value in track
int blurAmount=15;

// Trackbar call back function
void onChange(int pos, void* userInput);

//Mouse callback
void onMouse(int event, int x, int y, int, void* userInput);

int main(int argc, const char * argv[]) {
    cout << "Hello, World!\n";
    
    string image = "/Users/sharbster/Desktop/resources/car.jpg";
    
    namedWindow("Car",1);
    // create a trackbar
    createTrackbar("Self", "Video", &blurAmount, 30, onChange, &image);
    setMouseCallback("Video", onMouse, &image);
    
    // call to onChange to init
    onChange(blurAmount, &image);
    
    // wait
    waitKey(0);
    
    destroyWindow("Car");
    
    
    return 0;
}
