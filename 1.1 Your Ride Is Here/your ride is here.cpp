/*
ID: wcsiu1
PROG: ride
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ifstream fin("ride.in");
	ofstream fout("ride.out");
	string star, human;
	fin >> star >> human;
	int a = 1,b = 1;
	char A ='A';
	for(int i = 0;i < star.size();i++)
	{
		a = a * (star[i] - A + 1);
	}
		for(int i = 0;i < human.size();i++)
	{
		b = b * (human[i] - A + 1);
	}
	int c,d;
	c = a - (a/47) * 47;
	d = b - b/47 * 47;
	if(c == d)
		fout<<"GO"<<endl;
	else
		fout<<"STAY"<<endl;
	return 0;
}