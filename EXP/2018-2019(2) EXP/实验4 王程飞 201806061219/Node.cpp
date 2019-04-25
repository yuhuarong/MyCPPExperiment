#include<iostream>
typedef int ElementType;

class Node{
public:
   Node(ElementType d, Node* n=NULL):data(d),next(n) {}
   Node(){
   	
   }
   ElementType data;
   Node* next;
};
 
