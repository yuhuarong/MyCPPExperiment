#include<iostream>
using namespace std;

class Point{
	public:
		Point(float x=0, float y=0){
			this->x=x;
			this->y=y;
		}
		
		float getX() const{
			return x;
		} 
		
		float getY() const{
			return y;
		}
		
		void setX(float x){
			this->x=x;
		}
		
		void setY(float y){
			this->y=y;
		}
		
		void moveTo(float x, float y){
			this->x=x;
			this->y=y;
		} 
		
		friend ostream& operator<<(ostream& out, const Point& p){
			out<<"Point : "<<"("<<p.x<<", "<<p.y<<")"<<endl;
			return out;
		}
		
	private:
		float x;
		float y; 
};
