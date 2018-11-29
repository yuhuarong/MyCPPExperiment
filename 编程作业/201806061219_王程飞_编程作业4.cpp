#include <iostream> 
using namespace std;

int main()
{
	int year,month,day;
	cout << "请输入年份和月份：" << endl;
	cin >>  year >> month;
	switch (month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: cout<<year<<"-"<<month<<":31"<<endl;break;
		case 4:
		case 6:
		case 9:
		case 11:cout<<year<<"-"<<month<<":30"<<endl;break;
		case 2:cout<<year<<"-2:"<<(((year%4==0&&year%100!=0)||(year%400==0))?"29":"28")<<endl;break;
	}
	
	return 0;
}

