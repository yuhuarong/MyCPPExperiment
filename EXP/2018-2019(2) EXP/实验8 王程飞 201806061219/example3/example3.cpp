//��main�������ڵ��ļ��а���ͷ�ļ�header1.h:
#include <iostream>
#include"example3_header1.h"
#include "example3_header2.h"
//ע��Ҫ��˫���ţ���Ϊ�ļ�һ���Ƿ����û�Ŀ¼�е�
using namespace std;
using namespace h1;

int main( )
{
	Student stud1(101,"Wang",'M'); //���������stud1
	stud1.get_data( );
	cout<<fun(5,3)<<endl;
	return 0;
}
