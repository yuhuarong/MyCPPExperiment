#include<iostream>
using namespace std;

class Pool{
	public:
		void init(double d, double roadWidth){
			this->r=d/2;
			this->roadWidth=roadWidth;
		}
		void toString(){
			cout<<"ֱ�� "<<2*r<<" m, �ߵ��� "<<roadWidth<<" m����Ӿ�����Ϊ�� "<<getPrice()<<"Ԫ"<<endl;
		}
		
		double getPrice(){
			return getRoadPrice()+getRPrice();
		}
		
		
		
	private:
		const double pRoad=167.5;
		const double pR=36.4;
		
		double r;//�뾶 
		double roadWidth;//�ߵ���
		
		double getRoadPrice(){
			return pRoad*((r+roadWidth)*(r+roadWidth)-(r*r))*3.14;
		}
		
		double getRPrice(){
			return pR*r*r*3.14; 
		}
		
};
