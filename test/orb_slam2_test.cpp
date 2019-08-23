#include "orb_slam2_test.h"
#include <opencv.hpp>

using namespace cv;
using namespace std;

void opencv_test(void)
{
	Size sz(10, 8),sz2(14,12);
	Mat image(sz, CV_8UC1);
	Mat temp(sz2, CV_8UC1);

	//这句之后image和temp指向同一个内存
	image = temp(Rect(2, 2, sz.width, sz.height));

	/*copyMakeBorder(image, temp, 2, 2, 2, 2, BORDER_REFLECT_101);

	cout << image.rows << endl << image.cols << endl;*/

	try {
		for (int i = 0; i < temp.rows; ++i)
		{
			for (int j = 0; j < temp.cols; ++j)
			{
				temp.at<uchar>(i,j) = 9;  //注意单通道和多通道的赋值方式
			}
		}
		cout << "image:" << endl << (int)image.at<uchar>(1, 1) << endl << "temp:" << endl << (int)temp.at<uchar>(3, 3) << endl;
		cout << "image_rows:" << image.rows << endl << "image_cols:" << image.cols << endl;
		cout << "sz_width:" << sz.width << endl << "sz_height:" << sz.height << endl;
	        /*输出结果:得x-rows-height，y-cols-width
			image:
		    9
			temp :
			9
			image_rows : 8
			image_cols : 10
			sz_width:10
            sz_height:8*/

	}
	catch (...) {
		throw;
	}


	waitKey(0);
}