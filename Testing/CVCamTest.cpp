#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // Open video file (use 0 for default camera)
    cout << "Program has started successfully!" << endl;
    VideoCapture cap(0); 
    
    if (!cap.isOpened()) {
        cout << "Error opening video stream or file" << endl;
        return -1;
    }

    Mat frame;
    while (true) {
        cap >> frame; // Read next frame
        if (frame.empty()) break; // End of video

        imshow("Video", frame); // Display frame
        if (waitKey(25) == 27) break; // Press 'Esc' to exit
    }

    cap.release();
    destroyAllWindows();
    return 0;
}   