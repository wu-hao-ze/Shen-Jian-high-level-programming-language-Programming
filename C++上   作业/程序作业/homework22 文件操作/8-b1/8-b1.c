/*1953729 ��09 �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	FILE* fp;
	char fname[100] = { '\0' };
	fprintf(stderr, "�ļ���������ʽ�����ԣ�\n");
	fprintf(stderr, "    a.txt������·����ʽ\n");
	fprintf(stderr, "    ..\\data\\b.dat�����·����ʽ\n");
	fprintf(stderr, "    C:\\Windows\\System32\\c.dat���������·����ʽ\n");
	fprintf(stderr, "�������ļ���: ");
	fgets(fname, 100, stdin);
	if (fname[strlen(fname) - 1] == '\n')
		fname[strlen(fname) - 1] = '\0';
	fp = fopen(fname, "rb");
	if (fp == NULL)
	{
		printf("�ļ�%s��ʧ��!\n", fname);
		exit(EXIT_FAILURE);
	}
	while (!feof(fp))
	{
		if (ftell(fp) % 16 == 0)
		{
			if (ftell(fp) == 0)
			{
				if (fgetc(fp) == -1)
					exit(0);
				else
				{
					fseek(fp, -1L, 1);
					printf("%08x  ", ftell(fp));
				}
			}
			else
			{
				printf("    ");
				fseek(fp, -16L, 1);
				int ch;
				do
				{
					ch = fgetc(fp); 
					if (ch >= 33 && ch <= 126)
						printf("%c", ch);
					else
						printf(".");
				} while (ftell(fp) % 16 != 0);
				if (fgetc(fp) != -1)
				{
					fseek(fp, -1L, 1);
					printf("\n");
					printf("%08x  ", ftell(fp));
				}
				else
					break;
			}
		}
		int ch1 = fgetc(fp);
		if (ch1 == -1)
		{
			int i = ftell(fp);
			while (ftell(fp) % 16 != 0)
				fseek(fp, -1L, 1);
			int j = ftell(fp);
			printf("%*c", 3 * (16 - (i - j)), ' ');
			if ((i - j) < 8)
				printf("      ");
			else
				printf("    ");
			do
			{
				char ch = fgetc(fp);
				if (ch >= 33 && ch <= 126)
					printf("%c", ch);
				else
				{
					if (ch == -1)
						break;
					else
						printf(".");
				}
			} while (ftell(fp) % 16 != 0);
		}
		else
		{
			int ch3 = ch1;
			printf("%02x ", ch3);
			if (ftell(fp) % 8 == 0 && ftell(fp) % 16 != 0)
			{
				int ch2 = fgetc(fp);
				if (ch2 != -1)
				{
					fseek(fp, -1L, 1);
					printf("- ");
				}
				else
				{
					fseek(fp, -1L, 1);
					fgetc(fp);
				}
			}
		}
	}
	printf("\n");
	fclose(fp);
	return 0;
}
