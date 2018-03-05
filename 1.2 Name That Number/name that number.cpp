/*
ID: wcsiu1
PROG: namenum
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ifstream fin("namenum.in");
	ofstream fout("namenum.out");
	ifstream fdict("dict.txt");
	int number = 0;
	bool trigger = true;
	bool trigger2 = true;
	string name[5000];
	string temp;
	fin>>temp;
	for(number = 0;!fdict.eof();number++)
		fdict>>name[number];
	for(int i = 0;i < number;i++)
	{
		if(name[i].size() == temp.size())
		{
			for(int j = 0;j < temp.size();j++)
			{
				if(temp[j] == '2')
					if(name[i][j] != 'A' && name[i][j] != 'B' && name[i][j] != 'C')
					{
						trigger = false;
						break;
					}
				if(temp[j] == '3')
					if(name[i][j] != 'D' && name[i][j] != 'E' && name[i][j] != 'F')
					{
						trigger = false;
						break;
					}
				if(temp[j] == '4')
					if(name[i][j] != 'G' && name[i][j] != 'H' && name[i][j] != 'I')
					{
						trigger = false;
						break;
					}
				if(temp[j] == '5')
					if(name[i][j] != 'J' && name[i][j] != 'K' && name[i][j] != 'L')
					{
						trigger = false;
						break;
					}
				if(temp[j] == '6')
					if(name[i][j] != 'M' && name[i][j] != 'N' && name[i][j] != 'O')
					{
						trigger = false;
						break;
					}
				if(temp[j] == '7')
					if(name[i][j] != 'P' && name[i][j] != 'R' && name[i][j] != 'S')
					{
						trigger = false;
						break;
					}
				if(temp[j] == '8')
					if(name[i][j] != 'T' && name[i][j] != 'U' && name[i][j] != 'V')
					{
						trigger = false;
						break;
					}
				if(temp[j] == '9')
					if(name[i][j] != 'W' && name[i][j] != 'X' && name[i][j] != 'Y')
					{
						trigger = false;
						break;
					}
			}
			if(trigger)
			{
				fout<<name[i]<<endl;
				trigger2 = false;
			}
			trigger = true;
		}
	}
	if(trigger2)
		fout<<"NONE"<<endl;
	return 0;
}