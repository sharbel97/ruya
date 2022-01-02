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
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;


int main(int argc, const char * argv[]) {
    cout << "Hello, World!\n";
    
    Mat color = imread("/Users/sharbster/Desktop/resources/car.jpg");
    
    if (!color.data) {
        cout << "Could not open or find image" << endl;
        return -1;
    }
    
    // show images
    imshow("Benz Color", color);
    
    // wait for any key press
    waitKey(0);
    return 0;
}
