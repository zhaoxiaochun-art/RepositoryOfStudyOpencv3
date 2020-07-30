#include "studyOpencv3.h"
#include <QtWidgets/QApplication>
#include "opencv2/opencv.hpp"
using namespace cv;

int main(int argc, char *argv[])
{
	Mat img = imread("1233.jpg",IMREAD_REDUCED_COLOR_4);
	if (img.empty()) return -1;
	namedWindow("Example1", WINDOW_AUTOSIZE);
	imshow("Example1", img);
	waitKey(0);
	destroyWindow("Example1");
	return 0;
	/*QApplication a(argc, argv);
	studyOpencv3 w;
	w.show();
	return a.exec();*/
}
