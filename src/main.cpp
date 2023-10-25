#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <stdio.h>
#include <ctime>
//#include <serial/serial.h> // It compiled into /tmp/... WHY

using namespace cv;
using namespace std;

// Get DD:MM:YYYY.
class CurrentTime
{
private:
	char buffer[80];
public:
	CurrentTime()
	{
		std::time_t rawtime;
		struct tm* timeinfo;

		std::time(&rawtime);
		timeinfo = std::localtime(&rawtime);

		std::strftime(buffer, 80, "%d-%m-%Y", timeinfo);
	}

	const char* getBuffer()
	{
		return buffer;
	}
};

// Main
int main(int argc, char** argv)
{
	CurrentTime time;

	Mat src;
	VideoCapture cap(0);

	//serialConnection = serial::Serial("", 9600);

	// Code to figure out the camera's resolution.
	cap >> src;
	bool isColor = (src.type() == CV_8UC3);

	// VideoWriter initialisation.
	VideoWriter writer;
	int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');
	double fps = 5.0;
	string filename = "./live-";
	filename.append(time.getBuffer());
	filename.append(".avi");
	writer.open(filename, codec, fps, src.size(), isColor);

	// Main loop.
	for (;;)
	{
		if (!cap.read(src))
			break;

		writer.write(src);
		imshow("Live", src);
		if (waitKey(5) >= 0)
			break;
	}

	return 0;
}
