#pragma once
#include "Contract.cpp"

class ContractUI: public Contract{
	public: 
		ContractUI():Contract(){}
		ContractUI(int id, string partyA, string partyB, string content, Date validStart, Date ValidEnd, double money, Date signedDate):Contract(id, partyA, partyB, content, validStart, validEnd, money, signedDate){}
		
		ContractUI& operator=(const Contract& c){
			this->id=c.id;
			this->partyA=c.partyA;
			this->partyB=c.partyB;
			this->content=c.content;
			this->validStart=c.validStart;
			this->validEnd=c.validEnd;
			this->money=c.money;
			this->signedDate=c.signedDate;
			return *this;
		}
		
		friend ostream& operator<<(ostream& out, const ContractUI& contract){
			out<<"ID: "<<contract.id<<' ';
			out<<"�׷�: "<<contract.partyA<<' ';
			out<<"�ҷ�: "<<contract.partyB<<' ';
			out<<"����: "<<contract.content<<' ';
			out<<"��ʼ����: "<<contract.validStart<<' ';
			out<<"��������: "<<contract.validEnd<<' ';
			out<<"���: "<<contract.money<<' ';
			out<<"ǩ������: "<<contract.signedDate<<endl;
			return out;
		}

		friend istream& operator>>(istream& in, ContractUI& contract){
			cout<<"ID: ";in>>contract.id;
			cout<<"�׷�: ";in>>contract.partyA;
			cout<<"�ҷ�: ";in>>contract.partyB;
			cout<<"����: ";in>>contract.content;
			cout<<"��ʼ����(yyyy MM dd): ";in>>contract.validStart; 
			cout<<"��������(yyyy MM dd): ";in>>contract.validEnd; 
			cout<<"���: ";in>>contract.money;
			cout<<"ǩ������(yyyy MM dd): ";in>>contract.signedDate; 
			return in;
		}
}; 
