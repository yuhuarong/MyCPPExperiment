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
			out<<"甲方: "<<contract.partyA<<' ';
			out<<"乙方: "<<contract.partyB<<' ';
			out<<"内容: "<<contract.content<<' ';
			out<<"开始日期: "<<contract.validStart<<' ';
			out<<"结束日期: "<<contract.validEnd<<' ';
			out<<"金额: "<<contract.money<<' ';
			out<<"签订日期: "<<contract.signedDate<<endl;
			return out;
		}

		friend istream& operator>>(istream& in, ContractUI& contract){
			cout<<"ID: ";in>>contract.id;
			cout<<"甲方: ";in>>contract.partyA;
			cout<<"乙方: ";in>>contract.partyB;
			cout<<"内容: ";in>>contract.content;
			cout<<"开始日期(yyyy MM dd): ";in>>contract.validStart; 
			cout<<"结束日期(yyyy MM dd): ";in>>contract.validEnd; 
			cout<<"金额: ";in>>contract.money;
			cout<<"签订日期(yyyy MM dd): ";in>>contract.signedDate; 
			return in;
		}
}; 
