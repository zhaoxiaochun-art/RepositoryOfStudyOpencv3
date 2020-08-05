#include "studyOpencv3.h"
#include <QtWidgets/QApplication>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace std;
using namespace cv;
#include <QMessageBox>
#include<string>
#include<cstdio>
#include <QChar>
#include <QTextCodec>

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
	Mat src, dst;
	src = imread("1233.jpg");// , IMREAD_REDUCED_COLOR_2);
	//if (src.empty()) return -1;
	if (!src.data) return -1;//�������Ǿ���һ����˼
	namedWindow("input image", WINDOW_AUTOSIZE);//���û�����У�������Զ�����һ��Example1����
	imshow("input image", src);
	Mat M(300, 300, CV_8UC3, Scalar(60, 0, 0));
	//dst = src.clone();//11111
	//src.copyTo(dst);//22222
	//dst = Mat(src.size()/2, src.type());//33333
	//dst = Scalar(123, 0, 23);//33333
	//cvtColor(src, dst, COLOR_BGR2GRAY);
	namedWindow("output2 image", WINDOW_AUTOSIZE);//���û�����У�������Զ�����һ��Example1����
	imshow("output2 image", M);


	Mat M2=Mat::zeros(2, 2, CV_8UC1);
	namedWindow("output3 image", WINDOW_AUTOSIZE);//���û�����У�������Զ�����һ��Example1����
	imshow("output3 image", M2);
	//imwrite("d:/desktop/i.jpg", M2);

	//int cols = dst.cols;
	//int rows = dst.rows;
	//QMessageBox::about(nullptr,"cols,rows", QString::number(cols) + "��,"+ QString::number(rows) +"��");
	//const uchar*firstRow = dst.ptr<uchar>(0);
	//int myInt = firstRow[0];
	//int myInt2 = firstRow[1];
	//int myInt3 = firstRow[2];
	//int myInt4 = firstRow[3];
	//int myInt5 = firstRow[4];
	//QString myIntToStr = QString::number(myInt);//������61���ǵȺ�
	//QString myIntToStr2 = QString::number(myInt2);//������61���ǵȺ�
	//QString myIntToStr3 = QString::number(myInt3);//������61���ǵȺ�
	//QString myIntToStr4 = QString::number(myInt4);//������61���ǵȺ�
	//QString myIntToStr5 = QString::number(myInt5);//������61���ǵȺ�
// 	QString grayValue = "";
// 	grayValue.append(*firstRow);//�������ȺŲ���61
	//QMessageBox::about(nullptr, "channels", "BGR:" + QString::number(src.channels()) + ",GRAY:" + QString::number(dst.channels())+ "\n"+ myIntToStr + "\n" + myIntToStr2 + "\n" + myIntToStr3 + "\n" + myIntToStr4 + "\n" + myIntToStr5);
	/*int cols=src.cols*src.channels();//��������bgr����������
	int offsetx = src.channels();
	int rows = src.rows;
	dst = Mat::zeros(src.size(), src.type());//zeros����rgb��000�ĺ�ɫͼƬ����С�����ͺ�srcһ��
	for (int row = 1; row < rows - 1; row++){
		const uchar* current = src.ptr<uchar>(row);
		const uchar* previous = src.ptr<uchar>(row - 1);
		const uchar* next = src.ptr<uchar>(row + 1);
		uchar *output = dst.ptr<uchar>(row);
		for (int col= offsetx;col<cols-offsetx;col++)
		{
			output[col] = saturate_cast<uchar>(5 * current[col] - (current[col - offsetx] + current[col + offsetx] + previous[col] + next[col]));
			//I(i,j) = 5*I(i,j) - [I(i-1,j) + I(i+1,j) + I(i,j-1) + I(i,j+1)]
			//saturate_cast<uchar>�Ѻ������������0-255֮��
		}
	}*/

	// openCV API ��Ĥ����
	
	/*double t = getTickCount();
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);//����һ����Ĥ	
	filter2D(src, dst, src.depth(), kernel);//src.depth() ��ʾ��ԭͼ���һ����-1Ҳ��ʾһ��
	double timeconsume = (getTickCount() - t) / getTickFrequency();//tick������ÿ���tick�����ó�����
	QMessageBox::about(nullptr,"TIMECONSUME",QString::number(timeconsume));
	//��ʾ
	namedWindow("contrast Image",WINDOW_AUTOSIZE);
	imshow("contrast Image", dst);
	imwrite("d:/desktop/dst.jpg", dst);*/
	waitKey(0);
	return 0;
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
	/*namedWindow("Example1", WINDOW_AUTOSIZE);
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
	return 0;*/
}
