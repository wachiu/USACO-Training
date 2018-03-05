/*
ID: wcsiu1
PROG: gift1
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct friends
{
	int money;
	string name;
	int number;
};

void gain(string r, int money, int number, friends stack[])
{
	int i;
	for(i = 0;i < number && r.compare(stack[i].name);i++);
	stack[i].money += money;
	return;
}

int main()
{
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");
	friends stack[10];
	int number;
	fin>>number;
	for(int i = 0;i < number;i++)
	{
		fin>>stack[i].name;
	}
	for(int i = 0;i < number;i++)
	{
		stack[i].money = 0;
	}
	string input;
	int uput;
	int receiver;
	string tempname;
	for(int i = 0;i < number;i++)
	{
		fin>>input>>uput>>receiver;
		if(receiver != 0)
			gain(input,(-uput/receiver)*receiver,number, stack);
		for(int i = 0;i < receiver;i++)
		{
			fin>>tempname;
			gain(tempname,uput/receiver,number,stack);
		}
	}

	for(int i = 0;i < number;i++)
	{
		fout<<stack[i].name<<" "<<stack[i].money<<endl;
	}
	return 0;
}