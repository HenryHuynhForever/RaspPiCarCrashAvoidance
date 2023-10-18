#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgproc/hal/hal.hpp>

using namespace cv;

int main(){
	Mat frame;
	VideoCapture capture;
	
	int deviceID = 0;
	int apiID = cv::CAP_ANY;
	capture.open(deviceID, apiID);

	if (!capture.isOpened()){
		std::cout << "Could not open camera." << std::endl;
		return -1;
	}

	for (;;){
		capture.read(frame);

		if (frame.empty()){
			break;
		}
		
		Mat resizePass;
		Mat colorPass;
		Mat thresholdPass;

		resize(frame, resizePass, Size(), 0.5, 0.5, INTER_NEAREST);
		cvtColor(resizePass, colorPass, COLOR_BGR2GRAY);
		threshold(colorPass, thresholdPass, 50, 255, 1);

		imshow("Live", thresholdPass);

		if (waitKey(5) >= 0){
			break;
		}
	}

	return 0;
}
