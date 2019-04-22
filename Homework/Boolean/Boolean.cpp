#include<iostream>
#include "Boolean.h"
using namespace std;

ostream& operator<< (ostream& out, const Boolean& b) {
	out << ((b.getFlag() != 0) ? "true" : "false");
	return out;
}

Boolean& operator&&(const Boolean& a, const Boolean& b) {
	Boolean *c;
	c = new Boolean(a.getFlag() && b.getFlag());
	return *c;
}

Boolean& operator^(const Boolean& a, const Boolean& b) {
	Boolean* c;
	c = new Boolean( (a.getFlag() && !b.getFlag()) || (!a.getFlag() && b.getFlag()) );
	return *c;
}

Boolean& operator||(const Boolean& a, const Boolean& b) {
	Boolean* c;
	c = new Boolean(a.getFlag() || b.getFlag());
	return *c;
}

Boolean& Boolean::operator= (const Boolean& b) {
	flag = b.getFlag();
	return *this;
}

Boolean& Boolean::operator= (bool b) {
	flag = b;
	return *this;
}

Boolean& Boolean::operator!() {
	Boolean* a;
	if (flag) {
		a = new Boolean(0);
	}
	else
	{
		a = new Boolean(1);
	}
	return *a;
}

Boolean::Boolean(Boolean& b) {
	flag = b.flag;
}
	
Boolean::Boolean() {
	flag = 0;
}

void Boolean::setFlag(int i) {
	if (flag) {
		this->flag = 1;
	}
	else {
		this->flag = 0;
	}
}

Boolean::operator int(){
	return flag;
}

int Boolean::getFlag() const {
	return flag;
}


