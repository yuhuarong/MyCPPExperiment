// Chapter 9 of C++ How to Program
// Debugging Problem (lion.h)

#ifndef LION_H
#define LION_H

#include "animal.h"

class Lion : public Animal {
public:
   Lion( const int = 0, const int = 0 );
   void print() const;
};

#endif

