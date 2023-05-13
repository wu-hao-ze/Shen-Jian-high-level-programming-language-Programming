#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum class ITEM_TYPE { 
	Int,		//Ϊ�����int��ͻ����������ĸ��д��ʽ
	Double,
	String,
	Character,
	Null
};

#define OPEN_OPT_RDONLY		0	//��ֻ����ʽ�򿪣��򲻿��򷵻�ʧ�ܣ�
#define OPEN_OPT_RDWR		1	//�Զ�д��ʽ�򿪣��򲻿��ļ��򴴽���

/* ---------------------------------------------------------------
	 �������������Ҫ�Ķ���
	 constȫ�ֱ���/staticȫ�ֱ���(����)/define/class/struct/enum/enum class/union��
   ---------------------------------------------------------------- */



/* ---------------------------------------------------------------
	 class CFT�Ķ��壬���в��ֲ�Ҫ��������protected����������Ҫ�Ķ���
   ---------------------------------------------------------------- */
class CFT {
protected:
	string filename;
	fstream fp;

	int file_resize(int newsize);

	/* ---------------------------------------------------------------
		 �������������Ҫ�Ķ��壨�ڲ��ã�
	   ---------------------------------------------------------------- */

public:
	CFT();							//�޲ι��죬��filenameΪ""����
	CFT(const char* cfgname, int opt = OPEN_OPT_RDONLY);	//���ι��죬����ͬopen
	~CFT();							//����

	void open(const char* cfgname, int opt = OPEN_OPT_RDONLY);
	void close();

	/* ��������ɾ�� */
	int group_add(const char* group_name);
	int group_del(const char* group_name);

	/* �����ӣ����������� */
	int item_add(const char* group_name, const char* item_name, const int item_value);
	int item_add(const char* group_name, const char* item_name, const double item_value);
	int item_add(const char* group_name, const char* item_name, const char *item_value);
	int item_add(const char* group_name, const char* item_name, const string &item_value);
	int item_add(const char* group_name, const char* item_name, const char item_value);
	int item_add(const char* group_name, const char* item_name);	//NULL

	/* ��ɾ�� */
	int item_del(const char* group_name, const char* item_name);

	/* ����£����������� */
	int item_update(const char* group_name, const char* item_name, const int item_value);
	int item_update(const char* group_name, const char* item_name, const double item_value);
	int item_update(const char* group_name, const char* item_name, const char* item_value);
	int item_update(const char* group_name, const char* item_name, const string &item_value);
	int item_update(const char* group_name, const char* item_name, const char item_value);
	int item_update(const char* group_name, const char* item_name);	//NULL

	/* ȡĳ���ֵ������������ */
	int item_get_value(const char* group_name, const char* item_name, int &item_value);
	int item_get_value(const char* group_name, const char* item_name, double &item_value);
	int item_get_value(const char* group_name, const char* item_name, char *item_value);
	int item_get_value(const char* group_name, const char* item_name, string &item_value);
	int item_get_value(const char* group_name, const char* item_name, char &item_value);
	int item_get_value(const char* group_name, const char* item_name);

	/* ---------------------------------------------------------------
		 ���������������Ҫ�Ķ��壨��������ֵ�ֻ���������
	   ---------------------------------------------------------------- */
};

