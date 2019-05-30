// Chapter 9 of C++ How to Program
// Debugging Problem (animal.cpp)

#include <iostream>
#include <cstring>
using namespace std;

#include "animal.h"

Animal::Animal( const int h, const int w, char name[] )
{
   height = h;
   weight = w;
   setName(name);
}

void Animal::print() const
{
   cout << "This animal's height and weight are as follows\n"
        << "Height: " << height << "\tWeight: " << weight << endl << endl;
}

int Animal::getHeight() const { return height; }

int Animal::getWeight() const { return weight; }

void Animal::setHeight( const int h ) { height = h; }

void Animal::setWeight( const int w ) { weight = w; }

const char* Animal::getName() const { return name; }

void Animal::setName(const char* name) { strcpy(this->name, name); }

