#include <iostream>
using namespace std;
class Date; //对Date类的提前引用声明

class clock //定义clock类
{
	public:
	clock(int,int,int);
	
	//void display(const Date&); //display是成员函数，形参是Date类对象的引用
	void display(const Date&);
	private:
	int hour;
	int minute;
	int second;
};

class Date //声明Date类
{
	public:
	Date(int,int,int);
	//friend void clock::display(const Date&); //声明clock中的display函数为友元成员函数
	int getMonth() const;
	int getYear() const;
	int getDay() const;
	private:
	int month;
	int day;
	int year;
};
