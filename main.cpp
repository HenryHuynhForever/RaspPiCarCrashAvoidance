#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>

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

		imshow("Live", frame);

		if (waitKey(5) >= 0){
			break;
		}
	}

	return 0;
}
