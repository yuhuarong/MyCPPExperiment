#include<iostream>
using namespace std;

class Boolean {
public:
	Boolean();
	
	Boolean(Boolean& b);
	
	operator int();

	template<class T> Boolean(T flag) {
		if (flag) {
			this->flag = 1;
		} else {
			this->flag = 0;
		}
	}

	friend ostream& operator<<(ostream& out, const Boolean& b);

	int getFlag() const;

	void setFlag(int i);
	
	friend Boolean& operator^(const Boolean& a, const Boolean& b);
	
	Boolean& operator!();

	friend Boolean& operator&&(const Boolean& a, const Boolean& b);

	friend Boolean& operator||(const Boolean& a, const Boolean& b);

	Boolean& operator= (const Boolean& b);

	Boolean& operator= (bool b);

private:
	int flag;
};


