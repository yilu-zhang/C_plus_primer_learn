#include <iostream>
#include <opencv.hpp>

using namespace std;
using namespace cv;

void section_2_2()
{
	int _;
	int Double = 3;
	_ = 4;
	cout << _ << Double << endl;
	waitKey(0);
}

//const test,result:i can change,but that don't influence i2
void section_2_4()
{
	int i = 3;
	const int &i2 = i * 2; //6
	cout << i2 << endl;
	i++;  //test if it can change i
	cout << i2 << endl;  //6
	cout << i*2 << endl; //8
	waitKey(0);

	
}

