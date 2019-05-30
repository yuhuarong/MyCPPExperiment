// Chapter 9 of C++ How to Program
// Debugging Problem (animal.h)

#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
public:
   Animal(const int, const int, char* name);
   void print() const;
   int getHeight() const;
   int getWeight() const;
   void setHeight( int );
   void setWeight( int );
   const char * getName() const;
   void setName(const char* name);
private:
   int height;
   int weight;
   char name[50];
};

#endif

