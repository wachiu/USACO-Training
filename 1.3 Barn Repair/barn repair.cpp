/*
ID: wcsiu1
PROG: barn1
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");
	int occupied[200] = {0};
	bool trigger[200];
	for(int j = 0;j < 200;j++)
		trigger[j] = true;
	int M,S,C;
	int result = 0;
	fin>>M>>S>>C;
	for(int i = 0;i < C;i++)
		fin>>occupied[i];
	int j;
	for (int p = 1; p < C; p++)
	{
		int temp;
		temp = occupied[p];
		for (j = p; j > 0 && temp < occupied[j-1]; j--)
			occupied[j] = occupied[j-1];
		occupied[j] = temp;
	}
	int max = 0;
	int needed = M - 1;
	if(needed == 0)
	{
		fout<<occupied[C-1]-occupied[0]+1<<endl;
		return 0;
	}
	int count = 0;
	while(needed != 0)
	{
		for(int i = C - 1;i > 0;i--)
		{
			if(trigger[i] && occupied[i] - occupied[i-1] - 1 > max)
			{
				max = occupied[i] - occupied[i-1] - 1;
				count = i;
			}
		}
		trigger[count] = false;
		count = 0;
		result += max;
		max = 0;
		needed--;
	}
	if(occupied[0] != 1)
		result += occupied[0] - 1;
	if(occupied[S-1] != S)
		result += S - occupied[C-1];
	fout<<S - result<<endl;
	return 0;
}