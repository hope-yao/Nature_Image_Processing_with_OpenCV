
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;


//IplImage* doPyrDown(IplImage* in, int filter = IPL_GAUSSIAN_5x5) 
//{
//	// Best to make sure input image is divisible by two.
//	//
//	assert( in->width%2 == 0 && in->height%2 == 0 );
//	IplImage* out = cvCreateImage( cvSize( in->width/2, in->height/2 ), in->depth, in->nChannels );
//	cvPyrDown( in, out );
//	return( out );
//};



int main()
{
	VideoCapture cap(0); // open the default camera
	if (!cap.isOpened())  // check if we succeeded
		return -1;

	Size full_S = Size((int)(cap.get(CV_CAP_PROP_FRAME_WIDTH)),    // Acquire input size, I have NO IDEA why should div 2
			(int)(cap.get(CV_CAP_PROP_FRAME_HEIGHT)));
	Size S = Size((int)(cap.get(CV_CAP_PROP_FRAME_WIDTH)/2),    // Acquire input size, I have NO IDEA why should div 2
			(int)(cap.get(CV_CAP_PROP_FRAME_HEIGHT))/2);
        int ex = (cap.get(CV_CAP_PROP_FOURCC));     // Get Codec Type, added

	VideoWriter full_outputVideo, down_outputVideo;    // open the output
	down_outputVideo.open("Record.avi", CV_FOURCC('M', 'J', 'P', 'G'), cap.get(CV_CAP_PROP_FPS), S, true);
	full_outputVideo.open("full_Record.avi", CV_FOURCC('M', 'J', 'P', 'G'), cap.get(CV_CAP_PROP_FPS), full_S, true);

	if (!down_outputVideo.isOpened() || !full_outputVideo.isOpened())
	{
		cout << "Could not open the output video for write: " << endl;
		return -1;
	}

	namedWindow("Video", 1);
	cout << "Start Reading and Writing" << endl;

	for(int i=0;;i++)
        {
                Mat frame;
                cap >> frame;
                Mat down_frame;
                pyrDown(frame, down_frame, Size(frame.cols / 2, frame.rows / 2));
                down_outputVideo.write(down_frame);
                full_outputVideo.write(frame);
                putText(down_frame, "Press ESC to stop", Point(0, 0), 1, 1, Scalar(255, 255, 255), 2);
                imshow("Video", down_frame);


                char S = (char)waitKey(33);
                if (S == 27) break;
        }


	// the camera wil be deinitialized automatically in VideoCapture destructor
	cout << "Finished Writing" << endl;

	return 0;

}



