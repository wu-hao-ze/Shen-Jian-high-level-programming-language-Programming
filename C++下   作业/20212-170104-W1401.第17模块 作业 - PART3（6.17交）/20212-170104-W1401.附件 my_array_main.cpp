/* ѧ�� �༶ ���� */
#include <iostream>
#include <iomanip>
#include <string>
//��������Ҫ��ͷ�ļ�
using namespace std;

#if 0
/* �򿪴˺궨�壬��ʾʹ���Զ����array */
#include "my_array.h"

#else
/* �򿪴˺궨�壬��ʾʹ��ϵͳ��array */
#include <array>
#define my_array    array
#endif

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
    while (getchar() != '\n')
        ;
    cout << endl << endl;
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
    if (1) {
        /* ����int���� */
        cout << "--------------------" << endl;
        cout << "   int���Ͳ���" << endl;
        cout << "--------------------" << endl << endl;

        if (1) {
            /* ���������� */
            cout << "����������" << endl;
            cout << "--------------------" << endl;

            my_array<int, 5> arr1 = { 1, 2, 3, 4, 5};//ȫ����ʼ��

            /* ���ж�������� */
            cout << "�����ֵ(����)/�Զ��������" << endl;
            my_array<int, 5>::iterator it = arr1.begin();
            for (; it != arr1.end(); it++) {
                cout << *it << " ";
                (*it)++;
            }
            cout << endl;

            /* ������Ϊauto�Զ����壨auto�ڶ������ָ��ӵ�����ʱ�ܷ��㣬����ʹ�ã� */
            cout << "�����ֵ(����)" << endl;
            for (auto it = arr1.begin(); it != arr1.end(); it++) {
                cout << *it << " ";
                (*it)++;
            }
            cout << endl;

            cout << "�����ֵ(����)" << endl;
            for (auto rit = arr1.rbegin(); rit != arr1.rend(); rit++) {
                cout << *rit << " ";
                (*rit)++;
            }
            cout << endl;

            cout << "--------------------" << endl;
            my_array<int, 7> arr2 = { 11, 12, 13, 14, 15 };//���ֳ�ʼ��

            cout << "�����ֵ(����ֻ��)" << endl;
            for (auto cit = arr2.cbegin(); cit != arr2.cend(); cit++) {
                cout << *cit << " ";
                //            (*cit)++; //�˾�򿪺����Ҫ����
            }
            cout << endl;

            cout << "--------------------" << endl;
            my_array<int, 3> arr3;//����ʼ��

            cout << "�����ֵ(����ֻ��)" << endl;
            for (auto crit = arr3.crbegin(); crit != arr3.crend(); crit++) {
                cout << *crit << " ";
                //            (*crit)++; //�˾�򿪺����Ҫ����
            }
            cout << endl;

            wait_for_enter();
        }

        if (1) {
            /* ��С���� */
            cout << "�������С����" << endl;
            cout << "--------------------" << endl;

            my_array<int, 10> arr1;
            cout << "sizeof�Ĵ�С��" << sizeof(arr1) << endl;
            cout << "size()      ��" << arr1.size() << endl;
            cout << "max_size()  ��" << arr1.max_size() << endl; //array�Ĵ�С�����󲻿ɱ䣬���max_size��size��ͬ
            cout << "empty       ��" << (arr1.empty()?'Y':'N') << endl;

            cout << "--------------------" << endl;

            my_array<int, 0> arr2;
            cout << "sizeof�Ĵ�С��" << sizeof(arr2) << endl; //Ϊɶ��4 ��
            cout << "size()      ��" << arr2.size() << endl;
            cout << "max_size()  ��" << arr2.max_size() << endl; //array�Ĵ�С�����󲻿ɱ䣬���max_size��size��ͬ
            cout << "empty       ��" << (arr2.empty() ? 'Y' : 'N') << endl;

            wait_for_enter();
        }

        if (1) {
            /* Ԫ�ط��ʲ��� */
            cout << "Ԫ�ط��ʲ���" << endl;
            cout << "--------------------" << endl;

            const int arrsize = 7;
            my_array<int, arrsize> arr1 = {1,2,3,4,5,6,7};
            int i;

            for (i=0; i< arrsize; i++)
                cout << "array[" << i << "]��" << arr1[i] << endl;

            /* �˾�򿪣��������е�����������ɺ󣬿�ע�͵� */
//            cout << "[]Խ����ԣ�"  << arr1[arrsize] << endl;

            cout << "--------------------" << endl;

            for (i = 0; i < arrsize; i++)
                cout << "array.at(" << i << ")��" << arr1.at(i) << endl;

            /* �˾�򿪣��������е�����������ɺ󣬿�ע�͵� */
//            cout << "atԽ����ԣ�" << arr1.at(arrsize) << endl;

            cout << "--------------------" << endl;

            cout << "array����Ԫ�أ�" << arr1.front() << endl;
            cout << "array��βԪ�أ�" << arr1.back() << endl;

            cout << "--------------------" << endl;

            cout << "array���׵�ַ��" << &arr1 << " ��ַ+1��" << (&arr1+1) << endl;
            cout << "array���׵�ַ��" << arr1.data() << " ��ַ+1��" << (arr1.data()+1) << endl;
            cout << "array����Ԫ��: " << *(arr1.data()) << endl;
            for (i=0; i< arrsize; i++)
                cout << "data+" << i << "��" << *(arr1.data()+i) << "\tdata[" << i << "]��" << arr1.data()[i] << endl;

            wait_for_enter();
        }

        if (1) {
            /* ����������� */
            cout << "�����������" << endl;
            cout << "--------------------" << endl;

            my_array<int, 5> arr;

            arr.fill(789);

            cout << "�����ֵ" << endl;
            for (auto i : arr) { //auto����һ���÷����������
                cout << i << " ";
            }
            cout << endl;

            cout << "--------------------" << endl;

            my_array<int, 3> first = { 11, 22, 33 };
            my_array<int, 3> second = { 44, 55, 66 };

            cout << "����ǰ��" << endl;
            cout << "first ���飺";
            for (auto i : first) {
                cout << i << " ";
            }
            cout << endl;

            cout << "second���飺";
            for (auto i : second) { //auto����һ���÷����������
                cout << i << " ";
            }
            cout << endl;

            first.swap(second);

            cout << "--------------------" << endl;

            cout << "������" << endl;
            cout << "first ���飺";
            for (auto i : first) {
                cout << i << " ";
            }
            cout << endl;

            cout << "second���飺";
            for (auto i : second) { //auto����һ���÷����������
                cout << i << " ";
            }
            cout << endl;

            wait_for_enter();
        }

        if (1) {
            /* �Ƚϲ������� */
            cout << "����Ƚϲ���" << endl;
            cout << "--------------------" << endl;

            my_array<int, 5> a = { 10, 20, 30, 40, 50 };
            my_array<int, 5> b = { 10, 20, 30, 40, 50 };
            my_array<int, 5> c = { 10, 21, 30, 40, 50 };
            my_array<int, 5> d = { 10, 20, 30, 40, 49 };
            my_array<int, 3> e = { 1, 2, 3 };

            cout << "a == b ��" << (a == b) << endl;
            cout << "a != b ��" << (a != b) << endl;
            cout << "a >= b ��" << (a >= b) << endl;
            cout << "a >  b ��" << (a >  b) << endl;
            cout << "a <= b ��" << (a <= b) << endl;
            cout << "a <  b ��" << (a <  b) << endl;

            cout << "--------------------" << endl;

            cout << "a == c ��" << (a == c) << endl;
            cout << "a != c ��" << (a != c) << endl;
            cout << "a >= c ��" << (a >= c) << endl;
            cout << "a >  c ��" << (a >  c) << endl;
            cout << "a <= c ��" << (a <= c) << endl;
            cout << "a <  c ��" << (a <  c) << endl;

            cout << "--------------------" << endl;

            cout << "a == d ��" << (a == d) << endl;
            cout << "a != d ��" << (a != d) << endl;
            cout << "a >= d ��" << (a >= d) << endl;
            cout << "a >  d ��" << (a >  d) << endl;
            cout << "a <= d ��" << (a <= d) << endl;
            cout << "a <  d ��" << (a <  d) << endl;

//            cout << "a == e ��" << (a == e) << endl;  //�˾����򿪣�����Ӧ����

            wait_for_enter();
        }
    }

    if (1) {
        /* ����double���� */
        cout << "--------------------" << endl;
        cout << "   double���Ͳ���" << endl;
        cout << "--------------------" << endl << endl;

        if (1) {
            /* ���������� */
            cout << "����������" << endl;
            cout << "--------------------" << endl;

            my_array<double, 5> arr1 = { 1.1, 2.2, 3.3, 4.4, 5.5 };//ȫ����ʼ��

            /* ���ж�������� */
            cout << "�����ֵ(����)/�Զ��������" << endl;
            my_array<double, 5>::iterator it = arr1.begin();
            for (; it != arr1.end(); it++) {
                cout << *it << " ";
                (*it)++;
            }
            cout << endl;

            /* ������Ϊauto�Զ����壨auto�ڶ������ָ��ӵ�����ʱ�ܷ��㣬����ʹ�ã� */
            cout << "�����ֵ(����)" << endl;
            for (auto it = arr1.begin(); it != arr1.end(); it++) {
                cout << *it << " ";
                (*it)++;
            }
            cout << endl;

            cout << "�����ֵ(����)" << endl;
            for (auto rit = arr1.rbegin(); rit != arr1.rend(); rit++) {
                cout << *rit << " ";
                (*rit)++;
            }
            cout << endl;

            cout << "--------------------" << endl;
            my_array<double, 7> arr2 = { 1.1, 1.2, 1.3, 1.4, 1.5 };//���ֳ�ʼ��

            cout << "�����ֵ(����ֻ��)" << endl;
            for (auto cit = arr2.cbegin(); cit != arr2.cend(); cit++) {
                cout << *cit << " ";
                //            (*cit)++; //�˾�򿪺����Ҫ����
            }
            cout << endl;

            cout << "--------------------" << endl;
            my_array<double, 3> arr3;//����ʼ��

            cout << "�����ֵ(����ֻ��)" << endl;
            for (auto crit = arr3.crbegin(); crit != arr3.crend(); crit++) {
                cout << *crit << " ";
                //            (*crit)++; //�˾�򿪺����Ҫ����
            }
            cout << endl;

            wait_for_enter();
        }

        if (1) {
            /* ��С���� */
            cout << "�������С����" << endl;
            cout << "--------------------" << endl;

            my_array<double, 10> arr1;
            cout << "sizeof�Ĵ�С��" << sizeof(arr1) << endl;
            cout << "size()      ��" << arr1.size() << endl;
            cout << "max_size()  ��" << arr1.max_size() << endl; //array�Ĵ�С�����󲻿ɱ䣬���max_size��size��ͬ
            cout << "empty       ��" << (arr1.empty() ? 'Y' : 'N') << endl;

            cout << "--------------------" << endl;

            my_array<double, 0> arr2;
            cout << "sizeof�Ĵ�С��" << sizeof(arr2) << endl; //Ϊɶ��4 ��
            cout << "size()      ��" << arr2.size() << endl;
            cout << "max_size()  ��" << arr2.max_size() << endl; //array�Ĵ�С�����󲻿ɱ䣬���max_size��size��ͬ
            cout << "empty       ��" << (arr2.empty() ? 'Y' : 'N') << endl;

            wait_for_enter();
        }

        if (1) {
            /* Ԫ�ط��ʲ��� */
            cout << "Ԫ�ط��ʲ���" << endl;
            cout << "--------------------" << endl;

            const int arrsize = 7;
            my_array<double, arrsize> arr1 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
            int i;

            for (i = 0; i < arrsize; i++)
                cout << "array[" << i << "]��" << arr1[i] << endl;

            /* �˾�򿪣��������е�����������ɺ󣬿�ע�͵� */
//            cout << "[]Խ����ԣ�"  << arr1[arrsize] << endl;

            cout << "--------------------" << endl;

            for (i = 0; i < arrsize; i++)
                cout << "array.at(" << i << ")��" << arr1.at(i) << endl;

            /* �˾�򿪣��������е�����������ɺ󣬿�ע�͵� */
//            cout << "atԽ����ԣ�" << arr1.at(arrsize) << endl;

            cout << "--------------------" << endl;

            cout << "array����Ԫ�أ�" << arr1.front() << endl;
            cout << "array��βԪ�أ�" << arr1.back() << endl;

            cout << "--------------------" << endl;

            cout << "array���׵�ַ��" << &arr1 << " ��ַ+1��" << (&arr1 + 1) << endl;
            cout << "array���׵�ַ��" << arr1.data() << " ��ַ+1��" << (arr1.data() + 1) << endl;
            cout << "array����Ԫ��: " << *(arr1.data()) << endl;
            for (i = 0; i < arrsize; i++)
                cout << "data+" << i << "��" << *(arr1.data() + i) << "\tdata[" << i << "]��" << arr1.data()[i] << endl;

            wait_for_enter();
        }

        if (1) {
            /* ����������� */
            cout << "�����������" << endl;
            cout << "--------------------" << endl;

            my_array<double, 5> arr;

            arr.fill(123.456);

            cout << "�����ֵ" << endl;
            for (auto i : arr) { //auto����һ���÷����������
                cout << i << " ";
            }
            cout << endl;

            cout << "--------------------" << endl;

            my_array<double, 3> first = { 1.1, 2.2, 3.3 };
            my_array<double, 3> second = { 4.4, 5.5, 6.6 };

            cout << "����ǰ��" << endl;
            cout << "first ���飺";
            for (auto i : first) {
                cout << i << " ";
            }
            cout << endl;

            cout << "second���飺";
            for (auto i : second) { //auto����һ���÷����������
                cout << i << " ";
            }
            cout << endl;

            first.swap(second);

            cout << "--------------------" << endl;

            cout << "������" << endl;
            cout << "first ���飺";
            for (auto i : first) {
                cout << i << " ";
            }
            cout << endl;

            cout << "second���飺";
            for (auto i : second) { //auto����һ���÷����������
                cout << i << " ";
            }
            cout << endl;

            wait_for_enter();
        }

        if (1) {
            /* �Ƚϲ������� */
            cout << "����Ƚϲ���" << endl;
            cout << "--------------------" << endl;

            my_array<double, 5> a = { 1.0, 2.0, 3.0, 4.0, 5.0 };
            my_array<double, 5> b = { 1.0, 2.0, 3.0, 4.0, 5.0 };
            my_array<double, 5> c = { 1.0, 2.1, 3.0, 4.0, 5.0 };
            my_array<double, 5> d = { 1.0, 2.0, 3.0, 4.0, 4.9 };
            my_array<double, 3> e = { 1.1, 2.2, 3.3 };

            cout << "a == b ��" << (a == b) << endl;
            cout << "a != b ��" << (a != b) << endl;
            cout << "a >= b ��" << (a >= b) << endl;
            cout << "a >  b ��" << (a > b) << endl;
            cout << "a <= b ��" << (a <= b) << endl;
            cout << "a <  b ��" << (a < b) << endl;

            cout << "--------------------" << endl;

            cout << "a == c ��" << (a == c) << endl;
            cout << "a != c ��" << (a != c) << endl;
            cout << "a >= c ��" << (a >= c) << endl;
            cout << "a >  c ��" << (a > c) << endl;
            cout << "a <= c ��" << (a <= c) << endl;
            cout << "a <  c ��" << (a < c) << endl;

            cout << "--------------------" << endl;

            cout << "a == d ��" << (a == d) << endl;
            cout << "a != d ��" << (a != d) << endl;
            cout << "a >= d ��" << (a >= d) << endl;
            cout << "a >  d ��" << (a > d) << endl;
            cout << "a <= d ��" << (a <= d) << endl;
            cout << "a <  d ��" << (a < d) << endl;

            //            cout << "a == e ��" << (a == e) << endl;  //�˾����򿪣�����Ӧ����

            cout << "--------------------" << endl;

            /* ˼��һ�£������������ʲô�� */
            my_array<double, 5> a1 = { 1.0, 2.0, 3.0, 4.0, 5.0 };
            my_array<double, 5> b1 = { 1.0F, 2.0, 3.0, 4.0, 5.0 };
            my_array<double, 5> a2 = { 1.1, 2.1, 3.1, 4.1, 5.1 };
            my_array<double, 5> b2 = { 1.1F, 2.1, 3.1, 4.1, 5.1 };

            cout << "a1 == b1 ��" << (a1 == b1) << endl;
            cout << "a2 == b2 ��" << (a2 == b2) << endl; 

            wait_for_enter();
        }
    }

    if (1) {
        /* ����string���� */
        cout << "--------------------" << endl;
        cout << "   string���Ͳ���" << endl;
        cout << "--------------------" << endl << endl;

        if (1) {
            /* ���������� */
            cout << "����������" << endl;
            cout << "--------------------" << endl;

            my_array<string, 5> arr1 = { "Welcome", "to", "tongji", "univercity", "!" };//ȫ����ʼ��

            /* ���ж�������� */
            cout << "�����ֵ(����)/�Զ��������" << endl;
            my_array<string, 5>::iterator it = arr1.begin();
            for (; it != arr1.end(); it++) {
                cout << *it << " ";
//                (*it)++;      string����++
            }
            cout << endl;

            /* ������Ϊauto�Զ����壨auto�ڶ������ָ��ӵ�����ʱ�ܷ��㣬����ʹ�ã� */
            cout << "�����ֵ(����)" << endl;
            for (auto it = arr1.begin(); it != arr1.end(); it++) {
                cout << *it << " ";
//                (*it)++;      string����++
            }
            cout << endl;

            cout << "�����ֵ(����)" << endl;
            for (auto rit = arr1.rbegin(); rit != arr1.rend(); rit++) {
                cout << *rit << " ";
//                (*rit)++;     string����++
            }
            cout << endl;

            cout << "--------------------" << endl;
            my_array<string, 5> arr2 = { "��", "��·", "��", "����·", "�Ի��" };//ȫ����ʼ��

            cout << "�����ֵ(����ֻ��)" << endl;
            for (auto cit = arr2.cbegin(); cit != arr2.cend(); cit++) {
                cout << *cit << " ";
//            (*cit)++; //�˾�򿪺����Ҫ����
            }
            cout << endl;

            cout << "--------------------" << endl;
            my_array<string, 3> arr3;//����ʼ��

            cout << "�����ֵ(����ֻ��)" << endl;
            for (auto crit = arr3.crbegin(); crit != arr3.crend(); crit++) {
                if ((*crit).empty())
                    cout << "null ";
                else
                    cout << *crit << " ";
//            (*crit)++; //�˾�򿪺����Ҫ����
            }
            cout << endl;

            wait_for_enter();
        }

        if (1) {
            /* ��С���� */
            cout << "�������С����" << endl;
            cout << "--------------------" << endl;

            my_array<string, 10> arr1;
            cout << "sizeof(string)�Ĵ�С��" << sizeof(string) << endl;
            cout << "sizeof�Ĵ�С��" << sizeof(arr1) << endl;
            cout << "size()      ��" << arr1.size() << endl;
            cout << "max_size()  ��" << arr1.max_size() << endl; //array�Ĵ�С�����󲻿ɱ䣬���max_size��size��ͬ
            cout << "empty       ��" << (arr1.empty() ? 'Y' : 'N') << endl;

            cout << "--------------------" << endl;

            my_array<string, 0> arr2;
            cout << "sizeof(string)�Ĵ�С��" << sizeof(string) << endl;
            cout << "sizeof�Ĵ�С��" << sizeof(arr2) << endl; //Ϊɶ��4 ��
            cout << "size()      ��" << arr2.size() << endl;
            cout << "max_size()  ��" << arr2.max_size() << endl; //array�Ĵ�С�����󲻿ɱ䣬���max_size��size��ͬ
            cout << "empty       ��" << (arr2.empty() ? 'Y' : 'N') << endl;

            wait_for_enter();
        }

        if (1) {
            /* Ԫ�ط��ʲ��� */
            cout << "Ԫ�ط��ʲ���" << endl;
            cout << "--------------------" << endl;

            const int arrsize = 5;
            my_array<string, arrsize> arr1 = { "Welcome", "to", "tongji", "univercity", "!" };
            int i;

            for (i = 0; i < arrsize; i++)
                cout << "array[" << i << "]��" << arr1[i] << endl;

            /* �˾�򿪣��������е�����������ɺ󣬿�ע�͵� */
//            cout << "[]Խ����ԣ�"  << arr1[arrsize] << endl;

            cout << "--------------------" << endl;

            for (i = 0; i < arrsize; i++)
                cout << "array.at(" << i << ")��" << arr1.at(i) << endl;

            /* �˾�򿪣��������е�����������ɺ󣬿�ע�͵� */
//            cout << "atԽ����ԣ�" << arr1.at(arrsize) << endl;

            cout << "--------------------" << endl;

            cout << "array����Ԫ�أ�" << arr1.front() << endl;
            cout << "array��βԪ�أ�" << arr1.back() << endl;

            cout << "--------------------" << endl;

            cout << "array���׵�ַ��" << &arr1 << " ��ַ+1��" << (&arr1 + 1) << endl;
            cout << "array���׵�ַ��" << arr1.data() << " ��ַ+1��" << (arr1.data() + 1) << endl;
            cout << "array����Ԫ��: " << *(arr1.data()) << endl;

            for (i = 0; i < arrsize; i++)
                cout << "data+" << i << "��" << setw(12) << *(arr1.data() + i) << "\tdata[" << i << "]��" << arr1.data()[i] << endl;

            wait_for_enter();
        }

        if (1) {
            /* ����������� */
            cout << "�����������" << endl;
            cout << "--------------------" << endl;

            my_array<string, 5> arr;

            arr.fill("hello");

            cout << "�����ֵ" << endl;
            for (auto i : arr) { //auto����һ���÷����������
                cout << i << " ";
            }
            cout << endl;

            cout << "--------------------" << endl;

            my_array<string, 3> first = { "ABC", "DEF", "GHI" };
            my_array<string, 3> second = { "����", "����", "����"};

            cout << "����ǰ��" << endl;
            cout << "first ���飺";
            for (auto i : first) {
                cout << i << " ";
            }
            cout << endl;

            cout << "second���飺";
            for (auto i : second) { //auto����һ���÷����������
                cout << i << " ";
            }
            cout << endl;

            first.swap(second);

            cout << "--------------------" << endl;

            cout << "������" << endl;
            cout << "first ���飺";
            for (auto i : first) {
                cout << i << " ";
            }
            cout << endl;

            cout << "second���飺";
            for (auto i : second) { //auto����һ���÷����������
                cout << i << " ";
            }
            cout << endl;

            wait_for_enter();
        }

        if (1) {
            /* �Ƚϲ������� */
            cout << "����Ƚϲ���" << endl;

            cout << "--------------------" << endl;

            my_array<string, 5> a = { "Welcome", "to", "tongji", "univercity", "!" };
            my_array<string, 5> b = { "Welcome", "to", "tongji", "univercity", "!" };
            my_array<string, 5> c = { "Welcome", "To", "tongji", "univercity", "!" };
            my_array<string, 5> d = { "Welcome", "tp", "tongji", "univercity", "!" };
            my_array<string, 3> e = { "Welcome", "to", "tongji" };

            cout << "a == b ��" << (a == b) << endl;
            cout << "a != b ��" << (a != b) << endl;
            cout << "a >= b ��" << (a >= b) << endl;
            cout << "a >  b ��" << (a > b) << endl;
            cout << "a <= b ��" << (a <= b) << endl;
            cout << "a <  b ��" << (a < b) << endl;

            cout << "--------------------" << endl;

            cout << "a == c ��" << (a == c) << endl;
            cout << "a != c ��" << (a != c) << endl;
            cout << "a >= c ��" << (a >= c) << endl;
            cout << "a >  c ��" << (a > c) << endl;
            cout << "a <= c ��" << (a <= c) << endl;
            cout << "a <  c ��" << (a < c) << endl;

            cout << "--------------------" << endl;

            cout << "a == d ��" << (a == d) << endl;
            cout << "a != d ��" << (a != d) << endl;
            cout << "a >= d ��" << (a >= d) << endl;
            cout << "a >  d ��" << (a > d) << endl;
            cout << "a <= d ��" << (a <= d) << endl;
            cout << "a <  d ��" << (a < d) << endl;

//            cout << "a == e ��" << (a == e) << endl;  //�˾����򿪣�����Ӧ����

            wait_for_enter();
        }
    }


    return 0;
}
