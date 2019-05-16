#include "Point.cpp"
using namespace std;

class Circle: public Point{
	public:
		Circle(float x=0, float y=0, float r=0):Point(x, y),radius(r){}
		friend ostream& operator<<(ostream& out, const Circle& c){
			out<<"Circle : "<<"("<<c.getX()<<", "<<c.getY()<<") radius = "<<c.radius<<endl;
			return out;
		}
		
		float getRadius(){
			return radius;
		} 
		
		void setRadius(float r){
			if(r>0){
				radius=r;
			} else {
				radius=0;
			}
		}
	private:
		 float radius;
}; 
