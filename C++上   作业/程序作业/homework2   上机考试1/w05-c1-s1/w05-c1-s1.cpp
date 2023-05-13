/*1953729 –≈09 Œ‚∫∆‘Û*/ 
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a = 654321;
	cout << "==========";
	cout << "==========";
	cout << "==========";
	cout << "==========";
	cout << "=========="<<endl;
	cout << setiosflags(ios::left);
	cout << setw(10) << '0' << setw(10) << '1';
	cout << setw(10) << '2' << setw(10) << '3';
	cout << setw(10) << '4'<<endl;
	cout << "0123456789";
	cout << "0123456789";
	cout << "0123456789";
	cout << "0123456789";
	cout << "0123456789"<<endl;
	cout << "==========";
	cout << "==========";
	cout << "==========";
	cout << "==========";
	cout << "==========" << endl;
	cout << a << '#'<<endl;
	cout << setiosflags(ios::uppercase)<<hex << a << '#' << endl;
	cout << resetiosflags(ios::uppercase) << hex << a << '#' << endl;
	cout << setiosflags(ios::uppercase) << hex << a << '#' << endl;
	cout << setiosflags(ios::right);
	cout << setw(10) <<dec<< a << ',';
	cout << resetiosflags(ios::right);
	cout << setw(10) << a << '#' << endl;
	cout << setfill('*') << setw(10) << a << '#' << endl;
	cout << setiosflags(ios::right);
	cout << setfill(' ')<<setw(10)<<a << '#' << endl;
	cout << setiosflags(ios::showpos) << a << '#' << endl;
	cout << resetiosflags(ios::right);
	cout << setw(10) << oct << a << ',';
	cout << setiosflags(ios::right);
	cout << setw(10) << a << '#' << endl;
	cout << setfill('*') << setw(10) << a << '#' << endl;
	cout << resetiosflags(ios::right);
	cout << setfill(' ') << setw(10) << a << '#' << endl;
	return 0;
}
