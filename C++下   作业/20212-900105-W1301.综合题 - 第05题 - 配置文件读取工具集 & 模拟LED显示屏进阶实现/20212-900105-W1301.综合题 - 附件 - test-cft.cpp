#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

#include "../include/cfg_file_tools.h"

union cfg_value {
	int ivalue;
	double dvalue;
	char svalue[128];
	char cvalue;
	void *value;
};

struct cfg_item {
	const char *cfg_item_name;
	enum ITEM_TYPE cfg_item_type;
	union cfg_value cfg_item_value;
};

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��ʾ��Ϣ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
static void to_be_continued(const char *prompt)
{
	if (prompt)
		cout << prompt << "�����س�������...";
	else
		cout << "���س�������...";

	/* ���Գ��س�������������루ע�⣺_getch�Ļس���\r����getchar��\n��*/
	while (_getch() != '\r')
		;
	cout << endl;

	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���Ϊcfg_item�к��й����壬������ֻ�ܳ�ʼ����һ�����ú�����ʼ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
static void set_item(struct cfg_item *item)
{
	item[0].cfg_item_value.ivalue = 123;
	item[1].cfg_item_value.dvalue = 123.45;
	strcpy(item[2].cfg_item_value.svalue, "Hello");
	item[3].cfg_item_value.cvalue = 'Y';
//	item[4].cfg_item_value.ivalue = 0;
	item[5].cfg_item_value.ivalue = 99999;
	strcpy(item[6].cfg_item_value.svalue, "Hello<String>");
//	item[7].cfg_item_value.ivalue = 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int test_readconfig_cpp(const char *cfgname, const char **group_name, struct cfg_item *item)
{
	CFT fcfg;
	int ret, i;
	char tmp[256];

	/* ��һ��ģ�⣬��������� */
	if (1) {
		remove(cfgname); //ɾ���ļ�

		if (fcfg.open(cfgname, OPEN_OPT_RDWR)==0) {
			cout << "�޷��������ļ�(" << cfgname << ")." << endl;
			return -1;
		}
		for (i = 0; group_name[i]; i++) {
			if ((ret = fcfg.group_add(group_name[i])) <= 0)
				cout << "����[" << group_name[i] << "]ʧ��." << endl;
			else
				cout << "����[" << group_name[i] << "]�ɹ�." << endl;
		}
		fcfg.close(); //�ر��ļ���ģ�Ȿ���������

		sprintf(tmp, "��������ļ�%s���۲��Ƿ����8������", cfgname);
		to_be_continued(tmp);
	}

	/* �ڶ���ģ�⣬ÿ����������� */
	if (1) {
		int j;

		if (fcfg.open(cfgname, OPEN_OPT_RDWR) == 0) {
			cout << "�޷��������ļ�(" << cfgname << ")." << endl;
			return -1;
		}

		for (i = 0; group_name[i]; i++) {
			for (j = 0; item[j].cfg_item_name; j++) {
				sprintf(tmp, "%s-%s", group_name[i], item[j].cfg_item_name);
				/* ˵����item_add�ĵ�3��������void*����˲���ʲô���ͣ�������union��һ����Ա�ĵ�ַ����������Ա��ַ */
				switch (item[j].cfg_item_type) {
					case ITEM_TYPE::Int:
						ret = fcfg.item_add(group_name[i], tmp, item[j].cfg_item_value.ivalue);
						break;
					case ITEM_TYPE::Double:
						ret = fcfg.item_add(group_name[i], tmp, item[j].cfg_item_value.dvalue);
						break;
					case ITEM_TYPE::String:
						if (j==2)
							ret = fcfg.item_add(group_name[i], tmp, item[j].cfg_item_value.svalue);
						else
							ret = fcfg.item_add(group_name[i], tmp, string(item[j].cfg_item_value.svalue));
						break;
					case ITEM_TYPE::Character:
						ret = fcfg.item_add(group_name[i], tmp, item[j].cfg_item_value.cvalue);
						break;
					case ITEM_TYPE::Null:
						ret = fcfg.item_add(group_name[i], tmp);
						break;
					default:
						break;
				}
				cout << "����[" << group_name[i] << "]/" << tmp << (ret > 0 ? "�ɹ�." : "ʧ��.") << endl;
			}
		}
		fcfg.close(); //�ر��ļ���ģ�Ȿ���������

		sprintf(tmp, "��������ļ�%s���۲��Ƿ�8�������6��������", cfgname);
		to_be_continued(tmp);
	}

	/* ������ģ�⣬ɾ���鼰�� */
	if (1) {
		sprintf(tmp, "��������ļ�%s����[������3]�������ɷݣ�������2-������B�������ɷݣ��Һ����ֵ���Ͳ�ͬ", cfgname);
		to_be_continued(tmp);

		if (fcfg.open(cfgname, OPEN_OPT_RDWR) == 0) {
			cout << "�޷��������ļ�(" << cfgname << ")." << endl;
			return -1;
		}

		cout << "ɾ��[������3]��" << fcfg.group_del("������3")<< "��" << endl;
		cout << "ɾ��[������5]��" << fcfg.group_del("������5") << "��" << endl;

		cout << "ɾ��<������2-������B>��" << fcfg.item_del("������2", "������2-������B") << "��" << endl;

		fcfg.close(); //�ر��ļ���ģ�Ȿ���������

		sprintf(tmp, "��������ļ�%s���۲�[������3]/[������5]/<������2-������B>�Ƿ��ѱ�ɾ��", cfgname);
		to_be_continued(tmp);
	}

	/* ���Ĵ�ģ�⣬�޸��� */
	if (1) {
		if (fcfg.open(cfgname, OPEN_OPT_RDWR) == 0) {
			cout << "�޷��������ļ�(" << cfgname << ")." << endl;
			return -1;
		}

		int a = 54321;
		double b = 1023.4567;
		char c = 'N';
		string s = "helloworld<string>";

		/* �Ѵ�������� */
		fcfg.item_update("������4", "������4-������B", a);
		fcfg.item_update("������1", "������1-������D", "helloworld");
		fcfg.item_update("������8", "������8-������E", b);
		fcfg.item_update("������6", "������6-������F");
		fcfg.item_update("������7", "������7-������C", c);
		fcfg.item_update("������2", "������2-������D", s);

		/* ����������� */
		fcfg.item_update("������6", "������6-������U");
		fcfg.item_update("������7", "������7-������V", c);
		fcfg.item_update("������7", "������6-������W");
		fcfg.item_update("������4", "������4-������X", a);
		fcfg.item_update("������1", "������1-������Y", "helloworld");
		fcfg.item_update("������8", "������8-������Z", b);
		fcfg.item_update("������2", "������2-������Q", s);
		fcfg.close(); //�ر��ļ���ģ�Ȿ���������

		sprintf(tmp, "��������ļ�%s���۲����������Ƿ����޸�", cfgname);
		to_be_continued(tmp);
	}

	/* �����ģ�⣬�� */
	if (1) {
		if (fcfg.open(cfgname, OPEN_OPT_RDONLY) == 0) {
			cout << "�޷��������ļ�(" << cfgname << ")." << endl;
			return -1;
		}

		int a;
		double b;
		char c, s[80];
		string ss;

		/* �Ѵ�������� */
		if (fcfg.item_get_value("������4", "������4-������B", a)>0)
			printf("[������4]/������4-������B=%d\n", a);
		if (fcfg.item_get_value("������1", "������1-������F", a)>0)
			printf("[������1]/������1-������F=%d\n", a);
		if (fcfg.item_get_value("������6", "������6-������D", c)>0)
			printf("[������6]/������6-������D=%c\n", c);
		if (fcfg.item_get_value("������8", "������8-������C", s)>0)
			printf("[������8]/������8-������C=%s\n", s);
		if (fcfg.item_get_value("������2", "������2-������Q", ss) > 0)
			printf("[������2]/������2-������Q=%s\n", ss.c_str());
		if (fcfg.item_get_value("������7", "������7-������E")>0)
			printf("[������7]/������7-������E=<NULL>\n");
		if (fcfg.item_get_value("������6", "������6-������B", b)>0)
			printf("[������6]/������6-������B=%f\n", b);
		if (fcfg.item_get_value("������1", "������100")>0)
			printf("[������1]/������100=<NULL>\n");
		else
			printf("[������1]/������100 ������\n");

		fcfg.close(); //�ر��ļ���ģ�Ȿ���������

		sprintf(tmp, "��������ļ�%s���۲��������ö�ȡ�Ƿ���ȷ", cfgname);
		to_be_continued(tmp);
	}

	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	const char *cfgname = "c1.cfg";
	const char *group_name[] = {
		"������1",
		"������2",
		"������3",
		"������4",
		"������5",
		"������6",
		"������7",
		"������8",
		NULL
	};

	struct cfg_item item[] =
	{
		{ "������A",ITEM_TYPE::Int, 0 },		//������union�ĳ�ʼ����ֻ�ܳ�ʼ����һ��Ԫ��
		{ "������B", ITEM_TYPE::Double, 0 },
		{ "������C",ITEM_TYPE::String, 0 },
		{ "������D",ITEM_TYPE::Character, 0 },
		{ "������E", ITEM_TYPE::Null, 0 },
		{ "������F",ITEM_TYPE::Int, 0 },
		{ "������G",ITEM_TYPE::String, 0 },
		{ NULL,ITEM_TYPE::Null, 0 }
	};
	set_item(item); //��union����ֵ

	test_readconfig_cpp(cfgname, group_name, item);

	return 0;
}