#include "studyOpencv3.h"
#include <QtWidgets/QApplication>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace std;
using namespace cv;
#include <QMessageBox>

//�����������϶���
/*int g_slider_position = 0;
int g_run = 1,g_dontset = 0;//start out in single step mode
VideoCapture g_cap;
void onTrackbarSlide(int pos, void *)
{
	g_cap.set(CAP_PROP_POS_FRAMES, pos);
	if (!g_dontset) g_run = 1;
	g_dontset = 0;
}*/

//ʾ��2_5
/*void Example2_5(const Mat &image)
{
	namedWindow("Example2_5-in", WINDOW_NORMAL);
	namedWindow("Example2_5-out", WINDOW_NORMAL);
	imshow("Example2_5-in", image);
	Mat out;
	GaussianBlur(image, out, Size(5, 5), 3, 3);//Size��˹�ں˵Ĵ�С������������������3,3�ֱ���x��y������ı�׼ƫ��
	GaussianBlur(out, out, Size(5, 5), 3, 3);
	imshow("Example2_5-out", out);
	waitKey(0);
	destroyWindow("Example2_5-in");
	destroyWindow("Example2_5 - out");
}*/


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	/*studyOpencv3 w;
	w.show();
	return a.exec();*/

	//��һ������ͼƬ����������������������������������������
	//Mat img = imread("1233.jpg",IMREAD_REDUCED_COLOR_2);
	//if (img.empty()) return -1;
	////namedWindow("Example1", WINDOW_AUTOSIZE);//���û�����У�������Զ�����һ��Example1����
	//imshow("Example1", img);
	//waitKey(0);
	//destroyWindow("Example1");

	//�ڶ���������Ƶ����������������������������������������
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
		if (waitKey(30) > 0) break;
	}
	return 0;*/

	//�����������϶���
	/*namedWindow("Example2_4", WINDOW_NORMAL);
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
	return 0;*/

	//ʾ��2_5
	/*Mat img = imread("1233.jpg", IMREAD_REDUCED_COLOR_2);
	Example2_5(img); */

	//ʾ��2-6 ������ ת��ɫ ������
	/*Mat img1,img2,img_gry,img_cny;
	namedWindow("Example1", WINDOW_AUTOSIZE);
	namedWindow("Example1-1", WINDOW_AUTOSIZE);
	namedWindow("Example2", WINDOW_AUTOSIZE);
	img1= imread("1233.jpg");
	imshow("Example1", img1);
	pyrDown(img1, img2);//��Сһ��
	cvtColor(img2, img_gry, COLOR_BGR2GRAY);//תΪ�Ҷ�ͼ
	imshow("Example1-1", img_gry);
	Canny(img_gry, img_cny,10,100,3,true);//Ѱ�ұ�Ե
	imshow("Example2", img_cny);//��ʾ
	int x = 16, y = 32;
	Vec3b intensity = img2.at<Vec3b>(y, x);//Vec3b���Կ�����vector<uchar, 3>��
	uchar blue = intensity[0];
	uchar green = intensity[1];
	uchar red = intensity[2];
	QMessageBox::about(nullptr, "BGR value", QString::number((unsigned int)blue) + "," + QString::number((unsigned int)green) + "," + QString::number((unsigned int)red));
	QMessageBox::about(nullptr, "GRAY value", QString::number((unsigned int)(img_gry.at<uchar>(y,x))));
	for (int i=0;i<100;i++)
	{
		img_gry.at<uchar>(y++, x++) = 255;
	}
	imshow("Example1-1", img_gry);
	waitKey(0);
	destroyWindow("Example1");
	destroyWindow("Example2");
	return 0;*/

	//ʾ��2-11
	namedWindow("Example1", WINDOW_AUTOSIZE);
	namedWindow("Example2", WINDOW_AUTOSIZE);
	VideoCapture cap("1.mov");
	double fps = cap.get(CAP_PROP_FPS);
	Size sz(
		(int)cap.get(CAP_PROP_FRAME_WIDTH),
		(int)cap.get(CAP_PROP_FRAME_HEIGHT)
	);
	VideoWriter writer;
	writer.open("1.mov", CAP_OPENCV_MJPEG, fps, sz);//��opencv4.0��CV_FOURCC(��P��, ��I��, ��M��, ��1��)CV_FOURCC(��M��,��J��,��P��,��G��)���Ѿ���ΪCAP_OPENCV_MJPEG��
	Mat logpolar_frame, bgr_frame;
	for (;;)
	{
		cap>>bgr_frame;
		if (bgr_frame.empty())break;
		imshow("Example1", bgr_frame);
		logPolar(bgr_frame, logpolar_frame, Point2f(bgr_frame.cols / 2, bgr_frame.rows / 2), 40, WARP_FILL_OUTLIERS);
		imshow("Example2", logpolar_frame);
		waitKey(30);
	}
	destroyWindow("Example1");
	destroyWindow("Example2");
	cap.release();
	return 0;
}
