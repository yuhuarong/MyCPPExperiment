#include "friend_test.h"
clock::clock(int h,int m,int s) //��clock�Ĺ��캯��
{
	hour=h;
	minute=m;
	second=s;
}
/*
void clock::display(const Date &d) //display������������ꡢ�¡��պ�ʱ���֡���
{ 
	cout<<d.month<<"/"<<d.day<<"/"<<d.year<<endl; //����Date������е�˽������
	cout<<hour<<":"<<minute<<":"<<second<<endl; //���ñ�������е�˽������
}
*/

void clock::display(const Date &d) //display������������ꡢ�¡��պ�ʱ���֡���
{ 
	cout<<d.getYear()<<"/"<<d.getMonth()<<"/"<<d.getDay()<<endl; //����Date������е�˽������
	cout<<hour<<":"<<minute<<":"<<second<<endl; //���ñ�������е�˽������
}

int Date::getDay() const{
	return day;
}

int Date::getYear() const{
	return year;
}

int Date::getMonth() const{
	return month;
}

Date::Date(int m,int d,int y) //��Date�Ĺ��캯��
{
	month=m;
	day=d;
	year=y;
}
