#include<iostream>
using namespace std; 

		//ֱ��							//�ߵ��� 
double dPool[]{ 12.2, 5, 4.8, 6, 8.7 }, roadWidth[]{ 3, 2.8, 1, 1.4, 2.3 };

void solveWithProgress(){
	cout<<"------�������------"<<endl;
	const double pRoad=167.5;
	const double pR=36.4;
	for(int i=0;i<5;i++){
		cout<<"ֱ��Ϊ "<<dPool[i]<<"m, �ߵ���Ϊ "<<roadWidth[i]<<" m����Ӿ�����Ϊ�� "<<pRoad*((dPool[i]/2+roadWidth[i])*(dPool[i]/2+roadWidth[i])-(dPool[i]*dPool[i])/4)*3.14+pR*dPool[i]*dPool[i]*3.14/4<<"Ԫ"<<endl;
	}
	cout<<endl;
} //��������̷������ 

int main(){
	solveWithProgress();
	return 0;
}
