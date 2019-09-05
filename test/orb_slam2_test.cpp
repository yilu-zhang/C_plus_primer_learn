#include "orb_slam2_test.h"
#include <opencv.hpp>

using namespace cv;
using namespace std;

void opencv_test(void)
{
	Size sz(10, 8),sz2(14,12);
	Mat image1(sz, CV_8UC1);
	Mat image(sz, CV_8UC1);
	Mat temp(sz2, CV_8UC1);

	const uchar* center = &image1.at<uchar>(4, 5);

	//这句之后image和temp指向同一个内存
	image = temp(Rect(2, 2, sz.width, sz.height));

	/*copyMakeBorder(image, temp, 2, 2, 2, 2, BORDER_REFLECT_101);

	cout << image.rows << endl << image.cols << endl;*/

	try {
		for (int i = 0; i < image1.rows; ++i)
		{
			for (int j = 0; j < image1.cols; ++j)
			{
				image1.at<uchar>(i, j) = i + 2*j;  //注意单通道和多通道的赋值方式
			}
		}

		for (int i = 0; i < temp.rows; ++i)
		{
			for (int j = 0; j < temp.cols; ++j)
			{
				temp.at<uchar>(i,j) = i+j;  //注意单通道和多通道的赋值方式
			}
		}

		//特别注意：使用image和temp做同样操作输出结果不对。
		cout << "(4,5)poninter method:"<<(int)center[0] <<  "\t" << "(4,5)actual method:"<<(int)image1.at<uchar>(4, 5) << endl;//14 14
		cout << "(4,7)poninter method:" << (int)center[2] << "\t" << "(4,7)actual method:" << (int)image1.at<uchar>(4, 7) << endl;//18 18

		cout << "step:"<< (int)image.step << endl << (int)temp.step << endl; //14,14
		cout << "step1():" << (int)image.step1() << endl << (int)temp.step1() << endl; //14,14

		cout << "image:" << endl << (int)image.at<uchar>(1, 1) << endl << "temp:" << endl << (int)temp.at<uchar>(3, 3) << endl;
		cout << "image_rows:" << image.rows << endl << "image_cols:" << image.cols << endl;
		cout << "sz_width:" << sz.width << endl << "sz_height:" << sz.height << endl;
	        /*输出结果:得x-rows-height，y-cols-width
			image:
		    6
			temp :
			6
			image_rows : 8
			image_cols : 10
			sz_width:10
            sz_height:8*/
		cout << image.row(7).col(0)<<endl;  //第1行对应row（0）

		float distance[4][4];
		for (int i = 0; i < 4;i++)
		{
			distance[i][i] = 0;
			for (int j = i + 1; j < 4;j++)
			{
				distance[i][j] = i+j;
				distance[j][i] = i + j;
			}
		}

		vector<int> dist(distance[1], distance[1] + 3);//dist对应distance[1]前三个元素

		cout << dist[2] << endl;

		sort(dist.begin(), dist.end());

		cout << dist[0] << endl;

	}
	catch (...) {
		throw;
	}


	waitKey(0);
}

void image_operation(void)
{
	Mat image1;
	image1 = imread("1.jpg", 0);

	cout << image1.rows<< endl<<image1.cols<<endl;
	for(int i=0;i<image1.rows/2;i++)
		for (int j = 0; j < image1.cols / 2; j++)
		{
			image1.at<uchar>(i, j) = 120;
		}
	
	namedWindow("小车图",0);
	imshow("小车图",image1);

	imwrite("2.jpg",image1);

	waitKey(0);
}