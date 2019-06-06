//在main函数所在的文件中包含头文件header1.h:
#include <iostream>
#include"example3_header1.h"
#include "example3_header2.h"
//注意要用双引号，因为文件一般是放在用户目录中的
using namespace std;
using namespace h1;

int main( )
{
	Student stud1(101,"Wang",'M'); //定义类对象stud1
	stud1.get_data( );
	cout<<fun(5,3)<<endl;
	return 0;
}
