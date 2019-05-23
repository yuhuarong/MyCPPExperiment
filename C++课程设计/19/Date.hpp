#pragma once
#include<iostream>
using namespace std;
/*
日期类(Date)，包含年月日的信息
1）日期信息设置
2）显示日期
3）计算该日是星期几
4）提供该月的月历显示
5）计算与其他日期相差几天 
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
