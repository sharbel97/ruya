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
    // insert code here...
    cout << "Hello, World!\n";
    
    Mat color = imread("/resources/selfie.JPG");
    Mat gray = imread("/resources/selfie.JPG", IMREAD_GRAYSCALE);
    return 0;
}
