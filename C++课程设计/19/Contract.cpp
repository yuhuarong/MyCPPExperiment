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
			this->id=id;
			this->partyA=partyA;
			this->partyB=partyB;
			this->content=content;
			this->validStart=validStart;
			this->validEnd=ValidEnd;
			this->money=money;
			this->signedDate=signedDate;
		}
		
		void clear(){
			id=0;
			partyA="";
			partyB="";
			content="";
			validStart.init(1970,1,1);
			validEnd.init(1970,1,1);
			money=0;
			signedDate.init(1970,1,1);
		}
		
		friend ostream& operator<<(ostream& out, const Contract& contract){
			out<<"ID: "<<contract.id<<' ';
			out<<"甲方: "<<contract.partyA<<' ';
			out<<"乙方: "<<contract.partyB<<' ';
			out<<"内容: "<<contract.content<<' ';
			out<<"开始日期: "<<contract.validStart<<' ';
			out<<"结束日期: "<<contract.validEnd<<' ';
			out<<"金额: "<<contract.money<<' ';
			out<<"签订日期: "<<contract.signedDate<<endl;
			return out;
		}
		
		friend istream& operator>>(istream& in, Contract& contract){
			int yyyy, MM, dd;
			cout<<"ID: ";in>>contract.id;
			cout<<"甲方: ";in>>contract.partyA;
			cout<<"乙方: ";in>>contract.partyB;
			cout<<"内容: ";in>>contract.content;
			cout<<"开始日期(yyyy MM dd): ";in>>contract.validStart.year>>contract.validStart.month>>contract.validStart.day; 
			cout<<"结束日期(yyyy MM dd): ";in>>contract.validEnd.year>>contract.validEnd.month>>contract.validEnd.day; 
			cout<<"金额: ";in>>contract.money;
			cout<<"签订日期(yyyy MM dd): ";in>>contract.signedDate.year>>contract.signedDate.month>>contract.signedDate.day; 
			return in;
		}

		int id;
		string partyA;
		string partyB;
		string content;
		Date validStart;
		Date validEnd;
		double money;
		Date signedDate;
};

