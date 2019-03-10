#include <iostream>
#include "Date.hpp"
using namespace std;

int main(){
	Date d1,d2;
	d1.init(2020,2,18);
	d2.init(2019,3,23);
	d1.toString();cout<<" 与 ";d2.toString();cout<<" 相距 "<<d1.diff(d2)<<" 天"<<endl;
	
	d1.toString();cout<<" 星期"<<d1.getWeek()<<endl;
	d2.toString();cout<<" 星期"<<d2.getWeek()<<endl;
	
	d1.showMonthTable();
	d2.showMonthTable();
	
	return 0; 
}
