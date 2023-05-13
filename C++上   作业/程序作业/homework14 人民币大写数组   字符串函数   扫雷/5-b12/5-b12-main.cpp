/* -----------------------------------------

     ���ļ�����Ҫ�ύ��������Ķ�

   ----------------------------------------- */

#include <iostream>
#include <cstdio>
#include <conio.h>
using namespace std;

#include "5-b12.h"

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void wait_for_enter()
{
	cout << endl << "���س�������";
	while (_getch() != '\r')
		;
	cout << endl << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����ϸ�ڿ����д������֣��뼰ʱ��ӳ
***************************************************************************/
int main()
{
    if (1) {
        char s1[]="abcdefghijklmnopqrstuvwxyz";
        char s2[]="abcdefghijklmnopqrstuvwxyz\0UVWXYZ";
        char s3[]="";

        cout << "tj_strlen()���Բ��֣�" << endl;
        cout << "1.s1     �ĳ���Ӧ����26��ʵ���ǣ�" << tj_strlen(s1)      << endl;
        cout << "2.s2     �ĳ���Ӧ����26��ʵ���ǣ�" << tj_strlen(s2)      << endl;
        cout << "3.&s2[27]�ĳ���Ӧ����6�� ʵ���ǣ�" << tj_strlen(&s2[27]) << endl;
        cout << "4.s3     �ĳ���Ӧ����0�� ʵ���ǣ�" << tj_strlen(s3)      << endl;

	wait_for_enter();
        }

    if (1) {
        char s1[80]="abcdefghij";
        char s2[]="abcde";
        char s3[]="hello\0UVWXYZ";

        cout << "tj_strcat()���Բ��֣�" << endl;
        cout << "1.s1�����Ӧ����abcdefghij��                ʵ���ǣ�" << s1 << endl;
        cout << "  s1�ĳ���Ӧ����10��                        ʵ���ǣ�" << tj_strlen(s1) << endl;

        tj_strcat(s1, s2);
        cout << "2.s1�����Ӧ����abcdefghijabcde��           ʵ���ǣ�" << s1            << endl;
        cout << "  s1�ĳ���Ӧ����15��                        ʵ���ǣ�" << tj_strlen(s1) << endl;

        tj_strcat(s1, s3);
        cout << "3.s1�����Ӧ����abcdefghijabcdehello��      ʵ���ǣ�" << s1            << endl;
        cout << "  s1�ĳ���Ӧ����20��                        ʵ���ǣ�" << tj_strlen(s1) << endl;

        tj_strcat(s1, &s3[6]);
        cout << "4.s1�����Ӧ����abcdefghijabcdehelloUVWXYZ��ʵ���ǣ�" << s1            << endl;
        cout << "  s1�ĳ���Ӧ����26��                        ʵ���ǣ�" << tj_strlen(s1) << endl;

	wait_for_enter();
	}

    if (1) {
        char s1[80] = "abcdefghij";
        char s2[] = "abcde";
        char s3[] = "hello\0UVWXYZ";

        cout << "tj_strncat()���Բ��֣�" << endl;
        cout << "1.s1�����Ӧ����abcdefghij��                ʵ���ǣ�" << s1 << endl;
        cout << "  s1�ĳ���Ӧ����10��                        ʵ���ǣ�" << tj_strlen(s1) << endl;

        tj_strncat(s1, s2, 3);
        cout << "2.s1�����Ӧ����abcdefghijabc��             ʵ���ǣ�" << s1 << endl;
        cout << "  s1�ĳ���Ӧ����13��                        ʵ���ǣ�" << tj_strlen(s1) << endl;

        tj_strncat(s1, s3, 100);
        cout << "3.s1�����Ӧ����abcdefghijabchello��        ʵ���ǣ�" << s1 << endl;
        cout << "  s1�ĳ���Ӧ����18��                        ʵ���ǣ�" << tj_strlen(s1) << endl;

        tj_strncat(s1, &s3[6], 6);
        cout << "4.s1�����Ӧ����abcdefghijabchelloUVWXYZ��  ʵ���ǣ�" << s1 << endl;
        cout << "  s1�ĳ���Ӧ����24��                        ʵ���ǣ�" << tj_strlen(s1) << endl;

        wait_for_enter();
    }

    if (1) {
        char s1[80]="abcdefghijklm";
        char s2[]="abcde";
        char s3[]="hello\0UVWXYZ";
        char s4[80];

        cout << "tj_strcpy()���Բ��֣�" << endl;
        cout << "1.s1�����Ӧ����abcdefghijklm��   ʵ���ǣ�" << s1            << endl;
        cout << "  s1�ĳ���Ӧ����13��              ʵ���ǣ�" << tj_strlen(s1) << endl;

        tj_strcpy(s1, s2);
        cout << "2.s1�����Ӧ����abcde��           ʵ���ǣ�" << s1            << endl;
        cout << "  s1�ĳ���Ӧ����5��               ʵ���ǣ�" << tj_strlen(s1) << endl;

        tj_strcpy(s1, &s3[6]);
        cout << "3.s1�����Ӧ����UVWXYZ��          ʵ���ǣ�" << s1            << endl;
        cout << "  s1�ĳ���Ӧ����6��               ʵ���ǣ�" << tj_strlen(s1) << endl;

        tj_strcpy(s1, s3);
        cout << "4.s1�����Ӧ����hello��           ʵ���ǣ�" << s1            << endl;
        cout << "  s1�ĳ���Ӧ����5��               ʵ���ǣ�" << tj_strlen(s1) << endl;

        tj_strcpy(s4, s2);
        tj_strcat(s4, s3);
        tj_strcat(s4, &s3[6]);
        cout << "5.s4�����Ӧ����abcdehelloUVWXYZ��ʵ���ǣ�" << s4            << endl;
        cout << "  s4�ĳ���Ӧ����16��              ʵ���ǣ�" << tj_strlen(s4) << endl;

	wait_for_enter();
	}

    if (1) {
        char s1[80]="abcdefghijklm";
        char s2[]="abcde";
        char s3[]="hello\0UVWXYZ";
        char s4[80];

        cout << "tj_strncpy()���Բ��֣�" << endl;
        cout << " 1.s1�����Ӧ����abcdefghijklm��   ʵ���ǣ�" << s1            << endl;
        cout << "   s1�ĳ���Ӧ����13��              ʵ���ǣ�" << tj_strlen(s1) << endl;

        tj_strncpy(s1, s3, 10);
        cout << " 2.s1�����Ӧ����hellofghijklm��   ʵ���ǣ�" << s1            << endl;
        cout << "   s1�ĳ���Ӧ����13��              ʵ���ǣ�" << tj_strlen(s1) << endl;

        tj_strcpy(s1, "abcdefghijklm");
        tj_strncpy(s1, s3, 5);
        cout << " 3.s1�����Ӧ����hellofghijklm��   ʵ���ǣ�" << s1            << endl;
        cout << "   s1�ĳ���Ӧ����13��              ʵ���ǣ�" << tj_strlen(s1) << endl;

        tj_strcpy(s1, "abcdefghijklm");
        tj_strncpy(s1, s3, 3);
        cout << " 4.s1�����Ӧ����heldefghijklm��   ʵ���ǣ�" << s1            << endl;
        cout << "   s1�ĳ���Ӧ����13��              ʵ���ǣ�" << tj_strlen(s1) << endl;

        tj_strcpy(s1, "abcdefghijklm");
        tj_strncpy(&s1[4], s3, 10);
        cout << " 5.s1�����Ӧ����abcdhellojklm��   ʵ���ǣ�" << s1            << endl;
        cout << "   s1�ĳ���Ӧ����13��              ʵ���ǣ�" << tj_strlen(s1) << endl;

        tj_strcpy(s1, "abcdefghijklm");
        tj_strncpy(&s1[4], s3, 5);
        cout << " 6.s1�����Ӧ����abcdhellojklm��   ʵ���ǣ�" << s1            << endl;
        cout << "   s1�ĳ���Ӧ����13��              ʵ���ǣ�" << tj_strlen(s1) << endl;

        tj_strcpy(s1, "abcdefghijklm");
        tj_strncpy(&s1[4], s3, 3);
        cout << " 7.s1�����Ӧ����abcdhelhijklm��   ʵ���ǣ�" << s1            << endl;
        cout << "   s1�ĳ���Ӧ����13��              ʵ���ǣ�" << tj_strlen(s1) << endl;

        tj_strcpy(s1, "abcdefghijklm");
        tj_strncpy(&s1[4], &s3[6], 10);
        cout << " 8.s1�����Ӧ����abcdUVWXYZklm��   ʵ���ǣ�" << s1            << endl;
        cout << "   s1�ĳ���Ӧ����13��              ʵ���ǣ�" << tj_strlen(s1) << endl;

        tj_strcpy(s1, "abcdefghijklm");
        tj_strncpy(&s1[4], &s3[6], 6);
        cout << " 9.s1�����Ӧ����abcdUVWXYZklm��   ʵ���ǣ�" << s1            << endl;
        cout << "   s1�ĳ���Ӧ����13��              ʵ���ǣ�" << tj_strlen(s1) << endl;

        tj_strcpy(s1, "abcdefghijklm");
        tj_strncpy(&s1[4], &s3[6], 3);
        cout << "10.s1�����Ӧ����abcdUVWhijklm��   ʵ���ǣ�" << s1            << endl;
        cout << "   s1�ĳ���Ӧ����13��              ʵ���ǣ�" << tj_strlen(s1) << endl;

        tj_strncpy(s4, s2, tj_strlen(s2));
        s4[tj_strlen(s2)] = 0;
        cout << "11.s4�����Ӧ����abcde��           ʵ���ǣ�" << s4            << endl;
        cout << "   s4�ĳ���Ӧ����5��               ʵ���ǣ�" << tj_strlen(s4) << endl;

        tj_strcat(s4, s3);
        cout << "12.s4�����Ӧ����abcdehello��      ʵ���ǣ�" << s4            << endl;
        cout << "   s4�ĳ���Ӧ����10��              ʵ���ǣ�" << tj_strlen(s4) << endl;

        int old_len = tj_strlen(s4);
        tj_strncpy(&s4[10], &s3[6], tj_strlen(&s3[6]));
        s4[old_len + tj_strlen(&s3[6]) ] = 0;
        cout << "13.s4�����Ӧ����abcdehelloUVWXYZ��ʵ���ǣ�" << s4            << endl;
        cout << "   s4�ĳ���Ӧ����16��              ʵ���ǣ�" << tj_strlen(s4) << endl;

	wait_for_enter();
	}

    if (1) {
        char s1[]="horse";
        char s2[]="house";
        char s3[]="hell";
        char s4[]="hello";
        char s5[]="hello";
        char s6[]="hell";
        char s7[]="hello";
        char s8[]="hello";
        char s9[]="hello";
        char s10[]="hello\0UVWXYZ";
        char s11[]="HELLO";
        char s12[]="hello";
        char s13[]="HeLlO";
        char s14[]="hElLo";

        cout << "tj_strcmp()���Բ��֣�" << endl;
        cout << "1.s1 ��s2 �����Ӧ����-3��  ʵ���ǣ�" << tj_strcmp(s1,  s2)  << endl;
        cout << "2.s3 ��s4 �����Ӧ����-111��ʵ���ǣ�" << tj_strcmp(s3,  s4)  << endl;
        cout << "3.s5 ��s6 �����Ӧ����111�� ʵ���ǣ�" << tj_strcmp(s5,  s6)  << endl;
        cout << "4.s7 ��s8 �����Ӧ����0��   ʵ���ǣ�" << tj_strcmp(s7,  s8)  << endl;
        cout << "5.s9 ��s10�����Ӧ����0��   ʵ���ǣ�" << tj_strcmp(s9,  s10) << endl;
        cout << "6.s11��s12�����Ӧ����-32�� ʵ���ǣ�" << tj_strcmp(s11, s12) << endl;
        cout << "7.s13��s14�����Ӧ����-32�� ʵ���ǣ�" << tj_strcmp(s13, s14) << endl;

	wait_for_enter();
	}

    if (1) {
        char s1[]="horse";
        char s2[]="house";
        char s3[]="hell";
        char s4[]="hello";
        char s5[]="hello";
        char s6[]="hell";
        char s7[]="hello";
        char s8[]="hello";
        char s9[]="hello";
        char s10[]="hello\0UVWXYZ";
        char s11[]="HELLO";
        char s12[]="hello";
        char s13[]="HeLlO";
        char s14[]="hElLo";
        char s15[] = "HeLlO";
        char s16[] = "hElMo";
        char s17[] = "HeLXO";
        char s18[] = "hEllo";
        char s19[] = "HeL]O";//]=93
        char s20[] = "hEllo";//l=108
        char s21[] = "HeL]O";//]=93
        char s22[] = "hElLo";//L=76
        char s23[] = "HeL O";// =32
        char s24[] = "hEllo";//l=108
        char s25[] = "HeL O";//]=32
        char s26[] = "hElLo";//L=76

        cout << "tj_strcasecmp()���Բ��֣�" << endl;
        cout << "1.s1 ��s2 �����Ӧ����-3��  ʵ���ǣ�" << tj_strcasecmp(s1,  s2)  << endl;
        cout << "2.s3 ��s4 �����Ӧ����-111��ʵ���ǣ�" << tj_strcasecmp(s3,  s4)  << endl;
        cout << "3.s5 ��s6 �����Ӧ����111�� ʵ���ǣ�" << tj_strcasecmp(s5,  s6)  << endl;
        cout << "4.s7 ��s8 �����Ӧ����0��   ʵ���ǣ�" << tj_strcasecmp(s7,  s8)  << endl;
        cout << "5.s9 ��s10�����Ӧ����0��   ʵ���ǣ�" << tj_strcasecmp(s9,  s10) << endl;
        cout << "6.s11��s12�����Ӧ����0��   ʵ���ǣ�" << tj_strcasecmp(s11, s12) << endl;
        cout << "7.s13��s14�����Ӧ����0��   ʵ���ǣ�" << tj_strcasecmp(s13, s14) << endl;
        cout << "8.s15��s16�����Ӧ����-1 �� ʵ���ǣ�" << tj_strcasecmp(s15, s16) << endl;
        cout << "  s16��s15�����Ӧ����1 ��  ʵ���ǣ�" << tj_strcasecmp(s16, s15) << endl;
        cout << "9.s17��s18�����Ӧ����12��  ʵ���ǣ�" << tj_strcasecmp(s17, s18) << endl;
        cout << "  s18��s17�����Ӧ����-12�� ʵ���ǣ�" << tj_strcasecmp(s18, s17) << endl;
        cout << "10.s19��s20�����Ӧ����-15��ʵ���ǣ�" << tj_strcasecmp(s19, s20) << endl;
        cout << "   s20��s19�����Ӧ����15�� ʵ���ǣ�" << tj_strcasecmp(s20, s19) << endl;
        cout << "11.s21��s22�����Ӧ����-15��ʵ���ǣ�" << tj_strcasecmp(s21, s22) << endl;
        cout << "   s22��s21�����Ӧ����15�� ʵ���ǣ�" << tj_strcasecmp(s22, s21) << endl;
        cout << "12.s23��s24�����Ӧ����-76��ʵ���ǣ�" << tj_strcasecmp(s23, s24) << endl;
        cout << "   s24��s23�����Ӧ����76�� ʵ���ǣ�" << tj_strcasecmp(s24, s23) << endl;
        cout << "13.s25��s26�����Ӧ����-76��ʵ���ǣ�" << tj_strcasecmp(s25, s26) << endl;
        cout << "   s26��s25�����Ӧ����76�� ʵ���ǣ�" << tj_strcasecmp(s26, s25) << endl;

	wait_for_enter();
	}

    if (1) {
        char s1[]="horse";
        char s2[]="house";
        char s3[]="hell";
        char s4[]="hello";
        char s5[]="hello";
        char s6[]="hell";
        char s7[]="hello";
        char s8[]="hello";
        char s9[]="hello";
        char s10[]="hello\0UVWXYZ";
        char s11[]="HELLO";
        char s12[]="hello";
        char s13[]="HeLlO";
        char s14[]="hElLo";

        cout << "tj_strncmp()���Բ��֣�" << endl;
        cout << "1.s1 ��s2 �Ƚ�ǰ10���ַ������Ӧ����-3��  ʵ���ǣ�" << tj_strncmp(s1,  s2,  10) << endl;
        cout << "  s1 ��s2 �Ƚ�ǰ5 ���ַ������Ӧ����-3��  ʵ���ǣ�" << tj_strncmp(s1,  s2,  5)  << endl;
        cout << "  s1 ��s2 �Ƚ�ǰ3 ���ַ������Ӧ����-3��  ʵ���ǣ�" << tj_strncmp(s1,  s2,  3)  << endl;
        cout << "  s1 ��s2 �Ƚ�ǰ2 ���ַ������Ӧ����0��   ʵ���ǣ�" << tj_strncmp(s1,  s2,  2)  << endl;
        cout << "2.s3 ��s4 �Ƚ�ǰ10���ַ������Ӧ����-111��ʵ���ǣ�" << tj_strncmp(s3,  s4,  10) << endl;
        cout << "  s3 ��s4 �Ƚ�ǰ5 ���ַ������Ӧ����-111��ʵ���ǣ�" << tj_strncmp(s3,  s4,  5)  << endl;
        cout << "  s3 ��s4 �Ƚ�ǰ4 ���ַ������Ӧ����0��   ʵ���ǣ�" << tj_strncmp(s3,  s4,  4)  << endl;
        cout << "3.s5 ��s6 �Ƚ�ǰ10���ַ������Ӧ����111 ��ʵ���ǣ�" << tj_strncmp(s5,  s6,  10) << endl;
        cout << "  s5 ��s6 �Ƚ�ǰ5 ���ַ������Ӧ����111�� ʵ���ǣ�" << tj_strncmp(s5,  s6,  5)  << endl;
        cout << "  s5 ��s6 �Ƚ�ǰ4 ���ַ������Ӧ����0��   ʵ���ǣ�" << tj_strncmp(s5,  s6,  4)  << endl;
        cout << "4.s7 ��s8 �Ƚ�ǰ10���ַ������Ӧ����0 ��  ʵ���ǣ�" << tj_strncmp(s7,  s8,  10) << endl;
        cout << "  s7 ��s8 �Ƚ�ǰ5 ���ַ������Ӧ����0��   ʵ���ǣ�" << tj_strncmp(s7,  s8,  5)  << endl;
        cout << "  s7 ��s8 �Ƚ�ǰ4 ���ַ������Ӧ����0��   ʵ���ǣ�" << tj_strncmp(s7,  s8,  4)  << endl;
        cout << "5.s9 ��s10�Ƚ�ǰ10���ַ������Ӧ����0 ��  ʵ���ǣ�" << tj_strncmp(s9,  s10, 10) << endl;
        cout << "  s9 ��s10�Ƚ�ǰ5 ���ַ������Ӧ����0��   ʵ���ǣ�" << tj_strncmp(s9,  s10, 5)  << endl;
        cout << "  s9 ��s10�Ƚ�ǰ4 ���ַ������Ӧ����0��   ʵ���ǣ�" << tj_strncmp(s9,  s10, 4)  << endl;
        cout << "6.s11��s12�Ƚ�ǰ10���ַ������Ӧ����-32�� ʵ���ǣ�" << tj_strncmp(s11, s12, 10) << endl;
        cout << "  s11��s12�Ƚ�ǰ5 ���ַ������Ӧ����-32�� ʵ���ǣ�" << tj_strncmp(s11, s12, 5)  << endl;
        cout << "  s11��s12�Ƚ�ǰ2 ���ַ������Ӧ����-32�� ʵ���ǣ�" << tj_strncmp(s11, s12, 2)  << endl;
        cout << "7.s13��s14�Ƚ�ǰ10���ַ������Ӧ����-32�� ʵ���ǣ�" << tj_strncmp(s13, s14, 10) << endl;
        cout << "  s13��s14�Ƚ�ǰ5 ���ַ������Ӧ����-32�� ʵ���ǣ�" << tj_strncmp(s13, s14, 5)  << endl;
        cout << "  s13��s14�Ƚ�ǰ2 ���ַ������Ӧ����-32�� ʵ���ǣ�" << tj_strncmp(s13, s14, 2)  << endl;

	wait_for_enter();
	}

    if (1) {
        char s1[]="horse";
        char s2[]="house";
        char s3[]="hell";
        char s4[]="hello";
        char s5[]="hello";
        char s6[]="hell";
        char s7[]="hello";
        char s8[]="hello";
        char s9[]="hello";
        char s10[]="hello\0UVWXYZ";
        char s11[]="HELLO";
        char s12[]="hello";
        char s13[]="HeLlO";
        char s14[]="hElLo";
        char s15[] = "HeLlO";
        char s16[] = "hElMo";
        char s17[] = "HeLXO";
        char s18[] = "hEllo";
        char s19[] = "HeL]O";//]=93
        char s20[] = "hEllo";//l=108
        char s21[] = "HeL]O";//]=93
        char s22[] = "hElLo";//L=76
        char s23[] = "HeL O";// =32
        char s24[] = "hEllo";//l=108
        char s25[] = "HeL O";//]=32
        char s26[] = "hElLo";//L=76

        cout << "tj_strcasencmp()���Բ��֣�" << endl;
        cout << "1.s1 ��s2 �Ƚ�ǰ10���ַ������Ӧ����-3��  ʵ���ǣ�" << tj_strcasencmp(s1,  s2,  10) << endl;
        cout << "  s1 ��s2 �Ƚ�ǰ5 ���ַ������Ӧ����-3��  ʵ���ǣ�" << tj_strcasencmp(s1,  s2,  5)  << endl;
        cout << "  s1 ��s2 �Ƚ�ǰ3 ���ַ������Ӧ����-3��  ʵ���ǣ�" << tj_strcasencmp(s1,  s2,  3)  << endl;
        cout << "  s1 ��s2 �Ƚ�ǰ2 ���ַ������Ӧ����0��   ʵ���ǣ�" << tj_strcasencmp(s1,  s2,  2)  << endl;
        cout << "2.s3 ��s4 �Ƚ�ǰ10���ַ������Ӧ����-111��ʵ���ǣ�" << tj_strcasencmp(s3,  s4,  10) << endl;
        cout << "  s3 ��s4 �Ƚ�ǰ5 ���ַ������Ӧ����-111��ʵ���ǣ�" << tj_strcasencmp(s3,  s4,  5)  << endl;
        cout << "  s3 ��s4 �Ƚ�ǰ4 ���ַ������Ӧ����0��   ʵ���ǣ�" << tj_strcasencmp(s3,  s4,  4)  << endl;
        cout << "3.s5 ��s6 �Ƚ�ǰ10���ַ������Ӧ����111 ��ʵ���ǣ�" << tj_strcasencmp(s5,  s6,  10) << endl;
        cout << "  s5 ��s6 �Ƚ�ǰ5 ���ַ������Ӧ����111�� ʵ���ǣ�" << tj_strcasencmp(s5,  s6,  5)  << endl;
        cout << "  s5 ��s6 �Ƚ�ǰ4 ���ַ������Ӧ����0��   ʵ���ǣ�" << tj_strcasencmp(s5,  s6,  4)  << endl;
        cout << "4.s7 ��s8 �Ƚ�ǰ10���ַ������Ӧ����0 ��  ʵ���ǣ�" << tj_strcasencmp(s7,  s8,  10) << endl;
        cout << "  s7 ��s8 �Ƚ�ǰ5 ���ַ������Ӧ����0��   ʵ���ǣ�" << tj_strcasencmp(s7,  s8,  5)  << endl;
        cout << "  s7 ��s8 �Ƚ�ǰ4 ���ַ������Ӧ����0��   ʵ���ǣ�" << tj_strcasencmp(s7,  s8,  4)  << endl;
        cout << "5.s9 ��s10�Ƚ�ǰ10���ַ������Ӧ����0 ��  ʵ���ǣ�" << tj_strcasencmp(s9,  s10, 10) << endl;
        cout << "  s9 ��s10�Ƚ�ǰ5 ���ַ������Ӧ����0��   ʵ���ǣ�" << tj_strcasencmp(s9,  s10, 5)  << endl;
        cout << "  s9 ��s10�Ƚ�ǰ4 ���ַ������Ӧ����0��   ʵ���ǣ�" << tj_strcasencmp(s9,  s10, 4)  << endl;
        cout << "6.s11��s12�Ƚ�ǰ10���ַ������Ӧ����0��   ʵ���ǣ�" << tj_strcasencmp(s11, s12, 10) << endl;
        cout << "  s11��s12�Ƚ�ǰ5 ���ַ������Ӧ����0��   ʵ���ǣ�" << tj_strcasencmp(s11, s12, 5)  << endl;
        cout << "  s11��s12�Ƚ�ǰ2 ���ַ������Ӧ����0��   ʵ���ǣ�" << tj_strcasencmp(s11, s12, 2)  << endl;
        cout << "7.s13��s14�Ƚ�ǰ10���ַ������Ӧ����0��   ʵ���ǣ�" << tj_strcasencmp(s13, s14, 10) << endl;
        cout << "  s13��s14�Ƚ�ǰ5 ���ַ������Ӧ����0��   ʵ���ǣ�" << tj_strcasencmp(s13, s14, 5)  << endl;
        cout << "  s13��s14�Ƚ�ǰ2 ���ַ������Ӧ����0��   ʵ���ǣ�" << tj_strcasencmp(s13, s14, 2)  << endl;
        cout << "8.s15��s16�Ƚ�ǰ2���ַ������Ӧ����0 ��   ʵ���ǣ�" << tj_strcasencmp(s15, s16, 2) << endl;
        cout << "  s16��s15�Ƚ�ǰ2���ַ������Ӧ����0 ��   ʵ���ǣ�" << tj_strcasencmp(s16, s15, 2) << endl;
        cout << "9.s17��s18�Ƚ�ǰ4���ַ������Ӧ����12��   ʵ���ǣ�" << tj_strcasencmp(s17, s18, 4) << endl;
        cout << "  s18��s17�Ƚ�ǰ4���ַ������Ӧ����-12��  ʵ���ǣ�" << tj_strcasencmp(s18, s17, 4) << endl;
        cout << "10.s19��s20�Ƚ�ǰ4���ַ������Ӧ����-15�� ʵ���ǣ�" << tj_strcasencmp(s19, s20, 4) << endl;
        cout << "   s20��s19�Ƚ�ǰ4���ַ������Ӧ����15��  ʵ���ǣ�" << tj_strcasencmp(s20, s19, 4) << endl;
        cout << "11.s21��s22�Ƚ�ǰ4���ַ������Ӧ����-15�� ʵ���ǣ�" << tj_strcasencmp(s21, s22, 4) << endl;
        cout << "   s22��s21�Ƚ�ǰ4���ַ������Ӧ����15��  ʵ���ǣ�" << tj_strcasencmp(s22, s21, 4) << endl;
        cout << "12.s23��s24�Ƚ�ǰ4���ַ������Ӧ����-76�� ʵ���ǣ�" << tj_strcasencmp(s23, s24, 4) << endl;
        cout << "   s24��s23�Ƚ�ǰ4���ַ������Ӧ����76��  ʵ���ǣ�" << tj_strcasencmp(s24, s23, 4) << endl;
        cout << "13.s25��s26�Ƚ�ǰ4���ַ������Ӧ����-76�� ʵ���ǣ�" << tj_strcasencmp(s25, s26, 4) << endl;
        cout << "   s26��s25�Ƚ�ǰ4���ַ������Ӧ����76��  ʵ���ǣ�" << tj_strcasencmp(s26, s25, 4) << endl;

	wait_for_enter();
	}

     if (1) {
        char s1[]="123horseHELLO*#@";
        char s2[]="1A2b3C*d#E@f";

        cout << "tj_strupr()���Բ��֣�" << endl;
        tj_strupr(s1);
        cout << "1.s1 �����Ӧ����123HORSEHELLO*#@��ʵ���ǣ�" << s1 << endl;
        tj_strupr(s2);
        cout << "2.s2 �����Ӧ����1A2B3C*D#E@F��    ʵ���ǣ�" << s2 << endl;

	wait_for_enter();
	}

     if (1) {
        char s1[]="123horseHELLO*#@";
        char s2[]="1A2b3C*d#E@f";

        cout << "tj_strlwr()���Բ��֣�" << endl;
        tj_strlwr(s1);
        cout << "1.s1 �����Ӧ����123horsehello*#@��ʵ���ǣ�" << s1 << endl;
        tj_strlwr(s2);
        cout << "2.s2 �����Ӧ����1a2b3c*d#e@f��    ʵ���ǣ�" << s2 << endl;

	wait_for_enter();
	}

     if (1) {
        char s1[]="This is a pencil.";

        cout << "tj_strchr()���Բ��֣�" << endl;
        cout << "1.s1 �����Ӧ����1��ʵ���ǣ�" << tj_strchr(s1, 'T') << endl;
        cout << "2.s1 �����Ӧ����3��ʵ���ǣ�" << tj_strchr(s1, 'i') << endl;
        cout << "3.s1 �����Ӧ����5��ʵ���ǣ�" << tj_strchr(s1, ' ') << endl;
        cout << "4.s1 �����Ӧ����0��ʵ���ǣ�" << tj_strchr(s1, 'x') << endl;

	wait_for_enter();
	}

     if (1) {
        char s1[]="This is a pencil.";
        char s2[]="aabbbceddbbbceeeff";
        char s3[]="abcde";

        cout << "tj_strstr()���Բ��֣�" << endl;
        cout << "1.s1 �����Ӧ����1�� ʵ���ǣ�" << tj_strstr(s1, "T")      << endl;
        cout << "  s1 �����Ӧ����3�� ʵ���ǣ�" << tj_strstr(s1, "is")     << endl;
        cout << "  s1 �����Ӧ����11��ʵ���ǣ�" << tj_strstr(s1, "pencil") << endl;
        cout << "  s1 �����Ӧ����0�� ʵ���ǣ�" << tj_strstr(s1, "Pencil") << endl;
        cout << "2.s2 �����Ӧ����3�� ʵ���ǣ�" << tj_strstr(s2, "bb")     << endl;
        cout << "  s2 �����Ӧ����3�� ʵ���ǣ�" << tj_strstr(s2, "bbb")    << endl;
        cout << "  s2 �����Ӧ����4�� ʵ���ǣ�" << tj_strstr(s2, "bbc")    << endl;
        cout << "  s2 �����Ӧ����0�� ʵ���ǣ�" << tj_strstr(s2, "bbbb")   << endl;
        cout << "  s2 �����Ӧ����6�� ʵ���ǣ�" << tj_strstr(s2, "ce")     << endl;
        cout << "  s2 �����Ӧ����13��ʵ���ǣ�" << tj_strstr(s2, "cee")    << endl;
        cout << "3.s3 �����Ӧ����1�� ʵ���ǣ�" << tj_strstr(s3, "abcde")  << endl;
        cout << "  s3 �����Ӧ����0�� ʵ���ǣ�" << tj_strstr(s3, "abcdef") << endl;


	wait_for_enter();
	}

     if (1) {
        char s1[]="This is a pencil.";

        cout << "tj_strrchr()���Բ��֣�" << endl;
        cout << "1.s1 �����Ӧ����1�� ʵ���ǣ�" << tj_strrchr(s1, 'T') << endl;
        cout << "2.s1 �����Ӧ����15��ʵ���ǣ�" << tj_strrchr(s1, 'i') << endl;
        cout << "3.s1 �����Ӧ����10��ʵ���ǣ�" << tj_strrchr(s1, ' ') << endl;
        cout << "4.s1 �����Ӧ����0�� ʵ���ǣ�" << tj_strrchr(s1, 'x') << endl;

	wait_for_enter();
	}

     if (1) {
        char s1[]="This is a pencil.";
        char s2[]="aabbbceddbbbceeeff";
        char s3[]="abcde";

        cout << "tj_strrstr()���Բ��֣�" << endl;
        cout << "1.s1 �����Ӧ����1�� ʵ���ǣ�" << tj_strrstr(s1, "T")      << endl;
        cout << "  s1 �����Ӧ����6�� ʵ���ǣ�" << tj_strrstr(s1, "is")     << endl;
        cout << "  s1 �����Ӧ����11��ʵ���ǣ�" << tj_strrstr(s1, "pencil") << endl;
        cout << "  s1 �����Ӧ����0�� ʵ���ǣ�" << tj_strrstr(s1, "Pencil") << endl;
        cout << "2.s2 �����Ӧ����11��ʵ���ǣ�" << tj_strrstr(s2, "bb")     << endl;
        cout << "  s2 �����Ӧ����10��ʵ���ǣ�" << tj_strrstr(s2, "bbb")    << endl;
        cout << "  s2 �����Ӧ����11��ʵ���ǣ�" << tj_strrstr(s2, "bbc")    << endl;
        cout << "  s2 �����Ӧ����0�� ʵ���ǣ�" << tj_strrstr(s2, "bbbb")   << endl;
        cout << "  s2 �����Ӧ����13��ʵ���ǣ�" << tj_strrstr(s2, "ce")     << endl;
        cout << "  s2 �����Ӧ����13��ʵ���ǣ�" << tj_strrstr(s2, "cee")    << endl;
        cout << "3.s3 �����Ӧ����1�� ʵ���ǣ�" << tj_strrstr(s3, "abcde")  << endl;
        cout << "  s3 �����Ӧ����0�� ʵ���ǣ�" << tj_strrstr(s3, "abcdef") << endl;

	wait_for_enter();
        }

     if (1) {
        char s1[]="This is a pencil.";
        char s2[]="aabbbceddbbbceeeff";
        char s3[]="";

        cout << "tj_strrev()���Բ��֣�" << endl;
        cout << "1.s1 �����Ӧ����This is a pencil.��  ʵ���ǣ�" << s1 << endl;
        tj_strrev(s1);
        cout << "  s1 �����Ӧ����.licnep a si sihT��  ʵ���ǣ�" << s1 << endl;
        cout << "2.s2 �����Ӧ����aabbbceddbbbceeeff�� ʵ���ǣ�" << s2 << endl;
        tj_strrev(s2);
        cout << "  s2 �����Ӧ����ffeeecbbbddecbbbaa�� ʵ���ǣ�" << s2 << endl;

        cout << "3.s3 �����Ӧ���ǿգ� ʵ���ǣ�" << s3 << endl;  //����Ҫ�������"��"��ֱ�������ݼ���
        tj_strrev(s3);
        cout << "  s3 �����Ӧ���ǿգ� ʵ���ǣ�" << s3 << endl;  //����Ҫ�������"��"��ֱ�������ݼ���

	wait_for_enter();
        }

    return 0;
}
