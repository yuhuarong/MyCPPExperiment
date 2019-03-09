#include <iostream>
#include "Circum.hpp"
using namespace std;

int main() {
	Circum circum;
	
	circum.setMode();
	circum.init();
	
	cout<<"last : "<<circum.last()<<endl;
	cout<<"next : "<<circum.next(2)<<endl;
	
	circum.last();
	
	cout<<"last 10 : "<<circum.last(10)<<endl;
	cout<<"next 10 : "<<circum.next(20)<<endl;
	
	return 0;
}
