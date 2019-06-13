#pragma once

#include "Friends.h"
#include <iostream>

using namespace std;

class FriendsF : public Friends {

public:

	FriendsF() {}

	FriendsF(int bianhao, string name, string sex, string age, string jie, string xi, string ban, string dizhi, string pho, string qq, string email) :
		Friends(bianhao, name, sex, age, jie, xi, ban, dizhi, pho, qq, email) { }

	friend ostream& operator<<(std::ostream& out, FriendsF& f) {
		out << setiosflags(ios::left) << setw(5) << f.getbianhao() << setw(8) << f.getname()
			<< setw(6) << f.getsex() << setw(6) << f.getage() << setw(6) << f.getjie()
			<< setw(10) << f.getxi() << setw(10) << f.getban() << setw(18) << f.getdizhi()
			<< setw(14) << f.getpho() << setw(14) << f.getqq() << setw(24) << f.getemail() << endl;

		return out;
	}

	friend std::istream& operator>>(std::istream& in, FriendsF& f) {
		cout << "编号:"; in >> f.bianhao;
		cout << "姓名:"; in >> f.name;
		cout << "性别:"; in >> f.sex;
		cout << "年龄:"; in >> f.age;
		cout << "届:"; in >> f.jie;
		cout << "系:"; in >> f.xi;
		cout << "班:"; in >> f.ban;
		cout << "地址:"; in >> f.dizhi;
		cout << "电话:"; in >> f.pho;
		cout << "QQ:"; in >> f.qq;
		cout << "邮箱:"; in >> f.email;

		return in;
	}

	FriendsF& operator=(const Friends& f) {
		this->bianhao = f.bianhao;
		this->name = f.name;
		this->sex = f.sex;
		this->age = f.age;
		this->jie = f.jie;
		this->xi = f.xi;
		this->ban = f.ban;
		this->dizhi = f.dizhi;
		this->pho = f.pho;
		this->qq = f.qq;
		this->email = f.email;
		return *this;
	}

};

