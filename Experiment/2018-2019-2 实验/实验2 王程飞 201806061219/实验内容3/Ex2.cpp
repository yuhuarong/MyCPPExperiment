#include<iostream>
using namespace std;

class Ex2{
public:
	Ex2(int v=0){x=new int(v);}
    Ex2(const Ex2& ex2){x=new int(); this->setX(ex2.getX());}
    Ex2& operator=(const Ex2& ex2){*x=ex2.getX(); return *this;}
    void setX(int v){*x=v;}
    int getX() const{return *x;}
    ~Ex2(){cout<<"Îö¹¹ Ex2 x = "<<getX()<<endl; delete x;}
private:
	int *x;
};

