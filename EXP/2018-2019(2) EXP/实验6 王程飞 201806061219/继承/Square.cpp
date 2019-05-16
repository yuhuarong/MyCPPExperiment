#include "Point.cpp"
using namespace std;

class Square: public Point{
	public:
		Square(float x=0, float y=0, float A=0):Point(x, y), a(A){}
		friend ostream& operator<<(ostream& out, const Square& s){
			out<<"Square : "<<"("<<s.getX()<<", "<<s.getY()<<") a = "<<s.a<<endl;
			return out;
		}
		
		float getA(){
			return a;
		} 
		
		void setA(float a){
			if(a>0){
				this->a=a;
			} else {
				this->a=0;
			}
		}
		
	private:
		float a;
		 
}; 
