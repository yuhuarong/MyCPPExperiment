#pragma once
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream> 
#include <algorithm>

#include"Friends.h"
#include"FriendsF.h"




//�����Ҫ�ĺ�������� 
class fdp
{
public:
	//num������¼ �����ݿ�����ܵ�����
	int num = 3;

	Friends g[200];
	Friends p[200];

	//һ��¼��У����Ϣ   c==1; 	
	void add()
	{
		FriendsF fF;
		cout << "������Ҫ��ӵ�����" << endl;
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++)	//ͨ��һ��ѭ��¼����Ϣ 
		{
			cout << "�������" << i << "У�ѵ���Ϣ" << endl;
			cin >> fF;
			g[i] = fF;
			g[i].writeFriends();
		}
		num += n;
		cout << "У����Ϣ¼����ϣ����������ַ�����" << endl;
		char w;
		cin >> w;
		system("cls");
	}

	//����ɾ��У����Ϣ   c==2;
	void deleted()
	{
		ifstream filem("У��¼��Ϣ.txt", ios_base::in);//���ļ� 
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

			cout << "������Ҫ��ɾ����У�ѵ�����:" << endl;//����Ҫ�ѱ�Ÿĳ�ͨ������ɾ�������� 
			cin >> str;
			int i1;

			for (int i1 = 1; i1 <= num; i1++)
			{
				if (p[i1].getname() == str) { flag = true; break; }
			}break;//�Ѿ��Զ�break�� 

			if (!flag)
			{
				int fanhui;
				cout << "��Ų����ڣ������������ַ���" << endl;
				cin >> fanhui;
			}
		}

		ofstream file2("У��¼��Ϣ.txt", ios::out);
		for (int i1 = 1; i1 <= num; i1++)
		{
			if (p[i1].getname() == str)	continue;//��������ͬ�Ļ����Ͳ�¼������˵���Ϣ����ɾ������
			file2 << p[i1];
		}
		file2.close();

		num = num - 1;
		system("cls");
		cout << "ɾ����¼���" << endl;
	}

	//��������У�ѵ���Ϣ   c==3��	 
	void find()
	{
		FriendsF fF;
		bool flag = true;
		while (flag)
		{

			cout << "���������밴ʲô��ʽ��ѯУ����Ϣ" << endl;
			cout << "1-��������ѯ" << endl;
			cout << "2-���켶��ѯ" << endl;
			cout << "3-��ϵ��ѯ" << endl;
			cout << "4-���༶��ѯ" << endl;
			cout << "5-����" << endl;
			int m;//m����ֵ����ȷ�ϲ�ѯ�ķ�ʽ 
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
				cout << "������Ҫ��ѯ������:";
				cin >> nname;
				ifstream filem("У��¼��Ϣ.txt", ios_base::in);
				k = 0;

				while (filem >> p[k])
				{
					if (p[k].getname() == nname)
					{

						cout << setiosflags(ios::left) << setw(5) << "���" << setw(8) << "����" << setw(6) << "�Ա�"
							<< setw(6) << "����" << setw(6) << "�켶" << setw(10) << "ϵ" << setw(10) << "�༶"
							<< setw(18) << "��ַ" << setw(14) << "�绰" << setw(14) << "QQ" << setw(24) << "�ʼ�" << endl;

						fF = p[k];

						cout << fF;

						char fanhui;
						cout << "������������ĸ����" << endl;
						cin >> fanhui;
						system("cls");
						break;
					}
					k++;
				}

				if (filem.eof())
				{
					cout << endl;
					cout << " ���棺û��Ҫ���ҵ��� !!!  " << endl;
				}

				filem.close();
			}break;

			case 2:
			{
				string njie;
				cout << "������Ҫ��ѯ�Ľ�:";
				cin >> njie;
				ifstream filem("У��¼��Ϣ.txt", ios_base::in);
				k = 0;
				cout << setiosflags(ios::left) << setw(5) << "���" << setw(8) << "����" << setw(6) << "�Ա�"
					<< setw(6) << "����" << setw(6) << "�켶" << setw(10) << "ϵ" << setw(10) << "�༶"
					<< setw(18) << "��ַ" << setw(14) << "�绰" << setw(14) << "QQ" << setw(24) << "�ʼ�" << endl;

				while (filem>>p[k])
				{
					
					if (p[k].getjie() == njie)
					{
						fF = p[k];
						cout << p[k];
						char fanhui;
						cout << "�����������ַ�����" << endl;
						cin >> fanhui;
						system("cls");
						break;
					}
					k++;
					if (filem.eof())
					{
						cout << endl;
						cout << "  ���棺û��Ҫ���ҵĽ� !!!  " << endl;
					}
				}
				filem.close();
			}break;

			case 3:
			{
				string nxi;
				cout << "������Ҫ��ѯ��ϵ:";
				cin >> nxi;
				ifstream filem("У��¼��Ϣ.txt", ios_base::in);
				k = 0;

				cout << setiosflags(ios::left) << setw(5) << "���" << setw(8) << "����" << setw(6) << "�Ա�"
					<< setw(6) << "����" << setw(6) << "�켶" << setw(10) << "ϵ" << setw(10) << "�༶"
					<< setw(18) << "��ַ" << setw(14) << "�绰" << setw(14) << "QQ" << setw(24) << "�ʼ�" << endl;

				while (filem>>p[k])
				{
					
					if (p[k].getxi() == nxi)
					{	
						fF = p[k];
						cout << fF;
						char fanhui;
						cout << "�����������ַ�����" << endl;
						cin >> fanhui;
						system("cls");
						break;
					}
					k++;
					if (filem.eof())
					{
						cout << endl;
						cout << "  ���棺û��Ҫ���ҵ�ϵ !!!  ";
					}
				}
				filem.close();
			}break;

			case 4:
			{
				string nban;
				cout << "������Ҫ��ѯ�İ༶:";
				cin >> nban;
				ifstream filem("У��¼��Ϣ.txt", ios_base::in);
				k = 0;

				cout << setiosflags(ios::left) << setw(5) << "���" << setw(8) << "����" << setw(6) << "�Ա�"
					<< setw(6) << "����" << setw(6) << "�켶" << setw(10) << "ϵ" << setw(10) << "�༶"
					<< setw(18) << "��ַ" << setw(14) << "�绰" << setw(14) << "QQ" << setw(24) << "�ʼ�" << endl;

				while (filem>>p[k])
				{
					
					if (p[k].getban() == nban)
					{
						fF = p[k];
						cout << fF;
						char fanhui;
						cout << "�����������ַ�����" << endl;
						cin >> fanhui;
						system("cls");
						break;
					}
					k++;
					if (filem.eof())
					{
						cout << endl;
						cout << " ���棺û���ҵ�Ҫ���ҵİ༶ !!!  " << endl;
					}
				}
				filem.close();
			}break;

			default:
				cout << "����������(1-5)" << endl;
				break;

			}
		}
	}

	//�ġ��޸�У�ѵ���Ϣ   c==4��	
	void alter()
	{
		int k = 0;
		ifstream filem("У��¼��Ϣ.txt", ios_base::in);//���ļ�,�Ա��ȡ
		while (filem >> p[k])//eof()�ж�����Ƿ�����ļ��Ľ����� 
		{
			k++;
		}
		filem.close();
		num = k;
		int y;
		int x;
		int i2 = 0;
		cout << "��������Ҫ�޸����ݵ���Ա�ı�ţ�" << endl;
		while (cin >> x)//�ж�����ı���Ƿ��ж�Ӧ����Ա���� 
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

			if (flag)//����ñ�ŵ��˴��ڵĻ���׼����ʼ�޸��������� 
			{
				cout << "1:����" << ' ' << "2:�Ա�" << ' ' << "3������" << ' ' << "4����" << ' ' << "5��ϵ" << ' ' << "6���༶" << ' ' << "7����ַ" << ' ' << "8���绰" << ' ' << "9��QQ" << ' ' << "10������" << endl;
				break;
			}
			else { cout << "������������Ҫ�޸ĵ���Ա�ı��" << endl; }
		}

		cout << "��������Ϊ" << x << "������Ҫ�޸ĵ���Ŀ�Ĵ���" << endl;
		cin >> y;
		string s;

		switch (y)
		{
		case 1:
			cout << "�������µ�������"; cin >> p[i2].name; break;
		case 2:
			cout << "�������µ��Ա�"; cin >> p[i2].sex; break;
		case 3:
			cout << "�������µ����䣺"; cin >> p[i2].age; break;
		case 4:
			cout << "�������µĽ죺"; cin >> p[i2].jie; break;
		case 5:
			cout << "�������µ�ϵ��"; cin >> p[i2].xi; break;
		case 6:
			cout << "�������µİ༶��"; cin >> p[i2].ban; break;
		case 7:
			cout << "�������µĵ�ַ��"; cin >> p[i2].dizhi; break;
		case 8:
			cout << "�������µĵ绰��"; cin >> p[i2].pho; break;
		case 9:
			cout << "�������µ�QQ��"; cin >> p[i2].qq; break;
		case 10:
			cout << "�������µ����䣺"; cin >> p[i2].email; break;
		default:
			cout << "����Ŀ�����ڣ�����" << endl; break;
		}

		ofstream file1("У��¼��Ϣ.txt", ios::out);//����ļ����ڣ���ض��ļ�������ǰ�����ݽ���ɾ�� 
		for (int i3 = 0; i3 < num; i3++)
		{
			file1 << p[i3];
		}

		file1.close();
		system("cls");
		cout << "�������޸Ĳ��������" << endl;
		cout << "���������ַ�����" << endl;
		char fanhui;
		cin >> fanhui;

		//***************************�޸����ݽ���֮�����������˵�����֪��Ϊʲô�������� 
	}

	//�塢��ʾУ�ѵ���Ϣ   c==5��	
	void show()
	{
		int k = 0;
		ifstream filem("У��¼��Ϣ.txt", ios_base::in);
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
			cout << "1-������������ʾ" << ' ' << " 2-����������ʾ" << ' ' << "3-����" << endl;
			cout << "����������ѡ��" << endl;
			cin >> h;

			if (h == 3)
			{
				system("cls");
				break;
			}

			//��������������������
			if (h == 1)
			{
				//bool compareByName(Friends const&, Friends const&);
				cout << setiosflags(ios::left) << setw(5) << "���" << setw(8) << "����" << setw(6) << "�Ա�"
					<< setw(6) << "����" << setw(6) << "�켶" << setw(10) << "ϵ" << setw(10) << "�༶"
					<< setw(18) << "��ַ" << setw(14) << "�绰" << setw(14) << "QQ" << setw(24) << "�ʼ�" << endl;

				sort(p, p + num, compareByName);

				for (int i = 0; i < num; i++)
				{
					fF = p[i];
					cout << fF;
				}
				cout << "�����������ַ�����" << endl;
				char fanhui;
				cin >> fanhui;
				continue;

			}

			//�����ǽ����������	
			if (h == 2)
			{
				cout << setiosflags(ios::left) << setw(5) << "���" << setw(8) << "����" << setw(6) << "�Ա�"
					<< setw(6) << "����" << setw(6) << "�켶" << setw(10) << "ϵ" << setw(10) << "�༶"
					<< setw(18) << "��ַ" << setw(14) << "�绰" << setw(14) << "QQ" << setw(24) << "�ʼ�" << endl;

				sort(p, p + num, compareByJie);

				for (int i = 0; i < num; i++)
				{
					fF = p[i];
					cout << fF;
				}
				cout << "�����������ַ�����" << endl;
				char fanhui;
				cin >> fanhui;
				continue;
			}

			cout << "��������������������ַ���" << endl;
			int fanhui;
			cin >> fanhui;
		}

	}

	//���������ʱ����Ϊ�������ݵĺ���	
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
		cout << "=======================У��¼����=======================" << endl;
		cout << "========================================================" << endl;
		cout << "|                ��ӭ����У��¼����ϵͳ                |" << endl;
		cout << "|                    1.¼��У����Ϣ                    |" << endl;
		cout << "|                    2.ɾ��У����Ϣ                    |" << endl;
		cout << "|                    3.����У����Ϣ                    |" << endl;
		cout << "|                    4.�޸�У����Ϣ                    |" << endl;
		cout << "|                    5.��ʾУ����Ϣ                    |" << endl;
		cout << "|                    0.�˳�                            |" << endl;
		cout << "|------------------------------------------------------|" << endl;
		cout << "|--------------------��ѡ��0-5��:--------------------|" << endl;
		return 0;
	}
};



