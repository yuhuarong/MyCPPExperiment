#pragma once
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
			out<<contract.id<<' ';
			out<<contract.partyA<<' ';
			out<<contract.partyB<<' ';
			out<<contract.content<<' ';
			out<<contract.validStart<<' ';
			out<<contract.validEnd<<' ';
			out<<contract.money<<' ';
			out<<contract.signedDate<<endl;
			return out;
		}
		
		friend istream& operator>>(istream& in, Contract& contract){
			in>>contract.id;
			in>>contract.partyA;
			in>>contract.partyB;
			in>>contract.content;
			in>>contract.validStart.year>>contract.validStart.month>>contract.validStart.day; 
			in>>contract.validEnd.year>>contract.validEnd.month>>contract.validEnd.day; 
			in>>contract.money;
			in>>contract.signedDate.year>>contract.signedDate.month>>contract.signedDate.day; 
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

