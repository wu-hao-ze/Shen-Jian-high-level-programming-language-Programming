/* 学号 班级 姓名 */
#include <iostream>
#include <iomanip>
#include <string>
//允许加入必要的头文件
using namespace std;

#if 0
/* 打开此宏定义，表示使用自定义的array */
#include "my_array.h"

#else
/* 打开此宏定义，表示使用系统的array */
#include <array>
#define my_array    array
#endif

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void wait_for_enter()
{
    cout << endl << "按回车键继续";
    while (getchar() != '\n')
        ;
    cout << endl << endl;
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
    if (1) {
        /* 测试int类型 */
        cout << "--------------------" << endl;
        cout << "   int类型测试" << endl;
        cout << "--------------------" << endl << endl;

        if (1) {
            /* 迭代器测试 */
            cout << "迭代器测试" << endl;
            cout << "--------------------" << endl;

            my_array<int, 5> arr1 = { 1, 2, 3, 4, 5};//全部初始化

            /* 自行定义迭代器 */
            cout << "数组的值(正序)/自定义迭代器" << endl;
            my_array<int, 5>::iterator it = arr1.begin();
            for (; it != arr1.end(); it++) {
                cout << *it << " ";
                (*it)++;
            }
            cout << endl;

            /* 后续均为auto自动定义（auto在定义这种复杂迭代器时很方便，允许使用） */
            cout << "数组的值(正序)" << endl;
            for (auto it = arr1.begin(); it != arr1.end(); it++) {
                cout << *it << " ";
                (*it)++;
            }
            cout << endl;

            cout << "数组的值(逆序)" << endl;
            for (auto rit = arr1.rbegin(); rit != arr1.rend(); rit++) {
                cout << *rit << " ";
                (*rit)++;
            }
            cout << endl;

            cout << "--------------------" << endl;
            my_array<int, 7> arr2 = { 11, 12, 13, 14, 15 };//部分初始化

            cout << "数组的值(正序只读)" << endl;
            for (auto cit = arr2.cbegin(); cit != arr2.cend(); cit++) {
                cout << *cit << " ";
                //            (*cit)++; //此句打开后编译要报错
            }
            cout << endl;

            cout << "--------------------" << endl;
            my_array<int, 3> arr3;//不初始化

            cout << "数组的值(逆序只读)" << endl;
            for (auto crit = arr3.crbegin(); crit != arr3.crend(); crit++) {
                cout << *crit << " ";
                //            (*crit)++; //此句打开后编译要报错
            }
            cout << endl;

            wait_for_enter();
        }

        if (1) {
            /* 大小测试 */
            cout << "整体求大小测试" << endl;
            cout << "--------------------" << endl;

            my_array<int, 10> arr1;
            cout << "sizeof的大小：" << sizeof(arr1) << endl;
            cout << "size()      ：" << arr1.size() << endl;
            cout << "max_size()  ：" << arr1.max_size() << endl; //array的大小声明后不可变，因此max_size与size相同
            cout << "empty       ：" << (arr1.empty()?'Y':'N') << endl;

            cout << "--------------------" << endl;

            my_array<int, 0> arr2;
            cout << "sizeof的大小：" << sizeof(arr2) << endl; //为啥是4 ？
            cout << "size()      ：" << arr2.size() << endl;
            cout << "max_size()  ：" << arr2.max_size() << endl; //array的大小声明后不可变，因此max_size与size相同
            cout << "empty       ：" << (arr2.empty() ? 'Y' : 'N') << endl;

            wait_for_enter();
        }

        if (1) {
            /* 元素访问测试 */
            cout << "元素访问测试" << endl;
            cout << "--------------------" << endl;

            const int arrsize = 7;
            my_array<int, arrsize> arr1 = {1,2,3,4,5,6,7};
            int i;

            for (i=0; i< arrsize; i++)
                cout << "array[" << i << "]：" << arr1[i] << endl;

            /* 此句打开，则运行有弹窗，测试完成后，可注释掉 */
//            cout << "[]越界测试："  << arr1[arrsize] << endl;

            cout << "--------------------" << endl;

            for (i = 0; i < arrsize; i++)
                cout << "array.at(" << i << ")：" << arr1.at(i) << endl;

            /* 此句打开，则运行有弹窗，测试完成后，可注释掉 */
//            cout << "at越界测试：" << arr1.at(arrsize) << endl;

            cout << "--------------------" << endl;

            cout << "array的首元素：" << arr1.front() << endl;
            cout << "array的尾元素：" << arr1.back() << endl;

            cout << "--------------------" << endl;

            cout << "array的首地址：" << &arr1 << " 地址+1：" << (&arr1+1) << endl;
            cout << "array的首地址：" << arr1.data() << " 地址+1：" << (arr1.data()+1) << endl;
            cout << "array的首元素: " << *(arr1.data()) << endl;
            for (i=0; i< arrsize; i++)
                cout << "data+" << i << "：" << *(arr1.data()+i) << "\tdata[" << i << "]：" << arr1.data()[i] << endl;

            wait_for_enter();
        }

        if (1) {
            /* 整体操作测试 */
            cout << "整体操作测试" << endl;
            cout << "--------------------" << endl;

            my_array<int, 5> arr;

            arr.fill(789);

            cout << "数组的值" << endl;
            for (auto i : arr) { //auto的另一种用法，自行体会
                cout << i << " ";
            }
            cout << endl;

            cout << "--------------------" << endl;

            my_array<int, 3> first = { 11, 22, 33 };
            my_array<int, 3> second = { 44, 55, 66 };

            cout << "交换前：" << endl;
            cout << "first 数组：";
            for (auto i : first) {
                cout << i << " ";
            }
            cout << endl;

            cout << "second数组：";
            for (auto i : second) { //auto的另一种用法，自行体会
                cout << i << " ";
            }
            cout << endl;

            first.swap(second);

            cout << "--------------------" << endl;

            cout << "交换后：" << endl;
            cout << "first 数组：";
            for (auto i : first) {
                cout << i << " ";
            }
            cout << endl;

            cout << "second数组：";
            for (auto i : second) { //auto的另一种用法，自行体会
                cout << i << " ";
            }
            cout << endl;

            wait_for_enter();
        }

        if (1) {
            /* 比较操作测试 */
            cout << "整体比较测试" << endl;
            cout << "--------------------" << endl;

            my_array<int, 5> a = { 10, 20, 30, 40, 50 };
            my_array<int, 5> b = { 10, 20, 30, 40, 50 };
            my_array<int, 5> c = { 10, 21, 30, 40, 50 };
            my_array<int, 5> d = { 10, 20, 30, 40, 49 };
            my_array<int, 3> e = { 1, 2, 3 };

            cout << "a == b ：" << (a == b) << endl;
            cout << "a != b ：" << (a != b) << endl;
            cout << "a >= b ：" << (a >= b) << endl;
            cout << "a >  b ：" << (a >  b) << endl;
            cout << "a <= b ：" << (a <= b) << endl;
            cout << "a <  b ：" << (a <  b) << endl;

            cout << "--------------------" << endl;

            cout << "a == c ：" << (a == c) << endl;
            cout << "a != c ：" << (a != c) << endl;
            cout << "a >= c ：" << (a >= c) << endl;
            cout << "a >  c ：" << (a >  c) << endl;
            cout << "a <= c ：" << (a <= c) << endl;
            cout << "a <  c ：" << (a <  c) << endl;

            cout << "--------------------" << endl;

            cout << "a == d ：" << (a == d) << endl;
            cout << "a != d ：" << (a != d) << endl;
            cout << "a >= d ：" << (a >= d) << endl;
            cout << "a >  d ：" << (a >  d) << endl;
            cout << "a <= d ：" << (a <= d) << endl;
            cout << "a <  d ：" << (a <  d) << endl;

//            cout << "a == e ：" << (a == e) << endl;  //此句若打开，编译应报错

            wait_for_enter();
        }
    }

    if (1) {
        /* 测试double类型 */
        cout << "--------------------" << endl;
        cout << "   double类型测试" << endl;
        cout << "--------------------" << endl << endl;

        if (1) {
            /* 迭代器测试 */
            cout << "迭代器测试" << endl;
            cout << "--------------------" << endl;

            my_array<double, 5> arr1 = { 1.1, 2.2, 3.3, 4.4, 5.5 };//全部初始化

            /* 自行定义迭代器 */
            cout << "数组的值(正序)/自定义迭代器" << endl;
            my_array<double, 5>::iterator it = arr1.begin();
            for (; it != arr1.end(); it++) {
                cout << *it << " ";
                (*it)++;
            }
            cout << endl;

            /* 后续均为auto自动定义（auto在定义这种复杂迭代器时很方便，允许使用） */
            cout << "数组的值(正序)" << endl;
            for (auto it = arr1.begin(); it != arr1.end(); it++) {
                cout << *it << " ";
                (*it)++;
            }
            cout << endl;

            cout << "数组的值(逆序)" << endl;
            for (auto rit = arr1.rbegin(); rit != arr1.rend(); rit++) {
                cout << *rit << " ";
                (*rit)++;
            }
            cout << endl;

            cout << "--------------------" << endl;
            my_array<double, 7> arr2 = { 1.1, 1.2, 1.3, 1.4, 1.5 };//部分初始化

            cout << "数组的值(正序只读)" << endl;
            for (auto cit = arr2.cbegin(); cit != arr2.cend(); cit++) {
                cout << *cit << " ";
                //            (*cit)++; //此句打开后编译要报错
            }
            cout << endl;

            cout << "--------------------" << endl;
            my_array<double, 3> arr3;//不初始化

            cout << "数组的值(逆序只读)" << endl;
            for (auto crit = arr3.crbegin(); crit != arr3.crend(); crit++) {
                cout << *crit << " ";
                //            (*crit)++; //此句打开后编译要报错
            }
            cout << endl;

            wait_for_enter();
        }

        if (1) {
            /* 大小测试 */
            cout << "整体求大小测试" << endl;
            cout << "--------------------" << endl;

            my_array<double, 10> arr1;
            cout << "sizeof的大小：" << sizeof(arr1) << endl;
            cout << "size()      ：" << arr1.size() << endl;
            cout << "max_size()  ：" << arr1.max_size() << endl; //array的大小声明后不可变，因此max_size与size相同
            cout << "empty       ：" << (arr1.empty() ? 'Y' : 'N') << endl;

            cout << "--------------------" << endl;

            my_array<double, 0> arr2;
            cout << "sizeof的大小：" << sizeof(arr2) << endl; //为啥是4 ？
            cout << "size()      ：" << arr2.size() << endl;
            cout << "max_size()  ：" << arr2.max_size() << endl; //array的大小声明后不可变，因此max_size与size相同
            cout << "empty       ：" << (arr2.empty() ? 'Y' : 'N') << endl;

            wait_for_enter();
        }

        if (1) {
            /* 元素访问测试 */
            cout << "元素访问测试" << endl;
            cout << "--------------------" << endl;

            const int arrsize = 7;
            my_array<double, arrsize> arr1 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
            int i;

            for (i = 0; i < arrsize; i++)
                cout << "array[" << i << "]：" << arr1[i] << endl;

            /* 此句打开，则运行有弹窗，测试完成后，可注释掉 */
//            cout << "[]越界测试："  << arr1[arrsize] << endl;

            cout << "--------------------" << endl;

            for (i = 0; i < arrsize; i++)
                cout << "array.at(" << i << ")：" << arr1.at(i) << endl;

            /* 此句打开，则运行有弹窗，测试完成后，可注释掉 */
//            cout << "at越界测试：" << arr1.at(arrsize) << endl;

            cout << "--------------------" << endl;

            cout << "array的首元素：" << arr1.front() << endl;
            cout << "array的尾元素：" << arr1.back() << endl;

            cout << "--------------------" << endl;

            cout << "array的首地址：" << &arr1 << " 地址+1：" << (&arr1 + 1) << endl;
            cout << "array的首地址：" << arr1.data() << " 地址+1：" << (arr1.data() + 1) << endl;
            cout << "array的首元素: " << *(arr1.data()) << endl;
            for (i = 0; i < arrsize; i++)
                cout << "data+" << i << "：" << *(arr1.data() + i) << "\tdata[" << i << "]：" << arr1.data()[i] << endl;

            wait_for_enter();
        }

        if (1) {
            /* 整体操作测试 */
            cout << "整体操作测试" << endl;
            cout << "--------------------" << endl;

            my_array<double, 5> arr;

            arr.fill(123.456);

            cout << "数组的值" << endl;
            for (auto i : arr) { //auto的另一种用法，自行体会
                cout << i << " ";
            }
            cout << endl;

            cout << "--------------------" << endl;

            my_array<double, 3> first = { 1.1, 2.2, 3.3 };
            my_array<double, 3> second = { 4.4, 5.5, 6.6 };

            cout << "交换前：" << endl;
            cout << "first 数组：";
            for (auto i : first) {
                cout << i << " ";
            }
            cout << endl;

            cout << "second数组：";
            for (auto i : second) { //auto的另一种用法，自行体会
                cout << i << " ";
            }
            cout << endl;

            first.swap(second);

            cout << "--------------------" << endl;

            cout << "交换后：" << endl;
            cout << "first 数组：";
            for (auto i : first) {
                cout << i << " ";
            }
            cout << endl;

            cout << "second数组：";
            for (auto i : second) { //auto的另一种用法，自行体会
                cout << i << " ";
            }
            cout << endl;

            wait_for_enter();
        }

        if (1) {
            /* 比较操作测试 */
            cout << "整体比较测试" << endl;
            cout << "--------------------" << endl;

            my_array<double, 5> a = { 1.0, 2.0, 3.0, 4.0, 5.0 };
            my_array<double, 5> b = { 1.0, 2.0, 3.0, 4.0, 5.0 };
            my_array<double, 5> c = { 1.0, 2.1, 3.0, 4.0, 5.0 };
            my_array<double, 5> d = { 1.0, 2.0, 3.0, 4.0, 4.9 };
            my_array<double, 3> e = { 1.1, 2.2, 3.3 };

            cout << "a == b ：" << (a == b) << endl;
            cout << "a != b ：" << (a != b) << endl;
            cout << "a >= b ：" << (a >= b) << endl;
            cout << "a >  b ：" << (a > b) << endl;
            cout << "a <= b ：" << (a <= b) << endl;
            cout << "a <  b ：" << (a < b) << endl;

            cout << "--------------------" << endl;

            cout << "a == c ：" << (a == c) << endl;
            cout << "a != c ：" << (a != c) << endl;
            cout << "a >= c ：" << (a >= c) << endl;
            cout << "a >  c ：" << (a > c) << endl;
            cout << "a <= c ：" << (a <= c) << endl;
            cout << "a <  c ：" << (a < c) << endl;

            cout << "--------------------" << endl;

            cout << "a == d ：" << (a == d) << endl;
            cout << "a != d ：" << (a != d) << endl;
            cout << "a >= d ：" << (a >= d) << endl;
            cout << "a >  d ：" << (a > d) << endl;
            cout << "a <= d ：" << (a <= d) << endl;
            cout << "a <  d ：" << (a < d) << endl;

            //            cout << "a == e ：" << (a == e) << endl;  //此句若打开，编译应报错

            cout << "--------------------" << endl;

            /* 思考一下，这组测试想表达什么？ */
            my_array<double, 5> a1 = { 1.0, 2.0, 3.0, 4.0, 5.0 };
            my_array<double, 5> b1 = { 1.0F, 2.0, 3.0, 4.0, 5.0 };
            my_array<double, 5> a2 = { 1.1, 2.1, 3.1, 4.1, 5.1 };
            my_array<double, 5> b2 = { 1.1F, 2.1, 3.1, 4.1, 5.1 };

            cout << "a1 == b1 ：" << (a1 == b1) << endl;
            cout << "a2 == b2 ：" << (a2 == b2) << endl; 

            wait_for_enter();
        }
    }

    if (1) {
        /* 测试string类型 */
        cout << "--------------------" << endl;
        cout << "   string类型测试" << endl;
        cout << "--------------------" << endl << endl;

        if (1) {
            /* 迭代器测试 */
            cout << "迭代器测试" << endl;
            cout << "--------------------" << endl;

            my_array<string, 5> arr1 = { "Welcome", "to", "tongji", "univercity", "!" };//全部初始化

            /* 自行定义迭代器 */
            cout << "数组的值(正序)/自定义迭代器" << endl;
            my_array<string, 5>::iterator it = arr1.begin();
            for (; it != arr1.end(); it++) {
                cout << *it << " ";
//                (*it)++;      string不能++
            }
            cout << endl;

            /* 后续均为auto自动定义（auto在定义这种复杂迭代器时很方便，允许使用） */
            cout << "数组的值(正序)" << endl;
            for (auto it = arr1.begin(); it != arr1.end(); it++) {
                cout << *it << " ";
//                (*it)++;      string不能++
            }
            cout << endl;

            cout << "数组的值(逆序)" << endl;
            for (auto rit = arr1.rbegin(); rit != arr1.rend(); rit++) {
                cout << *rit << " ";
//                (*rit)++;     string不能++
            }
            cout << endl;

            cout << "--------------------" << endl;
            my_array<string, 5> arr2 = { "我", "走路", "到", "曲阳路", "吃火锅" };//全部初始化

            cout << "数组的值(正序只读)" << endl;
            for (auto cit = arr2.cbegin(); cit != arr2.cend(); cit++) {
                cout << *cit << " ";
//            (*cit)++; //此句打开后编译要报错
            }
            cout << endl;

            cout << "--------------------" << endl;
            my_array<string, 3> arr3;//不初始化

            cout << "数组的值(逆序只读)" << endl;
            for (auto crit = arr3.crbegin(); crit != arr3.crend(); crit++) {
                if ((*crit).empty())
                    cout << "null ";
                else
                    cout << *crit << " ";
//            (*crit)++; //此句打开后编译要报错
            }
            cout << endl;

            wait_for_enter();
        }

        if (1) {
            /* 大小测试 */
            cout << "整体求大小测试" << endl;
            cout << "--------------------" << endl;

            my_array<string, 10> arr1;
            cout << "sizeof(string)的大小：" << sizeof(string) << endl;
            cout << "sizeof的大小：" << sizeof(arr1) << endl;
            cout << "size()      ：" << arr1.size() << endl;
            cout << "max_size()  ：" << arr1.max_size() << endl; //array的大小声明后不可变，因此max_size与size相同
            cout << "empty       ：" << (arr1.empty() ? 'Y' : 'N') << endl;

            cout << "--------------------" << endl;

            my_array<string, 0> arr2;
            cout << "sizeof(string)的大小：" << sizeof(string) << endl;
            cout << "sizeof的大小：" << sizeof(arr2) << endl; //为啥是4 ？
            cout << "size()      ：" << arr2.size() << endl;
            cout << "max_size()  ：" << arr2.max_size() << endl; //array的大小声明后不可变，因此max_size与size相同
            cout << "empty       ：" << (arr2.empty() ? 'Y' : 'N') << endl;

            wait_for_enter();
        }

        if (1) {
            /* 元素访问测试 */
            cout << "元素访问测试" << endl;
            cout << "--------------------" << endl;

            const int arrsize = 5;
            my_array<string, arrsize> arr1 = { "Welcome", "to", "tongji", "univercity", "!" };
            int i;

            for (i = 0; i < arrsize; i++)
                cout << "array[" << i << "]：" << arr1[i] << endl;

            /* 此句打开，则运行有弹窗，测试完成后，可注释掉 */
//            cout << "[]越界测试："  << arr1[arrsize] << endl;

            cout << "--------------------" << endl;

            for (i = 0; i < arrsize; i++)
                cout << "array.at(" << i << ")：" << arr1.at(i) << endl;

            /* 此句打开，则运行有弹窗，测试完成后，可注释掉 */
//            cout << "at越界测试：" << arr1.at(arrsize) << endl;

            cout << "--------------------" << endl;

            cout << "array的首元素：" << arr1.front() << endl;
            cout << "array的尾元素：" << arr1.back() << endl;

            cout << "--------------------" << endl;

            cout << "array的首地址：" << &arr1 << " 地址+1：" << (&arr1 + 1) << endl;
            cout << "array的首地址：" << arr1.data() << " 地址+1：" << (arr1.data() + 1) << endl;
            cout << "array的首元素: " << *(arr1.data()) << endl;

            for (i = 0; i < arrsize; i++)
                cout << "data+" << i << "：" << setw(12) << *(arr1.data() + i) << "\tdata[" << i << "]：" << arr1.data()[i] << endl;

            wait_for_enter();
        }

        if (1) {
            /* 整体操作测试 */
            cout << "整体操作测试" << endl;
            cout << "--------------------" << endl;

            my_array<string, 5> arr;

            arr.fill("hello");

            cout << "数组的值" << endl;
            for (auto i : arr) { //auto的另一种用法，自行体会
                cout << i << " ";
            }
            cout << endl;

            cout << "--------------------" << endl;

            my_array<string, 3> first = { "ABC", "DEF", "GHI" };
            my_array<string, 3> second = { "张三", "李四", "王五"};

            cout << "交换前：" << endl;
            cout << "first 数组：";
            for (auto i : first) {
                cout << i << " ";
            }
            cout << endl;

            cout << "second数组：";
            for (auto i : second) { //auto的另一种用法，自行体会
                cout << i << " ";
            }
            cout << endl;

            first.swap(second);

            cout << "--------------------" << endl;

            cout << "交换后：" << endl;
            cout << "first 数组：";
            for (auto i : first) {
                cout << i << " ";
            }
            cout << endl;

            cout << "second数组：";
            for (auto i : second) { //auto的另一种用法，自行体会
                cout << i << " ";
            }
            cout << endl;

            wait_for_enter();
        }

        if (1) {
            /* 比较操作测试 */
            cout << "整体比较测试" << endl;

            cout << "--------------------" << endl;

            my_array<string, 5> a = { "Welcome", "to", "tongji", "univercity", "!" };
            my_array<string, 5> b = { "Welcome", "to", "tongji", "univercity", "!" };
            my_array<string, 5> c = { "Welcome", "To", "tongji", "univercity", "!" };
            my_array<string, 5> d = { "Welcome", "tp", "tongji", "univercity", "!" };
            my_array<string, 3> e = { "Welcome", "to", "tongji" };

            cout << "a == b ：" << (a == b) << endl;
            cout << "a != b ：" << (a != b) << endl;
            cout << "a >= b ：" << (a >= b) << endl;
            cout << "a >  b ：" << (a > b) << endl;
            cout << "a <= b ：" << (a <= b) << endl;
            cout << "a <  b ：" << (a < b) << endl;

            cout << "--------------------" << endl;

            cout << "a == c ：" << (a == c) << endl;
            cout << "a != c ：" << (a != c) << endl;
            cout << "a >= c ：" << (a >= c) << endl;
            cout << "a >  c ：" << (a > c) << endl;
            cout << "a <= c ：" << (a <= c) << endl;
            cout << "a <  c ：" << (a < c) << endl;

            cout << "--------------------" << endl;

            cout << "a == d ：" << (a == d) << endl;
            cout << "a != d ：" << (a != d) << endl;
            cout << "a >= d ：" << (a >= d) << endl;
            cout << "a >  d ：" << (a > d) << endl;
            cout << "a <= d ：" << (a <= d) << endl;
            cout << "a <  d ：" << (a < d) << endl;

//            cout << "a == e ：" << (a == e) << endl;  //此句若打开，编译应报错

            wait_for_enter();
        }
    }


    return 0;
}
