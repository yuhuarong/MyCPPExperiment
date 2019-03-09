#include <iostream>
#include "Date.hpp"
#include "Circum.hpp" 
using namespace std;

const int tYear=2019;
const int tMonth=3;
const int tDay=11;
const int tWeek=1;

void Date::init(){
	cout<<"input yyyy:mm:dd"<<endl;
	cin>>year>>month>>day;
	init(year, month, day);
}

void Date::init(int year, int month, int day){
	setYear(year);
	setMonth(month);
	setDay(day);
}

void Date::toString(){
	cout<<"Date: "<<year<<"-"<<month<<"-"<<day<<" 星期"<<getWeek();
}

int Date::diff(const Date& date){
	int later=0;
	if(this->year>date.getYear()){
		later=0;
	}else if(this->year<date.getYear()){
		later=1;
	}else{
		if(this->month>date.getMonth()){
			later=0;
		}else if(this->month<date.getMonth()){
			later=1;
		}else{
			if(this->day>date.getDay()){
				later=0;
			}else if(this->day<date.getDay()){
				later=1;
			}else{
				return 0;
			}
		}
	}
	
	int n=0;
	
	if(later==1){//date较后 
		Date tDate=*this;
		do{
			tDate=next(tDate);
			//tDate.toString();
			n++;
		}while(!(tDate.getYear()==date.getYear()&&tDate.getMonth()==date.getMonth()&&tDate.getDay()==date.getDay()));
	} else {//this较后 
		Date tDate=date;
		do{
			tDate=next(tDate);
			//tDate.toString();
			n++;
		}while(!(tDate.getYear()==this->getYear()&&tDate.getMonth()==this->getMonth()&&tDate.getDay()==this->getDay()));
	}
	return n;
}

void Date::showMonthTable(){
	
}

void Date::setYear(int year){
	this->year=year;
}
void Date::setMonth(int month){
	if(month>12){
		this->month=1;
	}else{
		this->month=month;
	}
	
}
int Date::setDay(int day){
	
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
		if(day>31||day<1){
			day=1;this->day=day;return 1;
		}
	}else if(month==2){
		if(isLeap()){
			if(day>29||day<1){
				day=1;this->day=day;return 1;
			}
		}else{
			if(day>28||day<1){
				day=1;this->day=day;return 1;
			}
		}
	}else{
		if(day>30||day<1){
			day=1;this->day=day;return 1;
		}
	}
	this->day=day;
	return 0;
}

int Date::getWeek() const{
	return 1;
}

int Date::getYear() const{
	return year;
}

int Date::getMonth() const{
	return month;
}

int Date::getDay() const{
	return day;
}

int Date::isLeap(){
	if(year%400==0||year%4==0&&year%100!=0){
		return 1;
	}
	return 0;
}

Date Date::next(const Date& d){
	Date date=d;
	
	if(date.setDay(d.getDay()+1)){//返回1则月+1 
		if(d.getMonth()<12){
			date.setMonth(d.getMonth()+1);
			date.setYear(d.getYear());
		}else{
			date.setMonth(d.getMonth()+1);
			date.setYear(d.getYear()+1);
		}
	}else{
		date.setMonth(d.getMonth());
		date.setYear(d.getYear());
	}
	
	return date; 
}

