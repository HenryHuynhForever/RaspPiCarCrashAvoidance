#include <iostream>
#include <ctime>

#include <wiringPi.h>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>

using namespace cv;

void print(std::string string){
	std::cout << string << std::endl;
}

int main(){
	VideoCapture capture = VideoCapture(0);

	if (capture.isOpened() == false){
		//print("Could not open camera.");
		return 1;
	}

	return 0;
}
