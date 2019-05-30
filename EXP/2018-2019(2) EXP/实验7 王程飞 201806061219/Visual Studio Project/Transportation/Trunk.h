#pragma once
#include "Vehicle.h"
class Trunk : public Vehicle
{
public:
	Trunk(int doors, int cylinders, int type, const char* color, double fuelLevel, int hasCargo) :
		Vehicle(doors, cylinders, type, color, fuelLevel) {
		this->hasCargo = hasCargo;
	}

	friend ostream& operator<<(ostream& out, Trunk& v) {
		out << "Number of doors: " << v.getDoors() << endl;
		out << "Number of cylinders: " << v.getCylinders() << endl;
		out << "Transmission type: " << v.getType() << endl;
		out << "Color: " << v.getColor() << endl;
		out << "Fuel level: " << v.getFuelLevel() << endl;
		out << "The trunk is ";
		if (v.hasCargo != 0) {
			out << "carring";
		}
		else {
			out << "not carring";
		}
		cout << " cargo" << endl;
		return out;
	}

private:
	int hasCargo;
};

