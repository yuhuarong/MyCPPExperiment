class Ex1{
public:
    Ex1(int v=0){x=v;} 
    Ex1(const Ex1& ex1){x=ex1.getX();}
    Ex1& operator=(const Ex1& ex1){x=ex1.x; return *this;}
    void setX(int v){x=v;}
    int getX() const{return x;}
private:
   int x;
};
