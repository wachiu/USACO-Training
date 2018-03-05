/*
ID: wcsiu1
PROG: friday
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool leap(int i)
{
	/*if((1900+i)%100 == 0)
	{
		if((1900+i)%400 == 0)
			return true;
		else
			return false;
	}
	if((1900+i)%4 == 0)
		return true;
	return false;*/
	return ((1900+i)%100 == 0 && (1900+i)%400 == 0) || ((1900+i)%100 != 0 && (1900+i)%4 == 0);
}

int main()
{
	ifstream fin("friday.in");
	ofstream fout("friday.out");
	int week[8] = {0};
	int N;
	fin>>N;
	int remain = 0;
	bool leaping;
	for(int i = 0;i < N;i++)
	{
		leaping = leap(i);
		for(int p = 1;p <13;p++)
		{
			if(leaping && p == 2)
			{
				week[(remain + 13)%7]++;
				remain = (29 + remain)%7;
			}
			if(!leaping && p == 2)
			{
				week[(remain + 13)%7]++;
				remain = (28 + remain)%7;
			}
			if(p == 1 || p == 3|| p == 5 || p == 7 || p == 8 || p == 10 || p == 12)
			{
				week[(remain + 13)%7]++;
				remain = (31 + remain)%7;
			}
			if(p == 4 || p == 6 || p == 9 || p ==11)
			{
				week[(remain + 13)%7]++;
				remain = (30 + remain)%7;
			}
		}
	}
	fout<<week[6]<<' ';
	for(int i = 0;i < 5;i++)
		fout<<week[i]<<' ';
	fout<<week[5]<<endl;
	return 0;
}