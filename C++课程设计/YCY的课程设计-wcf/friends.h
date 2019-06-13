#pragma once 
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>


using namespace std;

//按姓名查询查不到人的。但是班级，届，系都可以的 


//校友录的类 
class Friends {
public:
	Friends() {}

	Friends(
		int bianhao, string name,
		string sex, string age,
		string jie, string xi,
		string ban, string dizhi,
		string pho, string qq,
		string email
	) {
		this->bianhao = bianhao;
		this->name = name;
		this->sex = sex;
		this->age = age;
		this->jie = jie;
		this->xi = xi;
		this->ban = ban;
		this->dizhi = dizhi;
		this->pho = pho;
		this->qq = qq;
		this->email = email;
	}
	//该函数是将录入的值存入类内 
	void setfriends(int bianhao, string name, string sex, string age, string jie, string xi, string ban, string dizhi, string pho, string qq, string email)//构造friends里的数据 
	{

		this->bianhao = bianhao;
		this->name = name;
		this->sex = sex;
		this->age = age;
		this->jie = jie;
		this->xi = xi;
		this->ban = ban;
		this->dizhi = dizhi;
		this->pho = pho;
		this->qq = qq;
		this->email = email;

		//将录入的信息写入文件 
		ofstream file("校友录信息.txt", ios_base::app);//追加到文件尾
		file << *this;
		file.close();
	}

	void writeFriends()//构造friends里的数据 
	{
		ofstream file("校友录信息.txt", ios_base::app);//追加到文件尾
		file << *this;
		file.close();
	}

	//以下函数输出数据 
	int getbianhao() { return bianhao; }
	string getname() { return name; }
	string getsex() { return sex; }
	string getage() { return age; }
	string getjie() { return jie; }
	string getxi() { return xi; }
	string getban() { return ban; }
	string getdizhi() { return dizhi; }
	string getpho() { return pho; }
	string getqq() { return qq; }
	string getemail() { return email; }


	void setbianhao(int a) { bianhao = a; }
	void setname(string a) { name = a; }
	void setsex(string a) { sex = a; }
	void setage(string a) { age = a; }
	void setjie(string a) { jie = a; }
	void setxi(string a) { xi = a; }
	void setban(string a) { ban = a; }
	void setdizhi(string a) { dizhi = a; }
	void setpho(string a) { pho = a; }
	void setqq(string a) { qq = a; }
	void setemail(string a) { email = a; }

	friend std::ostream& operator<<(std::ostream& out, Friends& f) {
		out << f.bianhao << " "
			<< f.name << " "
			<< f.sex << " "
			<< f.age << " "
			<< f.jie << " "
			<< f.xi << " "
			<< f.ban << " "
			<< f.dizhi << " "
			<< f.pho << " "
			<< f.qq << " "
			<< f.email << endl;

		return out;
	}

	friend std::istream& operator>>(std::istream& in, Friends& f) {
		in >> f.bianhao
			>> f.name
			>> f.sex
			>> f.age
			>> f.jie
			>> f.xi
			>> f.ban
			>> f.dizhi
			>> f.pho
			>> f.qq
			>> f.email;
		return in;
	}

//protected://保护数据成员 
	int bianhao;//编号 
	string name;//姓名 
	string sex;//性别 
	string age;//年龄 
	string jie;//届 
	string xi;//系 
	string ban;//班级 
	string dizhi;//地址 
	string pho;//电话 
	string qq;//QQ 
	string email;//电子邮件 
};







