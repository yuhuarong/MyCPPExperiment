#include <iostream>
#include "Clock.hpp"
using namespace std;

/**
*�����Ƶĵط� 
* 1. ���ܿ��� �� ���ʱ 
* ���Ʒ���
* 1. ��Ӷ��������ԵĲ������������Ӧ�ķ��� 
*/


int main(int argc, char** argv) {
	/**
	*���� 10:30:02 �뿪 10:45:45
    *���� 10:32:14 �뿪 12:30:23
    *���� 13:11:23 �뿪 15:45:30
    *���� 12:10:55 �뿪 9:08:05
	*/
	Clock arriveTime[4],leaveTime[4];
	
	arriveTime[0].init(10,30,2);leaveTime[0].init(10,45,45);
	arriveTime[1].init(10,32,14);leaveTime[1].init(12,30,23);
	arriveTime[2].init(13,11,23);leaveTime[2].init(15,45,30);
	arriveTime[3].init(12,10,55);leaveTime[3].init(9,8,5);
	
	for(int i=0;i<4;i++){
		cout<<"��� ";arriveTime[i].toString();cout<<", �뿪�� ";leaveTime[i].toString();cout<<" �� "<<(double)(leaveTime[i].diff(arriveTime[i]))<<" h"<<endl;
	}
	
	return 0;
}
