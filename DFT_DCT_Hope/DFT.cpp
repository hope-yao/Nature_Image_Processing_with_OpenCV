//ref: http://docs.opencv.org/3.0-beta/doc/tutorials/core/discrete_fourier_transform/discrete_fourier_transform.html
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>

using namespace cv;
using namespace std;

static void help(char* progName)
{
    cout << endl
        <<  "This program demonstrated the use of the discrete Fourier transform (DFT). " << endl
        <<  "The dft of an image is taken and it's power spectrum is displayed."          << endl
        <<  "Usage:"                                                                      << endl
        << progName << " [image_name -- default zebras.jpg] "                       << endl << endl;
}

int main(int argc, char ** argv)
{
	help(argv[0]);

	const char* filename = argc >=2 ? argv[1] : "zebras.jpg";

	Mat I = imread(filename, CV_LOAD_IMAGE_GRAYSCALE);
	if( I.empty())
	{
	    cout<<"error in loading image file!"<<endl;
	    return -1;
	}

	Mat padded;                            //expand input image to optimal size
	int m = getOptimalDFTSize( I.rows );
	int n = getOptimalDFTSize( I.cols ); // on the border add zero values
	copyMakeBorder(I, padded, 0, m - I.rows, 0, n - I.cols, BORDER_CONSTANT, Scalar::all(0));

	Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};
	Mat complexI;
	merge(planes, 2, complexI);         // Add to the expanded another plane with zeros

	dft(complexI, complexI);            // this way the result may fit in the source matrix, "in place dft"
	int L = 50;
	for(int i = L; i<complexI.rows-L; i++){
        for(int j = L; j<complexI.cols-L; j++){
            complexI.at<float>(i,j) = 0;
        }
	}

	//calculating the idft
	cv::Mat inverseTransform;
	cv::dft(complexI, inverseTransform, cv::DFT_INVERSE|cv::DFT_REAL_OUTPUT);
	normalize(inverseTransform, inverseTransform, 0, 1, CV_MINMAX);
	imshow("Reconstructed", inverseTransform);
	waitKey();


	return 0;
}

