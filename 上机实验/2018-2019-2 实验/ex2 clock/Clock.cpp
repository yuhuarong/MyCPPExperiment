#include <iostream>
#include "Clock.hpp"
using namespace std;

double Clock::diff(const Clock& clock){
	long d=normlize()-clock.normlize()-60;
    if(d<0) return 0;
	int	h=d/60, m=d%60;
    if(m<15) return h;
    if(m>=15&&m<30) return h+0.5;
    if(m>=30&&m<60) return h+1;
}

void Clock::toString(){
	cout<<h<<":"<<m<<":"<<s; 
}

void Clock::init(){ 
	cout<<"ÊäÈëÊ±¼äh, m, s"<<endl;
	do{ cin>>h>>m>>s; }while(h<0||h>24||m<0||m>59||s<0||s>59);
	init(h, m, s); 
}
long Clock::normlize() const{
	return h*60+m;
}

void Clock::init(int h,int m,int s){ this->h=h;this->m=m;this->s=s; }
