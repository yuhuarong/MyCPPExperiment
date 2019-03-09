#include <iostream>
#include "Pool.hpp"
using namespace std;

		//直径							//走道宽 
double dPool[]{ 12.2, 5, 4.8, 6, 8.7 }, roadWidth[]{ 3, 2.8, 1, 1.4, 2.3 };

void solveWithObject(){
	cout<<"------面向对象------"<<endl;
	
	Pool pool[5];
	for(int i=0;i<5;i++){
		pool[i].init(dPool[i], roadWidth[i]);
		pool[i].toString();
	} 
	cout<<endl; 
	
}

int main() {
	solveWithObject();
	return 0;
}


