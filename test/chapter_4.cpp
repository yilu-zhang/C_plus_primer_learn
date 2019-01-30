#include <iostream>
#include <opencv.hpp>

using namespace std;
using namespace cv;

void section_4_2()
{
	bool b = -1;
	cout << "bool b:" << b << endl; //1

	short m,n;
	m = 5;
	n = -3;
	cout << "the divider is - and the dividend is + of %:"\
		<< m % n << endl; //2
	m = -m;
	n = -n;
	cout << "the divider is + and the dividend is - of %:"\
		<< m % n << endl;  //-2

	n = -n;
	cout << "the divider is - and the dividend is - of %:"\
		<< m % n << endl;  //-2

	waitKey(0);
}

void section_4_11()
{
	//test cal
	int i = 1.6 + 2.6 + 2;
	cout << "after trans i:" << i << endl; //6

	//test int convert to unsigned int
	unsigned int un_int = 1;
	int int_1(-2),int_2,int_3;
	cout << "usigned int size:" << sizeof(unsigned int) << endl\
		<<"int size:" << sizeof(int) << endl; //4,4
	cout << "integral promotion:" << un_int + int_1 << endl; //4294967295
	int_2 = int_3 = 4294967200;
	cout << "test overflow:" << int_2 + int_3 << endl; //no error,output-192
	waitKey(0);
}
