/* 1953729 ��09 ����� */
#include <iostream>
using namespace std;
int main()
{
	cout << "������һ��[0-100��)�����:" << endl;
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
	cout << "��д�����:" << endl;
	if (a != 0)
	{
		switch (a)
		{
			case 1:
				cout << "Ҽʰ";
				break;
			case 2:
				cout << "��ʰ";
				break;
			case 3:
				cout << "��ʰ";
				break;
			case 4:
				cout << "��ʰ";
				break;
			case 5:
				cout << "��ʰ";
				break;
			case 6:
				cout << "½ʰ";
				break;
			case 7:
				cout << "��ʰ";
				break;
			case 8:
				cout << "��ʰ";
				break;
			case 9:
				cout << "��ʰ";
				break;
		}
		if (b == 0)
			cout << "��";
	}
	if (b != 0)
	{
		switch (b)
		{
			case 1:
				cout << "Ҽ��";
				break;
			case 2:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 5:
				cout << "����";
				break;
			case 6:
				cout << "½��";
				break;
			case 7:
				cout << "����";
				break;
			case 8:
				cout << "����";
				break;
			case 9:
				cout << "����";
				break;
		}
	}
	if(c!=0)
	{
		switch (c)
		{
			case 1:
				cout << "ҼǪ";
				break;
			case 2:
				cout << "��Ǫ";
				break;
			case 3:
				cout << "��Ǫ";
				break;
			case 4:
				cout << "��Ǫ";
				break;
			case 5:
				cout << "��Ǫ";
				break;
			case 6:
				cout << "½Ǫ";
				break;
			case 7:
				cout << "��Ǫ";
				break;
			case 8:
				cout << "��Ǫ";
				break;
			case 9:
				cout << "��Ǫ";
				break;
		}
		if (d == 0 && e == 0 && f == 0)
			cout << "��";
		if (d == 0 && e == 0 && f != 0)
			cout << "��";
		if (d == 0 && e != 0)
			cout << "��";
	}
	if(d!=0)
	{
		if ((a != 0 || b != 0) && c == 0)
			cout << "��";
		switch (d)
		{
			case 1:
				cout << "Ҽ��";
				break;
			case 2:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 5:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 7:
				cout << "���";
				break;
			case 8:
				cout << "�ư�";
				break;
			case 9:
				cout << "����";
				break;
		}
		if (e == 0 && f == 0)
			cout << "��";
		if (e == 0 && f != 0)
			cout << "��";
	}
	if(e!=0)
	{
		if ((a != 0 || b != 0) && (d == 0 && c == 0))
			cout << "��";
		switch (e)
		{
			case 1:
				cout << "Ҽʰ";
				break;
			case 2:
				cout << "��ʰ";
				break;
			case 3:
				cout << "��ʰ";
				break;
			case 4:
				cout << "��ʰ";
				break;
			case 5:
				cout << "��ʰ";
				break;
			case 6:
				cout << "½ʰ";
				break;
			case 7:
				cout << "��ʰ";
				break;
			case 8:
				cout << "��ʰ";
				break;
			case 9:
				cout << "��ʰ";
				break;
		}
		if (f == 0)
			cout << "��";
	}
	if(f!=0)
	{
		if ((a != 0 || b != 0) && c == 0 && d == 0 && e == 0)
			cout << "��";
		switch (f)
		{
			case 1:
				cout << "Ҽ��";
				break;
			case 2:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 5:
				cout << "����";
				break;
			case 6:
				cout << "½��";
				break;
			case 7:
				cout << "����";
				break;
			case 8:
				cout << "����";
				break;
			case 9:
				cout << "����";
				break;
		}
	}
	if(g!=0)
	{
		switch (g)
		{
			case 1:
				cout << "ҼǪ";
				break;
			case 2:
				cout << "��Ǫ";
				break;
			case 3:
				cout << "��Ǫ";
				break;
			case 4:
				cout << "��Ǫ";
				break;
			case 5:
				cout << "��Ǫ";
				break;
			case 6:
				cout << "½Ǫ";
				break;
			case 7:
				cout << "��Ǫ";
				break;
			case 8:
				cout << "��Ǫ";
				break;
			case 9:
				cout << "��Ǫ";
				break;
		}
		if (h == 0 && i == 0 && j == 0)
			cout << "Բ";
		if (h == 0 && i == 0 && j != 0)
			cout << "��";
		if (h == 0 && i != 0)
			cout << "��";
	}
	if(h!=0)
	{
		if ((a != 0 || b != 0) && g == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0)
			cout << "��";
		switch (h)
		{
			case 1:
				cout << "Ҽ��";
				break;
			case 2:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 5:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 7:
				cout << "���";
				break;
			case 8:
				cout << "�ư�";
				break;
			case 9:
				cout << "����";
				break;
		}
		if (i == 0 && j == 0)
			cout << "Բ";
		if (i == 0 && j != 0)
			cout << "��";
	}
	if(i!=0)
	{
		if ((a != 0 || b != 0) && g == 0 && h == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0)
			cout << "��";
		switch (i)
		{
			case 1:
				cout << "Ҽʰ";
				break;
			case 2:
				cout << "��ʰ";
				break;
			case 3:
				cout << "��ʰ";
				break;
			case 4:
				cout << "��ʰ";
				break;
			case 5:
				cout << "��ʰ";
				break;
			case 6:
				cout << "½ʰ";
				break;
			case 7:
				cout << "��ʰ";
				break;
			case 8:
				cout << "��ʰ";
				break;
			case 9:
				cout << "��ʰ";
				break;
		}
		if (j == 0)
			cout << "Բ";
	}
	if(j!=0)
	{
		if ((a != 0 || b != 0) && g == 0 && h == 0 && i == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0 && i == 0)
			cout << "��";
		switch (j)
		{
			case 1:
				cout << "ҼԲ";
				break;
			case 2:
				cout << "��Բ";
				break;
			case 3:
				cout << "��Բ";
				break;
			case 4:
				cout << "��Բ";
				break;
			case 5:
				cout << "��Բ";
				break;
			case 6:
				cout << "½Բ";
				break;
			case 7:
				cout << "��Բ";
				break;
			case 8:
				cout << "��Բ";
				break;
			case 9:
				cout << "��Բ";
				break;
		}
	}
	if ((a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0 && i == 0 && j == 0)
		cout << "Բ";
	if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && x1 == 0 && x2 == 0)
		cout << "��Բ";
	if (x1 == 0 && x2 == 0)
		cout << "��";
	if(x1!=0)
	{
		switch (x1)
		{
			case 1:
				cout << "Ҽ��";
				break;
			case 2:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 5:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 7:
				cout << "���";
				break;
			case 8:
				cout << "�ƽ�";
				break;
			case 9:
				cout << "����";
				break;
		}
		if (x2 == 0)
			cout << "��";
	}
	if(x2!=0)
	{
		if ((a != 0 || b != 0) && x1 == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && x1 == 0 || (g != 0 || h != 0 || i != 0 || j != 0) && x1 == 0)
			cout << "��";
		switch (x2)
		{
			case 1:
				cout << "Ҽ��";
				break;
			case 2:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 5:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 7:
				cout << "���";
				break;
			case 8:
				cout << "�Ʒ�";
				break;
			case 9:
				cout << "����";
				break;
		}
	}
	cout << endl;
	return 0;
}
