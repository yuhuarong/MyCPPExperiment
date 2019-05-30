// Chapter 9 of C++ How to Program
// Debugging Problem (dog.cpp)

#include <iostream>

using std::cout;
using std::endl;

#include "dog.h"

Dog::Dog(const int h, const int w, const char* n)
	: Animal(h, w, n){}


void Dog::Print() const
{
   cout << "The person is named: " << name << endl;
   print();
}

