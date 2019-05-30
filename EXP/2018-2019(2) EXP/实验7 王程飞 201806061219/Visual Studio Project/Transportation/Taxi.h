#pragma once
#include "Vehicle.h"
class Taxi : public Vehicle
{
public:
	Taxi(int doors, int cylinders, int type, const char* color, double fuelLevel, int passengers) :
		Vehicle(doors, cylinders, type, color, fuelLevel) {
		this->passengers = passengers;
	}
	friend ostream& operator<<(ostream& out, Taxi& v) {
		out << "Number of doors: " << v.getDoors() << endl;
		out << "Number of cylinders: " << v.getCylinders() << endl;
		out << "Transmission type: " << v.getType() << endl;
		out << "Color: " << v.getColor() << endl;
		out << "Fuel level: " << v.getFuelLevel() << endl;
		out << "The taxi has ";
		if (v.passengers > 0) {
			out << v.passengers;
		} else{
			out << "no";
		}
		cout << " passengers" << endl;
		return out;
	}
private:
	int passengers;
};

