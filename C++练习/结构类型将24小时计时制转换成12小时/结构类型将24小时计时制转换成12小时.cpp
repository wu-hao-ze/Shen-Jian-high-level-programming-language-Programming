#include<iostream>
#include<cmath>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
struct time
{
	int hour;
	int minute;
	int second;
};
struct time change(struct time t)
{
	t.hour = t.hour % 12;
	return t;
}int main()
{
	struct time t;
	cin >> t.hour >> t.minute >> t.second;
	if (t.hour > 12)
	{
		t = change(t);
		cout << t.hour << t.minute << t.second << "pm";
	}
	else cout << t.hour << t.minute << t.second << "am";

}



