#pragma once
#include "dog.h"
#include "animal.h"

class Dog : public Animal {
public:
   Dog(const int, const int, const char * = "Toto");
   Dog(){}
   void Print() const;
   Dog& operator=(const Animal& a) {
	   setName(a.getName());
	   this->setWeight(a.getWeight());
	   this->setHeight(a.getHeight());
	   return *this;
   }
};