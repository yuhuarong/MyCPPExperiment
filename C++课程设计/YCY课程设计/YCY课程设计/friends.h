#pragma once 
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream> 
using namespace std;


class friends//У��¼���� 
{
public:
	//����friends������� 
	void setfriends(int& bianhao, char* name, char* sex, char* age, char* jie, char* xi, char* ban, char* dizhi, char* pho, char* qq, char* email)
	{
		//��¼���ֵ�������� 
		strcpy_s(this->name, name);
		strcpy_s(this->sex, sex);
		strcpy_s(this->age, age);
		strcpy_s(this->jie, jie);
		strcpy_s(this->xi, xi);
		strcpy_s(this->ban, ban);
		strcpy_s(this->dizhi, dizhi);
		strcpy_s(this->pho, pho);
		strcpy_s(this->qq, qq);
		strcpy_s(this->email, email);
		bianhao++;
		//��¼�����Ϣд���ļ� 
		ofstream file("У��¼��Ϣ.txt", ios_base::app);//׷�ӵ��ļ�β

		file << bianhao << endl;
		file << getname() << endl;
		file << getsex() << endl;
		file << getage() << endl;
		file << getjie() << endl;
		file << getxi() << endl;
		file << getban() << endl;
		file << getdizhi() << endl;
		file << getpho() << endl;
		file << getqq() << endl;
		file << getemail() << endl;
		file.close();
	}
	//������� 
	char* getnum() { return num; }//��� 
	char* getname() { return name; }
	char* getsex() { return sex; }
	char* getage() { return age; }
	char* getjie() { return jie; }
	char* getxi() { return xi; }
	char* getban() { return ban; }
	char* getdizhi() { return dizhi; }
	char* getpho() { return pho; }
	char* getqq() { return qq; }
	char* getemail() { return email; }
	friend istream& operator>>(istream& in, friends& f) {
		in >> f.num 
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

	//friend ostream& operator<<(ostream& out, friends& f) {
	//	out << f.num << endl 
	//		<< f.name << endl 
	//		<< f.sex << endl 
	//		<< f.age << endl 
	//		<< f.jie < endl 
	//		<< f.xi << endl 
	//		<< f.ban << endl 
	//		<< f.dizhi << endl 
	//		<< f.pho << endl 
	//		<< f.qq << endl 
	//		<< f.email << endl;
	//	return out;
	//}


private://˽�����ݳ�Ա 
	char num[10];//��ţ����鴢�棬����֮��Ĳ��� 
	char name[20];//���� 
	char sex[10];//�Ա� 
	char age[10];//���� 
	char jie[20];//�� 
	char xi[20];//ϵ 
	char ban[20];//�༶ 
	char dizhi[20];//��ַ 
	char pho[20];//�绰 
	char qq[20];//QQ 
	char email[20];//�����ʼ� 
};

class fdp {
public:
	//�����Ҫ�ĺ����� 
	//checked
	void add()
	{
		int v, l = 1;
		char name2[20];
		char sex2[10];
		char age2[10];
		char jie2[20];
		char xi2[20];
		char ban2[20];
		char dizhi2[20];
		char pho2[20];
		char qq2[20];
		char email2[20];
		cout << "������Ҫ��ӵ�����" << endl;
		cin >> k;//k��Ҫ��ӵ��˵�������ֱ�Ӳ��ڱ�ŵĺ��� 
		//g[1].getbianhao() = p[k1].getbianhao(); //------------------------- 
		v = bianhao;
		for (int i = v + 1; i <= v + k; i++)
		{
			cout << "�������" << i << "У�ѵ���Ϣ" << endl;
			cout << "������"; cin >> name2;
			cout << "�Ա�"; cin >> sex2;
			cout << "����:"; cin >> age2;
			cout << "��:"; cin >> jie2;
			cout << "ϵ:"; cin >> xi2;
			cout << "��:"; cin >> ban2;
			cout << "��ַ:"; cin >> dizhi2;
			cout << "�绰:"; cin >> pho2;
			cout << "QQ:"; cin >> qq2;
			cout << "����:"; cin >> email2;
			//�������ں���������Ĳ�����Ϣ�������ڲ��� 
			g[i].setfriends(bianhao, name2, sex2, age2, jie2, xi2, ban2, dizhi2, pho2, qq2, email2);
			l++; //-------------------------------																								
		}


	}//¼��У����Ϣ 
	 //checked
	void find()
	{
		cout << "1-��������ѯ" << endl;
		cout << "2-���켶��ѯ" << endl;
		cout << "3-��ϵ��ѯ" << endl;
		cout << "4-���༶��ѯ" << endl;
		int m;//m����ֵ����ȷ�ϲ�ѯ�ķ�ʽ 
		cin >> m;
		while (m < 1 || m>4)//ȷ�������m����ֵ����ʹ�� 
		{
			cout << "����������(1-4)" << endl;
			cin >> m;
		}
		switch (m)
		{
		case 1:
		{
			char nname[20];
			cout << "������Ҫ��ѯ������:";
			cin >> nname;
			ifstream filem("У��¼��Ϣ.txt", ios_base::in);
			k = 1;

			cout << "���" << setw(9) << "����" << setw(5) << "�Ա�" << setw(5) <<
				"����" << setw(5) << "�켶" << setw(5) << "ϵ" << setw(9) << "�༶" <<
				setw(10) << "��ַ" << setw(10) << "QQ" << setw(10) << "�ʼ�" << setw(10) << endl;

			while (!filem.eof())
			{
				filem >> p[k].getnum();
				filem >> p[k].getname();
				filem >> p[k].getsex();
				filem >> p[k].getage();
				filem >> p[k].getjie();
				filem >> p[k].getxi();
				filem >> p[k].getban();
				filem >> p[k].getdizhi();
				filem >> p[k].getpho();
				filem >> p[k].getqq();
				filem >> p[k].getemail();
				if (strcmp(p[k].getname(), nname) == 0)
				{         //�������������� 
					cout << setiosflags(ios::left) << p[k].getnum() << setw(9) << p[k].getname() <<
						setw(5) << p[k].getsex() << setw(5) << p[k].getage() << setw(5) << p[k].getjie() << setw(5) <<
						p[k].getxi() << setw(10) << p[k].getban() << setw(10) << p[k].getdizhi() << setw(10) <<
						p[k].getpho() << setw(10) << p[k].getqq() << setw(10) << p[k].getemail() << endl; break;
				}
				k++;
				if (filem.eof())
				{
					cout << endl;
					cout << "         ���棺û��Ҫ���ҵ��� ��!!   ";
				}
			}
			filem.close();
		}break;
		case 2:
		{
			char njie[20];
			cout << "������Ҫ��ѯ�Ľ�:";
			cin >> njie;
			ifstream filem("У��¼��Ϣ.txt", ios_base::in);
			k = 1;

			cout << "���" << setw(9) << "����" << setw(5) << "�Ա�" << setw(5) <<
				"����" << setw(5) << "�켶" << setw(5) << "ϵ" << setw(9) << "�༶" <<
				setw(10) << "��ַ" << setw(10) << "QQ" << setw(10) << "�ʼ�" << setw(10) << endl;

			while (!filem.eof())
			{
				filem >> p[k].getnum();
				filem >> p[k].getname();
				filem >> p[k].getsex();
				filem >> p[k].getage();
				filem >> p[k].getjie();
				filem >> p[k].getxi();
				filem >> p[k].getban();
				filem >> p[k].getdizhi();
				filem >> p[k].getpho();
				filem >> p[k].getqq();
				filem >> p[k].getemail();
				if (strcmp(p[k].getjie(), njie) == 0)
				{         //�������������� 
					cout << setiosflags(ios::left) << p[k].getnum() << setw(9) << p[k].getname() <<
						setw(5) << p[k].getsex() << setw(5) << p[k].getage() << setw(5) << p[k].getjie() << setw(5) <<
						p[k].getxi() << setw(10) << p[k].getban() << setw(10) << p[k].getdizhi() << setw(10) <<
						p[k].getpho() << setw(10) << p[k].getqq() << setw(10) << p[k].getemail() << endl; break;
				}
				k++;
				if (filem.eof())
				{
					cout << endl;
					cout << "         ���棺û��Ҫ���ҵ�ϵ !!!   ";
				}
			}
			filem.close();
		}break;
		case 3:
		{
			char nxi[20];
			cout << "������Ҫ��ѯ��ϵ:";
			cin >> nxi;
			ifstream filem("У��¼��Ϣ.txt", ios_base::in);
			k = 1;

			cout << "���" << setw(9) << "����" << setw(5) << "�Ա�" << setw(5) << "����"
				<< setw(5) << "�켶" << setw(5) << "ϵ" << setw(9) << "�༶" << setw(10)
				<< "��ַ" << setw(10) << "QQ" << setw(10) << "�ʼ�" << setw(10) << endl;

			while (!filem.eof())
			{
				filem >> p[k].getnum();
				filem >> p[k].getname();
				filem >> p[k].getsex();
				filem >> p[k].getage();
				filem >> p[k].getjie();
				filem >> p[k].getxi();
				filem >> p[k].getban();
				filem >> p[k].getdizhi();
				filem >> p[k].getpho();
				filem >> p[k].getqq();
				filem >> p[k].getemail();
				if (strcmp(p[k].getxi(), nxi) == 0)
				{         //�������������� 
					cout << setiosflags(ios::left) << p[k].getnum() << setw(9) << p[k].getname() <<
						setw(5) << p[k].getsex() << setw(5) << p[k].getage() << setw(5) << p[k].getjie() << setw(5) <<
						p[k].getxi() << setw(10) << p[k].getban() << setw(10) << p[k].getdizhi() << setw(10) <<
						p[k].getpho() << setw(10) << p[k].getqq() << setw(10) << p[k].getemail() << endl; break;
				}
				k++;
				if (filem.eof())
				{
					cout << endl;
					cout << "         ���棺û��Ҫ���ҵ�ϵ !!!  ";
				}
			}
			filem.close();
		}break;
		case 4:
		{
			char nban[20];
			cout << "������Ҫ��ѯ�İ༶:";
			cin >> nban;
			ifstream filem("У��¼��Ϣ.txt", ios_base::in);
			k = 1;

			cout << "���" << setw(9) << "����" << setw(5) << "�Ա�" << setw(5) <<
				"����" << setw(5) << "�켶" << setw(5) << "ϵ" << setw(9) << "�༶" <<
				setw(10) << "��ַ" << setw(10) << "QQ" << setw(10) << "�ʼ�" << setw(10) << endl;

			while (!filem.eof())
			{
				filem >> p[k].getnum();
				filem >> p[k].getname();
				filem >> p[k].getsex();
				filem >> p[k].getage();
				filem >> p[k].getjie();
				filem >> p[k].getxi();
				filem >> p[k].getban();
				filem >> p[k].getdizhi();
				filem >> p[k].getpho();
				filem >> p[k].getqq();
				filem >> p[k].getemail();
				if (strcmp(p[k].getban(), nban) == 0)
				{         //�������������� 
					cout << setiosflags(ios::left) << p[k].getnum() << setw(9) << p[k].getname() <<
						setw(5) << p[k].getsex() << setw(5) << p[k].getage() << setw(5) << p[k].getjie() << setw(5) <<
						p[k].getxi() << setw(10) << p[k].getban() << setw(10) << p[k].getdizhi() << setw(10) <<
						p[k].getpho() << setw(10) << p[k].getqq() << setw(10) << p[k].getemail() << endl; break;
				}
				k++;
				if (filem.eof())
				{
					cout << endl;
					cout << "         ���棺û��Ҫ���ҵİ༶ !!!  ";
				}
			}
			filem.close();
		}break;

		}
	}// ����У����Ϣ 
	 //checked
	void deleted()
	{
		char z[20];//z�Ǳ�ţ�����ɾ����Ϣ�� 
		ifstream filem("У��¼��Ϣ.txt", ios_base::in);//���ļ� 
		k = 1;
		while (filem>>p[k]){
			k++;
		}
		filem.close();
		cout << "������Ҫ��ɾ����У�ѵı��" << endl;
		cin >> z;
		//while (z<1 || z>bianhao)
		//{
		//	int menu();//-------------------
		//	cout << "û���ҵ���Ҫɾ����У����Ϣ��������ѡ��" << endl;
		//	menu(); break;
		//	cin >> z;
		//}
		ofstream file2("У��¼��Ϣ.txt", ios_base::out);
		for (int j = 1; j < k; j++)
		{
			if (strcmp(z, p[j].getnum())==0) continue;

			file2 << p[k].getnum() << endl;
			file2 << p[k].getname() << endl;

			file2 << p[k].getsex() << endl;
			file2 << p[k].getage() << endl;
			file2 << p[k].getjie() << endl;
			file2 << p[k].getxi() << endl;
			file2 << p[k].getban() << endl;
			file2 << p[k].getdizhi() << endl;
			file2 << p[k].getpho() << endl;
			file2 << p[k].getqq() << endl;
			file2 << p[k].getemail() << endl;

		}
		file2.close();
		cout << "ɾ����¼���" << endl;
	}//ɾ��У����Ϣ 
	 //checked
	void alter()//�޸�У�ѵ���Ϣ
	{
		k = 1;
		ifstream filem("У��¼��Ϣ.txt", ios_base::in);//���ļ�,�Ա��ȡ
		while (!filem.eof())//eof()�ж�����Ƿ�����ļ��Ľ����� 
		{
			filem >> p[k].getnum();
			filem >> p[k].getname();
			filem >> p[k].getsex();
			filem >> p[k].getage();
			filem >> p[k].getjie();
			filem >> p[k].getxi();
			filem >> p[k].getban();
			filem >> p[k].getdizhi();
			filem >> p[k].getpho();
			filem >> p[k].getqq();
			filem >> p[k].getemail();
			k++;
		}
		filem.close();
		int x, y;
		cout << "������Ҫ�޸ĵı�ţ�" << endl;
		cin >> x;
		cout << "��������Ϊ" << x << "������Ҫ�޸ĵ���Ŀ�Ĵ���" << endl;
		cout << "1:���-2������-3���Ա�-4������-5����-6��ϵ-7���༶-8����ַ-9���绰-10��QQ-11������" << endl;
		cin >> y;
		switch (y)
		{
		case 1:
		{cout << "�������µı��"; cin >> p[x].getnum(); }	break;
		case 2:
		{cout << "�������µ�����"; cin >> p[x].getname(); }	break;
		case 3:
		{cout << "�������µ��Ա�"; cin >> p[x].getsex(); }	break;
		case 4:
		{cout << "�������µ�����"; cin >> p[x].getage(); }	break;
		case 5:
		{cout << "�������µĽ�"; cin >> p[x].getjie(); }		break;
		case 6:
		{cout << "�������µ�ϵ"; cin >> p[x].getxi(); }		break;
		case 7:
		{cout << "�������µİ�"; cin >> p[x].getban(); }		break;
		case 8:
		{cout << "�������µĵ�ַ"; cin >> p[x].getdizhi(); }		break;
		case 9:
		{cout << "�������µĵ绰"; cin >> p[x].getpho(); }		break;
		case 10:
		{cout << "�������µ�QQ"; cin >> p[x].getqq(); }		break;
		case 11:
		{cout << "�������µ�����"; cin >> p[x].getemail(); }	break;
		}
		ofstream file1("У��¼��Ϣ.txt", ios_base::trunc);//����ļ����ڡ���ض��ļ�������ǰ�����ݽ���ɾ�� 
		for (k = 1; k <= bianhao; k++)
		{
			file1 << p[k].getnum() << endl;
			file1 << p[k].getname() << endl;
			file1 << p[k].getsex() << endl;
			file1 << p[k].getage() << endl;
			file1 << p[k].getjie() << endl;
			file1 << p[k].getxi() << endl;
			file1 << p[k].getban() << endl;
			file1 << p[k].getdizhi() << endl;
			file1 << p[k].getpho() << endl;
			file1 << p[k].getqq() << endl;
			file1 << p[k].getemail() << endl;
		}
		file1.close();
		cout << "�޸Ĳ��������" << endl;

	}//�޸�У����Ϣ 
	 //checked
	void show()
	{
		ifstream filem("У��¼��Ϣ.txt", ios_base::in);
		k = 1;
		cout << "���" << setw(9) << "����" << setw(5) << "�Ա�" << setw(5) <<
			"����" << setw(5) << "�켶" << setw(5) << "ϵ" << setw(9) << "�༶" <<
			setw(10) << "��ַ" << setw(10) << "QQ" << setw(10) << "�ʼ�" << setw(10) << endl;
		while (!filem.eof())
		{
			filem >> p[k].getnum();
			filem >> p[k].getname();
			filem >> p[k].getsex();
			filem >> p[k].getage();
			filem >> p[k].getjie();
			filem >> p[k].getxi();
			filem >> p[k].getban();
			filem >> p[k].getdizhi();
			filem >> p[k].getpho();
			filem >> p[k].getqq();
			filem >> p[k].getemail();
			cout << setiosflags(ios::left) << p[k].getnum() << setw(9) << p[k].getname()
				<< setw(5) << p[k].getsex() << setw(5) << p[k].getage() << setw(5)
				<< p[k].getjie() << setw(5) << p[k].getxi() << setw(10) << p[k].getban()
				<< setw(10) << p[k].getdizhi() << setw(10) << p[k].getpho()
				<< setw(10) << p[k].getqq() << setw(10) << p[k].getemail() << endl;
			k++;
		}
		k1 = --k;
		filem.close();
	}//��ʾУ����Ϣ 
private:
	int bianhao = 0;
	int k = 0;
	int k1 = 0;
	friends g[200];
	friends p[200];
};