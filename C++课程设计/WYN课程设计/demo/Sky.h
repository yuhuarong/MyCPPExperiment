#pragma once
#include <graphics.h>     
#include <conio.h>
#include <iostream>

using namespace std;

class Sky
{
public:
	static Sky& getInstance() {
		return sky;
	}
private:
	Sky() {
		loadimage(&img, "sky.jpg");
		img_ptr = GetImageBuffer(&img);
	}
	IMAGE img;
	DWORD* img_ptr;
	static Sky sky;
};

