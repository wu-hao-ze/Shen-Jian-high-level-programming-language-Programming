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
  函数名称：
  功    能：显示提示信息
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void to_be_continued(const char *prompt)
{
	if (prompt)
		cout << prompt << "，按回车键继续...";
	else
		cout << "按回车键继续...";

	/* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
	while (_getch() != '\r')
		;
	cout << endl;

	return;
}

/***************************************************************************
  函数名称：
  功    能：因为cfg_item中含有共用体，共用体只能初始化第一项，因此用函数初始化
  输入参数：
  返 回 值：
  说    明：
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int test_readconfig_cpp(const char *cfgname, const char **group_name, struct cfg_item *item)
{
	CFT fcfg;
	int ret, i;
	char tmp[256];

	/* 第一次模拟，添加若干组 */
	if (1) {
		remove(cfgname); //删除文件

		if (fcfg.open(cfgname, OPEN_OPT_RDWR)==0) {
			cout << "无法打开配置文件(" << cfgname << ")." << endl;
			return -1;
		}
		for (i = 0; group_name[i]; i++) {
			if ((ret = fcfg.group_add(group_name[i])) <= 0)
				cout << "增加[" << group_name[i] << "]失败." << endl;
			else
				cout << "增加[" << group_name[i] << "]成功." << endl;
		}
		fcfg.close(); //关闭文件，模拟本次设置完成

		sprintf(tmp, "请打开配置文件%s，观察是否仅有8个空组", cfgname);
		to_be_continued(tmp);
	}

	/* 第二次模拟，每组添加若干项 */
	if (1) {
		int j;

		if (fcfg.open(cfgname, OPEN_OPT_RDWR) == 0) {
			cout << "无法打开配置文件(" << cfgname << ")." << endl;
			return -1;
		}

		for (i = 0; group_name[i]; i++) {
			for (j = 0; item[j].cfg_item_name; j++) {
				sprintf(tmp, "%s-%s", group_name[i], item[j].cfg_item_name);
				/* 说明：item_add的第3个参数是void*，因此不管什么类型，均传入union第一个成员的地址，即其它成员地址 */
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
				cout << "增加[" << group_name[i] << "]/" << tmp << (ret > 0 ? "成功." : "失败.") << endl;
			}
		}
		fcfg.close(); //关闭文件，模拟本次设置完成

		sprintf(tmp, "请打开配置文件%s，观察是否8个组均有6个配置项", cfgname);
		to_be_continued(tmp);
	}

	/* 第三次模拟，删除组及项 */
	if (1) {
		sprintf(tmp, "请打开配置文件%s，将[配置组3]复制若干份，配置组2-设置项B复制若干份，且后面的值类型不同", cfgname);
		to_be_continued(tmp);

		if (fcfg.open(cfgname, OPEN_OPT_RDWR) == 0) {
			cout << "无法打开配置文件(" << cfgname << ")." << endl;
			return -1;
		}

		cout << "删除[配置组3]共" << fcfg.group_del("配置组3")<< "组" << endl;
		cout << "删除[配置组5]共" << fcfg.group_del("配置组5") << "组" << endl;

		cout << "删除<配置组2-设置项B>共" << fcfg.item_del("配置组2", "配置组2-设置项B") << "项" << endl;

		fcfg.close(); //关闭文件，模拟本次设置完成

		sprintf(tmp, "请打开配置文件%s，观察[配置组3]/[配置组5]/<配置组2-设置项B>是否已被删除", cfgname);
		to_be_continued(tmp);
	}

	/* 第四次模拟，修改项 */
	if (1) {
		if (fcfg.open(cfgname, OPEN_OPT_RDWR) == 0) {
			cout << "无法打开配置文件(" << cfgname << ")." << endl;
			return -1;
		}

		int a = 54321;
		double b = 1023.4567;
		char c = 'N';
		string s = "helloworld<string>";

		/* 已存在项，更新 */
		fcfg.item_update("配置组4", "配置组4-设置项B", a);
		fcfg.item_update("配置组1", "配置组1-设置项D", "helloworld");
		fcfg.item_update("配置组8", "配置组8-设置项E", b);
		fcfg.item_update("配置组6", "配置组6-设置项F");
		fcfg.item_update("配置组7", "配置组7-设置项C", c);
		fcfg.item_update("配置组2", "配置组2-设置项D", s);

		/* 不存在项，新增 */
		fcfg.item_update("配置组6", "配置组6-设置项U");
		fcfg.item_update("配置组7", "配置组7-设置项V", c);
		fcfg.item_update("配置组7", "配置组6-设置项W");
		fcfg.item_update("配置组4", "配置组4-设置项X", a);
		fcfg.item_update("配置组1", "配置组1-设置项Y", "helloworld");
		fcfg.item_update("配置组8", "配置组8-设置项Z", b);
		fcfg.item_update("配置组2", "配置组2-设置项Q", s);
		fcfg.close(); //关闭文件，模拟本次设置完成

		sprintf(tmp, "请打开配置文件%s，观察上述配置是否已修改", cfgname);
		to_be_continued(tmp);
	}

	/* 第五次模拟，读 */
	if (1) {
		if (fcfg.open(cfgname, OPEN_OPT_RDONLY) == 0) {
			cout << "无法打开配置文件(" << cfgname << ")." << endl;
			return -1;
		}

		int a;
		double b;
		char c, s[80];
		string ss;

		/* 已存在项，更新 */
		if (fcfg.item_get_value("配置组4", "配置组4-设置项B", a)>0)
			printf("[配置组4]/配置组4-设置项B=%d\n", a);
		if (fcfg.item_get_value("配置组1", "配置组1-设置项F", a)>0)
			printf("[配置组1]/配置组1-设置项F=%d\n", a);
		if (fcfg.item_get_value("配置组6", "配置组6-设置项D", c)>0)
			printf("[配置组6]/配置组6-设置项D=%c\n", c);
		if (fcfg.item_get_value("配置组8", "配置组8-设置项C", s)>0)
			printf("[配置组8]/配置组8-设置项C=%s\n", s);
		if (fcfg.item_get_value("配置组2", "配置组2-设置项Q", ss) > 0)
			printf("[配置组2]/配置组2-设置项Q=%s\n", ss.c_str());
		if (fcfg.item_get_value("配置组7", "配置组7-设置项E")>0)
			printf("[配置组7]/配置组7-设置项E=<NULL>\n");
		if (fcfg.item_get_value("配置组6", "配置组6-设置项B", b)>0)
			printf("[配置组6]/配置组6-设置项B=%f\n", b);
		if (fcfg.item_get_value("配置组1", "设置项100")>0)
			printf("[配置组1]/设置项100=<NULL>\n");
		else
			printf("[配置组1]/设置项100 不存在\n");

		fcfg.close(); //关闭文件，模拟本次设置完成

		sprintf(tmp, "请打开配置文件%s，观察上述配置读取是否正确", cfgname);
		to_be_continued(tmp);
	}

	return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	const char *cfgname = "c1.cfg";
	const char *group_name[] = {
		"配置组1",
		"配置组2",
		"配置组3",
		"配置组4",
		"配置组5",
		"配置组6",
		"配置组7",
		"配置组8",
		NULL
	};

	struct cfg_item item[] =
	{
		{ "设置项A",ITEM_TYPE::Int, 0 },		//共用体union的初始化，只能初始化第一个元素
		{ "设置项B", ITEM_TYPE::Double, 0 },
		{ "设置项C",ITEM_TYPE::String, 0 },
		{ "设置项D",ITEM_TYPE::Character, 0 },
		{ "设置项E", ITEM_TYPE::Null, 0 },
		{ "设置项F",ITEM_TYPE::Int, 0 },
		{ "设置项G",ITEM_TYPE::String, 0 },
		{ NULL,ITEM_TYPE::Null, 0 }
	};
	set_item(item); //给union赋初值

	test_readconfig_cpp(cfgname, group_name, item);

	return 0;
}