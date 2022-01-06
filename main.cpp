//
//  main.cpp
//  ruya
//
//  Created by Sharbel on 1/2/22.
//

#include <iostream>
using namespace std;

// OpenCV includes
#include <opencv2/opencv.hpp>
using namespace cv;


int main(int argc, const char * argv[]) {
    cout << "Hello, World!\n";

    Mat color = imread("car.jpg");
    imshow("Car", color);
    waitKey(0);
    return 0;
}
