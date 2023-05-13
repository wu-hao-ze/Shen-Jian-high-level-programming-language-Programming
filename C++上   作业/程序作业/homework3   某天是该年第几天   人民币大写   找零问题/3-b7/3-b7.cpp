/* 1953729 –≈09 Œ‚∫∆‘Û */
#include <iostream>
using namespace std;
int main()
{
	cout << "«Î ‰»Î“ª∏ˆ[0-100“⁄)º‰µƒ ˝:" << endl;
	double n;
	cin >> n;
	int a = (int)((long long int)(n) / 1000000000);
	int b = (int)((long long int)(n) / 100000000 % 10);
	int c = (int)((long long int)(n) / 10000000 % 10);
	int d = (int)((long long int)(n) / 1000000 % 10);
	int e = (int)((long long int)(n) / 100000 % 10);
	int f = (int)((long long int)(n) / 10000 % 10);
	int g = (int)((long long int)(n) / 1000 % 10);
	int h = (int)((long long int)(n) / 100 % 10);
	int i = (int)((long long int)(n) / 10 % 10);
	int j = (int)((long long int)(n) % 10);
	long long int t = (long long int)(n);
	double x = n - t + 0.0004;
	int x1 = (int)(x * 10) % 10;
	int x2 = (int)(x * 100) % 10;
	cout << "¥Û–¥Ω·π˚ «:" << endl;
	if (a != 0)
	{
		switch (a)
		{
			case 1:
				cout << "“º ∞";
				break;
			case 2:
				cout << "∑° ∞";
				break;
			case 3:
				cout << "»˛ ∞";
				break;
			case 4:
				cout << "À¡ ∞";
				break;
			case 5:
				cout << "ŒÈ ∞";
				break;
			case 6:
				cout << "¬Ω ∞";
				break;
			case 7:
				cout << "∆‚ ∞";
				break;
			case 8:
				cout << "∞∆ ∞";
				break;
			case 9:
				cout << "æ¡ ∞";
				break;
		}
		if (b == 0)
			cout << "“⁄";
	}
	if (b != 0)
	{
		switch (b)
		{
			case 1:
				cout << "“º“⁄";
				break;
			case 2:
				cout << "∑°“⁄";
				break;
			case 3:
				cout << "»˛“⁄";
				break;
			case 4:
				cout << "À¡“⁄";
				break;
			case 5:
				cout << "ŒÈ“⁄";
				break;
			case 6:
				cout << "¬Ω“⁄";
				break;
			case 7:
				cout << "∆‚“⁄";
				break;
			case 8:
				cout << "∞∆“⁄";
				break;
			case 9:
				cout << "æ¡“⁄";
				break;
		}
	}
	if(c!=0)
	{
		switch (c)
		{
			case 1:
				cout << "“º«™";
				break;
			case 2:
				cout << "∑°«™";
				break;
			case 3:
				cout << "»˛«™";
				break;
			case 4:
				cout << "À¡«™";
				break;
			case 5:
				cout << "ŒÈ«™";
				break;
			case 6:
				cout << "¬Ω«™";
				break;
			case 7:
				cout << "∆‚«™";
				break;
			case 8:
				cout << "∞∆«™";
				break;
			case 9:
				cout << "æ¡«™";
				break;
		}
		if (d == 0 && e == 0 && f == 0)
			cout << "ÕÚ";
		if (d == 0 && e == 0 && f != 0)
			cout << "¡„";
		if (d == 0 && e != 0)
			cout << "¡„";
	}
	if(d!=0)
	{
		if ((a != 0 || b != 0) && c == 0)
			cout << "¡„";
		switch (d)
		{
			case 1:
				cout << "“º∞€";
				break;
			case 2:
				cout << "∑°∞€";
				break;
			case 3:
				cout << "»˛∞€";
				break;
			case 4:
				cout << "À¡∞€";
				break;
			case 5:
				cout << "ŒÈ∞€";
				break;
			case 6:
				cout << "¬Ω∞€";
				break;
			case 7:
				cout << "∆‚∞€";
				break;
			case 8:
				cout << "∞∆∞€";
				break;
			case 9:
				cout << "æ¡∞€";
				break;
		}
		if (e == 0 && f == 0)
			cout << "ÕÚ";
		if (e == 0 && f != 0)
			cout << "¡„";
	}
	if(e!=0)
	{
		if ((a != 0 || b != 0) && (d == 0 && c == 0))
			cout << "¡„";
		switch (e)
		{
			case 1:
				cout << "“º ∞";
				break;
			case 2:
				cout << "∑° ∞";
				break;
			case 3:
				cout << "»˛ ∞";
				break;
			case 4:
				cout << "À¡ ∞";
				break;
			case 5:
				cout << "ŒÈ ∞";
				break;
			case 6:
				cout << "¬Ω ∞";
				break;
			case 7:
				cout << "∆‚ ∞";
				break;
			case 8:
				cout << "∞∆ ∞";
				break;
			case 9:
				cout << "æ¡ ∞";
				break;
		}
		if (f == 0)
			cout << "ÕÚ";
	}
	if(f!=0)
	{
		if ((a != 0 || b != 0) && c == 0 && d == 0 && e == 0)
			cout << "¡„";
		switch (f)
		{
			case 1:
				cout << "“ºÕÚ";
				break;
			case 2:
				cout << "∑°ÕÚ";
				break;
			case 3:
				cout << "»˛ÕÚ";
				break;
			case 4:
				cout << "À¡ÕÚ";
				break;
			case 5:
				cout << "ŒÈÕÚ";
				break;
			case 6:
				cout << "¬ΩÕÚ";
				break;
			case 7:
				cout << "∆‚ÕÚ";
				break;
			case 8:
				cout << "∞∆ÕÚ";
				break;
			case 9:
				cout << "æ¡ÕÚ";
				break;
		}
	}
	if(g!=0)
	{
		switch (g)
		{
			case 1:
				cout << "“º«™";
				break;
			case 2:
				cout << "∑°«™";
				break;
			case 3:
				cout << "»˛«™";
				break;
			case 4:
				cout << "À¡«™";
				break;
			case 5:
				cout << "ŒÈ«™";
				break;
			case 6:
				cout << "¬Ω«™";
				break;
			case 7:
				cout << "∆‚«™";
				break;
			case 8:
				cout << "∞∆«™";
				break;
			case 9:
				cout << "æ¡«™";
				break;
		}
		if (h == 0 && i == 0 && j == 0)
			cout << "‘≤";
		if (h == 0 && i == 0 && j != 0)
			cout << "¡„";
		if (h == 0 && i != 0)
			cout << "¡„";
	}
	if(h!=0)
	{
		if ((a != 0 || b != 0) && g == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0)
			cout << "¡„";
		switch (h)
		{
			case 1:
				cout << "“º∞€";
				break;
			case 2:
				cout << "∑°∞€";
				break;
			case 3:
				cout << "»˛∞€";
				break;
			case 4:
				cout << "À¡∞€";
				break;
			case 5:
				cout << "ŒÈ∞€";
				break;
			case 6:
				cout << "¬Ω∞€";
				break;
			case 7:
				cout << "∆‚∞€";
				break;
			case 8:
				cout << "∞∆∞€";
				break;
			case 9:
				cout << "æ¡∞€";
				break;
		}
		if (i == 0 && j == 0)
			cout << "‘≤";
		if (i == 0 && j != 0)
			cout << "¡„";
	}
	if(i!=0)
	{
		if ((a != 0 || b != 0) && g == 0 && h == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0)
			cout << "¡„";
		switch (i)
		{
			case 1:
				cout << "“º ∞";
				break;
			case 2:
				cout << "∑° ∞";
				break;
			case 3:
				cout << "»˛ ∞";
				break;
			case 4:
				cout << "À¡ ∞";
				break;
			case 5:
				cout << "ŒÈ ∞";
				break;
			case 6:
				cout << "¬Ω ∞";
				break;
			case 7:
				cout << "∆‚ ∞";
				break;
			case 8:
				cout << "∞∆ ∞";
				break;
			case 9:
				cout << "æ¡ ∞";
				break;
		}
		if (j == 0)
			cout << "‘≤";
	}
	if(j!=0)
	{
		if ((a != 0 || b != 0) && g == 0 && h == 0 && i == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0 && i == 0)
			cout << "¡„";
		switch (j)
		{
			case 1:
				cout << "“º‘≤";
				break;
			case 2:
				cout << "∑°‘≤";
				break;
			case 3:
				cout << "»˛‘≤";
				break;
			case 4:
				cout << "À¡‘≤";
				break;
			case 5:
				cout << "ŒÈ‘≤";
				break;
			case 6:
				cout << "¬Ω‘≤";
				break;
			case 7:
				cout << "∆‚‘≤";
				break;
			case 8:
				cout << "∞∆‘≤";
				break;
			case 9:
				cout << "æ¡‘≤";
				break;
		}
	}
	if ((a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0 && i == 0 && j == 0)
		cout << "‘≤";
	if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && x1 == 0 && x2 == 0)
		cout << "¡„‘≤";
	if (x1 == 0 && x2 == 0)
		cout << "’˚";
	if(x1!=0)
	{
		switch (x1)
		{
			case 1:
				cout << "“ºΩ«";
				break;
			case 2:
				cout << "∑°Ω«";
				break;
			case 3:
				cout << "»˛Ω«";
				break;
			case 4:
				cout << "À¡Ω«";
				break;
			case 5:
				cout << "ŒÈΩ«";
				break;
			case 6:
				cout << "¬ΩΩ«";
				break;
			case 7:
				cout << "∆‚Ω«";
				break;
			case 8:
				cout << "∞∆Ω«";
				break;
			case 9:
				cout << "æ¡Ω«";
				break;
		}
		if (x2 == 0)
			cout << "’˚";
	}
	if(x2!=0)
	{
		if ((a != 0 || b != 0) && x1 == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && x1 == 0 || (g != 0 || h != 0 || i != 0 || j != 0) && x1 == 0)
			cout << "¡„";
		switch (x2)
		{
			case 1:
				cout << "“º∑÷";
				break;
			case 2:
				cout << "∑°∑÷";
				break;
			case 3:
				cout << "»˛∑÷";
				break;
			case 4:
				cout << "À¡∑÷";
				break;
			case 5:
				cout << "ŒÈ∑÷";
				break;
			case 6:
				cout << "¬Ω∑÷";
				break;
			case 7:
				cout << "∆‚∑÷";
				break;
			case 8:
				cout << "∞∆∑÷";
				break;
			case 9:
				cout << "æ¡∑÷";
				break;
		}
	}
	cout << endl;
	return 0;
}
