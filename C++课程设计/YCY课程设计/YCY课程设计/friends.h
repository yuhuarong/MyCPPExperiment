#pragma once 
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream> 
using namespace std;


class friends//校友录的类 
{
public:
	//构造friends里的数据 
	void setfriends(int& bianhao, char* name, char* sex, char* age, char* jie, char* xi, char* ban, char* dizhi, char* pho, char* qq, char* email)
	{
		//将录入的值存入类内 
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
		//将录入的信息写入文件 
		ofstream file("校友录信息.txt", ios_base::app);//追加到文件尾

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
	//输出函数 
	char* getnum() { return num; }//编号 
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


private://私有数据成员 
	char num[10];//编号，数组储存，方便之后的操作 
	char name[20];//姓名 
	char sex[10];//性别 
	char age[10];//年龄 
	char jie[20];//届 
	char xi[20];//系 
	char ban[20];//班级 
	char dizhi[20];//地址 
	char pho[20];//电话 
	char qq[20];//QQ 
	char email[20];//电子邮件 
};

class fdp {
public:
	//五个主要的函数体 
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
		cout << "请输入要添加的人数" << endl;
		cin >> k;//k是要添加的人的人数，直接补在编号的后面 
		//g[1].getbianhao() = p[k1].getbianhao(); //------------------------- 
		v = bianhao;
		for (int i = v + 1; i <= v + k; i++)
		{
			cout << "请输入第" << i << "校友的信息" << endl;
			cout << "姓名："; cin >> name2;
			cout << "性别："; cin >> sex2;
			cout << "年龄:"; cin >> age2;
			cout << "届:"; cin >> jie2;
			cout << "系:"; cin >> xi2;
			cout << "班:"; cin >> ban2;
			cout << "地址:"; cin >> dizhi2;
			cout << "电话:"; cin >> pho2;
			cout << "QQ:"; cin >> qq2;
			cout << "邮箱:"; cin >> email2;
			//利用类内函数将输入的参数信息存入类内参数 
			g[i].setfriends(bianhao, name2, sex2, age2, jie2, xi2, ban2, dizhi2, pho2, qq2, email2);
			l++; //-------------------------------																								
		}


	}//录入校友信息 
	 //checked
	void find()
	{
		cout << "1-按姓名查询" << endl;
		cout << "2-按届级查询" << endl;
		cout << "3-按系查询" << endl;
		cout << "4-按班级查询" << endl;
		int m;//m的数值用来确认查询的方式 
		cin >> m;
		while (m < 1 || m>4)//确保输入的m的数值可以使用 
		{
			cout << "请重新输入(1-4)" << endl;
			cin >> m;
		}
		switch (m)
		{
		case 1:
		{
			char nname[20];
			cout << "请输入要查询的姓名:";
			cin >> nname;
			ifstream filem("校友录信息.txt", ios_base::in);
			k = 1;

			cout << "编号" << setw(9) << "姓名" << setw(5) << "性别" << setw(5) <<
				"年龄" << setw(5) << "届级" << setw(5) << "系" << setw(9) << "班级" <<
				setw(10) << "地址" << setw(10) << "QQ" << setw(10) << "邮件" << setw(10) << endl;

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
				{         //输出的数据左对齐 
					cout << setiosflags(ios::left) << p[k].getnum() << setw(9) << p[k].getname() <<
						setw(5) << p[k].getsex() << setw(5) << p[k].getage() << setw(5) << p[k].getjie() << setw(5) <<
						p[k].getxi() << setw(10) << p[k].getban() << setw(10) << p[k].getdizhi() << setw(10) <<
						p[k].getpho() << setw(10) << p[k].getqq() << setw(10) << p[k].getemail() << endl; break;
				}
				k++;
				if (filem.eof())
				{
					cout << endl;
					cout << "         警告：没有要查找的人 ！!!   ";
				}
			}
			filem.close();
		}break;
		case 2:
		{
			char njie[20];
			cout << "请输入要查询的届:";
			cin >> njie;
			ifstream filem("校友录信息.txt", ios_base::in);
			k = 1;

			cout << "编号" << setw(9) << "姓名" << setw(5) << "性别" << setw(5) <<
				"年龄" << setw(5) << "届级" << setw(5) << "系" << setw(9) << "班级" <<
				setw(10) << "地址" << setw(10) << "QQ" << setw(10) << "邮件" << setw(10) << endl;

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
				{         //输出的数据左对齐 
					cout << setiosflags(ios::left) << p[k].getnum() << setw(9) << p[k].getname() <<
						setw(5) << p[k].getsex() << setw(5) << p[k].getage() << setw(5) << p[k].getjie() << setw(5) <<
						p[k].getxi() << setw(10) << p[k].getban() << setw(10) << p[k].getdizhi() << setw(10) <<
						p[k].getpho() << setw(10) << p[k].getqq() << setw(10) << p[k].getemail() << endl; break;
				}
				k++;
				if (filem.eof())
				{
					cout << endl;
					cout << "         警告：没有要查找的系 !!!   ";
				}
			}
			filem.close();
		}break;
		case 3:
		{
			char nxi[20];
			cout << "请输入要查询的系:";
			cin >> nxi;
			ifstream filem("校友录信息.txt", ios_base::in);
			k = 1;

			cout << "编号" << setw(9) << "姓名" << setw(5) << "性别" << setw(5) << "年龄"
				<< setw(5) << "届级" << setw(5) << "系" << setw(9) << "班级" << setw(10)
				<< "地址" << setw(10) << "QQ" << setw(10) << "邮件" << setw(10) << endl;

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
				{         //输出的数据左对齐 
					cout << setiosflags(ios::left) << p[k].getnum() << setw(9) << p[k].getname() <<
						setw(5) << p[k].getsex() << setw(5) << p[k].getage() << setw(5) << p[k].getjie() << setw(5) <<
						p[k].getxi() << setw(10) << p[k].getban() << setw(10) << p[k].getdizhi() << setw(10) <<
						p[k].getpho() << setw(10) << p[k].getqq() << setw(10) << p[k].getemail() << endl; break;
				}
				k++;
				if (filem.eof())
				{
					cout << endl;
					cout << "         警告：没有要查找的系 !!!  ";
				}
			}
			filem.close();
		}break;
		case 4:
		{
			char nban[20];
			cout << "请输入要查询的班级:";
			cin >> nban;
			ifstream filem("校友录信息.txt", ios_base::in);
			k = 1;

			cout << "编号" << setw(9) << "姓名" << setw(5) << "性别" << setw(5) <<
				"年龄" << setw(5) << "届级" << setw(5) << "系" << setw(9) << "班级" <<
				setw(10) << "地址" << setw(10) << "QQ" << setw(10) << "邮件" << setw(10) << endl;

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
				{         //输出的数据左对齐 
					cout << setiosflags(ios::left) << p[k].getnum() << setw(9) << p[k].getname() <<
						setw(5) << p[k].getsex() << setw(5) << p[k].getage() << setw(5) << p[k].getjie() << setw(5) <<
						p[k].getxi() << setw(10) << p[k].getban() << setw(10) << p[k].getdizhi() << setw(10) <<
						p[k].getpho() << setw(10) << p[k].getqq() << setw(10) << p[k].getemail() << endl; break;
				}
				k++;
				if (filem.eof())
				{
					cout << endl;
					cout << "         警告：没有要查找的班级 !!!  ";
				}
			}
			filem.close();
		}break;

		}
	}// 查找校友信息 
	 //checked
	void deleted()
	{
		char z[20];//z是编号，用来删除信息的 
		ifstream filem("校友录信息.txt", ios_base::in);//打开文件 
		k = 1;
		while (filem>>p[k]){
			k++;
		}
		filem.close();
		cout << "请输入要被删除的校友的编号" << endl;
		cin >> z;
		//while (z<1 || z>bianhao)
		//{
		//	int menu();//-------------------
		//	cout << "没有找到你要删除的校友信息，请重新选择" << endl;
		//	menu(); break;
		//	cin >> z;
		//}
		ofstream file2("校友录信息.txt", ios_base::out);
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
		cout << "删除记录完毕" << endl;
	}//删除校友信息 
	 //checked
	void alter()//修改校友的信息
	{
		k = 1;
		ifstream filem("校友录信息.txt", ios_base::in);//打开文件,以便读取
		while (!filem.eof())//eof()判断语句是否读到文件的结束符 
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
		cout << "请输入要修改的编号：" << endl;
		cin >> x;
		cout << "请输入编号为" << x << "的人需要修改的项目的代号" << endl;
		cout << "1:编号-2：姓名-3：性别-4：年龄-5：届-6：系-7：班级-8：地址-9：电话-10：QQ-11：邮箱" << endl;
		cin >> y;
		switch (y)
		{
		case 1:
		{cout << "请输入新的编号"; cin >> p[x].getnum(); }	break;
		case 2:
		{cout << "请输入新的姓名"; cin >> p[x].getname(); }	break;
		case 3:
		{cout << "请输入新的性别"; cin >> p[x].getsex(); }	break;
		case 4:
		{cout << "请输入新的年龄"; cin >> p[x].getage(); }	break;
		case 5:
		{cout << "请输入新的届"; cin >> p[x].getjie(); }		break;
		case 6:
		{cout << "请输入新的系"; cin >> p[x].getxi(); }		break;
		case 7:
		{cout << "请输入新的班"; cin >> p[x].getban(); }		break;
		case 8:
		{cout << "请输入新的地址"; cin >> p[x].getdizhi(); }		break;
		case 9:
		{cout << "请输入新的电话"; cin >> p[x].getpho(); }		break;
		case 10:
		{cout << "请输入新的QQ"; cin >> p[x].getqq(); }		break;
		case 11:
		{cout << "请输入新的邮箱"; cin >> p[x].getemail(); }	break;
		}
		ofstream file1("校友录信息.txt", ios_base::trunc);//如果文件存在。则截断文件，及以前的内容将被删除 
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
		cout << "修改并保存完毕" << endl;

	}//修改校友信息 
	 //checked
	void show()
	{
		ifstream filem("校友录信息.txt", ios_base::in);
		k = 1;
		cout << "编号" << setw(9) << "姓名" << setw(5) << "性别" << setw(5) <<
			"年龄" << setw(5) << "届级" << setw(5) << "系" << setw(9) << "班级" <<
			setw(10) << "地址" << setw(10) << "QQ" << setw(10) << "邮件" << setw(10) << endl;
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
	}//显示校友信息 
private:
	int bianhao = 0;
	int k = 0;
	int k1 = 0;
	friends g[200];
	friends p[200];
};