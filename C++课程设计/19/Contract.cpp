#include <iostream>
#include <string>
#include "Date.hpp"
using namespace std;

class Contract{
	public:
		Contract(){
			id=0;
			partyA="";
			partyB="";
			content="";
			validStart.init(1970,1,1);
			validEnd.init(1970,1,1);
			money=0;
			signedDate.init(1970,1,1);
		}
		Contract(int id, string partyA, string partyB, string content, Date validStart, Date ValidEnd, double money, Date signedDate){
			
		}
	private:
		int id;
		string partyA;
		string partyB;
		string content;
		Date validStart;
		Date validEnd;
		double money;
		Date signedDate;
};
