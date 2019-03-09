#include<iostream>
#include "Pool.hpp"
using namespace std;

void Pool::toString(){
	cout<<"直径 "<<2*r<<" m, 走道宽 "<<roadWidth<<" m的游泳池造价为： "<<getPrice()<<"元"<<endl;
}

double Pool::getPrice(){
	return getRoadPrice()+getRPrice();
}

void Pool::init(double d, double roadWidth){
	this->r=d/2;
	this->roadWidth=roadWidth;
}

double Pool::getRPrice(){
	return pR*r*r*3.14; 
}

double Pool::getRoadPrice(){
	return pRoad*((r+roadWidth)*(r+roadWidth)-(r*r))*3.14;
}
