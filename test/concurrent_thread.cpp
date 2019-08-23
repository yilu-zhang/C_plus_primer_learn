#include "concurrent_thread.h"
#include <opencv.hpp>
#include <iostream>
#include <thread> 
#include <mutex>

using namespace std;
using namespace cv;

mutex mu;
mutex mu2;
void share_print(string s, int id)
{
	//若在lock之后出现意外，会造成死锁
	//mu.lock();
	//cout << s << id << endl;
	//mu.unlock();

	//guard会自动在析构函数解锁，即使发生异常
	//这里cout是全局变量，在其他线程被调用还是会相互影响，更好的方法是用ofstream，用类来定义
	//lock_guard<mutex> guard(mu);
	//lock_guard<mutex> guard2(mu2);

	unique_lock<mutex> loker(mu, defer_lock);// 1 std::def_lock 留下未上锁的互斥量
	loker.lock();
	cout << s << id << endl; //cout是一个ofstream一样的变量
	loker.unlock();
}

void share_print2(string s, int id)
{
	//若在lock之后出现意外，会造成死锁
	//mu.lock();
	//cout << s << id << endl;
	//mu.unlock();

	//guard会自动在析构函数解锁，即使发生异常
	//这里cout是全局变量，在其他线程被调用还是会相互影响，更好的方法是用ofstream，用类来定义
	lock_guard<mutex> guard(mu);
	//lock_guard<mutex> guard2(mu2);
	cout << s << id << endl;


	//unique_lock<mutex> loker(mu,defer_lock);
	//cout << s << id << endl;
	//loker.lock();
	//loker.unlock();
}

void thread_mutex_1(void)
{
	//cout << "hello concurent world!" << endl;
	//cout << "thread_mutex_1_id:" << this_thread::get_id() << endl;
	for (int i = 0; i < 100; i++)
	{
		share_print("from_thread_mutex_1:", i);
	}
}

void thread_1(void)
{
	cout << "hello concurent world!" << endl;
	cout << "thread_1_id:" << this_thread::get_id() << endl;
	for (int i = 0; i < 10;i++)
	{
		lock_guard<mutex> guard(mu);
		cout << "from thread_1:" << i << endl;
	}
	//waitKey(0);
}

class thread_2
{
public:
	void operator()(string &msg) {
		cout << "hello concurent world!" << endl;
		cout << "thread_2_id:" << this_thread::get_id() << endl;
		for (int i = 0; i < 10; i++)
		{
			lock_guard<mutex> guard(mu);
			cout << "from thread_2:" << i << endl;
		}

		msg = "i love c++";
		//waitKey(0);
	}


	//void operator()(string msg) {
	//	cout << "hello concurent world!" << endl;
	//	cout << "thread_2_id:" << this_thread::get_id() << endl;
	//	for (int i = 0; i < 10; i++)
	//	{
	//		cout << "from thread_2:" << i << endl;
	//	}

	//	msg = "i love c++";
	//	//waitKey(0);
	//}
};

void concurren_thread_main(void)
{
	string s1 = "i love slam!";
	string s2 = "i love slam!";
	thread_2 thread_2_fact;

	thread t1(thread_1);
	thread t2(thread_2_fact,s1); //可以是任何可被调用的对象
	thread t3((thread_2()),ref(s2));  //类的另外一种声明方式
	//thread t3((thread_2()), move(s2));  //类的另外一种声明方式,移动不好理解

	try {
		//t.join(); //加入式，等待t线程完成
		//t.detach();//分离式，加上这句，主线程先结束不会报错，但主线程结束会销毁一些变量，若t线程有使用则会造成未定义错误
		cout << "hardware_concurrency:" << thread::hardware_concurrency() << endl;  //返回的是核心数：4
		cout << "main_thread_id:" << this_thread::get_id() << endl;
		//cout << "all_thread_id:" << (int)(thread::id) << endl;
		for (int i = 0; i < 10;i++)
		{
			lock_guard<mutex> guard(mu);
			cout << "from main:" << i << endl;
		}
	}
	catch (...) {
		t1.join();
		t2.join();
		t3.join();
		throw;
	}
	
	if (t1.joinable())
	{
		t1.join();
	}

	t2.join();
	cout <<"from thread_2:" << s1 << endl; //观察s是否被改变,不变

	t3.join();
	cout << "from thread_3:" << s2 << endl; //观察s是否被改变，改变

	waitKey(0);
}

void concurrent_thread_mutex_main(void)
{
	thread mutex_t1(thread_mutex_1);

	for (int i = 0; i < 100; i++)
	{
		share_print2("from_thread_mutex_1:", i);
	}

	mutex_t1.join();

	waitKey(0);
}
/*未加互斥量的输出
hello concurent world!hello concurent world!
hardware_concurrency:hello concurent world!

	4
	thread_2_id : main_thread_id : thread_1_id : 1156011344
	18200
	from main : 0
	thread_2_id : 14992
	from thread_2 : 0from main : 1
	from thread_1 : 0

	from main : 2
	from thread_2 : from thread_2 : from main : 3
	1

	0
	from thread_2 : 2
	from thread_2 : 1from main : from thread_1 : from thread_2 : 3
	4
	1
*/

/*加互斥量后打印结果
from_thread_mutex_1:0
from_thread_mutex_1:0
from_thread_mutex_1:1
from_thread_mutex_1:1
from_thread_mutex_1:2
from_thread_mutex_1:2
from_thread_mutex_1:3
from_thread_mutex_1:3
from_thread_mutex_1:4
from_thread_mutex_1:4
from_thread_mutex_1:5
from_thread_mutex_1:5
from_thread_mutex_1:6
from_thread_mutex_1:6
from_thread_mutex_1:7
from_thread_mutex_1:7
from_thread_mutex_1:8
from_thread_mutex_1:8
from_thread_mutex_1:9
from_thread_mutex_1:9
*/

