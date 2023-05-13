/*1953729 信09 吴浩泽*/
/*已验证 1951477 孟宇、1950029 陈竟卓、2051995 朱泽凯、1952087 王鑫伟、2052312 许志康 的hex文件生成*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int change(int x)
{
	switch (x)
	{
		case 'a':
			return 10;
		case 'b':
			return 11;
		case 'c':
			return 12;
		case 'd':
			return 13;
		case 'e':
			return 14;
		case 'f':
			return 15;
		default:
			return x - 48;
	}
}
int main()
{
	FILE* fp, * fp1;
	char fname[100] = { '\0' };
	char fname1[100] = { '\0' };
	fprintf(stderr, "文件名以下形式均可以：\n");
	fprintf(stderr, "    a.txt：不带路径形式\n");
	fprintf(stderr, "    ..\\data\\b.dat：相对路径形式\n");
	fprintf(stderr, "    C:\\Windows\\System32\\c.dat：绝对相对路径形式\n");
	fprintf(stderr, "请输入要转换的hex格式文件名 : ");
	fgets(fname, 100, stdin);
	if (fname[strlen(fname) - 1] == '\n')
		fname[strlen(fname) - 1] = '\0';
	fprintf(stderr, "请输入转换后的文件名 : ");
	fgets(fname1, 100, stdin);
	if (fname1[strlen(fname1) - 1] == '\n')
		fname1[strlen(fname1) - 1] = '\0';
	fp = fopen(fname, "rb");
	fp1 = fopen(fname1, "wb");
	if (fp == NULL)
	{
		printf("文件%s打开失败!\n", fname);
		exit(EXIT_FAILURE);
	}
	if (fp1 == NULL)
	{
		printf("文件%s打开失败!\n", fname1);
		exit(EXIT_FAILURE);
	}
	while (!feof(fp))
	{
		int ch;
		int name[100];
		while (fgetc(fp) != -1)
		{
			fseek(fp, 9L, 1);
			for (int i = 0; i < 34; i++)
			{
				ch = fgetc(fp);
				if (ch == ' ' || ch == '-')
					;
				else
				{
					if (fgetc(fp) != ' ')
					{
						fseek(fp, -2, 1);
						name[0] = fgetc(fp);
						name[1] = fgetc(fp);
						name[0] = change(name[0]);
						name[1] = change(name[1]);
						ch = name[0] * 16 + name[1];
						fputc(ch, fp1);
					}
				}
			}
			while (fgetc(fp) == ' ')
				;
			for (int i = 0; i < 15; i++)
				fgetc(fp);
			if (fgetc(fp) == -1)
				break;
		}
	}
	fclose(fp);
	fclose(fp1);
	return 0;
}