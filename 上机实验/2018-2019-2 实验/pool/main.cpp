#include <iostream>
#include "Pool.hpp"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
		//ֱ��							//�ߵ��� 
double dPool[]{ 12.2, 5, 4.8, 6, 8.7 }, roadWidth[]{ 3, 2.8, 1, 1.4, 2.3 };

void solveWithProgress(){
	cout<<"------�������------"<<endl<<endl;
	const double pRoad=167.5;
	const double pR=36.4;
	for(int i=0;i<5;i++){
		cout<<"ֱ��Ϊ "<<dPool[i]<<"m, �ߵ���Ϊ "<<roadWidth[i]<<" m����Ӿ�����Ϊ�� "<<pRoad*((dPool[i]/2+roadWidth[i])*(dPool[i]/2+roadWidth[i])-(dPool[i]*dPool[i])/4)*3.14+pR*dPool[i]*dPool[i]*3.14/4<<"Ԫ"<<endl;
	}
	cout<<endl;
} //��������̷������ 

void solveWithObject(){
	cout<<"------�������------"<<endl;
	Pool pool[5];
	
	for(int i=0;i<5;i++){
		pool[i].init(dPool[i], roadWidth[i]);
		pool[i].toString();
	} 
	cout<<endl; 
} //��������󷽷���� 

int main(int argc, char** argv) {
	
	solveWithObject();
	solveWithProgress();
	return 0;
}


