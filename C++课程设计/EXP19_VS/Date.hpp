#pragma once
#include<iostream>
using namespace std;
/*
������(Date)�����������յ���Ϣ
1��������Ϣ����
2����ʾ����
3��������������ڼ�
4���ṩ���µ�������ʾ
5�������������������� 
*/

class Date{
	public:
		void init();
		void init(int, int, int);
		void toString();
		int diff(const Date& date);
		void showMonthTable();
		
		void setYear(int);
		void setMonth(int);
		int setDay(int);
		
		int getYear() const;
		int getMonth() const;
		int getDay() const;
		int getWeek();
		
		friend ostream& operator<<(ostream& out, const Date& date);
		friend istream& operator>>(istream& in, Date& date);
		
		int operator==(const Date& date){
			if(this->year==date.year&&this->month==date.month&&this->day==date.day){
				return 1;
			}
			
			return 0;
		}
		
		int operator>(const Date& date){
			if(this->year>date.year){
				return 1; 
			} else if(this->year==date.year){
				if(this->month>date.month){
					return 1;
				} else if(this->month==date.month){
					if(this->day>date.day){
						return 1;
					} else {
						return 0;
					}
				} else {
					return 0;
				}
			} else {
				return 0;
			}
		}
		
		int operator<(const Date& date){
			if(this->year<date.year){
				return 1; 
			} else if(this->year==date.year){
				if(this->month<date.month){
					return 1;
				} else if(this->month==date.month){
					if(this->day<date.day){
						return 1;
					} else {
						return 0;
					}
				} else {
					return 0;
				}
			} else {
				return 0;
			}
		}
		
		int year;
		int month;
		int day;
		
		int isLeap();
		int getMax();
		
		Date next(const Date&);
		
}; 
