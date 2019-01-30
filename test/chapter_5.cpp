#include "chapter_5.h"
#include <opencv.hpp>

using namespace cv;
using namespace std;

void section_5_4()
{
	//error:for (int i=0,int j=2; i < 3; i++);for (int i=0,double j=2; i < 3; i++)
	for (int i=0,j=2; i < 3; i++) 
	{
		cout << "for test:" << i << j + 1 << endl;
	}

	waitKey(0);
}