#include<iostream>
#include "Pool.hpp"
using namespace std;

void Pool::toString(){
	cout<<"ֱ�� "<<2*r<<" m, �ߵ��� "<<roadWidth<<" m����Ӿ�����Ϊ�� "<<getPrice()<<"Ԫ"<<endl;
}

double Pool::getPrice(){
	return getRoadPrice()+getRPrice();
}

Pool::Pool(double d, double roadWidth){
	this->r=d/2;
	this->roadWidth=roadWidth;
}

double Pool::getRPrice(){
	return pR*r*r*3.14; 
}

double Pool::getRoadPrice(){
	return pRoad*((r+roadWidth)*(r+roadWidth)-(r*r))*3.14;
}

Pool::~Pool(){
	cout<<"���� Pool �ߵ��� : "<<this->roadWidth<<" �뾶 : "<<this->r<<endl; 
}
