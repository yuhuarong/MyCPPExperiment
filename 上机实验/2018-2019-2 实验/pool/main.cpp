#include <iostream>
#include "Pool.hpp"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
		//直径							//走道宽 
double dPool[]{ 12.2, 5, 4.8, 6, 8.7 }, roadWidth[]{ 3, 2.8, 1, 1.4, 2.3 };

void solveWithProgress(){
	cout<<"------面向过程------"<<endl<<endl;
	const double pRoad=167.5;
	const double pR=36.4;
	for(int i=0;i<5;i++){
		cout<<"直径为 "<<dPool[i]<<"m, 走道宽为 "<<roadWidth[i]<<" m的游泳池造价为： "<<pRoad*((dPool[i]/2+roadWidth[i])*(dPool[i]/2+roadWidth[i])-(dPool[i]*dPool[i])/4)*3.14+pR*dPool[i]*dPool[i]*3.14/4<<"元"<<endl;
	}
	cout<<endl;
} //用面向过程方法解决 

void solveWithObject(){
	cout<<"------面向对象------"<<endl;
	Pool pool[5];
	
	for(int i=0;i<5;i++){
		pool[i].init(dPool[i], roadWidth[i]);
		pool[i].toString();
	} 
	cout<<endl; 
} //用面向对象方法解决 

int main(int argc, char** argv) {
	
	solveWithObject();
	solveWithProgress();
	return 0;
}


