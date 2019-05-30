#pragma once

class Animal {
public:
   Animal(int h = 0, int w = 0, const char* name = "TODO");
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
