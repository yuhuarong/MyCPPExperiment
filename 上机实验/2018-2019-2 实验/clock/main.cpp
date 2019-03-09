#include <iostream>
#include "Clock.hpp"
using namespace std;

/**
*不完善的地方 
* 1. 不能跨日 月 年计时 
* 完善方案
* 1. 添加对上述属性的参数，并加入对应的方法 
*/


int main(int argc, char** argv) {
	/**
	*进入 10:30:02 离开 10:45:45
    *进入 10:32:14 离开 12:30:23
    *进入 13:11:23 离开 15:45:30
    *进入 12:10:55 离开 9:08:05
	*/
	Clock arriveTime[4],leaveTime[4];
	
	arriveTime[0].init(10,30,2);leaveTime[0].init(10,45,45);
	arriveTime[1].init(10,32,14);leaveTime[1].init(12,30,23);
	arriveTime[2].init(13,11,23);leaveTime[2].init(15,45,30);
	arriveTime[3].init(12,10,55);leaveTime[3].init(9,8,5);
	
	for(int i=0;i<4;i++){
		cout<<"到达： ";arriveTime[i].toString();cout<<", 离开： ";leaveTime[i].toString();cout<<" 共 "<<(double)(leaveTime[i].diff(arriveTime[i]))<<" h"<<endl;
	}
	
	return 0;
}
