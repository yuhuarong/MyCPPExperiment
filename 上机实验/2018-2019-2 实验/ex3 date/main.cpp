#include <iostream>
#include "Date.hpp"
using namespace std;

int main(){
	Date d1,d2;
	d1.init(2020,3,28);
	d2.init(2019,3,28);
	d1.toString();cout<<" Óë ";d2.toString();cout<<" Ïà¾à "<<d1.diff(d2)<<" Ìì";
	
	return 0; 
}
