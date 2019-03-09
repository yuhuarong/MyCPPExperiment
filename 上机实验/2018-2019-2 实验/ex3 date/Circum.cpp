#include <iostream>
#include "Circum.hpp"
using namespace std;

void Circum::setMode(int min,int max){
	this->max=(max>min)?max:min;
	this->min=(max<min)?max:min;
	
	cout<<"max : "<<min<<" max : "<<max<<endl;
}
void Circum::setMode(){
	cout<<"输入min 和 max :"<<endl; 
	cin>>min>>max;
	setMode(min,max);
}

void Circum::init(int now){
	if(now>max){
		this->now=max;
	}else if(now<min){
		this->now=min;
	}else{
		this->now=now;
	}
	
	toString();
}

void Circum::init(){
	cout<<"请输入初始值："<<endl; 
	cin>>now;
	init(now);
}

int Circum::next(){
	int mode=max-min+1;
	now=((now-min)+1)%mode+min;
	return now;
}

int Circum::last(int i){
	while(i--){
		last();
	}
	return now;
}


int Circum::last(){
	int mode=max-min+1;
	now=((now-min)-1+mode)%mode+min;
	return now;
}

int Circum::next(int i){
	while(i--){
		next();
	}
	return now;
}



void Circum::toString(){
	cout<<"now : "<<this->now<<endl; 
}

int Circum::getNow() const{
	return now;
}
