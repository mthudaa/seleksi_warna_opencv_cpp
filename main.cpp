#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void main(){
	Mat img, hsv, mask;
	VideoCapture cap(0);

	int h_low = 0, s_low = 50, v_low = 140;
	int h_hi = 26, s_hi = 255, v_hi = 255;

	//slider untuk mengatur range nilai HSV
	namedWindow("slider");
	createTrackbar("hue low : ", "slider", &h_low, 255);
	createTrackbar("sat low : ", "slider", &s_low, 255);
	createTrackbar("val low : ", "slider", &v_low, 255);
	createTrackbar("hue hi : ", "slider", &h_hi, 255);
	createTrackbar("sat hi : ", "slider", &s_hi, 255);
	createTrackbar("val hi : ", "slider", &v_hi, 255);

	while(true){
		Scalar low(h_low, s_low, v_low);
		Scalar hi(h_hi, s_hi, v_hi);
		cap.read(img);
		cvtColor(img, hsv, COLOR_BGR2HSV);
		inRange(hsv, low, hi, mask);
		imshow("image ori", img);
		imshow("image selection", mask);
		waitKey(1);
	}
}
