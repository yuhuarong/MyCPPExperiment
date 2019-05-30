// Chapter 9 of C++ How to Program
// Debugging Problem (dog.h)

#ifndef DOG_H
#define DOG_H

#include "dog.h"

class Dog : public Animal {
public:
   Dog(const int, const int, const char * = "Toto");
   Dog(){}
   void Print() const;
   void setName( const char * );
private:
   char name[ 30 ];
};

#endif

