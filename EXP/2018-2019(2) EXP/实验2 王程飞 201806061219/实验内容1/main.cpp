#include <iostream>
#include "Pool.hpp"
using namespace std;

		//Ö±¾¶							//×ßµÀ¿í 
double dPool[]{ 12.2, 5, 4.8, 6, 8.7 }, roadWidth[]{ 3, 2.8, 1, 1.4, 2.3 };

void solveWithObject(){
	for(int i=0;i<5;i++){
		Pool pool(dPool[i], roadWidth[i]);
		pool.toString();
	} 
	cout<<endl; 
	
}

int main() {
	solveWithObject();
	return 0;
}


