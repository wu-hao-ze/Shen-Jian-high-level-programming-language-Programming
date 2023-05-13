/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int usage(const char *procname)
{
	cout << "Usage: " << procname << " 要检查的学号/all 匹配学号/all 源程序名/all 相似度阀值(60-100) 输出(filename/screen)" << endl;
	cout << "               2059999          2059998      all          80                screen" << endl;
	cout << "               2059999          all          15-b3.cpp    75                result.txt" << endl;
	cout << "               all              all          15-b3.cpp    80                check.dat" << endl;
	cout << "               all              all          all          85                screen" << endl;

	return 0;
}
