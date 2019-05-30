#include <iostream>
using namespace std;
#pragma once
class Vehicle
{
public:
	Vehicle(int doors, int cylinders, int type, const char* color, double fuelLevel) {
		this->doors = doors;
		this->cylinders = cylinders;
		this->type = type;
		this->fuelLevel = fuelLevel;
		strcpy_s(this->color, color);
	}

	friend ostream& operator<<(ostream& out, Vehicle& v) {
		out << "Number of doors: " << v.getDoors() << endl;
		out << "Number of cylinders: " << v.getCylinders() << endl;
		out << "Transmission type: " << v.getType()<< endl;
		out << "Color: " << v.getColor() << endl;
		out << "Fuel level: " << v.getFuelLevel() << endl;
		return out;
	}

	int getDoors() {
		return doors;
	}

	int getCylinders() {
		return cylinders;
	}

	int getType() {
		return type;
	}

	char* getColor() {
		return color;
	}

	double getFuelLevel() {
		return fuelLevel;
	}

private:
	int doors;
	int cylinders;
	int type;
	char color[50];
	double fuelLevel;
};

