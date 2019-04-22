#include<iostream>
using namespace std;

class Boolean {
public:
	Boolean() {
		flag = 0;
	}
	Boolean(Boolean& b) {
		flag = b.flag;
	}

	template<class T> Boolean(T flag) {
		if (flag) {
			this->flag = 1;
		} else {
			this->flag = 0;
		}
	}

	friend ostream& operator<<(ostream& out, const Boolean& b);

	int getFlag() const {
		return flag;
	}

	void setFlag(int i) {
		if (flag) {
			this->flag = 1;
		}
		else {
			this->flag = 0;
		}
	}
	
	friend Boolean& operator^(const Boolean a, const Boolean b) {
		Boolean* c;
		c = new Boolean( (a.getFlag() && !b.getFlag()) || (!a.getFlag() && b.getFlag()) );
		return *c;
	}

	Boolean& operator!() {
		Boolean* a;
		if (flag) {
			a = new Boolean(0);
		}
		else
		{
			a = new Boolean(1);
		}
		return *a;
	}

	friend Boolean& operator&&(const Boolean& a, const Boolean& b) {
		Boolean *c;
		c = new Boolean(a.getFlag() && b.getFlag());
		return *c;
	}

	friend Boolean& operator||(const Boolean& a, const Boolean& b) {
		Boolean* c;
		c = new Boolean(a.getFlag() || b.getFlag());
		return *c;
	}

	Boolean& operator= (const Boolean& b) {
		flag = b.getFlag();
		return *this;
	}

	Boolean& operator= (bool b) {
		flag = b;
		return *this;
	}

private:
	int flag;
};

