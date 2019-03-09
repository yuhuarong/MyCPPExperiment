#include <iostream>
#include "Clock.hpp"
using namespace std;

double Clock::diff(const Clock& clock){
	long d=normlize()-clock.normlize();
	//cout<<endl<<d<<endl;
    if(d<0) return 0;
	int	h=d/60, m=d%60;
	//cout<<h<<" "<<m<<endl;
    if(m<15) return h;
    if(m>=15&&m<30) return h+0.5;
    if(m>=30&&m<60) return h+1;
}
