#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

#include"Friends.h"
#include"FriendsF.h"
#include"Fdp.cpp"

using namespace std;


int main()
{
	fdp f;
	int c;
	f.menu();
	cin >> c;
	if (c <= 5)
	{
		switch (c)
		{
		case 1:f.add(); cout << endl << endl; main(); break;
		case 2:f.deleted(); cout << endl << endl; main(); break;
		case 3:f.find(); cout << endl << endl; main(); break;
		case 4:f.alter(); cout << endl << endl; main(); break;
		case 5:f.show(); cout << endl << endl; main(); break;
		case 0:exit(1); break;
		}
	}
	else { cout << setw(35) << "input error!!!" << endl; main(); }
}






