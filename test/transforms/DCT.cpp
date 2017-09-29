#include<opencv2/opencv.hpp>
#include<opencv2/opencv_modules.hpp>
#include<iostream>
#include<string.h>


using namespace cv;
using namespace std;

int main()
{

	// Read image
	Mat img = imread("zebras.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	// Make sure the both image dimensions are a multiple of 2
	Mat img2;
	int w = img.cols;
	int h = img.rows;
	int w2,h2;
	if (w % 2 == 0)
		w2 = w;
	else
		w2 = w+1;
	if (h % 2 == 0)
		h2 = h;
	else
		h2 = h+1;
	copyMakeBorder(img, img2, 0, h2-h, 0, w2-w, IPL_BORDER_REPLICATE);

	// Grayscale image is 8bits per pixel,
	// but dct() method wants float values!
	Mat img3 = Mat( img2.rows, img2.cols, CV_64F);
	img2.convertTo(img3, CV_64F);
	imshow("img.jpg", img3);


}
