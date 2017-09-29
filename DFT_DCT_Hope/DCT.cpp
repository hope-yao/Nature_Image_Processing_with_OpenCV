// source: https://stackoverflow.com/questions/27730534/error-in-implementation-of-dct-in-opencv
#include<opencv2/opencv.hpp>
#include<opencv2/opencv_modules.hpp>
#include<iostream>
#include<string.h>


using namespace cv;
using namespace std;

int main(int argc, char ** argv)
{
	const char* filename = argc >=2 ? argv[1] : "zebras.jpg";

	Mat image = imread(filename, CV_LOAD_IMAGE_GRAYSCALE);
	if( image.empty())
	{
	    cout<<"error in loading image file!"<<endl;
	    return -1;
	}

	Mat padded;                            //expand input image to optimal size
	int m = getOptimalDFTSize( image.rows );
	int n = getOptimalDFTSize( image.cols ); // on the border add zero values
	Mat img2;
	copyMakeBorder(image, img2, 0, m - image.rows, 0, n - image.cols, BORDER_CONSTANT, Scalar::all(0));
	imshow("img.jpg", img2);
	cvWaitKey();

	Mat fimage;
	image.convertTo(fimage, CV_32F, 1.0/255); // also scale to [0..1] range (not mandatory)

	// you're lucky with lena (512x512), for odd sizes, you have to
	// pad it to pow2 size, or use dft() instead:
	Mat dimage;
	dct( fimage, dimage );
	// process dimage,
	int L = 50;
	for(int i = L; i<dimage.rows; i++){
        for(int j = L; j<dimage.cols; j++){
            dimage.at<float>(i,j) = 0;
        }
	}
	// then same way back:
	idct( dimage, dimage);

	imshow("result",dimage);
	waitKey();

}

