#include "studyOpencv3.h"
#include <QtWidgets/QApplication>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace std;
using namespace cv;

//第三个程序：拖动条
int g_slider_position = 0;
int g_run = 1,g_dontset = 0;//start out in single step mode
VideoCapture g_cap;
void onTrackbarSlide(int pos, void *)
{
	g_cap.set(CAP_PROP_POS_FRAMES, pos);
	if (!g_dontset) g_run = 1;
	g_dontset = 0;
}

int main(int argc, char *argv[])
{	
	/*QApplication a(argc, argv);
	studyOpencv3 w;
	w.show();
	return a.exec();*/

	//第一个程序：图片↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
	//Mat img = imread("1233.jpg",IMREAD_REDUCED_COLOR_2);
	//if (img.empty()) return -1;
	////namedWindow("Example1", WINDOW_AUTOSIZE);//如果没有这行，下面会自动生成一个Example1窗口
	//imshow("Example1", img);
	//waitKey(0);
	//destroyWindow("Example1");

	//第二个程序：视频↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
	/*namedWindow("Example3", WINDOW_NORMAL);
	VideoCapture cap;
	cap.open("1.mov");
	Mat frame;
	for (;;)
	{
		cap>>frame;
		if(frame.empty()) break;
		imshow("Example3", frame);
		if (char(waitKey(1)) == 'q')
		{
			destroyWindow("Example3");
			return 1;
		}
		if (waitKey(33) > 0) break;
	}
	return 0;*/

	//第三个程序：拖动条
	namedWindow("Example2_4", WINDOW_NORMAL);
	g_cap.open("1.mov");
	int frames = (int)g_cap.get(CAP_PROP_FRAME_COUNT);
	int tmpW = (int)g_cap.get(CAP_PROP_FRAME_WIDTH);
	int tmpH = (int)g_cap.get(CAP_PROP_FRAME_HEIGHT);
	createTrackbar("Position", "Example2_4", &g_slider_position, frames,onTrackbarSlide);
	Mat frame;
	for (;;)
	{
		if (g_run!=0)
		{
			g_cap >> frame;
			if (frame.empty()) break;
			int current_pos = (int)g_cap.get(CAP_PROP_POS_FRAMES);
			g_dontset = 1;
			setTrackbarPos("Position", "Example2_4", current_pos);
			imshow("Example2_4", frame);
			g_run -= 1;
		}
		char c = waitKey(10);
		if (c == 's') g_run = 1;
		if (c == 'r') g_run = -1;
		if (c == 27) break;//ESC
	}
	destroyWindow("Example2_4");
	return 0;
}
