#include<iostream>
using namespace std;

class Pool{
	public:
		void init(double d, double roadWidth){
			this->r=d/2;
			this->roadWidth=roadWidth;
		}
		void toString(){
			cout<<"直径 "<<2*r<<" m, 走道宽 "<<roadWidth<<" m的游泳池造价为： "<<getPrice()<<"元"<<endl;
		}
		
		double getPrice(){
			return getRoadPrice()+getRPrice();
		}
		
		
		
	private:
		const double pRoad=167.5;
		const double pR=36.4;
		
		double r;//半径 
		double roadWidth;//走道宽
		
		double getRoadPrice(){
			return pRoad*((r+roadWidth)*(r+roadWidth)-(r*r))*3.14;
		}
		
		double getRPrice(){
			return pR*r*r*3.14; 
		}
		
};
