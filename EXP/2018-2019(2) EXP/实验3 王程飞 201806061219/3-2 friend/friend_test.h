#include <iostream>
using namespace std;
class Date; //��Date�����ǰ��������

class clock //����clock��
{
	public:
	clock(int,int,int);
	
	//void display(const Date&); //display�ǳ�Ա�������β���Date����������
	void display(const Date&);
	private:
	int hour;
	int minute;
	int second;
};

class Date //����Date��
{
	public:
	Date(int,int,int);
	//friend void clock::display(const Date&); //����clock�е�display����Ϊ��Ԫ��Ա����
	int getMonth() const;
	int getYear() const;
	int getDay() const;
	private:
	int month;
	int day;
	int year;
};
