#include <iostream>
#include <opencv.hpp>

using namespace std;
using namespace cv;


//test string,typedef,cin+while
//summary:s2 is copy of s1 and copy don't mean that change s1 lead s2 to change 
void section_3_2()
{
	typedef int zhang;
	zhang r = 1;
	string s1;
	string s2 = s1;
	string s3 = s1,s4;
	s1 = "test copy of string";
	s3 = s1;
	cout << "s2 is:" << s2 << endl\
		<< "s3 is:" << s3 << endl
		<< "typedef test:" << r << endl;

	//C++ 11:range for
	s4 = "zhangyilu";
	for (auto c : s4)
	{
		cout << "range for test:"<<c << endl;
	}
	cout << s4 << endl;

	s4 = "zhangyilu";
	for (auto &c : s4)
	{
		c = toupper(c);
		cout << "range for test-toupper:" << c << endl;
	}
	cout << s4 << endl;

	//test cin+while
	//const string hex_digit = "0123456789ABCDEF";
	//cout << "please cin 0-15" << endl << "separated by space.finished by enter" << endl;

	//string result,cin_str;
	//string::size_type num;
	////two while both don't end£¬different from book	P78 and P86
	//while (getline(cin, cin_str))
	//{
	//	cout << cin_str << endl;
	//}

	//while (cin >> num)  
	//{
	//	if (num < hex_digit.size())
	//		result += hex_digit[num];
	//}
	//cout << result << endl;

    //we can use vec(number) init
	vector<int> vec1{ 1,2,3},vec2(10);
	cout << vec1[0]<< endl;
	cout << vec2[3] << endl;

	////must manual init
	//int i;
	//cout << i << endl;

	waitKey(0);
}

void section_3_4()
{
	vector<int> a{ 1,2,3 };
	a.push_back(4);
	cout << "the vector factor:";
	for (auto p = a.begin(); p != a.end(); ++p)
	{
		 cout << *p << '\0';
	}

	waitKey(0);
}

//test pointer array and quote array
void section_3_5()
{
	int arr[5] = { 1,2,3,4,5 };
	int(*arr_ptr)[5] = &arr; //pointer array,include 5 pointers
	int *arr_ptr1 = arr; //include 1 pointer
	int(&arr_quote)[5] = arr;

	cout << "arr_ptr:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << (*arr_ptr)[i]<<'\0'; //result:1,2,3,4,5;wrong expression:*arr_ptr[i]
	}

	cout << endl << "arr_ptr1:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr_ptr1[i] << '\0'; //result:1,2,3,4,5;
	}

	cout << endl << "arr_quote:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr_quote[i] << '\0';  //result:1,2,3,4,5;
	}

	int *arr_end = end(arr);
	cout << endl << "end pointer factor:" << *arr_end<<endl; //uncertin nunber
	cout << "pre end pointer factor:" << *(arr_end - 1) << endl; //5

	cout << "arr address and number:"<<endl;
	for (int i : arr)
	{
		cout << &i <<':'<<i<<'\0';//same address
		//0000003BB294FB74:1 0000003BB294FB74:2 0000003BB294FB74:3 0000003BB294FB74:4 0000003BB294FB74:5
	}

	cout << endl<<"arr address:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << &arr[i] << '\0'; 
		//0000003BB294FA08 0000003BB294FA0C 0000003BB294FA10 0000003BB294FA14 0000003BB294FA18
	}

	waitKey(0);
}