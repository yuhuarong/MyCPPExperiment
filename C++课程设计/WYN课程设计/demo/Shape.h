#pragma once
#include <graphics.h>     
#include <conio.h>
#include <iostream>

using namespace std;

class Shape
{
public:
	Shape(int posX, int posY) {
		this->posX = posX;
		this->posY = posY;
	}

	float getX() {
		return posX;
	}

	float getY() {
		return posY;
	}

	void setX(float posX) {
		this->posX = posX;
	}

	void setY(float posY) {
		this->posY = posY;
	}

private:
	float posX;
	float posY;
	IMAGE img;
};

