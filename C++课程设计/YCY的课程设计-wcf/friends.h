#pragma once 
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>


using namespace std;

//��������ѯ�鲻���˵ġ����ǰ༶���죬ϵ�����Ե� 


//У��¼���� 
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
	//�ú����ǽ�¼���ֵ�������� 
	void setfriends(int bianhao, string name, string sex, string age, string jie, string xi, string ban, string dizhi, string pho, string qq, string email)//����friends������� 
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

		//��¼�����Ϣд���ļ� 
		ofstream file("У��¼��Ϣ.txt", ios_base::app);//׷�ӵ��ļ�β
		file << *this;
		file.close();
	}

	void writeFriends()//����friends������� 
	{
		ofstream file("У��¼��Ϣ.txt", ios_base::app);//׷�ӵ��ļ�β
		file << *this;
		file.close();
	}

	//���º���������� 
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

//protected://�������ݳ�Ա 
	int bianhao;//��� 
	string name;//���� 
	string sex;//�Ա� 
	string age;//���� 
	string jie;//�� 
	string xi;//ϵ 
	string ban;//�༶ 
	string dizhi;//��ַ 
	string pho;//�绰 
	string qq;//QQ 
	string email;//�����ʼ� 
};







