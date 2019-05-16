#include "Point.h"
using namespace std;

class Circle: public Point{
	public:
		Circle(double x, double y, double r):Point(x, y),radius(r){}
		friend ostream& operator<<(ostream& out, const Circle& c){
			out<<"Circle : "<<"("<<c.Point::getX()<<", "<<c.Point::getY()<<") radius = "<<c.radius<<endl;
			return out;
		}
		
		double getRadius(){
			return radius;
		} 
		
		void setRadius(double r){
			if(r>0){
				radius=r;
			} else {
				radius=0;
			}
		}
	private:
		 double radius;
}; 
