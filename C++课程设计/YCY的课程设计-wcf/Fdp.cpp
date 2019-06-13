#pragma once
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream> 
#include <algorithm>

#include"Friends.h"
#include"FriendsF.h"




//五个主要的函数体的类 
class fdp
{
public:
	//num用来记录 该数据库里的总的人数
	int num = 3;

	Friends g[200];
	Friends p[200];

	//一、录入校友信息   c==1; 	
	void add()
	{
		FriendsF fF;
		cout << "请输入要添加的人数" << endl;
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++)	//通过一个循环录入信息 
		{
			cout << "请输入第" << i << "校友的信息" << endl;
			cin >> fF;
			g[i] = fF;
			g[i].writeFriends();
		}
		num += n;
		cout << "校友信息录入完毕，输入任意字符返回" << endl;
		char w;
		cin >> w;
		system("cls");
	}

	//二、删除校友信息   c==2;
	void deleted()
	{
		ifstream filem("校友录信息.txt", ios_base::in);//打开文件 
		int k = 1;

		while (k <= num)
		{
			filem >> p[k];
			k++;
		}

		filem.close();
		string str;
		bool flag = false;
		while (!flag)
		{

			cout << "请输入要被删除的校友的姓名:" << endl;//我想要把编号改成通过姓名删除可以吗 
			cin >> str;
			int i1;

			for (int i1 = 1; i1 <= num; i1++)
			{
				if (p[i1].getname() == str) { flag = true; break; }
			}break;//已经自动break了 

			if (!flag)
			{
				int fanhui;
				cout << "编号不存在，输入任意数字返回" << endl;
				cin >> fanhui;
			}
		}

		ofstream file2("校友录信息.txt", ios::out);
		for (int i1 = 1; i1 <= num; i1++)
		{
			if (p[i1].getname() == str)	continue;//如果编号相同的话，就不录入这个人的信息，就删掉了他
			file2 << p[i1];
		}
		file2.close();

		num = num - 1;
		system("cls");
		cout << "删除记录完毕" << endl;
	}

	//三、查找校友的信息   c==3；	 
	void find()
	{
		FriendsF fF;
		bool flag = true;
		while (flag)
		{

			cout << "请输入您想按什么方式查询校友信息" << endl;
			cout << "1-按姓名查询" << endl;
			cout << "2-按届级查询" << endl;
			cout << "3-按系查询" << endl;
			cout << "4-按班级查询" << endl;
			cout << "5-返回" << endl;
			int m;//m的数值用来确认查询的方式 
			cin >> m;
			if (m == 5)
			{
				system("cls");
				break;
			}

			int k;

			switch (m)
			{
			case 1:
			{
				string nname;
				cout << "请输入要查询的姓名:";
				cin >> nname;
				ifstream filem("校友录信息.txt", ios_base::in);
				k = 0;

				while (filem >> p[k])
				{
					if (p[k].getname() == nname)
					{

						cout << setiosflags(ios::left) << setw(5) << "编号" << setw(8) << "姓名" << setw(6) << "性别"
							<< setw(6) << "年龄" << setw(6) << "届级" << setw(10) << "系" << setw(10) << "班级"
							<< setw(18) << "地址" << setw(14) << "电话" << setw(14) << "QQ" << setw(24) << "邮件" << endl;

						fF = p[k];

						cout << fF;

						char fanhui;
						cout << "请输入任意字母返回" << endl;
						cin >> fanhui;
						system("cls");
						break;
					}
					k++;
				}

				if (filem.eof())
				{
					cout << endl;
					cout << " 警告：没有要查找的人 !!!  " << endl;
				}

				filem.close();
			}break;

			case 2:
			{
				string njie;
				cout << "请输入要查询的届:";
				cin >> njie;
				ifstream filem("校友录信息.txt", ios_base::in);
				k = 0;
				cout << setiosflags(ios::left) << setw(5) << "编号" << setw(8) << "姓名" << setw(6) << "性别"
					<< setw(6) << "年龄" << setw(6) << "届级" << setw(10) << "系" << setw(10) << "班级"
					<< setw(18) << "地址" << setw(14) << "电话" << setw(14) << "QQ" << setw(24) << "邮件" << endl;

				while (filem>>p[k])
				{
					
					if (p[k].getjie() == njie)
					{
						fF = p[k];
						cout << p[k];
						char fanhui;
						cout << "请输入任意字符返回" << endl;
						cin >> fanhui;
						system("cls");
						break;
					}
					k++;
					if (filem.eof())
					{
						cout << endl;
						cout << "  警告：没有要查找的届 !!!  " << endl;
					}
				}
				filem.close();
			}break;

			case 3:
			{
				string nxi;
				cout << "请输入要查询的系:";
				cin >> nxi;
				ifstream filem("校友录信息.txt", ios_base::in);
				k = 0;

				cout << setiosflags(ios::left) << setw(5) << "编号" << setw(8) << "姓名" << setw(6) << "性别"
					<< setw(6) << "年龄" << setw(6) << "届级" << setw(10) << "系" << setw(10) << "班级"
					<< setw(18) << "地址" << setw(14) << "电话" << setw(14) << "QQ" << setw(24) << "邮件" << endl;

				while (filem>>p[k])
				{
					
					if (p[k].getxi() == nxi)
					{	
						fF = p[k];
						cout << fF;
						char fanhui;
						cout << "请输入任意字符返回" << endl;
						cin >> fanhui;
						system("cls");
						break;
					}
					k++;
					if (filem.eof())
					{
						cout << endl;
						cout << "  警告：没有要查找的系 !!!  ";
					}
				}
				filem.close();
			}break;

			case 4:
			{
				string nban;
				cout << "请输入要查询的班级:";
				cin >> nban;
				ifstream filem("校友录信息.txt", ios_base::in);
				k = 0;

				cout << setiosflags(ios::left) << setw(5) << "编号" << setw(8) << "姓名" << setw(6) << "性别"
					<< setw(6) << "年龄" << setw(6) << "届级" << setw(10) << "系" << setw(10) << "班级"
					<< setw(18) << "地址" << setw(14) << "电话" << setw(14) << "QQ" << setw(24) << "邮件" << endl;

				while (filem>>p[k])
				{
					
					if (p[k].getban() == nban)
					{
						fF = p[k];
						cout << fF;
						char fanhui;
						cout << "请输入任意字符返回" << endl;
						cin >> fanhui;
						system("cls");
						break;
					}
					k++;
					if (filem.eof())
					{
						cout << endl;
						cout << " 警告：没有找到要查找的班级 !!!  " << endl;
					}
				}
				filem.close();
			}break;

			default:
				cout << "请重新输入(1-5)" << endl;
				break;

			}
		}
	}

	//四、修改校友的信息   c==4；	
	void alter()
	{
		int k = 0;
		ifstream filem("校友录信息.txt", ios_base::in);//打开文件,以便读取
		while (filem >> p[k])//eof()判断语句是否读到文件的结束符 
		{
			k++;
		}
		filem.close();
		num = k;
		int y;
		int x;
		int i2 = 0;
		cout << "请输入需要修改数据的人员的编号：" << endl;
		while (cin >> x)//判断输入的编号是否有对应的人员存在 
		{
			bool flag = false;

			for (i2 = 0; i2 < num; i2++)
			{
				if (p[i2].getbianhao() == x)
				{
					flag = true;
					break;
				}
			}

			if (flag)//如果该编号的人存在的话就准备开始修改他的数据 
			{
				cout << "1:姓名" << ' ' << "2:性别" << ' ' << "3：年龄" << ' ' << "4：届" << ' ' << "5：系" << ' ' << "6：班级" << ' ' << "7：地址" << ' ' << "8：电话" << ' ' << "9：QQ" << ' ' << "10：邮箱" << endl;
				break;
			}
			else { cout << "请重新输入需要修改的人员的编号" << endl; }
		}

		cout << "请输入编号为" << x << "的人需要修改的项目的代号" << endl;
		cin >> y;
		string s;

		switch (y)
		{
		case 1:
			cout << "请输入新的姓名："; cin >> p[i2].name; break;
		case 2:
			cout << "请输入新的性别："; cin >> p[i2].sex; break;
		case 3:
			cout << "请输入新的年龄："; cin >> p[i2].age; break;
		case 4:
			cout << "请输入新的届："; cin >> p[i2].jie; break;
		case 5:
			cout << "请输入新的系："; cin >> p[i2].xi; break;
		case 6:
			cout << "请输入新的班级："; cin >> p[i2].ban; break;
		case 7:
			cout << "请输入新的地址："; cin >> p[i2].dizhi; break;
		case 8:
			cout << "请输入新的电话："; cin >> p[i2].pho; break;
		case 9:
			cout << "请输入新的QQ："; cin >> p[i2].qq; break;
		case 10:
			cout << "请输入新的邮箱："; cin >> p[i2].email; break;
		default:
			cout << "该项目不存在！！！" << endl; break;
		}

		ofstream file1("校友录信息.txt", ios::out);//如果文件存在，则截断文件，及以前的内容将被删除 
		for (int i3 = 0; i3 < num; i3++)
		{
			file1 << p[i3];
		}

		file1.close();
		system("cls");
		cout << "数据已修改并保存完毕" << endl;
		cout << "输入任意字符返回" << endl;
		char fanhui;
		cin >> fanhui;

		//***************************修改数据结束之后会输出两个菜单，不知道为什么会这样子 
	}

	//五、显示校友的信息   c==5；	
	void show()
	{
		int k = 0;
		ifstream filem("校友录信息.txt", ios_base::in);
		FriendsF fF;
		while (filem >> p[k])
		{
			k++;
		}

		num = k;

		filem.close();

		int h;
		bool flag = true;
		while (flag)
		{
			system("cls");
			cout << "1-按姓名排序显示" << ' ' << " 2-按届排序显示" << ' ' << "3-返回" << endl;
			cout << "请输入您的选择" << endl;
			cin >> h;

			if (h == 3)
			{
				system("cls");
				break;
			}

			//这里是姓名的排序和输出
			if (h == 1)
			{
				//bool compareByName(Friends const&, Friends const&);
				cout << setiosflags(ios::left) << setw(5) << "编号" << setw(8) << "姓名" << setw(6) << "性别"
					<< setw(6) << "年龄" << setw(6) << "届级" << setw(10) << "系" << setw(10) << "班级"
					<< setw(18) << "地址" << setw(14) << "电话" << setw(14) << "QQ" << setw(24) << "邮件" << endl;

				sort(p, p + num, compareByName);

				for (int i = 0; i < num; i++)
				{
					fF = p[i];
					cout << fF;
				}
				cout << "请输入任意字符返回" << endl;
				char fanhui;
				cin >> fanhui;
				continue;

			}

			//这里是届的排序和输出	
			if (h == 2)
			{
				cout << setiosflags(ios::left) << setw(5) << "编号" << setw(8) << "姓名" << setw(6) << "性别"
					<< setw(6) << "年龄" << setw(6) << "届级" << setw(10) << "系" << setw(10) << "班级"
					<< setw(18) << "地址" << setw(14) << "电话" << setw(14) << "QQ" << setw(24) << "邮件" << endl;

				sort(p, p + num, compareByJie);

				for (int i = 0; i < num; i++)
				{
					fF = p[i];
					cout << fF;
				}
				cout << "请输入任意字符返回" << endl;
				char fanhui;
				cin >> fanhui;
				continue;
			}

			cout << "输入错误，请输入任意数字返回" << endl;
			int fanhui;
			cin >> fanhui;
		}

	}

	//用来排序的时候作为交换数据的函数	
	void swap(Friends * a, Friends * b)
	{
		int t = a->getbianhao();
		a->setbianhao(b->getbianhao());
		b->setbianhao(t);


		string s;

		s = a->getage();
		a->setage(b->getage());
		b->setage(s);


		s = a->getban();
		a->setban(b->getban());
		b->setban(s);


		s = a->getdizhi();
		a->setdizhi(b->getdizhi());
		b->setdizhi(s);


		s = a->getemail();
		a->setemail(b->getemail());
		b->setemail(s);


		s = a->getjie();
		a->setjie(b->getjie());
		b->setjie(s);


		s = a->getname();
		a->setname(b->getname());
		b->setname(s);


		s = a->getpho();
		a->setpho(b->getpho());
		b->setpho(s);


		s = a->getqq();
		a->setqq(b->getqq());
		b->setqq(s);


		s = a->getsex();
		a->setsex(b->getsex());
		b->setsex(s);


		s = a->getxi();
		a->setxi(b->getxi());
		b->setxi(s);

	}

	static bool compareByName(const Friends & a, const Friends & b) {
		return a.name < b.name;
	}

	static bool compareByJie(const Friends & a, const Friends & b) {
		return a.jie < b.jie;
	}

	int menu()
	{
		cout << endl;
		cout << "=======================校友录管理=======================" << endl;
		cout << "========================================================" << endl;
		cout << "|                欢迎进入校友录管理系统                |" << endl;
		cout << "|                    1.录入校友信息                    |" << endl;
		cout << "|                    2.删除校友信息                    |" << endl;
		cout << "|                    3.查找校友信息                    |" << endl;
		cout << "|                    4.修改校友信息                    |" << endl;
		cout << "|                    5.显示校友信息                    |" << endl;
		cout << "|                    0.退出                            |" << endl;
		cout << "|------------------------------------------------------|" << endl;
		cout << "|--------------------请选择（0-5）:--------------------|" << endl;
		return 0;
	}
};



