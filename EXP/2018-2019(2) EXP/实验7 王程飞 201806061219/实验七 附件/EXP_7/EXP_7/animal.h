// Chapter 9 of C++ How to Program
// Debugging Problem (animal.h)

#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
public:
   Animal( const int = 0, const int = 0 );
   void print() const;
   int getHeight() const;
   int getWeight() const;
   void setHeight( int );
   void setWeight( int );
   const char * getName() const;
private:
   int height;
   int weight;
   char* name;
};

#endif

